# Percobaan Inter Integrated Circuit
### 1. Jelaskan bagaimana cara kerja komunikasi I2C antara Arduino dan LCD pada rangkaian tersebut! 
#### jawab :
Arduino bertindak sebagai master, sedangkan LCD sebagai slave. Komunikasi dilakukan melalui 2 pin:
-  SDA (data)
- SCL (clock)

Arduino mengirim data ke alamat I2C LCD (misalnya 0x27), lalu LCD menampilkan data tersebut.
### 2. Apakah pin potensiometer harus seperti itu? Jelaskan yang terjadi apabila pin kiri dan pin kanan tertukar! 
#### jawab : 
Konfigurasi:

- Kiri → GND
- Tengah → A0 (input analog)
- Kanan → 5V

Jika kiri dan kanan tertukar:
Nilai tetap terbaca, tapi arah pembacaan terbalik
(diputar kanan malah mengecil, kiri malah membesar)
### 3. Modifikasi program dengan menggabungkan antara UART dan I2C (keduanya sebagai
output) sehingga: 
- Data tidak hanya ditampilkan di LCD tetapi juga di Serial Monitor
- Adapun data yang ditampilkan pada Serial Monitor sesuai dengan table berikut:
  
| ADC | Volt (V) | Persen (%) |
|-----|----------|------------|

Tampilan jika potensiometer dalam kondisi diputar paling kiri 
- ADC: 0  0% | setCursor(0, 0) dan Bar (level) | setCursor(0, 1)
- Berikan penjelasan disetiap baris kode nya
#### jawab : 
```
#include <Wire.h>              // Library komunikasi I2C
#include <LiquidCrystal_I2C.h> // Library LCD I2C

LiquidCrystal_I2C lcd(0x27, 16, 2); // Inisialisasi LCD (alamat 0x27, 16 kolom, 2 baris)

int potPin = A0;   // Pin potensiometer
int nilaiADC = 0;  // Variabel untuk menyimpan nilai ADC

void setup() {
  lcd.init();          // Inisialisasi LCD
  lcd.backlight();     // Menyalakan backlight LCD
  Serial.begin(9600);  // Memulai komunikasi serial
}

void loop() {
  nilaiADC = analogRead(potPin); // Membaca nilai analog (0–1023)

  // Konversi ke tegangan
  float volt = nilaiADC * (5.0 / 1023.0);

  // Konversi ke persen
  int persen = (nilaiADC * 100) / 1023;

  // ================= LCD =================
  lcd.setCursor(0, 0);                 
  lcd.print("Nilai ADC: ");           
  lcd.print(nilaiADC);                

  lcd.setCursor(0, 1);                

  int bar = map(nilaiADC, 0, 1023, 0, 16); // Mapping ke panjang bar (0–16)

  for (int i = 0; i < bar; i++) {
    lcd.print("|"); // Menampilkan bar
  }

  for (int i = bar; i < 16; i++) {
    lcd.print(" "); // Menghapus sisa karakter
  }

  // ================= SERIAL MONITOR =================
  Serial.print("ADC: ");
  Serial.print(nilaiADC);

  Serial.print(" Volt: ");
  Serial.print(volt, 2); // 2 angka di belakang koma
  Serial.print(" V");

  Serial.print(" Persen: ");
  Serial.print(persen);
  Serial.println("%");

  delay(500); // Delay agar tidak terlalu cepat update
}
```
Alur Program
- Arduino membaca potensiometer
- Data dikonversi ke volt & persen
- Data ditampilkan ke: LCD (I2C), Serial Monitor (UART)
- Ditampilkan juga dalam bentuk bar (level)

link : https://wokwi.com/projects/461255884655783937

### 4. Lengkapi table berikut berdasarkan pengamatan pada Serial Monitor 
| ADC | Volt (V) | Persen (%) |
|-----|------|------------|
| 1   |      |          |
| 21  |      |          |
| 49  |      |          |
| 74  |      |          |
| 96  |      |          |
#### jawab : 
| ADC | Volt (V) | Persen (%) |
|-----|----------|------------|
| 1   | 0.00     | 0%         |
| 21  | 0.10     | 2%         |
| 49  | 0.24     | 5%         |
| 74  | 0.36     | 7%         |
| 96  | 0.47     | 9%         |
