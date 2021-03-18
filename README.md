# Smartify
IOT Based Home Automation Project using Google Firebase ,Android App &amp; NodeMCU ESP8266.
In this project, we will learn how to make IoT Based Home Automation Project using Google Firebase & NodeMCU ESP8266. One of the most common & popular hobby projects you will come across the internet is Home Automation Project. By Home Automation we mean controlling home appliances without a manual switch. When connected with the Internet, home devices are an important constituent of the Internet of Things (“IoT”) Application.![iot-project-google-firebase-controlling-led-using-android-app](https://user-images.githubusercontent.com/78377154/111585465-5ba91400-87e5-11eb-9361-007666f087d1.png)


Hardwere used:
1.Nodemcu(lolin esp8266 v1.0)
2.4 Relay board (5.0 volt)
3.Jumer wires
4.Power adaptors(5.0 volt)
5.Working WIFI connection

Softwere used
  1.Arduino IDE
  2.Android Studio
  3.Firebase Account


In this project we will use Google Firebase. Google Firebase is a Google-backed application development software used for creating, managing,and modifying data generated from any android/IOS application, web services, IoT sensors & Hardware. To learn more about the Google Firebase Console, you can read the official Google Firebase Documentation from Google Firebase

We will design a Home Automation Android Application using Android Studio. Using the Firebase Host & Authentication Key, we will connect the Android Application with Google Firebase. We will then send the ON/OFF command as 1/0 from App. The data from the App is sent to Google Firebase. Now the Google Firebase data is updated to NodeMCU Board via Internet Connection. Thus the digital GPIO Pins becomes high & low turning ON/OFF the appliances connected to Relay.
The circuit diagram for Google Firebase Based Home Automation using ESP8266 is given below. Using this circuit diagram you can assemble the circuit on Breadboard using 4 channel Relay and NodeMCU Board.
![Home-Automation-using-Blynk-Circuit](https://user-images.githubusercontent.com/78377154/111582641-200c4b00-87e1-11eb-993f-4b25a29afa58.jpg)

Setting up Nodemcu
    Library Used by Nodemcu
      Adding Firebase & JSON Library to Arduino IDE
        1. ArduinoJSON Library
        So first go to the library manager and search for “JSON” & install the library as shown in the figure below.
        (https://user-images.githubusercontent.com/78377154/111582959-a2950a80-87e1-11eb-8c5e-896eb3e9cd8e.png)

        2. Google FirebaseExtended Library
        Now you need to install Google Firebase library as well. So, download the library from below link and add it to Library folder after extraction.
        https://github.com/mobizt/Firebase-ESP8266

        Source Code:


              #include <FirebaseArduino.h>
              #define FIREBASE_HOST "**********"           // Your Firebase Project URL 
              #define FIREBASE_AUTH "************"         // Your Firebase Database Secret
              #define WIFI_SSID "**************"           // your WiFi SSID
              #define WIFI_PASSWORD "********"             // your WiFi PASSWORD
              int retRelay1;
              int retRelay2;
              int retRelay3;
              int retRelay4;
              FirebaseData fbdo;  

              void setup() 
              {
                pinMode(D0,OUTPUT);
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
                Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                                         
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


Setting Up firebase:
Step 1: Creating Fairbase Account
Step 2: Then Show Like This Interface and Give Project Name and Select Country Name
Step 3: Hear I Select Project Name Home Automation and Select My Country Then Press Create
Step 4: After a Moment Show This Interface Click on Contention
Step 5: Then Go to Get Started with Realtime database

<img width="1280" alt="Screenshot 2021-03-18 at 12 15 45 PM" src="https://user-images.githubusercontent.com/78377154/111584390-c8bbaa00-87e3-11eb-88fd-7c4e6d0edb7d.png">

Step 6:Go to Your Setting Then Show Your Api Key
Step 7:Copy Api token key 


Making Android App
1.Open Android Studio
2.Create new Project
3.Add firebase into Android Studio project
4.Add 4 Buttons using XML
5.Add Onclick listner to the added buttons
6.Update the firebase collection as the button clicks.
7.Export .apk file and run on your Device Thats All.

<img width="296" alt="Screenshot 2021-03-18 at 12 39 13 PM" src="https://user-images.githubusercontent.com/78377154/111586526-f81fe600-87e6-11eb-8bec-5ba8e0c6579c.png">

We have succesfully complete our Project.

