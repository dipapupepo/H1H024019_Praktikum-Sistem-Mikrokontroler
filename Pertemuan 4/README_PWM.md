# Percobaan 2 PWM
### 1. Jelaskan mengapa LED dapat diatur kecerahannya menggunakan fungsi analogWrite()!
#### jawab :
LED dapat diatur kecerahannya menggunakan fungsi analogWrite() karena Arduino menghasilkan sinyal PWM (Pulse Width Modulation), yaitu sinyal digital yang dinyalakan dan dimatikan dengan sangat cepat.
Kecerahan LED ditentukan oleh duty cycle (persentase waktu sinyal HIGH):
- Duty cycle kecil → LED redup
- Duty cycle besar → LED terang
Meskipun bukan sinyal analog murni, perubahan cepat ini membuat LED tampak memiliki kecerahan yang bervariasi.

### 2. Apa hubungan antara nilai ADC (0–1023) dan nilai PWM (0–255)?
#### jawab : 
Nilai ADC (0–1023) merupakan hasil pembacaan analog dari potensiometer, sedangkan nilai PWM (0–255) digunakan untuk mengatur kecerahan LED. Karena rentangnya berbeda, diperlukan proses konversi menggunakan fungsi map():
PWM=map(ADC,0,1023,0,255)
Hubungannya:
- ADC = 0 → PWM = 0 (LED mati)
- ADC = 1023 → PWM = 255 (LED paling terang)
- Nilai di antaranya → menghasilkan kecerahan bertahap
  
### 3. Modifikasi program agar LED hanya menyala pada rentang PWM 50–200
#### jawab :
```
pwm = map(nilaiADC, 0, 1023, 0, 255);

// Batasi kecerahan LED
if (pwm >= 50 && pwm <= 200) {
  analogWrite(ledPin, pwm);
} else {
  analogWrite(ledPin, 0); // LED mati di luar rentang
}
```
#### Penjelasan:
- Nilai ADC tetap dibaca penuh (0–1023)
- Setelah dikonversi ke PWM:
  - Jika PWM antara 50–200 → LED menyala (kecerahan sedang)
  - Jika di luar rentang tersebut → LED dimatikan

### Rangkaian Percobaan : 
https://www.tinkercad.com/things/50ulmxE28de-pulse-width-modulation-pwm?sharecode=fSev7cce8segQJ5VBLzKJzlDa7Ds0lzBYLoIFCtVdPw
