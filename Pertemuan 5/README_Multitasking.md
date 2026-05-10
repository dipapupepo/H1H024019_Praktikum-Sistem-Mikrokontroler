# Multitasking

### 1. Apakah ketiga task berjalan secara bersamaan atau bergantian? Jelaskan mekanismenya!
#### jawab:

Ketiga task tidak benar-benar berjalan secara bersamaan, tetapi dijalankan secara bergantian oleh scheduler pada FreeRTOS.

- `TaskBlink1` mengontrol LED pada pin 8.
- `TaskBlink2` mengontrol LED pada pin 7.
- `TaskPrint` menampilkan nilai counter ke Serial Monitor.

Scheduler FreeRTOS akan menjalankan task yang siap dieksekusi. Ketika suatu task memanggil `vTaskDelay()`, task tersebut akan berhenti sementara (blocked), lalu scheduler memberikan giliran ke task lain. Dengan mekanisme ini, ketiga task terlihat berjalan bersamaan.

### 2. Bagaimana cara menambahkan task keempat? Jelaskan langkahnya!
#### jawab: 
Langkah-langkah menambahkan task keempat:

1. Membuat fungsi task baru, misalnya `TaskBlink3()`.
2. Menambahkan `xTaskCreate()` di dalam `setup()`.
3. Menentukan stack size, prioritas, dan nama task.

Contoh:

```cpp
void TaskBlink3(void *pvParameters) {
  pinMode(6, OUTPUT);

  while (1) {
    Serial.println("Task4");
    digitalWrite(6, HIGH);
    vTaskDelay(400 / portTICK_PERIOD_MS);
    digitalWrite(6, LOW);
    vTaskDelay(400 / portTICK_PERIOD_MS);
  }
}
```
Tambahkan ke `setup()`
```cpp
xTaskCreate(TaskBlink3, "task4", 128, NULL, 1, NULL);
```
### 3. Modifikasilah program dengan menambah sensor potensiometer, lalu gunakan nilainya untuk mengontrol kecepatan LED! Bagaimana hasilnya?
#### jawab:
Potensiometer dihubungkan ke pin A0 untuk membaca nilai analog (0–1023). Nilai tersebut diubah menjadi delay LED menggunakan fungsi map().
```cpp
int nilai = analogRead(A0);
int delayLed = map(nilai, 0, 1023, 100, 1000);
vTaskDelay(delayLed / portTICK_PERIOD_MS);
```
Hasil percobaan:
- Saat potensiometer diputar ke kiri, LED berkedip lebih cepat.
- Saat diputar ke kanan, LED berkedip lebih lambat.
- Kecepatan LED dapat diatur secara real-time.

Rangkaian : https://www.tinkercad.com/things/laq8M4qETnh-multitasking?sharecode=XA6G9nw6FFSCD6_PSNXEPUdFcF4xAkpOFk4awsYJVGQ
