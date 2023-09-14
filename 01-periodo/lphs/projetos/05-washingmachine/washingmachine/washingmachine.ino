#include <Stepper.h> //Chamada de Biblioteca
int passos = 500; //Padrão do Driver - Precisão de Passos
int led = 2; //Define o Led para informar que a máquina está ligada

int botaoLed = 3; //Define a porta do botão para ligar o led
int botaoBater = 4; //Define a porta do botão para ligar o motor
int botaoCentrifugar = 5; //Define a porta do botão para ligar o motor

int inicioLed = LOW;
int inicioBater = LOW;
int inicioCentrifugar = LOW;

int contador = 0;

Stepper lphs(passos, 8, 10, 9, 11); //Chamada da função através da função
// Números não em ordem 

void setup(){
  //LED
  pinMode(led, OUTPUT);

  //Botão
  pinMode(botaoLed, INPUT);
  Serial.begin(9600); //9600 Taxa de comunicação padrão do arduino "baud"

  //Motor de Passo
	lphs.setSpeed(60); // Configura a velocidade
}

void loop(){
  //BotãoLed
  inicioLed = digitalRead(botaoLed);
  Serial.println(inicioLed);

  if(inicioLed == HIGH){
    digitalWrite(led, HIGH);
    delay(5000);  
  }  else {
    digitalWrite(led, LOW);
  }
  
  //BotãoBater
  inicioBater = digitalRead(botaoBater);
  Serial.println(inicioBater);


  if(inicioBater == HIGH){
    while (contador < 3){
      lphs.step(-1024); // Chama a função com valor negativo para girar em anti horario
      delay(500); //Para um segundo
      lphs.step(1024); // Chama a função com valor negativo para girar em horario
      delay(500);
      contador++;
    }
    contador = 0;
  }


  //BotãoCentrifugar
  inicioCentrifugar = digitalRead(botaoCentrifugar);
  Serial.println(inicioCentrifugar);

 if(inicioCentrifugar == HIGH){
  while (contador < 3){
  lphs.step(2048); // Chama a função com valor negativo para fazer um giro completo
  contador++;
  }
  contador = 0;
  }
}


/*
* PROJETO MÁQUINA DE LAVAR
* - Utilizar botão/botões 
* - Ligar a máquina - LED Ativo informando que a máquina está ligada
* - Bater - 180° - Motor de Passo
* - Centrifugar - 360° - Motor de Passo
*/ 

/*GRUPO
* Enrico Araujo
* Julia Romao
* Nicole Castro
* Rodrigo Grande
*/