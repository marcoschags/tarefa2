#include <pico/stdlib.h>
#include <stdio.h>
#include <hardware/timer.h>
#include <hardware/pwm.h>

// Configuração dos pinos GPIO
#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUZZER 14

void setup() {
  // Configurar GPIOs como saída
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Inicializar a comunicação serial para depuração
  Serial.begin(115200);
  while (!Serial) {
    ; // Aguarde a inicialização do monitor serial
  }
  Serial.println("Raspberry Pi Pico W: Sistema inicializado.");
}

void loop() {
  // Etapa 1: Ligar LED verde e desligar os outros
  Serial.println("Ligando LED verde...");
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_RED, LOW);
  delay(1000);

  // Etapa 2: Ligar LED azul e desligar os outros
  Serial.println("Ligando LED azul...");
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, HIGH);
  digitalWrite(LED_RED, LOW);
  delay(1000);

  // Etapa 3: Ligar LED vermelho e desligar os outros
  Serial.println("Ligando LED vermelho...");
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_RED, HIGH);
  delay(1000);

  // Etapa 4: Ligar todos os LEDs
  Serial.println("Ligando todos os LEDs (luz branca)...");
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_BLUE, HIGH);
  digitalWrite(LED_RED, HIGH);
  delay(1000);

  // Etapa 5: Desligar todos os LEDs
  Serial.println("Desligando todos os LEDs...");
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_RED, LOW);
  delay(1000);

  // Etapa 6: Acionar o buzzer por 2 segundos
  Serial.println("Acionando buzzer por 2 segundos...");
  digitalWrite(BUZZER, HIGH);
  delay(2000);
  digitalWrite(BUZZER, LOW);

  Serial.println("Ciclo completo.\n");
}
