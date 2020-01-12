//  NOTE...
//  Nilai analog joystik x dari bawah ke atas adalah 0 - 255.
//  Nilai analog joystik y dari kiri ke kanan adalah 0 - 255.
//  Nilai analog joystik x dan y  ketika berada di tengah bernilai 127.

void analogJoystik() {

  nilaiKoordinatY = mapFloat(PS3.getAnalogHat(LeftHatY),0,255,-1,1);
  nilaiKoordinatX = mapFloat(PS3.getAnalogHat(LeftHatX),255,0,-1,1);

  // Jika analog kiri bergerak dan analog kanan berada di tengah.
  if ((PS3.getAnalogHat(RightHatX) == 127) && (PS3.getAnalogHat(RightHatY) == 127)){
    kin3(nilaiKoordinatY,nilaiKoordinatX,0);
    stopRobot = false;
  }

  // Jika analog kanan dan kiri berada di tengah.
  if ((PS3.getAnalogHat(LeftHatX) == 127) && (PS3.getAnalogHat(LeftHatY) == 127) &&
  (PS3.getAnalogHat(RightHatX) == 127) && (PS3.getAnalogHat(RightHatY) == 127))
  {
    //  Mengindikasikan semua motor untuk berhenti.
    stopRobot = true;
  }

  //  Jika analog kiri di tengah dan kanan di kanan.
  //  Robot berputar ke kanan.
  if ((PS3.getAnalogHat(LeftHatY) == 127) && (PS3.getAnalogHat(RightHatX) < 127))
  {

    //  Mapping dari nilai semula input analog joystik kanan range 127 sampai 0
    //  menjadi range 0 sampai nilai baseKecepatan dikalikan -1 supaya nilai kembalinya 
    //  menjadi negatif kemudian ditambah kecepatanDua. Setelah itu write menggunakan motor(pwm, indexPinMotor).
    motor( (map(PS3.getAnalogHat(RightHatX), 127, 0, 0, (-1 * baseKecepatan) ) - kecepatanDua), 0);
    motor( (map(PS3.getAnalogHat(RightHatX), 127, 0, 0, (-1 * baseKecepatan) ) - kecepatanDua), 1);
    motor( (map(PS3.getAnalogHat(RightHatX), 127, 0, 0, (-1 * baseKecepatan) ) - kecepatanDua), 2);

    //  Mengindikasikan semua motor untuk tidak berhenti.
    stopRobot = false;
    
  }

  //  Jika analog kiri di tengah dan kanan di kiri.
  //  Robot berputar ke kiri.
  if ((PS3.getAnalogHat(LeftHatY) == 127) && (PS3.getAnalogHat(RightHatX) > 127))
  {
    
    //  Mapping dari nilai semula input analog joystik kanan range 127 sampai 255 
    //  menjadi range 0 sampai nilai baseKecepatan kemudian ditambah kecepatanDua.
    //  Setelah itu write menggunakan motor(pwm, indexPinMotor).
    motor( (map(PS3.getAnalogHat(RightHatX), 127, 255, 0, baseKecepatan) + kecepatanDua), 0);
    motor( (map(PS3.getAnalogHat(RightHatX), 127, 255, 0, baseKecepatan) + kecepatanDua), 1);
    motor( (map(PS3.getAnalogHat(RightHatX), 127, 255, 0, baseKecepatan) + kecepatanDua), 2);

    //  Mengindikasikan semua motor untuk tidak berhenti.
    stopRobot = false;
    
  }
}
