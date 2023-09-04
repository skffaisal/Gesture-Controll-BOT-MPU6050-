
/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp-now-esp32-arduino-ide/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#include <esp_now.h>
#include <WiFi.h>

#define M1 21
#define M2 22
#define M3 25
#define M4 26

void f();
void b();
void r();
void l();

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
    
    float a;
    float b;
 
} struct_message;

// Create a struct_message called myData
struct_message myData;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("a ");
  Serial.println(myData.a);
  Serial.print("b ");
  Serial.println(myData.b);
  Serial.println();
}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);

   
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
 
void loop() {
  Serial.println(myData.a);
  Serial.println(myData.b);
  if(myData.a > 7.0 ){
    Serial.println("Right");
    r();
    delay(1000);
  }

    if(myData.a < - 7.0 ){
    Serial.println("Left");
    l();
    delay(1000);
  }

  if(myData.b < -5.0 ){
    Serial.println("Back");
    b();
    delay(1000);
  }

  if(myData.b > 5.0 ){
    Serial.println("Forward");
    f();
    delay(1000);
  }

     if((myData.b > -5 || myData.b< 5))
    {
           digitalWrite(M1, LOW);
          digitalWrite(M2, LOW);
           digitalWrite(M3, LOW);
          digitalWrite(M4, LOW);
 }
      if((myData.a > -7 || myData.a< 7))
    {
           digitalWrite(M1, LOW);
          digitalWrite(M2, LOW);
           digitalWrite(M3, LOW);
          digitalWrite(M4, LOW);
 }
   
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
