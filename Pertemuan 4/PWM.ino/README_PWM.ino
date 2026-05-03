PENJELASAN PROGRAM 

Program ini bertujuan untuk mengatur kecerahan **LED** menggunakan input dari **potensiometer** dengan memanfaatkan metode Pulse Width Modulation (PWM) pada Arduino.
Pada program ini, pin A0 digunakan sebagai input analog untuk membaca nilai dari potensiometer, sedangkan pin 9 digunakan sebagai output PWM untuk mengendalikan LED.
Terdapat dua variabel utama, yaitu `nilaiADC` yang digunakan untuk menyimpan hasil pembacaan analog dengan rentang 0 hingga 1023, serta `pwm` yang digunakan untuk menyimpan hasil konversi ke sinyal PWM dengan rentang 0 hingga 255.
Pada fungsi `setup()`, pin LED diatur sebagai output menggunakan `pinMode()`. Selain itu, komunikasi serial diaktifkan dengan `Serial.begin(9600)` untuk menampilkan data pada Serial Monitor.
Pada fungsi `loop()`, program berjalan secara berulang dengan langkah-langkah sebagai berikut:

1. Pembacaan ADC
   Nilai dari potensiometer dibaca menggunakan fungsi `analogRead(potPin)` yang menghasilkan nilai antara 0 hingga 1023.
2. Konversi Nilai
   Nilai ADC kemudian dikonversi menjadi nilai PWM menggunakan fungsi `map()` dari rentang 0–1023 menjadi 0–255.
3. Output PWM
   Nilai PWM yang dihasilkan digunakan untuk mengatur kecerahan LED melalui fungsi `analogWrite(ledPin, pwm)`.
4. Monitoring Data
   Nilai ADC dan PWM ditampilkan pada Serial Monitor menggunakan `Serial.print()` dan `Serial.println()`.
5. Stabilisasi Sistem
   Delay selama 50 ms diberikan untuk menjaga kestabilan pembacaan dan tampilan data.
