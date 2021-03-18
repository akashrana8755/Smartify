#include <ESP8266WiFi.h>                                           
#include<FirebaseESP8266.h>        
                                

#define FIREBASE_HOST "https://smart-home-71211-default-rtdb.firebaseio.com/"              // the project name address from firebase id
#define FIREBASE_AUTH "9MAbSxcdmPfeKDsKJ3fLeEpYhMFxTa4I8H1e74uQ"       // the secret key generated from firebase
#define WIFI_SSID "Joker Range"                                          
#define WIFI_PASSWORD "Akash@1999"                                  

int retRelay1;
int retRelay2;
int retRelay3;
int retRelay4;

  
FirebaseData fbdo;                                                             
void setup() 
{ pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  Serial.begin(9600);
  delay(1000);                  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                               
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                  // connect to firebase
                         
}
 
void loop() 
{
  if (Firebase.getInt(fbdo, "Relay1")) {

    if (fbdo.dataType() == "int") {
      Serial.println(fbdo.intData());
      retRelay1=fbdo.intData();
      if(retRelay1==1)
      {
      digitalWrite(D0,LOW);
      }
      else
      {
      digitalWrite(D0,HIGH);
      }
    }

  } else {
    Serial.println(fbdo.errorReason());
  }


  if (Firebase.getInt(fbdo, "Relay2")) {

    if (fbdo.dataType() == "int") {
      Serial.println(fbdo.intData());
      retRelay2=fbdo.intData();
      if(retRelay2==1)
      {
      digitalWrite(D1,LOW);
      }
      else
      {
      digitalWrite(D1,HIGH);
      }
    }

  } else {
    Serial.println(fbdo.errorReason());
  }

if (Firebase.getInt(fbdo, "Relay3")) {

    if (fbdo.dataType() == "int") {
      Serial.println(fbdo.intData());
      retRelay3=fbdo.intData();
      if(retRelay3==1)
      {
      digitalWrite(D2,LOW);
      }
      else
      {
      digitalWrite(D2,HIGH);
      }
    }

  } else {
    Serial.println(fbdo.errorReason());
  }


if (Firebase.getInt(fbdo, "Relay4")) {

    if (fbdo.dataType() == "int") {
      Serial.println(fbdo.intData());
      retRelay4=fbdo.intData();
      if(retRelay4==1)
      {
      digitalWrite(D3,LOW);
      }
      else
      {
      digitalWrite(D3,HIGH);
      }
    }

  } else {
    Serial.println(fbdo.errorReason());
  }

}
