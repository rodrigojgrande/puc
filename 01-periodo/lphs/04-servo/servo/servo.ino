#include <Servo.h>

int a=666;
int b=999;
int pos = 0; //Posição
int pot = A2; //Porta análogica
int p; //Variavel temporária

Servo servo; // Chamada biblioteca

void setup() {
  servo.attach(9); //Integrado ao pino 9 (PWM)
  pinMode(pot, INPUT); // Anexando a porta analógica
  Serial.begin(9600); // Iniciar o monitoramento
}

void loop() {
  p = analogRead(pot);
  Serial.println(p);
  Serial.println(pot);

// VELOCIDADE BAIXA CASO A POSIÇÃO FOR MENOR QUE 500
// CONTROLE NO POTENCIOMETRO
    if (p < 500){
    Serial.println(a);

     for(pos = 0; pos <=180; pos += 5) {
      servo.write(pos);
      delay(200);
      }

      for (pos = 180; pos >= 0; pos -= 5) {
      servo.write(pos);
      delay(200);
      } 
    }
  
  // VELOCIDADE RÁPIDA CASO A POSIÇÃO FOR MAIOR OU IGUAL A 500
  // CONTROLE NO POTENCIOMETRO
  else if (p >= 500) {
    Serial.println(b);

      for(pos = 0; pos <=180; pos += 50) {
      servo.write(pos);
      delay(200);
      }

      for (pos = 180; pos >= 0; pos -= 50) {
      servo.write(pos);
      delay(200);
      } 
    } 
  }