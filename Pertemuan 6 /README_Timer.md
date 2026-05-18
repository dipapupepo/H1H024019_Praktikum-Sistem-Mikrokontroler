# Percobaan 6B : Timer 
### 1. Jelaskan bagaimana fungsi millis() bekerja pada program tersebut!
#### jawab :
Fungsi millis() digunakan untuk mengambil waktu sejak Arduino menyala dalam satuan milidetik.
Pada program:
`unsigned long currentMillis = millis();`
Nilai waktu sekarang disimpan ke variabel currentMillis.
Kemudian program mengecek:
`if(currentMillis - previousMillis >= interval)`
Jika selisih waktunya sudah mencapai interval yang ditentukan (1000 ms), maka LED akan berubah kondisi.

### 2. Apa perbedaan utama antara delay() dan millis()?
#### jawab : 
| delay()                    | millis()               |
| -------------------------- | ---------------------- |
| Program berhenti sementara | Program tetap berjalan |
| Bersifat blocking          | Bersifat non-blocking  |
| Tidak bisa multitasking    | Bisa multitasking      |
| Kurang efisien             | Lebih fleksibel        |

### 3. Mengapa metode millis() disebut non-blocking?
#### jawab :
Karena saat menunggu waktu tertentu, program tidak berhenti. Arduino tetap dapat menjalankan proses lain secara bersamaan.

Contohnya:
- membaca sensor
- menerima input tombol
- mengontrol LED lain

### 4. Modifikasi program agar :
- LED pertama berkedip setiap 1 detik
- LED kedua berkedip setiap 500 ms
- Tanpa menggunnakan delay()
Berikan penjelasan tiap baris program
#### jawab :
Source Code
```
#include <Arduino.h>

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;

const long interval1 = 1000;
const long interval2 = 500;

bool led1State = false;
bool led2State = false;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {

  unsigned long currentMillis = millis();

  // LED 1 setiap 1 detik
  if(currentMillis - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis;
    led1State = !led1State;
    digitalWrite(13, led1State);
  }

  // LED 2 setiap 500 ms
  if(currentMillis - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis;
    led2State = !led2State;
    digitalWrite(12, led2State);
  }
}
```
Penjelasan Program
`unsigned long previousMillis1 = 0;`
Menyimpan waktu terakhir LED 1 berubah.

`unsigned long previousMillis2 = 0;`
Menyimpan waktu terakhir LED 2 berubah.

`const long interval1 = 1000;`
Interval LED 1 sebesar 1 detik.

`const long interval2 = 500;`
Interval LED 2 sebesar 500 ms.

`bool led1State = false;
bool led2State = false;`
Menyimpan status LED.

`pinMode(13, OUTPUT);
pinMode(12, OUTPUT);`
Mengatur pin LED sebagai output.

`unsigned long currentMillis = millis();`
Mengambil waktu saat ini.

`if(currentMillis - previousMillis1 >= interval1)`
Mengecek apakah sudah lewat 1 detik.

`led1State = !led1State;`
Mengubah kondisi LED.

`digitalWrite(13, led1State);`
Menyalakan atau mematikan LED sesuai status.

Program LED kedua bekerja dengan konsep yang sama, hanya interval waktunya berbeda.

Rangkaian : https://www.tinkercad.com/things/aOTGrdVnH3k-modif-timer?sharecode=PhKLawcZ-8XMWANEjB5TFxiGGuDC8lgvzRtrLTrgSp4
