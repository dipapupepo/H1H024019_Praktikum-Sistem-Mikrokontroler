# Percobaan 1 (Percabangan)

## 1. Pada kondisi apa program masuk ke blok if?
**Jawab:**
Program masuk ke blok `if` ketika nilai variabel `timeDelay <= 100`.  
Artinya, saat delay sudah semakin kecil (LED berkedip semakin cepat) dan mencapai batas minimum (100 ms atau kurang), maka kondisi `if` akan dijalankan.

---

## 2. Pada kondisi apa program masuk ke blok else?
**Jawab:**
Program masuk ke blok `else` ketika kondisi `timeDelay > 100`.  
Selama nilai delay masih di atas 100 ms, program akan terus mempercepat kedipan LED dengan cara mengurangi nilai `timeDelay`.

---

## 3. Apa fungsi dari perintah delay(timeDelay)?
**Jawab:**
Fungsi `delay(timeDelay)` adalah untuk memberikan jeda waktu (dalam milidetik).  
Perintah ini mengatur kecepatan LED berkedip:
- Semakin besar `timeDelay` → LED berkedip semakin lambat  
- Semakin kecil `timeDelay` → LED berkedip semakin cepat  

---

## 4. Jika program yang dibuat memiliki alur mati → lambat → cepat → reset (mati), ubah menjadi LED tidak langsung reset → tetapi berubah dari cepat → sedang → mati dan berikan penjelasan disetiap baris kode nya dalam bentuk README.md!
**jawab:**

### Source Code
```cpp
const int ledPin = 6;      // Menentukan pin LED
int timeDelay = 1000;      // Delay awal (lambat)
bool kembali = false;      // Penanda untuk memperlambat kembali

void setup() {
  pinMode(ledPin, OUTPUT); // Set pin LED sebagai output
}

void loop() {
  digitalWrite(ledPin, HIGH); // LED menyala
  delay(timeDelay);           // Tunggu sesuai delay

  digitalWrite(ledPin, LOW);  // LED mati
  delay(timeDelay);           // Tunggu sesuai delay

  if (!kembali) {             // Jika masih fase percepatan
    timeDelay -= 100;         // Percepat kedipan LED

    if (timeDelay <= 100) {   // Jika sudah mencapai kecepatan maksimum
      kembali = true;         // Ubah ke fase perlambatan
    }

  } else {                    // Jika fase perlambatan
    timeDelay += 100;         // Perlambat kedipan LED

    if (timeDelay >= 1000) {  // Jika sudah kembali ke kondisi lambat
      while (true);           // Program berhenti (LED mati)
    }
  }
}
