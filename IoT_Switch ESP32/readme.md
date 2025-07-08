# 💡 IoT Lamp Control with ESP32 & Firebase

Proyek Internet of Things (IoT) yang memungkinkan pengguna untuk **mengontrol lampu secara jarak jauh** menggunakan perangkat **ESP32** dan layanan **Firebase Realtime Database**.

## 📁 Struktur Folder
Repositori ini terdiri dari beberapa folder utama:

- `IoT_Switch ESP32/` – Folder utama yang berisi kode program untuk ESP32.
  - `main.ino` – Source code utama untuk menghubungkan ESP32 ke Firebase dan mengontrol lampu.
  - `secrets.h` *(jika digunakan)* – File konfigurasi untuk menyimpan API Key dan URL Firebase secara aman.

## ⚙️ Fitur Utama
- Kontrol ON/OFF lampu via Firebase secara real-time.
- Koneksi WiFi otomatis menggunakan **WiFiManager**.
- Firebase Realtime Database sebagai media komunikasi antara aplikasi dan perangkat ESP32.
- Feedback status lampu dari ESP32 ke Firebase.

## 🛠️ Teknologi yang Digunakan
- [ESP32](https://www.espressif.com/en/products/socs/esp32)
- [Firebase Realtime Database](https://firebase.google.com/products/realtime-database)
- [WiFiManager](https://github.com/tzapu/WiFiManager) untuk konfigurasi jaringan WiFi

## 🔌 Wiring (Skema Koneksi)
![Wiring ESP32 ke Relay dan Lampu](https://raw.githubusercontent.com/Adhe110/IoT_Switch/main/IoT_Switch%20ESP32/wiring.png)  
*(Gambar wiring dapat ditambahkan di folder repo dan link diperbarui sesuai nama filenya)*

**Contoh koneksi:**
- Pin D4 ESP32 → Relay IN
- COM relay → Fasa listrik
- NO relay → Ke lampu
- Netral → Langsung ke lampu

## 📦 Instalasi Library Arduino
Pastikan kamu sudah menginstal library berikut di Arduino IDE:
- `WiFiManager`
- `Firebase ESP Client` by Mobizt

## 🔧 Konfigurasi Firebase
1. Buat project baru di Firebase Console.
2. Aktifkan Realtime Database.
3. Ambil:
