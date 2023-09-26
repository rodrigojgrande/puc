//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino
 
//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pinTrigger 2 // Dispara o sinal (PX)
#define pinEcho 3 // Recebe o sinal (RX)
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pinTrigger, pinEcho);
 
void setup()
{
  Serial.begin(9600);
  Serial.println("Recebendo dados do sensor...");
}
 
void loop()
{
  //Le as informacoes do senso em cm 
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
 
  //Exibe informacoes no serial monitor
  Serial.println("Distancia em cm: ");
  Serial.println(cmMsec);
  Serial.println(" ");
  delay(1000);
}