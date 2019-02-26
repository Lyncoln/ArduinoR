/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com  
*********/

// Load Wi-Fi library
#include <ESP8266WiFi.h>
#include <DHTesp.h>


DHTesp dht;
#define PINO 5
#define LED 2


// Replace with your network credentials
const char* ssid     = "lyncoln";
const char* password = "1012141618";

// Set web server port number to 80
WiFiServer server(80);

void setup() {

  
  dht.setup(PINO, DHTesp::DHT11);
  pinMode(LED,OUTPUT);
  
  Serial.begin(115200);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}
int cont = 0;
void loop(){
    int temperatura = dht.getTemperature();
    int humidade = dht.getHumidity();  
    WiFiClient client = server.available();   // Listen for incoming clients
    client.println("<!DOCTYPE html>\n<html>\n<head>\n<style>\nh1.centro{\ntext-align:center;\n\n}\np.quadrado {\n  border: 1px solid powderblue;\n  padding: 30px;\n background-color: white; \n}\n</style>\n</head>\n<body bgcolor = \"   #4169e1\">\n\n<font face=\"Arial\"><h1 class =\"centro\">\nProjeto SMART EAGLE\n</h1></font>\n\n<p>\n<b><font size=\"5\" face=\"Times\">\nSensores trabalhando: \n</font>\n</b></p>\n\n<p class = quadrado id = \"temperatura\">\nTemperatura: ");
    client.println(temperatura);
    client.println("\n</p>\n<p class = quadrado id = \"humidade\">\nHumidade: ");
    client.println(humidade); 
    client.println("\n</p>\n\n</body>\n</html>\n\n\n"); 
    
    
    delay(2000);  
}
  
  
