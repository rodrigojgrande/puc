// Biblioteca do LCD 16x2
#include <LiquidCrystal.h>

// Inicializa a biblioteca com os pinos da interface
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Configura as linhas e colunas do LCD
  lcd.begin(16, 2);
  // Escreve na tela do LCD
  lcd.setCursor(0,0);
  lcd.print("Hello World by:");
  lcd.setCursor(0,1);
  lcd.print("Julia, Nicole e Rodrigo");
}

void loop() {
  // Faz a rolagem do LCD 
  lcd.autoscroll();
  delay(300);

  // Cria um espaçamento e criar um loop no scroll do LCD
  lcd.setCursor(35, 1);
  // Espaços em branco para que o LCD faça o scroll
  lcd.print(" ");
}
 