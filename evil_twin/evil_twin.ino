// GitHub: YigitRobotics

#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESPAsyncWebServer.h>
#include "esp_wifi.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const char *fakeSSID = "Ücretsiz WİFİ"; // Sahte ağ adını değiştirebilirsiniz :)
AsyncWebServer server(80);

void setup() {
    Serial.begin(115200);
    Wire.begin(21, 22);
    
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 OLED başlatılamadı"));
        for (;;);
    }
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("ESP32 Evil Twin By: YigitRobotics");
    display.display();

    WiFi.softAP(fakeSSID);
    delay(1000);

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/html", "<h1>Bu siteye ulaşılamıyor!</h1>");
    });
    server.begin();

    Serial.print("Sahte ağ başlatıldı: ");
    Serial.println(fakeSSID);
}

void loop() {
    wifi_sta_list_t stationList;
    esp_wifi_ap_get_sta_list(&stationList);
    
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Bağlanan Cihazlar:");
    
    for (int i = 0; i < stationList.num; i++) {
        wifi_sta_info_t station = stationList.sta[i];
        char macStr[18];
        sprintf(macStr, "%02X:%02X:%02X:%02X:%02X:%02X", 
            station.mac[0], station.mac[1], station.mac[2], 
            station.mac[3], station.mac[4], station.mac[5]);
        Serial.println(macStr);
        display.println(macStr);
    }
    
    display.display();
    delay(5000);
}
