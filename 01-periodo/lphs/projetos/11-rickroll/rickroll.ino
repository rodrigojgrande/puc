/*
DOCUMENTAÇÃO
Portas Utilizando:
02 => LCD
03 => LCD
04 => LCD
05 => LCD
08 => PIR
09 => SERVO
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

// BUZZER 
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0


// change this to make the song slower or faster
int tempo = 114;

// change this to whichever pin you want to use
int buzzer = 7;

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int melody[] = {

  // Never Gonna Give You Up - Rick Astley
  // Score available at https://musescore.com/chlorondria_5/never-gonna-give-you-up_alto-sax
  // Arranged by Chlorondria

 /* 
 NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,

  NOTE_E5,-8, NOTE_E5,-8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,-8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //18
  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,8, NOTE_A4,8, NOTE_A4,8, 
  NOTE_E5,4, NOTE_D5,2, 
  */
  
  // NOTE_A4,16, 
  
  // NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,

  // NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  // NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,

  // NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8,  //23
  // NOTE_E5,4, NOTE_D5,2, REST,4,
  
  
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;
// BUZZER


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

    // <LEFT ARM>
    for(positionLeftArm = 180; positionLeftArm >= 0; positionLeftArm--) {
      leftArm.write(positionLeftArm);
    }
    // </LEFT ARM>

     delay(500);

    // <RIGHT ARM>
    for(positionRightArm = 90; positionRightArm >= 0; positionRightArm--) {
    // for(positionRightArm = -90; positionRightArm <= 0; positionRightArm++) {
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
    for(positionRightArm = -90; positionRightArm <= 0; positionRightArm++) {
      rightArm.write(positionRightArm);
    }
    // </RIGHT ARM>
    // </SERVO>
    Serial.println(active);

      // BUZZER
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
  // BUZZER
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