#include <WiFi.h>

const char* ssid = "*Your SSID*";         /*Enter Your SSID*/
const char* password = "*Your Password*"; /*Enter Your Password*/

WiFiServer server(80); /* Instance of WiFiServer with port number 80 */
String request;
#define M1 21
#define M2 22
#define M3 25
#define M4 26


void f();
void b();
void r();
void l();
 

int Motor_Status; 

WiFiClient client;

void setup() 
{
  Serial.begin(115200);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  //pinMode(EN, OUTPUT);
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, LOW);
  //digitalWrite(EN, HIGH);
}




void loop()
{
  //f();
//b();
//r();
l();          
     
}

void f()
{
          digitalWrite(M1, HIGH);
          digitalWrite(M2, LOW);
          digitalWrite(M3, LOW);
          digitalWrite(M4, HIGH);
}
void b()
{
          digitalWrite(M1, LOW);
          digitalWrite(M2, HIGH);
          digitalWrite(M3, HIGH);
          digitalWrite(M4, LOW);
}
void r()
{
          digitalWrite(M1, LOW);
          digitalWrite(M2, HIGH);
          digitalWrite(M3, LOW);
          digitalWrite(M4, HIGH);
}
void l()
{
          digitalWrite(M1, HIGH);
          digitalWrite(M2, LOW);
          digitalWrite(M3, HIGH);
          digitalWrite(M4, LOW);
}
