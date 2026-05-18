# Percobaan 6A : External Interrupt

### 1. Jelaskan proses bagaimana tombol dapat mengubah kondisi LED menggunakan interrupt!
#### jawab :
Saat tombol ditekan, pin interrupt pada Arduino mendeteksi perubahan sinyal. Karena program menggunakan mode FALLING, interrupt akan aktif ketika tegangan berubah dari HIGH ke LOW. Setelah interrupt terdeteksi, Arduino menghentikan sementara program utama dan menjalankan fungsi ISR (tombolInterrupt()). Di dalam ISR, variabel ledState dibalik nilainya menggunakan:
```
ledState = !ledState;
```
Jika sebelumnya LED mati (false), maka akan berubah menjadi hidup (true), begitu juga sebaliknya. Setelah ISR selesai dijalankan, program kembali ke loop utama dan menampilkan kondisi LED sesuai nilai ledState.

### 2. Apa fungsi attachInterrupt() pada program tersebut?
#### jawab :
```Fungsi attachInterrupt()``` digunakan untuk menghubungkan pin interrupt dengan fungsi ISR.
Format:
```attachInterrupt(digitalPinToInterrupt(pin), ISR, mode);```
Pada program:
```attachInterrupt(
 digitalPinToInterrupt(2),
 tombolInterrupt,
 FALLING
);
```
Artinya:
- Pin 2 digunakan sebagai pin interrupt
- Fungsi tombolInterrupt() dijalankan saat interrupt terjadi
- Interrupt dipicu ketika terjadi perubahan HIGH ke LOW (FALLING)

### 3. Mengapa pada ISR tidak disarankan menggunnakan delay() dan Serial.print()?
#### jawab :
Karena saat ISR berjalan, program utama akan berhenti sementara. Jika di dalam ISR terdapat proses berat seperti `delay()`,`Serial.print()` maka sistem bisa menjadi lambat, tidak responsif, bahkan menyebabkan error. ISR sebaiknya dibuat sesingkat mungkin agar interrupt dapat diproses dengan cepat.

### 4. Apa fungsi keyword volatile pada variabel ledState?
#### jawab :
Keyword volatile digunakan agar compiler selalu membaca nilai variabel terbaru dari memori.
Contoh:
```volatile bool ledState = false;```
Karena variabel ledState dapat berubah di dalam ISR dan juga digunakan pada program utama (loop()), maka diperlukan volatile supaya perubahan nilainya selalu terdeteksi dengan benar.

### 5. Pada percobaan digunakan mode interrups FALLING. Modifikasikan program menggunakan mode interrupt lain (RISING, CHANGE, atau LOW) kemudian:
- Jelaskan perbedaan cara kerja masing-masing modeinterrupt tersebut
- Analisis perubahan perilaku LED yang terjadi pada setiap mode
- Sertakan soyrce code dan penjelasan program
#### jawab :
- RISING
  
Source Code :
```
#include <Arduino.h>

volatile bool ledState = false;

void tombolInterrupt() {
  ledState = !ledState;
}

void setup() {
  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP);

  attachInterrupt(
    digitalPinToInterrupt(2),
    tombolInterrupt,
    RISING
  );
}

void loop() {
  digitalWrite(13, ledState);
}
```
Penjelasan :
Mode RISING aktif ketika sinyal berubah dari LOW ke HIGH. Karena tombol menggunakan INPUT_PULLUP, kondisi normal pin adalah HIGH. Saat tombol ditekan menjadi LOW, dan saat dilepas kembali menjadi HIGH. Jadi interrupt akan terjadi ketika tombol dilepas.

Perilaku LED :
LED berubah kondisi saat tombol dilepas, bukan saat ditekan.

Rangkaian : https://www.tinkercad.com/things/lAPjPSmnMmL-rising?sharecode=dt7EX50iqJUtEAVpHw-R3z5mv3zmrwv1KjB9DLaeyHc
- CHANGE

Source Code :
```
#include <Arduino.h>

volatile bool ledState = false;

void tombolInterrupt() {
  ledState = !ledState;
}

void setup() {
  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP);

  attachInterrupt(
    digitalPinToInterrupt(2),
    tombolInterrupt,
    CHANGE
  );
}

void loop() {
  digitalWrite(13, ledState);
}
```
Penjelasan :
Mode CHANGE aktif setiap terjadi perubahan sinyal, baik:
HIGH ke LOW
LOW ke HIGH
Jadi interrupt terjadi dua kali:
saat tombol ditekan
saat tombol dilepas

Perilaku LED :
LED bisa berubah lebih cepat karena toggle terjadi dua kali dalam satu kali tekan tombol.

Rangkaian : https://www.tinkercad.com/things/kLVq6FvpW3Z-change?sharecode=pf2Q_esok3jvV1fZXeqav1s47AK9CPeMOEOAK8DDSFk
- LOW
  
Source Code :
```
#include <Arduino.h>

volatile bool ledState = false;

void tombolInterrupt() {
  ledState = !ledState;
}

void setup() {
  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP);

  attachInterrupt(
    digitalPinToInterrupt(2),
    tombolInterrupt,
    LOW
  );
}

void loop() {
  digitalWrite(13, ledState);
}
```
Penjelasan :
Mode LOW aktif selama pin berada pada kondisi LOW. Karena tombol ditekan membuat pin menjadi LOW, maka interrupt akan terus dipanggil selama tombol masih ditekan.

Perilaku LED :
LED dapat berkedip sangat cepat atau berubah terus menerus selama tombol ditekan karena ISR dipanggil berulang kali.

Rangkaian : https://www.tinkercad.com/things/29r9T746CrQ-low?sharecode=pn8R1Rw2o8uwZf6PQRDMB6-y1n6iHQjO2Tnw8VWrTN4
