void motor(int pwm, int motor){

  if (stopRobot == true) {
    analogWrite(RPWM[0], 0);
    analogWrite(RPWM[1], 0);
    analogWrite(RPWM[2], 0);
    analogWrite(LPWM[0], 0);
    analogWrite(LPWM[1], 0);
    analogWrite(LPWM[2], 0);
    
  } else {
    if (pwm<0){
      analogWrite(LPWM[motor], abs(pwm) );
      analogWrite(RPWM[motor], 0);
    } else {
      analogWrite(LPWM[motor], 0);
      analogWrite(RPWM[motor], pwm);
    }

//    if(motor == 0){
//    Serial.print("motor[");
//    Serial.print(motor);
//    Serial.print("] : ");
//    Serial.print(pwm);
//    Serial.print("\t");      
//    }
//    if(motor == 1){
//    Serial.print("motor[");
//    Serial.print(motor);
//    Serial.print("] : ");
//    Serial.print(pwm);
//    Serial.print("\t");      
//    }
//    if(motor == 2){
//    Serial.print("motor[");
//    Serial.print(motor);
//    Serial.print("] : ");
//    Serial.print(pwm);
//    Serial.print("\t");
//    Serial.print("\n");
//    }
    
  }
}

float deg2rad(float inputAngle){
  return inputAngle * (M_PI / 180.0);
}

float rad2deg(float inputAngle){
  return inputAngle *  (180.0 / M_PI);
}

void kin3(float x, float y, float w){
  float b = baseKecepatan + kecepatanDua;
  int m[3];
  
  m[0]  = (y*(-0.5)*b - x*(sqrt(3)/2)*b + w*0.33);
  m[1]  = ( (y*(-0.5)*b + x*(sqrt(3)/2)*b + w*0.33));
  m[2]  = (y*b);
  
  
  for(int i=0;i<3;i++){
    motor(m[i],i);
  }
}
