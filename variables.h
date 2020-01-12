float nilaiKoordinatY;            //  Nilai Koordinat Y.
float nilaiKoordinatX;            //  Nilai Koordinat X.

int kecepatanGrip = 150;          //  Kecepatan Capit Gripper.
                                  //  Semakin kecil semakin cepat.  
int kecepatanGerinda = 64;

String pemotong = "pemanas";
String posisiCapitDepan = "dibawah";
int posisiLenganNaik = 205;       //  Posisi lengan naik.
int posisiLenganTurun = 512;      //  Posisi lengan turun.
bool stopRobot;                   //  Status robot berhenti atau tidak.

int posisiGripKanan = 0;          //  Posisi grip kanan sebelum di mapping.
int posisiGripKiri = 0;           //  Posisi grip kiri sebelum di mapping.
int posisiGripTengah = 0;         //  Posisi grip tengah sebelum di mapping.
int posisiGripKananMap = 20;       //  Posisi grip kanan setelah di mapping.
int posisiGripKiriMap = 20;        //  Posisi grip kiri setelah di mapping.
int posisiGripTengahMap = 20;      //  Posisi grip tengah setelah di mapping.

int posisiServoPotong;
int posisiServoPotongMap = 2040;

int rpwmKanan = 0;                //  PWM Awal Motor.
int lpwmKanan = 0;                //  PWM Awal Motor.
int rpwmKiri = 0;                 //  PWM Awal Motor.
int lpwmKiri = 0;                 //  PWM Awal Motor.
int rpwmTengah = 0;               //  PWM Awal Motor.
int lpwmTengah = 0;               //  PWM Awal Motor.

float baseKecepatan = 40.0;       //  Base kecepatan robot.
float kecepatanDua = 0;           //  Kecepatan tambahan R2.
int kecepatanLenganNaik = 400;    //  Kecepatan lengan naik.
