/*
TRABALHO PLACAR OLIMPUC 2024
ESPORTE - FUTEBOL
TEMPO DE PARTIDA: 20min (20s)
DATA DE ENTREGA: 07/11
INTEGRANTES DO GRUPO:
  Enrico Araujo
  Júlia Romao
  Nicole Castro
  Rodrigo Grande
*/

// Biblioteca do LCD 16x2
#include <LiquidCrystal.h>

int botaoEquipeA = 9;
int botaoEquipeB = 10;

int PlacarEquipeA = 0;
int PlacarEquipeB = 0;

int inicioA =  LOW;
int inicioB =  LOW;

// BUZZER
 int buzzer = 13; //Ativa o Buzzer
 int porta = A3; // Porta Analogica
// BUZZER

// Inicializa a biblioteca com os pinos da interface
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // LCD
  // Configura as linhas e colunas do LCD
  lcd.begin(16, 2);
  // Escreve na tela do LCD
  lcd.setCursor(0,0);
  lcd.print("TIME A - TIME B");
  lcd.setCursor(0,1);
  //lcd.print("  7    X    1 ");
  lcd.print("  "+ (String)PlacarEquipeA +"    X    1 ");
  //lcd.print(PlacarEquipeA);
  // LCD

  // BUZZER
  pinMode(buzzer, OUTPUT);
  pinMode(porta, INPUT);
  // BUZZER

  //BOTAO
  pinMode(botaoEquipeA, INPUT);
  //pinMode(10, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  inicioA = digitalRead(botaoEquipeA);
  //Serial.println(inicioA);
  

  if(inicioA == HIGH){
    PlacarEquipeA = PlacarEquipeA + 1;
    //Serial.println(PlacarEquipeA);
    //Serial.println("Apertado");
    Serial.println("Placar Equipe A");
    Serial.println(PlacarEquipeA);
    Serial.println("X");
    Serial.println("Placar Equipe B");
    Serial.println(PlacarEquipeB);
  }  else {
    //Serial.println("Não Apertado");
  }
 

  inicioB = digitalRead(botaoEquipeB);
  //Serial.println(inicioB);

  if(inicioB == HIGH){
    PlacarEquipeB = PlacarEquipeB + 1;
    //Serial.println(PlacarEquipeB);
    //Serial.println("Apertado");
    Serial.println("Placar Equipe A");
    Serial.println(PlacarEquipeA);
    Serial.println("X");
    Serial.println("Placar Equipe B");
    Serial.println(PlacarEquipeB);
  }  else {
    //Serial.println("Não Apertado");
  }

  delay(200); 

  lcd.begin(16, 2);
  // Escreve na tela do LCD
  lcd.setCursor(0,0);
  lcd.print("TIME A - TIME B");
  lcd.setCursor(0,1);
  //lcd.print("  7    X    1 ");

  lcd.print("  ");
  lcd.print(PlacarEquipeA);
  lcd.print("    X  ");
  lcd.print(PlacarEquipeB);
  lcd.print(" ");

}