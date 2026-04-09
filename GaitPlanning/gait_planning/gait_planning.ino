#include <math.h>

#define RAD_TO_DEG 57.29577951

struct Point3D {
  x, y, z;
};


struct SudutKaki {
  double coxa, femur, tibia;
};

double t_iter = 0.0;

double t_iter = 0.0;
bool isFaseMaju = true;


Point3D hitungTrajectoryPolynomial(Point3D P1, Point3D P2, Point3D P3, Point3D P4, double t) {
    Point3D P;
    double t1 = 1.0 - t;
    
    P.x = (t1*t1*t1)*P1.x + 3*t*(t1*t1)*P2.x + 3*(t*t)*t1*P3.x + (t*t*t)*P4.x;
    P.y = (t1*t1*t1)*P1.y + 3*t*(t1*t1)*P2.y + 3*(t*t)*t1*P3.y + (t*t*t)*P4.y;
    P.z = (t1*t1*t1)*P1.z + 3*t*(t1*t1)*P2.z + 3*(t*t)*t1*P3.z + (t*t*t)*P4.z;
    
    return P;
}


SudutKaki hitungIK3DoF(double x, double y, double z) {
    SudutKaki hasil = {0, 0, 0};
    
    double L1 = 3.0;  
    double L2 = 7.0;  
    double L3 = 10.0; 

    hasil.coxa = atan2(y, x) * RAD_TO_DEG;

    double D = sqrt(x * x + y * y); 
    double R = D - L1;              
    double H = sqrt(R * R + z * z); 

    if (H > (L2 + L3)) {
        Serial.println("Target di luar jangkauan kaki!");
        return hasil;
    }

    double theta_f1 = atan2(z, R) * RAD_TO_DEG; 
    double cos_f2 = (L2*L2 + H*H - L3*L3) / (2 * H * L2);
    double theta_f2 = acos(cos_f2) * RAD_TO_DEG;
    hasil.femur = theta_f1 + theta_f2;

    double cos_tibia = (L2*L2 + L3*L3 - H*H) / (2 * L2 * L3);
    hasil.tibia = acos(cos_tibia) * RAD_TO_DEG - 90.0; 

    return hasil;
}


void setup() {
    Serial.begin(9600); 
    Serial.println("=== SIMULASI TRIPOD GAIT HEXAPOD ===");
    
}


void loop() {
    Point3D P1 = {10.0, 5.0, 0.0};   
    Point3D P2 = {12.0, 5.0, 4.0};   
    Point3D P3 = {18.0, 5.0, 4.0};   
    Point3D P4 = {20.0, 5.0, 0.0};   

    Point3D S1 = {20.0, 5.0, 0.0};   
    Point3D S4 = {10.0, 5.0, 0.0};   

    Serial.print("Waktu iterasi t = ");
    Serial.println(t_iter);

    Point3D targetMaju = hitungTrajectoryPolynomial(P1, P2, P3, P4, t_iter);
    SudutKaki sudutMaju = hitungIK3DoF(targetMaju.x, targetMaju.y, targetMaju.z);
    
    Point3D targetMundur;
    targetMundur.x = S1.x + t_iter * (S4.x - S1.x); 
    targetMundur.y = 5.0; 
    targetMundur.z = 0.0; 
    SudutKaki sudutMundur = hitungIK3DoF(targetMundur.x, targetMundur.y, targetMundur.z);

    if (isFaseMaju) {
        Serial.print("[GRUP 1 - Melayang] Sudut Femur: "); Serial.println(sudutMaju.femur);
        Serial.print("[GRUP 2 - Mendorong] Sudut Femur: "); Serial.println(sudutMundur.femur);
    } else {
        Serial.print("[GRUP 2 - Melayang] Sudut Femur: "); Serial.println(sudutMaju.femur);
        Serial.print("[GRUP 1 - Mendorong] Sudut Femur: "); Serial.println(sudutMundur.femur);
    }
    Serial.println("--------------------------------");

    t_iter += 0.2;

    if (t_iter > 1.0) {
        t_iter = 0.0;
        isFaseMaju = !isFaseMaju; 
        Serial.println(">>> FASE SELESAI, TUKAR PERAN KAKI <<<");
        delay(500); 
    }

    delay(100);
}