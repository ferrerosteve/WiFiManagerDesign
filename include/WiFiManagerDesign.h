#ifndef WIFIMANAGERDESIGN_H
#define WIFIMANAGERDESIGN_H
#include <WiFiManager.h>
#include <ESPAsyncTCP.h>
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