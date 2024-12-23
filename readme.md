# Tugas UAS Pemdas CPMK8

prompt untuk compile program

```bash
g++ main.cpp Akuarium.cpp -o program.exe
```

run:

```bash
// Powershell
.\program.exe

// Git Bash
./program.exe
```









# laporan kerkel cpmk 8
- ### Tujuan 
dibuatnya adt akuarium ini adalah untuk mengetahui apa saja aspek aspek penting yang mempengaruhi kehidupan ikan hias sehingga ikan-ikan tersebut dapat hidup dengan sehat dan tentram.

- ### Fungsi 
Fungsi dari program tersebut yakni untuk mensimulasikan kehidupan di akuarium yang dapat divisualisasikan melalui input sistem adt akuarium yang memiliki struktur berupa volume maksimal (maxVolume) dan suhu akuarium (currentTemp), yang kemudian akan ditampilkan dengan detail yang cukup. Kemudian akan diberikan beberapa opsi input user seperti 'addfish', 'clean', 'draintanki' dan 'filltanki'. Terdapat pengulangan pada program ini yaitu setiap 5 detik akan ada perubahan pada suhu dan tingkat kekotoran akuarium tersebut. Dengan menginput 'v' akan menampilkan detail-detail mengenai status akuarium dan masalah apa yang menimbulkan stress ikan. Untuk keluar dari program, user menginputkan karakter 'q' pada terminal.

- ## penjelasan singkat program utama
  + program utama terdapat pada ```main.cpp```, sebagai main function yang akan dijalankan untuk simulasi sebuah akuarium yang bisa di operasikan via input
  + dalam ```main.cpp``` terdapat import ke arah ```Akuarium.h``` dan ```Akuarium.cpp``` sebuah module buatan dari class Akuarium beserta metodenya.
  + terdapat import ```Custom_Struct.h``` sebagai module buatan untuk menyimpan struct yang digunakan.
  + ADT Class Akuarium merupakan class buatan yang memiliki properti berupa, container ikan, tanki , tingkat kekotoran dan suhu, class ini memiliki metode yang dapat digunakan untuk mengubah, ,menampilkan, mengatur dan menghapus properti yang ada pada class tersebut.

  - ### lebih lengkapnya :
    + Akuarium::getFishCount(), ```Metode untuk mengembalikan nilai total ikan yang ada pada akuarium```
    + Akuarium::getTotalFishCount(), ```Metode untuk mengembalikan kapasitas maksimal ikan yang bisa ditampung akuarium```
    + Akuarium::stringFish(), ```Metode untuk mengembalikan data string dari ikan yang ada pada akuarium```
    + list<Fish>::iterator Akuarium::getFish(string fishType) ```Metode untuk mengembalikan objek Fish yang sama dengan tipe yang diinput```

    + Akuarium::addFish ```Metode untuk menambahkan ikan ke akuarium```
    + Akuarium::minFish ```Metode untuk mengurangi jumlah ikan pada akuarium```
    + Akuarium::setFish  ```Metode untuk mengatur jumlah tipe ikan yang ada pada akuarium```

    + Akuarium::getTemp() ```Metode untuk mengembalikan nilai dari temperatur saat itu```
    + Akuarium::upTemp() ```Metode untuk menambahkan nilai suhu```
    + Akuarium::downTemp() ```Metode untuk mengurangi nilai suhu```
    + Akuarium::setTemp() ```Metode untuk mengatur nilai suhu```

    + Volume Akuarium::getTanki() ```Metode untuk mengembalikan Volume tanki akuarium ```
    + Akuarium::tankiCapacity() ```Metode untuk mengembalikan nilai total kapasitas tanki (L)```
    + Akuarium::addCurrentTanki ```Metode untuk menambahkan volume air akuarium```
    + Akuarium::minCurrentTanki ```Metode untuk mengurangi volume air akuarium```
    + Akuarium::setCurrentTanki ```Metode untuk mengatur volume air akuarium menjadi volume```

    + Akuarium::getDirty() ```Metode untuk mengembalikan nilai persentase kekotoran akuarium```
    + Akuarium::upDirty() ```Metode untuk menambahkan persentase kekotoran akuarium```
    + Akuarium::downDirty() ```Metode untuk mengurangi persentase kekotoran akuarium```
    + Akuarium::setDirty() ```Metode untuk mengatur persentase kekotoran akuarium menjadi nilai tertentu```

    + Akuarium::display() ```Metode untuk menampilkan properti akuarium```
    + Akuarium::isFishStress() ```Metode untuk memeriksa apakah ikan mengalami stres berdasarkan kondisi akuarium```
    + Akuarium::solution() ```Metode untuk mengembalikan solusi terkait masalah di akuarium, seperti ikan terlalu banyak atau akuarium terlalu kotor```

    + void updateAkuarium(Akuarium* ak){} ```Prosedur interval untuk mengupdate akuarium```



- ### aktivitas
  + jumat, 20 desember jam 19:00 projek ini dimulai dan pending pada jam 21:00
    + penentuan ide dan judul dari hasil pemikiran anggota dan menentukan hasilnya hari itu juga
    + kelompok sudah membuat garis besarannya projek dan mulai mencicil tugasnya

  + sabtu, 21 desember jam 20:00 projek ini dimulai dan pending pada jam 21:00
    + kelompok sudah melanjutkan projek

  + minggu, 22 desember jam 19:00 projek ini dimulai dan selesai pada jam 22:00 
    + kelompok menyelesaikan projekan
    + kelompok melakukan quality control


- ### hambatan
  + anggota tidak bertemu selama pengerjaan karena sudah pulang dan punya kesibukan pada waktu masing-masing (tetapi secara online masih bisa dilakukan)

- ### kesimpulan
  + program sesuai dengan tujuan awal, simulasi berhasil dijalankan dengan inputan inputan yang ada. pada prosesnya program utama dapat berjalan lancar dengan fungsi dan perintah yang ada secara selaras, untuk output sendiri sesuai dengan apa yang diinginkan
