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
        float very_close;
        float close;
        float medium;
        float far;
    };

    struct FuzzyOutputPreference {
        float turn_left;
        float straight;
        float turn_right;
        float backward; 
    };

    float trimf(float x, float a, float b, float c) {
        if (x <= a || x >= c) return 0.0;
        else if (x <= b) return (x - a) / (b - a);
        else return (c - x) / (c - b);
    }

    distanceSet fuzzifyDistance(long distance) {
        distanceSet ds;
        // ds.very_close = trimf(distance, 0, 0, 20);
        // ds.close = trimf(distance, 10, 30, 50);
        // ds.medium = trimf(distance, 40, 60, 80);
        // ds.far = trimf(distance, 70, 100, 100);

        ds.very_close = trimf(distance, 0, 8, 25);
        ds.close = trimf(distance, 15, 35, 55);
        ds.medium = trimf(distance, 40, 70, 90);
        ds.far = trimf(distance, 75, 100, 100);
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

    FuzzyOutputPreference fuzzyInference(long d1, long d2, long d3, long d4) {
        distanceSet front = fuzzifyDistance(d1);
        distanceSet right = fuzzifyDistance(d2);
        distanceSet left = fuzzifyDistance(d3);
        distanceSet back = fuzzifyDistance(d4);

        float pref_turn_left = 0.0;
        float pref_straight = 0.0;
        float pref_turn_right = 0.0;
        float pref_backward = 0.0;

        // float activation_rule1 = fuzzyMin(fdk.far, fdk_.far);
        // pref_straight = fuzzyMax(pref_straight, activation_rule1);

        // float activation_rule2 = fuzzyMin(fdk.close, fdk_.far);
        // pref_turn_right = fuzzyMax(pref_turn_right, activation_rule2);

        // float activation_rule3 = fuzzyMin(fdk_.close, fdk.far);
        // pref_turn_left = fuzzyMax(pref_turn_left, activation_rule3);

        // float activation_rule4 = fuzzyMax(fdk.very_close, fdk_.very_close);
        // pref_straight = fuzzyMax(pref_straight, activation_rule4);

        // float activation_rule5 = fuzzyMin(fuzzyMax(fdk.close, fdk_.close), fsk.far);
        // pref_turn_left = fuzzyMax(pref_turn_left, activation_rule5);

        // float activation_rule6 = fuzzyMin(fuzzyMax(fdk.close, fdk_.close), fsk_.far);
        // pref_turn_right = fuzzyMax(pref_turn_right, activation_rule6);

        // float activation_rule7 = fuzzyMin(fdk.close, fuzzyMin(fdk_.close, fuzzyMin(fsk.close, fsk_.close)));
        // pref_straight = fuzzyMax(pref_straight, activation_rule7);

        // float activation_rule8 = fuzzyMax(fdk.very_close, fdk_.very_close);
        // activation_rule8 = fuzzyMin(activation_rule8, fuzzyMin(fsk.very_close, fsk_.very_close));
        // pref_backward = fuzzyMax(pref_backward, activation_rule8);

        float activation_rule1 = fuzzyMin(front.far,fuzzyMin(right.close, left.close)); // depan jauh, kanan dekat dan kiri dekat maka maju
        pref_straight = fuzzyMax(pref_straight, activation_rule1);

        float activation_rule2 = fuzzyMin(right.far, fuzzyMin(front.close, left.close)); // kanan jauh, depan dekat, kiri dekat maka belok kanan
        pref_turn_right = fuzzyMax(pref_turn_right, activation_rule2);

        float activation_rule3 = fuzzyMin(left.far, fuzzyMin(front.close, right.close)); // kiri jauh, depan dekat, kanan dekat maka belok kiri
        pref_turn_left = fuzzyMax(pref_turn_left, activation_rule3);

        float activation_rule4  = fuzzyMin(front.very_close, fuzzyMin(right.very_close, left.very_close)); // depan sangat dekat, kanan sangat dekat, kiri sangat dekat maka mundur
        pref_backward = fuzzyMax(pref_backward, activation_rule4);

        float activation_rule5 = fuzzyMin(front.far, fuzzyMin(left.medium, right.medium)); // depan jauh, kanan dan kiri sedang maka maju
        pref_straight = fuzzyMax(pref_straight, activation_rule5);

        float activation_rule6 = fuzzyMin(front.medium, fuzzyMin(left.medium, right.medium)); // depan, kiri, kanan sedang maka maju
        pref_straight = fuzzyMax(pref_straight, activation_rule6);

        float activation_rule7 = fuzzyMin(left.close, fuzzyMin(front.far, right.far)); // kiri dekat, kanan dan depan jauh maka belok kanan
        pref_turn_right = fuzzyMax(pref_turn_right, activation_rule7);

        float activation_rule8 = fuzzyMin(right.close, fuzzyMin(front.far, left.far)); // kanan dekat, depan dan kiri jauh maka belok kiri
        pref_turn_left = fuzzyMax(pref_turn_left, activation_rule8);

        float activation_rule9 = fuzzyMin(front.close, fuzzyMin(left.far, right.far)); // depan dekat, kanan dan kiri jauh, maka maju (pelan)
        pref_straight = fuzzyMax(pref_straight, activation_rule9);

        float activation_rule10 = fuzzyMin(back.close, front.far); // depan jauh dan belakang dekat maka maju
        pref_straight = fuzzyMax(pref_straight, activation_rule10);

        float activation_rule11 = front.very_close;
        pref_backward = fuzzyMax(pref_backward, activation_rule11);

        float activation_rule12 = fuzzyMin(fuzzyMin(front.medium, left.medium), fuzzyMin(right.medium, back.medium)); // semua jarak sedang maka maju saja
        pref_straight = fuzzyMax(pref_straight, activation_rule12);

        float activation_rule13 = fuzzyMin(front.medium, fuzzyMin(left.close, right.close)) // depan sedang, kanan dan kiri dekat maka maju
        pref_straight = fuzzyMax(pref_straight, activation_rule13);

        float activation_rule14 = fuzzyMin(left.close, fuzzyMin(front.far, right.medium)); // kiri dekat, depan jauh dan kanan sedang maka maju sambil belok ke kanan
        pref_turn_right = fuzzyMax(pref_turn_right, activation_rule14 * 0.5f); // konstanta belum fix
        pref_straight = fuzzyMax(pref_straight, activation_rule14 * 0.3f);

        float activation_rule15 = fuzzyMin(right.close, fuzzyMin(front.far, left.medium)); // kanan dekat, depan jauh, kiri sedang maka maju sambil belok kiri
        pref_turn_left = fuzzyMax(pref_turn_left, activation_rule15 * 0.5f);
        pref_straight = fuzzyMax(pref_straight, activation_rule15 * 0.3f);


        FuzzyOutputPreference fo;
        fo.turn_left = pref_turn_left;
        fo.straight = pref_straight;
        fo.turn_right = pref_turn_right;
        fo.backward = pref_backward;

        return fo;
    }

    const int OUTPUT_UNIVERSE_SIZE = 61;
    const float OUTPUT_UNIVERSE_MIN = -100.0f;
    const float OUTPUT_UNIVERSE_MAX = 100.0f;

    float mf_turn_left_out(float x) {
        return trimf(x, -80, -50, -10);
    }
    float mf_straight_out(float x) {
        return trimf(x, -30, 0, 30);
    }
    float mf_turn_right_out(float x) {
        return trimf(x, 10, 50, 80);
    }

    float mf_backward_out(float x) {
        return trimf(x, -100, -70, -40); 
    }

    float defuzzifyCOG(FuzzyOutputPreference output) {
        float numerator = 0.0;
        float denominator = 0.0;

        for (int i = 0; i < OUTPUT_UNIVERSE_SIZE; i++) {
            float x = OUTPUT_UNIVERSE_MIN + i * (OUTPUT_UNIVERSE_MAX - OUTPUT_UNIVERSE_MIN) / (OUTPUT_UNIVERSE_SIZE - 1);

            float combined = fuzzyMax(
                fuzzyMax3(
                    fuzzyMin(output.turn_left, mf_turn_left_out(x)),
                    fuzzyMin(output.straight, mf_straight_out(x)),
                    fuzzyMin(output.turn_right, mf_turn_right_out(x))
                ),
                fuzzyMin(output.backward, mf_backward_out(x)) 
            );

            numerator += x * combined;
            denominator += combined;
        }

        if (denominator == 0) return 0.0;
        return numerator / denominator;
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
            BACKWARD = 0,
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

            FuzzyOutputPreference result = fuzzyInference(d1, d2, d3, d4);
            float final_value = defuzzifyCOG(result);

            if (final_value < -50.0f) {
                direction = BACKWARD ; // ganti dengan fungsi gait planning mundue
            } else if (final_value < -15.0f) {
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
                case BACKWARD:
                    // backward_gait();     // fungsi mundur
                    break;
            }
        }

        // delay(200);
    }