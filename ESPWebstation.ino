#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

/*Put WiFi SSID & Password*/
const char* ssid = "LH";   // Enter SSID here
const char* password = "agarwal@18"; // Enter Password here

ESP8266WebServer server(80);
#define D4 2

bool LEDstatus = LOW;

void setup() {
  Serial.begin(115200);
  delay(100);
  pinMode(D4, OUTPUT);

  Serial.println("Connecting to ");
  Serial.println(ssid);

  //connect to your local wi-fi network
  WiFi.begin(ssid, password);

  //check NodeMCU is connected to Wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  
  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  server.on("/ledon", handle_ledon);
  server.on("/ledoff", handle_ledoff);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP Server Started");
}
void loop() {
  server.handleClient();
  
  if(LEDstatus)
  {
    digitalWrite(D4, HIGH);}
  else
  {
    digitalWrite(D4, LOW);}
}

void handle_OnConnect() {
  LEDstatus = LOW;
  Serial.println("LED: OFF");
  server.send(200, "text/html", updateWebpage(LEDstatus)); 
}

void handle_ledon() {
  LEDstatus = HIGH;
  Serial.println("LED: ON");
  server.send(200, "text/html", updateWebpage(LEDstatus)); 
}

void handle_ledoff() {
  LEDstatus = LOW;
  Serial.println("LED: OFF");
  server.send(200, "text/html", updateWebpage(LEDstatus)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String updateWebpage(uint8_t LEDstatus){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>LED Control</title>\n";

  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>ESP8266 Web Server</h1>\n";
  ptr +="<h3>Using Station(STA) Mode</h3>\n";
  
   if(LEDstatus){
    ptr +="<p>BLUE LED: ON</p><a class=\"button button-off\" href=\"/ledoff\">OFF</a>\n";
   }else{
    ptr +="<p>BLUE LED: OFF</p><a class=\"button button-on\" href=\"/ledon\">ON</a>\n";
   }

  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}

//Credits ~ BinaryUpdates
