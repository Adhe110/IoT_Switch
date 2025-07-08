# 💡 IoT Lamp Control with ESP32 & Firebase

Proyek IoT untuk mengontrol lampu menggunakan **ESP32** dan **Firebase Realtime Database**. Sistem ini memungkinkan pengguna menyalakan atau mematikan lampu secara jarak jauh melalui internet.

## 📂 Struktur Folder

📁 [`IoT_Switch ESP32`](https://github.com/Adhe110/IoT_Switch/tree/main/IoT_Switch%20ESP32)  
Berisi kode utama ESP32:
- `IoT_Switch_ESP32.ino` – Program utama untuk ESP32.
- `Wiring.png` – Library Firebase (dimasukkan di Arduino IDE melalui Library 

## ⚙️ Fitur Utama
- Kendali lampu dari Firebase secara **real-time**.
- Terhubung otomatis ke WiFi menggunakan **WiFiManager**.
- Sinkronisasi status lampu dari dan ke Firebase.
- Cocok untuk proyek **IoT Smart Home** skala kecil.


## 🔧 Setup Firebase

1. Masuk ke [Firebase Console](https://console.firebase.google.com/).
2. Buat project baru → Aktifkan Realtime Database.
3. Dapatkan:
   - **API Key**
   - **Database URL**
4. Masukkan ke dalam sketch:
   ```cpp
   #define API_KEY "API_KEY_KAMU"
   #define DATABASE_URL "https://nama-project.firebaseio.com/"
