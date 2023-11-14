// Servo Motor
#include <Servo.h>

// Biblioteca do LCD 16x2
#include <LiquidCrystal.h>

// <SERVO>
#define SERVOLEFTARM 9 // Porta Digital 2
#define SERVORIGHTARM 10 // Porta Digital 3

Servo leftArm; // Variável Servo
Servo rightArm; // Variável Servo

int positionLeftArm; // Posição Servo
int positionRightArm; // Posição Servo
// </SERVO>

// Inicializa a biblioteca com os pinos da interface
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup () {
  // <SERVO>
  leftArm.attach(SERVOLEFTARM); //Víncula a váriavel com a porta analógica
  rightArm.attach(SERVORIGHTARM);
  Serial.begin(9600);
  leftArm.write(0); // Inicia motor posição zero
  rightArm.write(0); // Inicia motor posição zero
  // </SERVO>

  // <LCD>
  // Configura as linhas e colunas do LCD
  lcd.begin(16, 2);
  // Escreve na tela do LCD

  // PARADO
  lcd.setCursor(0,0);
  lcd.print("    0      0   ");
  lcd.setCursor(0,1);
  lcd.print("      ----     ");
  
  // DANÇANDO
  // lcd.setCursor(0,0);
  // lcd.print("    >      <   ");
  // lcd.setCursor(0,1);
  // lcd.print("      ----     ");
  //</LCD>
}

void loop(){
  // <SERVO>
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
  // </SERVO>
  delay(1000);
  
}
