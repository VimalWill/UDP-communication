//import libraries for esp and udp 
#include<ESP8266WiFi.h>
#include<WiFiUdp.h>

WiFiUDP udp;

//declare dependiences 
unsigned int port = 5555;

const char* ssid = "Vimal";
const char* pass = "Vimal@2001";

char packet[10];
char reply[] = "hello";

//wifi connection start up 
void wifi(){
  Serial.println("connecting to WiFi....");
  WiFi.begin(ssid,pass);
  while(WiFi.status()!= WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print("connected to: ");
  Serial.print(WiFi.localIP());
  Serial.println();
  
}
void setup(){
  Serial.begin(115200);
  wifi();
  udp.begin(port);
}
void loop(){
  int rp = udp.parsePacket();
  if(rp){
    udp.read(packet,5);
    Serial.println(packet);
  }
  else{
    Serial.println("wait");
    delay(1000);
  }
  udp.beginPacket(udp.remoteIP(),udp.remotePort());
  Serial.println(udp.remoteIP());
  Serial.println(udp.remotePort());
  udp.write(reply);
  udp.endPacket();
}
