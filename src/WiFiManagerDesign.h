#ifndef WIFIMANAGERDESIGN_H
#define WIFIMANAGERDESIGN_H
#include <WiFiManager.h>
#if defined(ESP8266)
  #include <ESPAsyncTCP.h>
#elif defined(ESP32)
  #include <AsyncTCP.h>
#endif
#define WEBSERVER_H
#include <ESPAsyncWebServer.h>
#include "LittleFS.h"

class WiFiManagerDesign
{
    public:
        WiFiManagerDesign(WiFiManager *wifiManager);
    private:
        WiFiManager *_wifiManager;
        AsyncWebServer *_fileServer;
};
#endif