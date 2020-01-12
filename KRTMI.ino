//  Library   --------------- //
#include "variables.h"        //  Import file variables.h
#include "PIN.h"              //  Import file PIN.h
#include <PS3BT.h>            //  Import PS3BT.h dari library USB Host Shield 2.0
#include <usbhub.h>           //  Import usbhub.h dari library USB Host Shield 2.0
#include <Servo.h>            //  Import Servo.h
#include <DynamixelSerial1.h> //  Import DynamixelSerial1.h dari library
#ifdef dobogusinclude         //  Bawaan library USB Host Shield 2.0
#include <spi4teensy3.h>      //  Bawaan library USB Host Shield 2.0


#endif                        //  Bawaan library USB Host Shield 2.0
#include <SPI.h>              //  Bawaan library USB Host Shield 2.0

Servo sGripKanan;   //  Buat objek Servo.
Servo sGripKiri;    //  Buat objek Servo.
Servo sGripTengah;  //  Buat objek Servo.

USB Usb;        //  Buat objek USB.
BTD Btd(&Usb);  //  You have to create the Bluetooth Dongle instance like so
PS3BT PS3(&Btd, 0x00, 0x1A, 0x7D, 0xDA, 0x71, 0x13); // Bluetooth dongle MAC Address - diperoleh ketika running sketch.
bool printTemperature, printAngle;  //  Bawaan library USB Host Shield 2.0

//  ========  Void Setup  ========  //
void setup() {

  //  Set serial baud rate.
  Serial.begin(115200);

  //  Inisialisasi servo pada 1Mbps dan Pin PWM Control.
  Dynamixel.begin(1000000, pinDynamixel);

  //  Bawaan library USB Shield Host 2.0
  //  Jangan dihapus
  #if !defined(__MIPSEL__)
    while (!Serial);
  #endif

  //  Bawaan library USB Host Shield 2.0
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  
  Serial.print(F("\r\n|==== Dewi Sri Robots Initialized. ====|"));
  Serial.print(F("\nTunggu bentar gan konekin dulu.."));

  //  Set beberapa pin di mode OUTPUT.
  pinMode(RPWM[0], OUTPUT);
  pinMode(RPWM[1], OUTPUT);
  pinMode(RPWM[2], OUTPUT);
  pinMode(LPWM[0], OUTPUT);
  pinMode(LPWM[1], OUTPUT);
  pinMode(LPWM[2], OUTPUT);
  pinMode(pinPemanas, OUTPUT);
  pinMode(pinGerinda, OUTPUT);

  //  Sinkronkan masing - masing Servo sesuai variabel pin.
  sGripKanan.attach(pinSGka);
  sGripKiri.attach(pinSGki);
  sGripTengah.attach(pinSGte);
  
  // Set semua servo pada posisi awal.
  
  Dynamixel.moveSpeed(idDynaPotongPanas, 1020, 150);
  Dynamixel.moveSpeed(idDynaLenganKiri, posisiLenganNaik, kecepatanLenganNaik);
//  Dynamixel.moveSpeed(idDynaLenganTengah, posisiLenganNaik, kecepatanLenganNaik);
  Dynamixel.moveSpeed(idDynaLenganKanan, posisiLenganNaik, kecepatanLenganNaik);

  Dynamixel.setEndless(idDynaLenganTengah,ON);
  Dynamixel.turn(idDynaLenganTengah,LEFT,0);

  digitalWrite(pinPemanas, LOW);
  analogWrite(pinGerinda, 0);

  sGripKiri.write(20);
  sGripKanan.write(20);
  sGripTengah.write(20);

  PS3.setLedOff();
  PS3.setLedOn(LED1);
  pemotong = "pemanas";
  
}

//  ========  Void Loop ========  //
void loop() {

  //  Variabel nilai kecepatanDua berfungsi sebagai kecepatan tambahan.
  kecepatanDua = map(PS3.getAnalogButton(R2),0,255,0,60);

  Usb.Task(); // Bawaan library USB Host Shield 2.0

  //  Ketika joystick terhubung.
  if (PS3.PS3Connected || PS3.PS3NavigationConnected) {

    //  Panggil fungsi analogJoystik() pada file
    //  analogJoystik.ino
    analogJoystik();

    //  Panggil fungsi tombolJoystik() pada file
    //  tombolJoystik.ino
    tombolJoystik();


    printStatusCapit(); //  Serial print status capit.
    
  } // Penutup PS3 USB Connected
} // Penutup void loop()
