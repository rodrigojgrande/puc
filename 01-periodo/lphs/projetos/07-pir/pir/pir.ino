int pinoSensor = 2; // Pino Sensor de Presença
int pinoLed = 4; //Pino Led

int ativo = 1;
int inativo = 0;
 
void setup(){
  Serial.begin(9600);
  pinMode(pinoLed, OUTPUT); // Define o pino como saída
  pinMode(pinoSensor, INPUT); //Define o pino como entrada
}
void loop(){
 if(digitalRead(pinoSensor) == HIGH){ //Se a leitura for igual a HIGH
    digitalWrite(pinoLed, HIGH); //Acende o Led
    Serial.println(ativo);
 }else{ //Se não
  digitalWrite(pinoLed, LOW); //Apaga o LED
  Serial.println(inativo);
 }
}