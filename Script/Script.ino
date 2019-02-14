/* Definicao de macros*/

#define PRESENCA 3
#define TEMPERATURA_UMIDADE 2
#define GAS A0
#define SOM 4
#define SOM2D 5
#define SOM2A A1
#define GAS2A A2
#define GAS2D 6

/* Biblioteca do DHT11 (Sensor de temperatura) */
#include <dht.h> 
dht DHT;

void setup() {
  
  pinMode(PRESENCA, INPUT);
  pinMode(GAS,INPUT);
  pinMode(SOM,INPUT);
  pinMode(SOM2D,INPUT);
  pinMode(SOM2A,INPUT);
  pinMode(GAS2A,INPUT);
  pinMode(GAS2D,INPUT);
  Serial.begin(9600);
  
}

void loop() {
  SensorGas2();
  delay(1000);
}

/* Funcoes Auxiliares */

void SensorDht(void){
  DHT.read11(TEMPERATURA_UMIDADE); 
  float temperatura = DHT.temperature,
        umidade = DHT.humidity;  
  Serial.print(temperatura);
  Serial.print("   ");
  Serial.println(umidade); 
}

void SensorPresenca(void){
   if(digitalRead(PRESENCA)){
    Serial.println(1);
  }
  else {
    Serial.println(0);   
  } 
}

//Sensor de gás com 3 pinos MQ 9
void SensorGas(void) {
  int leitura = analogRead(GAS);
  //float nivelGas = (leitura*100.0)/1023.0;
  Serial.println(leitura);
  
}

//Sensor de Som Azul
void SensorSom(void) {
  if(digitalRead(SOM)){
    Serial.println(1);
  }
  else{
    Serial.println(0);
  }
}

//Sensor de Som Vermelho
void SensorSom2(void) {
  Serial.println(analogRead(SOM2A));
  Serial.println(digitalRead(SOM2D));
}

//Sensor de gas com 4 pinos MQ 135
void SensorGas2(void) {
  Serial.println(analogRead(GAS2A));
  Serial.println(digitalRead(GAS2D));
}
