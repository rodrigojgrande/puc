// Declara as variaveis e portas utilizadas
int verde = 8;
int amarelo = 9;
int vermelho = 10;

// Indica a porta a ser utilizada
void setup() {
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);
}

void loop() {
  // Liga o amarelo
  digitalWrite(vermelho, LOW);
  digitalWrite(amarelo, HIGH);
  digitalWrite(verde, LOW);

  // 2 Segundos aceso
  delay(2000); 

  // Desliga o amarelo e acende o vermelho
  digitalWrite(amarelo, LOW);
  digitalWrite(vermelho, HIGH);
  
  // 5 Segundos aceso
  delay(5000);

  // Apaga o vermelho e acende o verde
  digitalWrite(vermelho, LOW);
  digitalWrite(verde, HIGH);

  // 5 Segundos aceso
  delay(5000);
}
