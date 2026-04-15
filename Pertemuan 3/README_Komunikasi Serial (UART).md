# Percobaan Komunikasi Serial
### 1. Jelaskan proses dari input keyboard hingga LED menyala/mati!
#### jawab :
Saat user mengetik perintah di Serial Monitor, data dikirim dari komputer ke Arduino melalui komunikasi UART. Arduino membaca data tersebut menggunakan Serial.read(), lalu memprosesnya dengan percabangan (if). Jika perintah sesuai (misalnya ‘1’ atau ‘0’), Arduino akan mengatur pin digital HIGH atau LOW sehingga LED menyala atau mati.
### 2. Mengapa digunakan Serial.available() sebelum membaca data? Apa yang terjadi jika
baris tersebut dihilangkan? 
#### jawab :
`Serial.available()` digunakan untuk mengecek apakah ada data yang masuk ke buffer serial.

Jika tidak digunakan:
- Arduino bisa membaca data kosong
- Program bisa error atau membaca nilai tidak valid
- LED bisa tidak merespon dengan benar
### 3. Modifikasi program agar LED berkedip (blink) ketika menerima input '2' dengan kondisi
jika ‘2’ aktif maka LED akan terus berkedip sampai perintah selanjutnya diberikan dan
berikan penjelasan disetiap baris kode nya
#### jawab :
```
int ledPin = 8;        // Menentukan pin LED
char data;             // Variabel untuk menyimpan input serial
bool blinking = false; // Status apakah LED dalam mode berkedip

unsigned long previousMillis = 0; // Menyimpan waktu sebelumnya
const long interval = 500;        // Interval kedip (500 ms)

void setup() {
  pinMode(ledPin, OUTPUT); // Set pin LED sebagai output
  Serial.begin(9600);      // Memulai komunikasi serial
}

void loop() {

  // Mengecek apakah ada data masuk dari Serial Monitor
  if (Serial.available() > 0) {
    data = Serial.read(); // Membaca data

    if (data == '1') {
      digitalWrite(ledPin, HIGH); // LED nyala
      blinking = false;           // Matikan mode blink
    }
    else if (data == '0') {
      digitalWrite(ledPin, LOW);  // LED mati
      blinking = false;           // Matikan mode blink
    }
    else if (data == '2') {
      blinking = true;            // Aktifkan mode blink
    }
  }

  // Jika mode blinking aktif
  if (blinking) {
    unsigned long currentMillis = millis(); // Ambil waktu sekarang

    // Cek apakah sudah mencapai interval
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      // Toggle LED (nyala ↔ mati)
      digitalWrite(ledPin, !digitalRead(ledPin));
    }
  }
}
```
Program membaca input dari Serial Monitor
Jika:
- '1' → LED menyala
- '0' → LED mati
- '2' → LED berkedip terus
- Mode blink akan berjalan terus sampai ada input baru
- Menggunakan millis() supaya tidak menghambat pembacaan input
  
link : https://www.tinkercad.com/things/i3mWE1mzms7/editel

### 4. Tentukan apakah menggunakan delay() atau milis()! Jelaskan pengaruhnya terhadap sistem
#### jawab : 
- delay() → menghentikan seluruh program sementara (blocking), sehingga tidak bisa membaca input baru selama delay berjalan
- millis() → non-blocking, memungkinkan Arduino tetap membaca input sambil menjalankan proses lain

Kesimpulan:
Lebih baik menggunakan millis() karena sistem jadi responsif dan tidak “freeze”.
