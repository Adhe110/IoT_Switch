
# 💡 IoT Lamp Control with ESP32 & Firebase

Proyek IoT untuk mengontrol lampu menggunakan **ESP32** dan **Firebase Realtime Database**. Lampu dapat dikendalikan dari jarak jauh melalui internet, dengan komunikasi dua arah antara perangkat dan Firebase.

## 📁 Folder Utama

📂 [`IoT_Switch ESP32`](https://github.com/Adhe110/IoT_Switch/tree/main/IoT_Switch%20ESP32)  
Berisi file kode:
- `IoT_Switch_ESP32.ino` – Kode lengkap ESP32
- Menggunakan `WiFiManager` dan `Firebase_ESP_Client`

## ⚙️ Fitur

- 🔌 Koneksi WiFi otomatis menggunakan **WiFiManager**
- 🔄 Koneksi real-time dengan Firebase
- 💡 Kontrol status lampu dari Aplikasi Mobile (`ON`/`OFF`)

## 🔧 Library yang Digunakan

Pastikan semua library ini sudah terinstall di Arduino IDE:

| Library | Fungsi | Link |
|--------|--------|------|
| `WiFiManager` | Konfigurasi jaringan via browser | [WiFiManager GitHub](https://github.com/tzapu/WiFiManager) |
| `Firebase_ESP_Client` | Komunikasi dengan Firebase RTDB | [Firebase Client GitHub](https://github.com/mobizt/Firebase-ESP-Client) |
| `WiFi.h` | Library bawaan ESP32 | - |

> Install melalui **Library Manager** di Arduino IDE agar lebih mudah.

## 🔌 Wiring (Skema Koneksi)
![Wiring ESP32 ke Relay dan Lampu](https://raw.githubusercontent.com/Adhe110/IoT_Switch/main/IoT_Switch%20ESP32/wiring.png)  
*(Gambar wiring dapat ditambahkan di folder repo dan link diperbarui sesuai nama filenya)*

**Contoh koneksi:**
- Pin D4 ESP32 → Relay IN
- COM relay → Fasa listrik
- NO relay → Ke lampu
- Netral → Langsung ke lampu

```

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
   auth.user.email = "email@domain.com";
   auth.user.password = "password";
```


## 🧪 Cara Menjalankan

Berikut langkah-langkah menjalankan proyek IoT Lamp Control ini:

1. **Buka Arduino IDE** dan sambungkan board **ESP32** ke komputer.
2. **Instal library yang dibutuhkan** melalui **Library Manager**:
   - WiFiManager
   - Firebase ESP Client
3. Pilih **Board**: `ESP32 Dev Module` atau board ESP32 yang sesuai.
4. Buka file `IoT_Switch_ESP32.ino`, lalu ubah bagian ini dengan data Firebase kamu:
   ```cpp
   #define API_KEY "ISI_API_KEY_KAMU"
   #define DATABASE_URL "https://url-database-kamu.firebaseio.com/"
   auth.user.email = "email@domain.com";
   auth.user.password = "password";
   ```
5. Klik **Upload** di Arduino IDE untuk mengirim kode ke ESP32.
6. Setelah ESP32 menyala, ia akan membuat jaringan WiFi sementara:
   - SSID: `ESP32_LED_Setup`
   - Password: `12345678`
7. Sambungkan HP atau laptop ke WiFi tersebut, maka portal konfigurasi akan muncul.
8. Pilih jaringan WiFi rumah kamu dan masukkan password-nya.
9. Setelah berhasil, ESP32 akan terhubung ke WiFi dan Firebase. Serial Monitor akan menampilkan:
   ```
   ✅ WiFi Terhubung: NAMAWIFI
   ✅ Firebase Ready
   ```
10. Masuk ke aplikasi mobile untuk menyalakan atau mematikan lampu.

### 📱 Tampilan Aplikasi Mobile
<div align="center">
<img src="https://i.ibb.co/JMhCjC3/Whats-App-Image-2025-07-08-at-03-04-11-2.jpg" width="200">
</div>


## 🧠 Tips
- Gunakan resistor pada pin kontrol relay.
- Pastikan relay sudah mendukung tegangan kerja ESP32 (3.3V atau 5V).

## 👨‍💻 Author

- GitHub: [@Adhe110](https://github.com/Adhe110)

---



Lisensi bebas digunakan untuk pembelajaran & pengembangan proyek pribadi.
