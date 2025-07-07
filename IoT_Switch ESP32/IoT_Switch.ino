#include <WiFi.h>
#include <WiFiManager.h>  // https://github.com/tzapu/WiFiManager
#include <Firebase_ESP_Client.h>


// Firebase Setup
#define API_KEY "ISI_API_KEY_KAMU" //API KEY FIREBASE
#define DATABASE_URL "https://url-database-kamu.firebaseio.com/" //URL FIREBASE

#define LED_PIN 4  // GPIO4

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

String lastStatus = "";  // Simpan status LED terakhir

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // WiFiManager Setup
  WiFiManager wm;
  bool res;

  res = wm.autoConnect("ESP32_LED_Setup", "12345678");  // SSID & password AP

  if (!res) {
    Serial.println("❌ Gagal konek WiFi");
    ESP.restart(); // restart jika gagal
  } else {
    Serial.println("✅ WiFi Terhubung: " + WiFi.SSID());
  }

  // Firebase Setup
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;

  auth.user.email = "email@domain.com"; //USER_EMAIL
  auth.user.password = "password"; // USER_PASSWORD

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  while (!Firebase.ready()) {
    delay(100);
  }
  Serial.println("✅ Firebase Ready");
}

void loop() {
  // Baca status dari Firebase
  if (Firebase.RTDB.getString(&fbdo, "/led_status")) {
    String status = fbdo.stringData();
    if (status != lastStatus) {
      Serial.println("Status LED dari Firebase: " + status);

      if (status.equalsIgnoreCase("ON") || status == "1" || status.equalsIgnoreCase("true")) {
        digitalWrite(LED_PIN, HIGH);
        Serial.println("LED MENYALA");
      } else {
        digitalWrite(LED_PIN, LOW);
        Serial.println("LED MATI");
      }
      lastStatus = status;
    }
  } else {
    Serial.println("❌ Gagal baca data: " + fbdo.errorReason());
  }

  delay(2000);
}