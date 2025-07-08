# 💡 IoT Lamp Control with ESP32 & Firebase

Proyek IoT untuk mengontrol lampu menggunakan **ESP32** dan **Firebase Realtime Database**. Sistem ini memungkinkan pengguna menyalakan atau mematikan lampu secara jarak jauh melalui Aplikasi mobile.

---

## 📁 Folder Utama

📂 [`IoT_Switch ESP32`](https://github.com/Adhe110/IoT_Switch/tree/main/IoT_Switch%20ESP32) Berisi:
- `IoT_Switch_ESP32.ino` – Kode program ESP32
- `wiring.PNG` – Skema wiring ESP32 ke relay dan lampu

---

## ⚙️ Fitur

- 🔌 Koneksi WiFi otomatis menggunakan **WiFiManager**
- 🔄 Komunikasi real-time antara Firebase dan ESP32
- 💡 Kontrol status lampu (`ON`/`OFF`) dari **Aplikasi mobile**

---

## 🔧 Library yang Digunakan

Pastikan library berikut sudah diinstal melalui **Library Manager** di Arduino IDE:

| Library | Fungsi | Link |
|--------|--------|------|
| `WiFiManager` | Konfigurasi WiFi via portal lokal | [WiFiManager GitHub](https://github.com/tzapu/WiFiManager) |
| `Firebase_ESP_Client` | Komunikasi Firebase Realtime Database | [Firebase ESP Client GitHub](https://github.com/mobizt/Firebase-ESP-Client) |
| `WiFi.h` | Koneksi WiFi untuk ESP32 | (Bawaan ESP32 Core) |

---

## 🔌 Wiring (Skema Koneksi)

![Wiring ESP32 ke Relay dan Lampu](https://raw.githubusercontent.com/Adhe110/IoT_Switch/main/IoT_Switch%20ESP32/wiring.PNG)

**Contoh koneksi:**
- D4 ESP32 → IN Relay  
- COM Relay → Fasa listrik  
- NO Relay → Ke lampu  
- Netral → Langsung ke lampu

---

## 🔧 Setup Firebase

1. Masuk ke [Firebase Console](https://console.firebase.google.com/)
2. Buat project baru → Aktifkan **Realtime Database**
3. Ambil data berikut:
   - **API Key**
   - **Database URL**
4. Masukkan ke dalam sketch:
   ```cpp
   #define API_KEY "API_KEY_KAMU"
   #define DATABASE_URL "https://nama-project.firebaseio.com/"
   auth.user.email = "email@domain.com";
   auth.user.password = "password";

## 🧪 Cara Menjalankan

Berikut langkah-langkah menjalankan proyek IoT Lamp Control ini:

1. **Buka Arduino IDE** dan sambungkan board **ESP32** ke komputer.
2. **Instal library yang dibutuhkan** melalui **Library Manager**:
   - WiFiManager
   - Firebase ESP Client
3. Pilih **Board**: `ESP32 Dev Module` atau board ESP32 lain yang sesuai.
4. Buka file `IoT_Switch_ESP32.ino`, lalu ubah bagian ini dengan data Firebase kamu:

   ```cpp
   #define API_KEY "ISI_API_KEY_KAMU"
   #define DATABASE_URL "https://url-database-kamu.firebaseio.com/"
   auth.user.email = "email@domain.com";
   auth.user.password = "password";

5. Klik **Upload** di Arduino IDE untuk mengirim kode ke ESP32.
6. Setelah ESP32 menyala, ia akan membuat jaringan WiFi sementara:
   - SSID: ESP32_LED_Setup
   - Password: 12345678
7. Sambungkan HP atau laptop ke WiFi tersebut, maka portal konfigurasi akan muncul.
8. Pilih jaringan WiFi rumah kamu dan masukkan password-nya.
9. Setelah berhasil, ESP32 akan terhubung ke WiFi dan Firebase. Serial Monitor akan menampilkan:
   
   ✅ WiFi Terhubung: NAMAWIFI
   
   ✅ Firebase Ready

11. Masuk ke aplikasi mobile untuk menyalakan atau mematikan lampu.

### 📱 Tampilan Aplikasi Mobile
<div align="center">
<img src="https://i.ibb.co/JMhCjC3/Whats-App-Image-2025-07-08-at-03-04-11-2.jpg" width="200">
</div>

## 🧠 Tips
- Pastikan relay sudah mendukung tegangan kerja ESP32 (3.3V atau 5V).
- ⚠️ **HATI-HATI!** Saat bekerja dengan listrik **220V AC**,


🛠️ **Proyek ini masih akan terus dikembangkan** — baik dari sisi fitur, antarmuka mobile, maupun integrasi sensor lainnya.
