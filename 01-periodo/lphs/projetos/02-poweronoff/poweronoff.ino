// Declara as variaveis e portas utilizadas
int led = 8;
int botao = 9;
int inicio = LOW;

// Indica a porta a ser utilizada
void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
  Serial.begin(9600); //9600 Taxa de comunicação padrão do arduino "baud"
}

void loop() {
  inicio = digitalRead(botao);
  Serial.println(inicio);

  if(inicio == HIGH){
    digitalWrite(led, HIGH);  
  }  else {
    digitalWrite(led, LOW);
  }
  delay(200); 

}
