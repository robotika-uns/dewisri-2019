float mapFloat(float x, float in_min, float in_max, float out_min, float out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void printStatusCapit() {
    Serial.print("\nGrip Kanan : ");
    Serial.print(posisiGripKananMap);
    Serial.print("\tGrip Kiri : ");
    Serial.print(posisiGripKiriMap);
    Serial.print("\tGrip Depan : ");
    Serial.print(posisiGripTengahMap);
}
