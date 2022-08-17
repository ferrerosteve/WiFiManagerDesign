#include <WiFiManagerDesign.h> // https://github.com/ferrerosteve/WiFiManagerDesign
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager


void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    
    //WiFiManager, Local intialization. Once its business is done, there is no need to keep it around
    WiFiManager wifiManager;
    WiFiManagerDesign wiFiManagerDesign(&wifiManager);

    if(!wifiManager.autoConnect("AutoConnectAP","password")) {
        Serial.println("Failed to connect");
    } 
    else {
        //if you get here you have connected to the WiFi    
        Serial.println("Connected)");
    }
}

void loop() {
    // put your main code here, to run repeatedly:   
}