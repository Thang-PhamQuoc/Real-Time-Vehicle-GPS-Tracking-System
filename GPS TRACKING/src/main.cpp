#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include "addons/RTDBHelper.h"
#include <TinyGPS++.h>

// INFORMATION WIFI
#define WIFI_SSID "....."
#define WIFI_PASSWORD "...."
//ADD YOUR FIREBASE URL
#define DATABASE_URL "gps-tracker-106e6-default-rtdb.asia-southeast1.firebasedatabase.app"
#define RXD2 16
#define TXD2 17

TinyGPSPlus gps;
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2); 
  
  // WIFI CONNECT
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Dang ket noi WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nKet noi WiFi thanh cong!");

  // FIREBASE 
  config.database_url = DATABASE_URL;
  config.signer.test_mode = true; 
  
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void loop() {
  // READ DATA FORM GPS
  while (Serial2.available() > 0) {
    gps.encode(Serial2.read());
  }

  // SEND DATA ON FIREBASE 
  if (Firebase.ready() && (millis() - sendDataPrevMillis > 5000 || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();

    // INSPECTING THE DATA 
    if (gps.location.isValid()) {
      float lat = gps.location.lat();
      float lng = gps.location.lng();

      Firebase.RTDB.setFloat(&fbdo, "/XeTai_01/lat", lat);
      Firebase.RTDB.setFloat(&fbdo, "/XeTai_01/lng", lng);

      Serial.printf("Da gui Firebase -> Toa do: %.6f, %.6f\n", lat, lng);
    } else {
      // IF DOESN'T HAVE DATA, SEND ERROR ON TERMINAL 
      Serial.println("GPS: Dang tim ve tinh... (Chua gui du lieu)");
    }
  }
}