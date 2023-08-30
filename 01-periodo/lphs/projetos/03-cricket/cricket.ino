// Declaracao de Variaveis
int b = 3; //Ativa o Buzzer
int pot = A3; // Porta Analogica
int p; // Variavel temporaria para decisão (Flag)

// Frequencias das notas musicais
int doh = 262; 
int mi = 330;
int sol = 392;
int si = 492;
int tempo = 200;

void setup() {
  Serial.begin(9600);
  pinMode(b, OUTPUT);
  pinMode(pot, INPUT);
}

void loop() {
  p = analogRead(pot);
  Serial.println(p);

  if (p < 250){
    tone(b, doh, tempo);
  } 
  
  else if (p > 250 && p < 500) {
    tone(b, mi, tempo);
  } 
  
  else if (p > 500 && p < 750) {
    tone(b, sol, tempo);
  } 
  
  else if (p > 750) {
    tone(b, si, tempo);
  } 

  delay(500);
}
