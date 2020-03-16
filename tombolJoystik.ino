void tombolJoystik() {
	//  Analog R2 & L2  -------------------------------------//
	if (PS3.getAnalogButton(L2) || PS3.getAnalogButton(R2)) {
		if (PS3.PS3Connected) {
		}
	}

	if (PS3.getButtonClick(PS)) {
	} else {
		//  TOMBOL SEGITIGA & R1 [ Mencapit ]  -------------------------------- //
		if ((PS3.getButtonPress(TRIANGLE)) && (PS3.getButtonPress(R1))) {
			if (posisiGripTengahMap == 20) {                                  //  Jika capit sudah mentok.
				sGripTengah.write(posisiGripTengahMap);                       //  Gripper diam diposisi.
			} else {                                                          //  Jika capit belum mentok.
				posisiGripTengah = posisiGripTengah - 1;                      //  Kurangi variabel posisi servo capit.
				posisiGripTengahMap = map(posisiGripTengah, 0, 50, 20, 100);  //  Mapping kecepatan buka tutup capit.
				sGripTengah.write(posisiGripTengahMap);                       //  Eksekusi servo.
			}
		}

		//  TOMBOL SEGITIGA & L1 [ Membuka ]  --------------------------------- //
		if ((PS3.getButtonPress(TRIANGLE)) && (PS3.getButtonPress(L1))) {
			if (posisiGripTengahMap == 100) {                                 //  Jika capit sudah mentok.
				sGripTengah.write(posisiGripTengahMap);                       //  Gripper diam diposisi.
			} else {                                                          //  Jika capit belum mentok.
				posisiGripTengah = posisiGripTengah + 1;                      //  Tambahi variabel posisi servo capit.
				posisiGripTengahMap = map(posisiGripTengah, 0, 50, 20, 100);  // Mapping kecepatan buka tutup capit.
				sGripTengah.write(posisiGripTengahMap);                       //  Eksekusi servo.
			}
		}

		//  TOMBOL LINGKARAN & R1 [ Mencapit ]  -------------------------------- //
		if ((PS3.getButtonPress(CIRCLE)) && (PS3.getButtonPress(R1))) {
			if (posisiGripKananMap == 20) {                                //  Jika capit sudah mentok.
				sGripKanan.write(posisiGripKananMap);                      //  Gripper diam diposisi.
			} else {                                                       //  Jika capit belum mentok.
				posisiGripKanan = posisiGripKanan - 1;                     //  Kurangi variabel posisi servo capit.
				posisiGripKananMap = map(posisiGripKanan, 0, 5, 20, 100);  // Mapping kecepatan buka tutup capit.
				sGripKanan.write(posisiGripKananMap);                      //  Eksekusi servo.
			}
		}

		//  TOMBOL LINGKARAN & L1 [ Membuka ]  --------------------------------- //
		if ((PS3.getButtonPress(CIRCLE)) && (PS3.getButtonPress(L1))) {
			if (posisiGripKananMap == 100) {                               //  Jika capit sudah mentok.
				sGripKanan.write(posisiGripKananMap);                      //  Gripper diam diposisi.
			} else {                                                       //  Jika capit belum mentok.
				posisiGripKanan = posisiGripKanan + 1;                     //  Tambahi variabel posisi servo capit.
				posisiGripKananMap = map(posisiGripKanan, 0, 5, 20, 100);  // Mapping kecepatan buka tutup capit.
				sGripKanan.write(posisiGripKananMap);                      //  Eksekusi servo.
			}
		}

		//  TOMBOL KOTAK & R1 [ Mencapit ]  -------------------------------- //
		if ((PS3.getButtonPress(SQUARE)) && (PS3.getButtonPress(R1))) {
			if (posisiGripKiriMap == 20) {                               //  Jika capit sudah mentok.
				sGripKiri.write(posisiGripKiriMap);                      //  Gripper diam diposisi.
			} else {                                                     //  Jika capit belum mentok.
				posisiGripKiri = posisiGripKiri - 1;                     //  Kurangi variabel posisi servo capit.
				posisiGripKiriMap = map(posisiGripKiri, 0, 5, 20, 100);  // Mapping kecepatan buka tutup capit.
				sGripKiri.write(posisiGripKiriMap);                      //  Eksekusi servo.
			}
		}

		//  TOMBOL KOTAK & L1 [ Membuka ]  --------------------------------- //
		if ((PS3.getButtonPress(SQUARE)) && (PS3.getButtonPress(L1))) {
			if (posisiGripKiriMap == 100) {                              //  Jika capit sudah mentok.
				sGripKiri.write(posisiGripKiriMap);                      //  Gripper diam diposisi.
			} else {                                                     //  Jika capit belum mentok.
				posisiGripKiri = posisiGripKiri + 1;                     //  Tambahi variabel posisi servo capit.
				posisiGripKiriMap = map(posisiGripKiri, 0, 5, 20, 100);  // Mapping kecepatan buka tutup capit.
				sGripKiri.write(posisiGripKiriMap);                      //  Eksekusi servo.
			}
		}

		//  TOMBOL CROSS   ------------- //
		if (PS3.getButtonPress(CROSS)) {
			if (pemotong == "pemanas") {
				digitalWrite(pinPemanas, HIGH);
			} else {
				analogWrite(pinGerinda, kecepatanGerinda);
			}
		}

		if (!PS3.getButtonPress(CROSS)) {
			if (pemotong == "pemanas") {
				digitalWrite(pinPemanas, LOW);
			} else {
				analogWrite(pinGerinda, 0);
			}
		}

		if (PS3.getButtonPress(RIGHT)) {
			if (posisiServoPotongMap == 2048) {
				posisiServoPotongMap = posisiServoPotongMap;
			} else {
				posisiServoPotongMap = posisiServoPotongMap + 1;
			}
			posisiServoPotong = mapFloat(posisiServoPotongMap, 0, 2048, 0, 1023);
			Dynamixel.moveSpeed(idDynaPotongPanas, posisiServoPotong, 100);
		}

		if (PS3.getButtonPress(LEFT)) {
			if (posisiServoPotongMap == 0) {
				posisiServoPotongMap = posisiServoPotongMap;
			} else {
				posisiServoPotongMap = posisiServoPotongMap - 1;
			}
			posisiServoPotong = map(posisiServoPotongMap, 0, 2048, 0, 1023);
			Dynamixel.moveSpeed(idDynaPotongPanas, posisiServoPotong, 100);
		}

		//  TOMBOL SEGITIGA DAN ATAS   ------------ //
		if (PS3.getButtonPress(TRIANGLE) && PS3.getButtonPress(UP)) {
			Dynamixel.turn(idDynaLenganTengah, RIGTH, 800);
		}

		//  TOMBOL SEGITIGA DAN BAWAH   ------------ //
		if (PS3.getButtonPress(TRIANGLE) && PS3.getButtonPress(DOWN)) {
			Dynamixel.turn(idDynaLenganTengah, LEFT, 350);
		}

		//  TOMBOL SEGITIGA TIDAK DI KLIK   ------------ //
		if (!PS3.getButtonPress(TRIANGLE) && !PS3.getButtonPress(DOWN) && !PS3.getButtonPress(UP)) {
			Dynamixel.turn(idDynaLenganTengah, LEFT, 0);
		}

		//  TOMBOL LINGKARAN DAN ATAS  ------------ //
		if (PS3.getButtonPress(CIRCLE) && PS3.getButtonPress(UP)) {
			Dynamixel.moveSpeed(idDynaLenganKanan, posisiLenganNaik, 400);
		}

		//  TOMBOL LINGKARAN DAN ATAS ------------ //
		if (PS3.getButtonPress(CIRCLE) && PS3.getButtonPress(DOWN)) {
			Dynamixel.moveSpeed(idDynaLenganKanan, posisiLenganTurun, 250);
		}

		//  TOMBOL KOTAK DAN ATAS ------------ //
		if (PS3.getButtonPress(SQUARE) && PS3.getButtonPress(UP)) {
			Dynamixel.moveSpeed(idDynaLenganKiri, posisiLenganNaik, 400);
		}

		//  TOMBOL KOTAK DAN BAWAH ------------ //
		if (PS3.getButtonPress(SQUARE) && PS3.getButtonPress(DOWN)) {
			Dynamixel.moveSpeed(idDynaLenganKiri, posisiLenganTurun, 250);
		}

		if (PS3.getButtonPress(UP)) {
			Serial.print("UP");
		}

		if (PS3.getButtonClick(L1))
			//        Serial.print(F("\r\nL1"));
			if (PS3.getButtonClick(L3))
				Serial.print(F("\r\nL3"));
		if (PS3.getButtonClick(R1))
			//        Serial.print(F("\r\nR1"));
			if (PS3.getButtonClick(R3))
				Serial.print(F("\r\nR3"));

		if (PS3.getButtonClick(SELECT)) {
			PS3.printStatusString();

			if (pemotong == "pemanas") {
				PS3.setLedOff();
				PS3.setLedOn(LED4);
				pemotong = "gerinda";
			} else {
				PS3.setLedOff();
				PS3.setLedOn(LED1);
				pemotong = "pemanas";
			}
		}

		if (PS3.getButtonClick(START)) {
			printAngle = !printAngle;
		}
	}
}
