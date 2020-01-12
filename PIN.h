//  PIN PWM Motor   --------------------------------- //
int LPWM[] = {12,8,10};   //  PIN Motor LPWM.
int RPWM[] = {3,9,11};    //  PIN Motor RPWM.

//  PIN PWM Servo biasa   --------------------------- //
const int pinSGka = 6;    // Pin Servo Gripper Kanan.
const int pinSGki = 5;    // Pin Servo Gripper Kiri.
const int pinSGte = 4;    // Pin Servo Gripper Tengah.

//  PIN & ID Servo Dynamixel   ---------------------------- //
const int pinDynamixel = 2;       // Pin PWM data Dynamixel.
const int idDynaPotongPanas = 20; // ID Servo Potong Panas.
const int idDynaLenganKiri = 14;   // ID Servo Lengan Kiri.
const int idDynaLenganKanan = 13;  // ID Servo Lengan Kanan.
const int idDynaLenganTengah = 2; // ID Servo Lengan Tengah.

//  PIN Pemotong   ---------------------------------------- //
const int pinPemanas = 48;     // Pin digital senar potong.
const int pinGerinda = 7;      // Pin analog PWM gerinda.
