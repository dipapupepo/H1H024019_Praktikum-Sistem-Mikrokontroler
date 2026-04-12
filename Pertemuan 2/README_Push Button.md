# Percobaan Push Button 
### 1. Gambarkan rangkaian schematic yang digunakan pada percobaan!
#### Jawab :
https://www.tinkercad.com/things/5F15UpDN3vd/editel?returnTo=%2Fdashboard&sharecode=GYoE7KyAog9svOJ0rKCKgU7jAsMT9c9iScUhafUfnw4

### 2. Mengapa menggunakan INPUT_PULLUP? Apa keuntungannya?
#### Jawab : 
Mode INPUT_PULLUP digunakan untuk mengaktifkan resistor internal pada Arduino sehingga tidak diperlukan resistor eksternal. Keuntungannya adalah rangkaian menjadi lebih sederhana dan sinyal input menjadi lebih stabil karena tidak mengalami kondisi floating.

### 3. Jika salah satu LED segmen tidak menyala, apa penyebabnya?
#### Jawab : 
Hardware:
- Kabel tidak terhubung dengan benar
- Resistor rusak atau tidak terpasang
- LED pada seven segment rusak

Software:

- Pin tidak sesuai dengan kode
- Kesalahan logika HIGH/LOW
- Pola array salah
  
4. Modifikasi 2 push button (increment & decrement)
```
int btnUp = 2;
int btnDown = 3;
int num = 0;

void setup(){
  pinMode(btnUp, INPUT_PULLUP);
  pinMode(btnDown, INPUT_PULLUP);
}

void loop(){
  if(digitalRead(btnUp) == LOW){
    num++;
    if(num > 15) num = 0;
    delay(200);
  }

  if(digitalRead(btnDown) == LOW){
    num--;
    if(num < 0) num = 15;
    delay(200);
  }
}
```
Penjelasan:
- Tombol ditekan → LOW
- btnUp → tambah angka
- btnDown → kurang angka
- Batas dijaga 0–15
- delay() → menghindari bouncing
