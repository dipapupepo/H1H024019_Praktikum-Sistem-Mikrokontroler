# Percobaan 2 (Perulangan)

### 1. Gambarkan rangkaian schematic 5 LED running yang digunakan pada percobaan!
**Jawab:**
Rangkaian LED running terdiri dari beberapa LED yang dihubungkan ke pin digital Arduino (pin 2 sampai 7).  
Setiap LED disusun secara berurutan dan dilengkapi resistor sebagai pembatas arus agar tidak rusak.  

Link simulasi Tinkercad:  
https://www.tinkercad.com/things/bJb43U88WzV/editel?returnTo=%2Fdashboard&sharecode=S5mK-roMe16TAB1YictsuJaH9p4c1ZoYpfkBRQ_yojs

---
### 2. Jelaskan bagaimana program membuat efek LED berjalan dari kiri ke kanan!
**Jawab:**
Efek LED berjalan dari kiri ke kanan dibuat menggunakan perulangan berikut:

```cpp
for (int ledPin = 2; ledPin < 8; ledPin++)
````
Penjelasan:
* Perulangan dimulai dari pin kecil ke besar (2 sampai 7)
* LED menyala satu per satu secara berurutan
* Diberikan delay sehingga terlihat seperti efek berjalan
---

### 3. Jelaskan bagaimana program membuat LED kembali dari kanan ke kiri!
**Jawab:**
Efek LED dari kanan ke kiri dibuat dengan perulangan berikut:

```cpp
for (int ledPin = 7; ledPin >= 2; ledPin--)
```
Penjelasan:
* Perulangan berjalan dari pin besar ke kecil
* LED menyala dari kanan ke kiri
* Digunakan untuk menghasilkan efek bolak-balik
---

### 4. Buatkan program agar LED menyala tiga LED kanan dan tiga LED kiri secara bergantian!
**Jawab:**

### Source Code

```cpp
void setup() {
  for (int i = 2; i < 8; i++) {
    pinMode(i, OUTPUT); // Mengatur semua pin sebagai output
  }
}

void loop() {
  // Menyalakan LED kiri
  for (int i = 2; i <= 4; i++) {
    digitalWrite(i, HIGH);
  }

  delay(500); // Jeda waktu

  // Mematikan LED kiri
  for (int i = 2; i <= 4; i++) {
    digitalWrite(i, LOW);
  }

  // Menyalakan LED kanan
  for (int i = 5; i <= 7; i++) {
    digitalWrite(i, HIGH);
  }

  delay(500); // Jeda waktu

  // Mematikan LED kanan
  for (int i = 5; i <= 7; i++) {
    digitalWrite(i, LOW);
  }
}
```
Program akan menyalakan LED kiri terlebih dahulu, kemudian mematikannya setelah jeda waktu.
Setelah itu LED kanan dinyalakan dan dimatikan dengan pola yang sama.
Proses ini berlangsung terus menerus di dalam fungsi `loop()` sehingga menghasilkan efek bergantian.
```
