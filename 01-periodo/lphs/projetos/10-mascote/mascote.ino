#include <Servo.h>

#define SERVOLEFTARM 2 // Porta Digital 2
#define SERVORIGHTARM 3 // Porta Digital 3

Servo leftArm; // Variável Servo
Servo rightArm; // Variável Servo

int positionLeftArm; // Posição Servo
int positionRightArm; // Posição Servo

void setup ()
{
  leftArm.attach(SERVOLEFTARM); //Víncula a váriavel com a porta analógica
  rightArm.attach(SERVORIGHTARM);
  Serial.begin(9600);
  leftArm.write(0); // Inicia motor posição zero
  rightArm.write(0); // Inicia motor posição zero
}

void loop(){

  // <LEFT ARM>
  for(positionLeftArm = 0; positionLeftArm < 90; positionLeftArm++) {
    leftArm.write(positionLeftArm);
  }
  // </LEFT ARM>

  // <RIGHT ARM>
  for(positionRightArm = 0; positionRightArm < 90; positionRightArm++) {
    rightArm.write(positionRightArm);
  }
  // </RIGHT ARM>

  delay(500);

  // <LEFT ARM>
  for(positionLeftArm = 90; positionLeftArm >= 0; positionLeftArm--) {
    leftArm.write(positionLeftArm);
  }
  // </LEFT ARM>

  // <RIGHT ARM>
  for(positionRightArm = 90; positionRightArm >= 0; positionRightArm--) {
    rightArm.write(positionRightArm);
  }
  // </RIGHT ARM>

  delay(1000);
  
}
