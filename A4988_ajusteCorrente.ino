// Controle de Motor de Passo com Modulo driver A4988
// Sketch para ajuste de corrente do Modulo A4988 - ajuste POT
// Modulo A4988 / Motor de Passo Bipolar / Arduino Nano / IDE 1.8.5
//
// Gustavo Murta 29/mar/2018

// Definições das Portas Digitais do Arduino

int RST = 8;              // Porta digital D08 - reset do A4988
int SLP = 9;              // Porta digital D09 - dormir (sleep) A4988
int ENA = 7;              // Porta digital D07 - ativa (enable) A4988
int MS1 = 4;              // Porta digital D04 - MS1 do A4988
int MS2 = 5;              // Porta digital D05 - MS2 do A4988
int MS3 = 6;              // Porta digital D06 - MS3 do A4988
int DIR = 3;              // Porta digital D03 - direção (direction) do A4988
int STP = 2;              // Porta digital D02 - passo(step) do A4988

int MeioPeriodo = 1480;    // MeioPeriodo no pulso em microsegundos  500 Hz = 988
float PPS = 200;          // Pulsos por segundo
boolean sentido = true;   // Variavel de sentido
int PPR = 200;            // Número de passos por volta
int Pulsos;               // Pulsos para o driver do motor
int Voltas;               // voltas do motor
float RPM;                // Rotacoes por minuto


void setup()
{
  Serial.begin(9600);

  DDRD = DDRD | B11111100;  // Configura Portas D02 até D07 como saída
  disa_A4988();             // Desativa o chip A4988 
 
  DDRB = 0x0F;              // Configura Portas D08,D09,D10 e D11 como saída
  digitalWrite(SLP, HIGH);  // Desativa sleep do A4988
  rst_A4988();              // Reseta o chip A4988
  ena_A4988();              // Ativa o chip A4988

  ajuste_A4988();           // Ajuste de corrente A4988
}

void rst_A4988()
{
  digitalWrite(RST, LOW);     // Realiza o reset do A4988
  delay (10);                 // Atraso de 10 milisegundos
  digitalWrite(RST, HIGH);    // Libera o reset do A4988
  delay (10);                 // Atraso de 10 milisegundos
}

void disa_A4988()
{
  digitalWrite(ENA, HIGH);    // Desativa o chip A4988
  delay (10);                 // Atraso de 10 milisegundos
}

void ena_A4988()
{
  digitalWrite(ENA, LOW);     // Ativa o chip A4988
  delay (10);                 // Atraso de 10 milisegundos
}

void ajuste_A4988()
{
  FULL();                     // Selecione o Modo do Passo
  Serial.println(" Ajuste a corrente no POT do A4988 ");
}

void FULL()
{
  digitalWrite(MS1, LOW);    // Configura modo Passo completo (Full step)
  digitalWrite(MS2, LOW);
  digitalWrite(MS3, LOW);
  Serial.println(" FULL - Passo Completo ");
}

void loop()
{
}
