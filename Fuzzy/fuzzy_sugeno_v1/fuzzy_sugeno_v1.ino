    #include <vector>

    #define TRIG1 7
    #define ECHO1 6

    #define TRIG2 9
    #define ECHO2 8

    #define TRIG3 11
    #define ECHO3 10

    #define TRIG4 13
    #define ECHO4 12

    unsigned long previousMillis_sensor = 0;
    unsigned long previousMillis_gait   = 0;

    const long interval_sensor = 150;   // baca sensor + fuzzy setiap 150 ms
    const long interval_gait   =  40;   // update servo/gait setiap 40 ms

    struct distanceSet {
        float close;
        float medium;
        float far;
    };

    struct RuleOutput {
        float firing;
        float z;
    }

    float trapmf(float x, float a, float b, float c, float d) {
        if (x <= a || x >= d) return 0.0;
        else if (x <= b) return (x - a) / (b - a);
        else if (x <= c) return 1.0;
        else return (d - x) / (d - c);
    }

    distanceSet fuzzifyDistance(long distance) {
        distanceSet ds;
    
        ds.close = trapmf(distance, 0, 0, 5, 7.5);
        ds.medium = trapmf(distance, 5, 7.5, 10, 15);
        ds.far = trapmf(distance, 5, 7.5, 10, 10);
        return ds;
    }

    float fuzzyMin(float a, float b) {
        return (a < b) ? a : b;
    }

    float fuzzyMax(float a, float b) {
        return (a > b) ? a : b;
    }

    float fuzzyMax3(float a, float b, float c) {
        return fuzzyMax(a, fuzzyMax(b, c));
    }

    long readUltrasonic(int trigPin, int echoPin) {
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        long duration = pulseIn(echoPin, HIGH, 30000);
        if (duration == 0) return 100;
        long distance = duration * 0.034 / 2;
        return constrain(distance, 0, 100);
    }

    void fuzzyInference(long d1, long d2, long d3, long d4, vector<RuleOutput>& outputs) {
        distanceSet front = fuzzifyDistance(d1);
        distanceSet right = fuzzifyDistance(d2);
        distanceSet left = fuzzifyDistance(d3);
        distanceSet back = fuzzifyDistance(d4);

        // Rule 1: Depan far, kanan close, kiri close → straight (z=0)
        outputs[0].firing = fuzzyMin(front.far, fuzzyMin(right.close, left.close));
        outputs[0].z = 0.0f;

        // Rule 2: Kanan far, depan close, kiri close → turn_right (z=50)
        outputs[1].firing = fuzzyMin(right.far, fuzzyMin(front.close, left.close));
        outputs[1].z = 50.0f;

        // Rule 3: Kiri far, depan close, kanan close → turn_left (z=-50)
        outputs[2].firing = fuzzyMin(left.far, fuzzyMin(front.close, right.close));
        outputs[2].z = -50.0f;

        // Rule 4: Depan far, kiri medium, kanan medium → straight (z=0)
        outputs[3].firing = fuzzyMin(front.far, fuzzyMin(left.medium, right.medium));
        outputs[3].z = 0.0f;

        // Rule 5: Depan medium, kiri medium, kanan medium → straight (z=0)
        outputs[4].firing = fuzzyMin(front.medium, fuzzyMin(left.medium, right.medium));
        outputs[4].z = 0.0f;

        // Rule 6: Kiri close, depan far, kanan far → turn_right (z=50)
        outputs[5].firing = fuzzyMin(left.close, fuzzyMin(front.far, right.far));
        outputs[5].z = 50.0f;

        // Rule 7: Kanan close, depan far, kiri far → turn_left (z=-50)
        outputs[6].firing = fuzzyMin(right.close, fuzzyMin(front.far, left.far));
        outputs[6].z = -50.0f;

        // Rule 8: Depan close, kiri far, kanan far → straight (pelan, z=0 tapi bisa adjust)
        outputs[7].firing = fuzzyMin(front.close, fuzzyMin(left.far, right.far));
        outputs[7].z = 0.0f;

        // Rule 9: Depan far, belakang close → straight (z=0)
        outputs[8].firing = fuzzyMin(back.close, front.far);
        outputs[8].z = 0.0f;

        // Rule 10: Semua medium → straight (z=0)
        outputs[9].firing = fuzzyMin(fuzzyMin(front.medium, left.medium), fuzzyMin(right.medium, back.medium));
        outputs[9].z = 0.0f;
    }

    float defuzzifySugeno(const vector<RuleOutput> &outputs) {
        float num = 0.0f, den = 0.0f;
        for(const auto& output : outputs) {
            num += output.firing * output.z;
            den += outputs.firing;
        }
        return (den > 0) ? num / den : 0.0f;
    }

    long d1, d2, d3, d4;

    void setup() {
        Serial.begin(9600);

        pinMode(TRIG1, OUTPUT); pinMode(ECHO1, INPUT);
        pinMode(TRIG2, OUTPUT); pinMode(ECHO2, INPUT);
        pinMode(TRIG3, OUTPUT); pinMode(ECHO3, INPUT);
        pinMode(TRIG4, OUTPUT); pinMode(ECHO4, INPUT);

    }

    void loop() {
        unsigned long currentMillis = millis();

        enum DIRECTION {
            LEFT = 1,
            RIGHT = 2,
            STRAIGHT_FORWARD = 3
        };

        DIRECTION direction = STRAIGHT_FORWARD;

        // Baca sensor dan hitung logika fuzzy
        if(currentMillis - previousMillis_sensor >= interval_sensor) {
            d1 = readUltrasonic(TRIG1, ECHO1); // depan
            d2 = readUltrasonic(TRIG2, ECHO2); // kanan
            d3 = readUltrasonic(TRIG3, ECHO3); // kiri
            d4 = readUltrasonic(TRIG4, ECHO4); // belakang

            vector<RuleOuput> outputs;
            fuzzyInference(d1, d2, d3, d4, outputs);
            float final_value = deuzzifySugeno(outputs);

            if (final_value < -15.0f) {
                direction = LEFT; // ganti dengan fungsi gait planning belok ke kiri
            } else if (final_value > 15.0f) {
                direction = RIGHT; // ganti dengan fungsi gait planning belok ke kanan
            } else {
                direction = STRAIGHT_FORWARD; // ganti dengan fungsi gait planning maju
            }

            Serial.println((int)direction); 
        }

        // Panggil fungsi gait untuk menggerakkkan robot
        if(currentMillis - previousMillis_gait >= interval_gait) {
            switch (current_direction) {
                case STRAIGHT_FORWARD:
                    //forward_gait();      // fungsi maju kamu
                    break;
                case LEFT:
                    // rotate_left_gait();  // fungsi belok kiri
                    break;
                case RIGHT:
                    // rotate_right_gait(); // fungsi belok kanan
                    break;
            }
        }
    }