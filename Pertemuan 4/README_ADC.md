# Percobaan 1 ADC

### 1. Apa fungsi perintah analogRead() pada rangkaian praktikum ini?
#### jawab :
Perintah analogRead() digunakan untuk membaca nilai tegangan analog dari potensiometer yang terhubung ke pin analog Arduino. Nilai yang dibaca akan dikonversi menjadi data digital dengan rentang 0–1023 (karena ADC Arduino 10-bit). Nilai ini merepresentasikan posisi putaran potensiometer.

### 2. Mengapa diperlukan fungsi map() dalam program tersebut?
#### jawab : 
Fungsi map() digunakan untuk mengubah (mengkonversi) nilai ADC dari potensiometer (0–1023) menjadi nilai sudut servo (0–180 derajat).
Tanpa map(), nilai dari potensiometer tidak sesuai dengan rentang yang dibutuhkan servo, sehingga servo tidak akan bergerak dengan benar.

### 3. Modifikasi program agar servo hanya bergerak dalam rentang 30° hingga 150°
#### jawab :
```
pos = map(val, 0, 1023, 30, 150);
```
- 0, 1023 → rentang nilai ADC dari potensiometer
- 30, 150 → rentang sudut servo yang diinginkan
#### Artinya:
- Saat potensiometer minimum → servo di 30°
- Saat potensiometer maksimum → servo di 150°
- Servo tidak akan bergerak di bawah 30° atau di atas 150°

#### rangkaian percobaan : 
https://www.tinkercad.com/things/elSUQk8Npxc-analog-to-digital-converter-adc?sharecode=oyZhHtEUNLNf1W-AcIpn5ga8gw3MYZShJwAvT4x48oY
