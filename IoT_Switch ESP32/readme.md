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
  <table>  
    <tr>  
      <td><img src="https://i.ibb.co/27rvCcd2/f931cb61-2b98-4842-8f37-2a63f1c49de9.jpg" width="200"></td>  
      <td><img src="https://i.ibb.co/JWVHJsMF/98f2087c-b754-42a1-9ae4-fb0b33a0ab3c.jpg" width="200"></td>  
      <td><img src="https://i.ibb.co/Cs6qD9Nm/e566e007-1c0a-4cf9-b7c1-9184d35a2ac6.jpg" width="200"></td> 
      <td><img src="https://i.ibb.co/9k0JybVw/01dc0cda-66cc-4134-95e5-76e123206e3b.jpg" width="200"></td>  
    </tr>  
  </table>  
</div>  



## 🧠 Tips
- Gunakan resistor pada pin kontrol relay.
- Pastikan relay sudah mendukung tegangan kerja ESP32 (3.3V atau 5V).

## 👨‍💻 Author

- GitHub: [@Adhe110](https://github.com/Adhe110)

---



Lisensi bebas digunakan untuk pembelajaran & pengembangan proyek pribadi.
## 📦 Instalasi Library Arduino
Pastikan kamu sudah menginstal library berikut di Arduino IDE:
- `WiFiManager`
- `Firebase ESP Client` by Mobizt

## 🔧 Konfigurasi Firebase
1. Buat project baru di Firebase Console.
2. Aktifkan Realtime Database.
3. Ambil:
