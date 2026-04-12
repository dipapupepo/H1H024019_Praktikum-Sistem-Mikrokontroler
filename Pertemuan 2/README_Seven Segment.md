# Percobaan Seven Segment
### 1. Gambarkan rangkaian scematic yang digunakan pada percobaan!
#### jawab: 
https://www.tinkercad.com/things/c8IVg1XfKzK-seven-segment?sharecode=u88vAl38j9FgyaRvPVEaIw1Br2fLibAjsCL2ncg5EAk

### 2. Apa yang terjadi jika nilai num lebih dari 15?
#### jawab: 
Nilai num yang lebih dari 15 tidak dapat ditampilkan dengan benar pada seven segment karena seven segment hanya mampu menampilkan angka hexadecimal dari 0 sampai F (0–15). Jika nilai melebihi 15, maka tampilan akan menjadi tidak valid atau tidak sesuai pola angka/huruf yang seharusnya.

### 3. Apakah prohram ini menggunakan common cathode atau common anode? Jelaskan alasannya!
#### jawab:
Program ini menggunakan common cathode. Hal ini karena LED pada seven segment akan menyala ketika diberikan logika HIGH pada pin Arduino. Pada common cathode, semua katoda terhubung ke ground, sehingga LED akan aktif saat diberi tegangan HIGH.

#### Modifikasi program agar tampilan berjalan dari F ke 0 + penjelasan 
#### jawab:
```cpp
int segPins[] = {7,6,5,11,10,8,9}; 

byte hexPattern[16][7] = {
  {1,1,1,1,1,1,0}, //0
  {0,1,1,0,0,0,0}, //1
  {1,1,0,1,1,0,1}, //2
  {1,1,1,1,0,0,1}, //3
  {0,1,1,0,0,1,1}, //4
  {1,0,1,1,0,1,1}, //5
  {1,0,1,1,1,1,1}, //6
  {1,1,1,0,0,0,0}, //7
  {1,1,1,1,1,1,1}, //8
  {1,1,1,1,0,1,1}, //9
  {1,1,1,0,1,1,1}, //A
  {0,0,1,1,1,1,1}, //b
  {1,0,0,1,1,1,0}, //C
  {0,1,1,1,1,0,1}, //d
  {1,0,0,1,1,1,1}, //E
  {1,0,0,0,1,1,1}  //F
};

void setup(){
  for(int i=0;i<7;i++){
    pinMode(segPins[i], OUTPUT);
  }
}

void loop(){
  for(int num=15; num>=0; num--){
    for(int i=0;i<7;i++){
      digitalWrite(segPins[i], hexPattern[num][i]);
    }
    delay(1000);
  }
}
```
penjelasan :

- segPins[] → menyimpan pin yang terhubung ke segmen
- hexPattern[][] → pola LED untuk angka 0–F
- setup() → set semua pin jadi OUTPUT
- loop() → perulangan dari 15 ke 0
- digitalWrite() → nyalain/matiin segmen
- delay() → jeda antar angka
