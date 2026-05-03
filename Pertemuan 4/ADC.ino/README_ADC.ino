PENJELASAN PROGRAM 

Program ini bertujuan untuk mengontrol pergerakan servo motor menggunakan input dari potensiometer melalui proses Analog to Digital Converter (ADC) pada Arduino. Pada program ini, digunakan library Servo.h untuk mempermudah pengendalian servo motor. Objek servo dibuat dengan nama myservo yang nantinya digunakan untuk mengatur posisi sudut servo.

Pin yang digunakan terdiri dari:
- Pin A0 sebagai input analog untuk membaca nilai dari potensiometer
- Pin 9 sebagai output PWM untuk mengendalikan servo motor
Terdapat dua variabel utama, yaitu:
- val untuk menyimpan nilai hasil pembacaan ADC (0–1023)
- pos untuk menyimpan nilai sudut servo (0–180 derajat)
Pada fungsi setup(), servo dihubungkan ke pin 9 menggunakan myservo.attach(servoPin). Selain itu, komunikasi serial diaktifkan dengan Serial.begin(9600) untuk menampilkan data pada Serial Monitor.

Pada fungsi loop(), program berjalan secara berulang dengan langkah-langkah sebagai berikut:
1. Pembacaan ADC
   Nilai dari potensiometer dibaca menggunakan fungsi analogRead(potensioPin) yang menghasilkan nilai antara 0 hingga 1023.
2. Konversi Nilai
   Nilai ADC kemudian dikonversi menjadi sudut servo menggunakan fungsi map() dari rentang 0–1023 menjadi 0–180 derajat.      pos=map(val,0,1023,0,180)
3. Penggerakan Servo
   Hasil konversi tersebut digunakan untuk menggerakkan servo melalui perintah myservo.write(pos).
4. Monitoring Data
   Nilai ADC dan sudut servo ditampilkan pada Serial Monitor menggunakan Serial.print() dan Serial.println().
5. Stabilisasi
   Delay selama 15 ms diberikan untuk menjaga pergerakan servo agar lebih halus dan mengurangi getaran.

