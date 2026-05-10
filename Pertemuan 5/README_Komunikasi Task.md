# Komunikasi Task

### 1. Apakah kedua task berjalan secara bersamaan atau bergantian? Jelaskan mekanismenya!
#### jawab:
Kedua task berjalan secara bergantian dengan pengaturan scheduler FreeRTOS.

- `read_data()` mengirim data suhu dan kelembapan ke queue.
- `display()` menerima data dari queue dan menampilkannya ke Serial Monitor.

Saat `read_data()` selesai mengirim data dan menjalankan `vTaskDelay()`, scheduler akan memberikan giliran ke `display()`. Dengan cara ini, kedua task terlihat berjalan bersamaan.

### 2. Apakah program ini berpotensi mengalami race condition? Jelaskan!
#### jawab: 
Program ini tidak berpotensi mengalami race condition karena data tidak diakses secara langsung oleh dua task. Pertukaran data dilakukan melalui queue (`xQueueSend()` dan `xQueueReceive()`) yang sudah memiliki mekanisme sinkronisasi dari FreeRTOS.

### 3. Modifikasilah program dengan menggunakan sensor DHT sesungguhnya sehingga informasi yang ditampilkan dinamis. Bagaimana hasilnya?
#### jawab: 
Pada praktikum ini sensor DHT tidak tersedia, sehingga digunakan nilai statis:

```cpp
x.temp = 54;
x.h = 30;
```
rangkaian: https://wokwi.com/projects/463640603784526849
