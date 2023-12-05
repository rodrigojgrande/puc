/*
DOCUMENTAÇÃO
Portas Utilizando:
02 => LCD
03 => LCD
04 => LCD
05 => LCD
08 => PIR
09 =>  SERVO
10 => SERVO
11 => LCD
12 => LCD

Portas Livres: 06 - 07 - 13

Fios:
Vermelho: 5V
Marrom: GND
Laranja: Portas
Roxo: Potenciometro
Azul: Servo Right Arm
Verde: Servo Left Arm 
Amarelo: Pir Sensor


*/

// Servo Motor
#include <Servo.h>

// Biblioteca do LCD 16x2
#include <LiquidCrystal.h>

// <SERVO>
#define SERVOLEFTARM 9 // Porta Digital 9
#define SERVORIGHTARM 10 // Porta Digital 10

Servo leftArm; // Variável Servo
Servo rightArm; // Variável Servo

int positionLeftArm; // Posição Servo
int positionRightArm; // Posição Servo
// </SERVO>

// LCD
// Inicializa a biblioteca com os pinos da interface LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// PIR
int pirSensor = 8; // Pino Sensor de Presença
int active = 1;
int inactive = 0;

void setup () {
  // <SERVO>
  leftArm.attach(SERVOLEFTARM); //Víncula a váriavel com a porta analógica
  rightArm.attach(SERVORIGHTARM);
  Serial.begin(9600);
  leftArm.write(0); // Inicia motor posição zero
  rightArm.write(0); // Inicia motor posição zero
  // </SERVO>

  // <PIR>
  //pinMode(pinoLed, OUTPUT); // Define o pino como saída
  pinMode(pirSensor, INPUT); //Define o pino como entrada
  // </PIR>

  // <LCD>
  // Configura as linhas e colunas do LCD
  lcd.begin(16, 2);
  // Escreve na tela do LCD
}

void loop(){
  // <PIR>
  if(digitalRead(pirSensor) == HIGH){ //Se a leitura for igual a HIGH
    // DANÇANDO
    lcd.setCursor(0,0);
    lcd.print("    >      <   ");
    lcd.setCursor(0,1);
    lcd.print("      ----     ");
    //</LCD>

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
    for(positionLeftArm = 90; positionLeftArm < 180; positionLeftArm++) {
      leftArm.write(positionLeftArm);
    }
    // </LEFT ARM>

     delay(500);

    // <LEFT ARM>
    for(positionLeftArm = 180; positionLeftArm >= 0; positionLeftArm--) {
      leftArm.write(positionLeftArm);
    }
    // </LEFT ARM>

    // <RIGHT ARM>
    for(positionRightArm = 90; positionRightArm >= 0; positionRightArm--) {
      rightArm.write(positionRightArm);
    }
    // </RIGHT ARM>
    // </SERVO>
    Serial.println(active);
  }else{ 
    // PARADO
    lcd.setCursor(0,0);
    lcd.print("    0      0   ");
    lcd.setCursor(0,1);
    lcd.print("      ----     ");
    // PARADO

    Serial.println(inactive);
  }
  // </PIR>
  delay(1000);
}
