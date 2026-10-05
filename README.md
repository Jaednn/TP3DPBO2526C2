# Tugas Praktikum 3 - Desain Pemrograman Berorientasi Objek (DPBO)

## 1. Janji
Saya Afzaal Zaidan Febryanto dengan NIM 2508692 mengerjakan Tugas Praktikum 3 dalam mata kuliah Desain dan Pemrograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

## 2. Desain Diagram Program
Program ini didesain sesuai dengan diagram referensi yang diberikan. Secara garis besar, terdapat rancangan *Hybrid Inheritance* serta penerapan *Composition* dan *Aggregation*.

<img width="2551" height="3301" alt="Diagram" src="https://github.com/user-attachments/assets/1a507ada-398b-4e29-a26c-d66ece89063d" />


## 3. Penjelasan Atribut dan Methods Setiap Kelas

### a. Kelas `Kendaraan` (Base Class)
* **Atribut**: 
  * `merek` (string): Merek dari kendaraan (contoh: Toyota, Hyundai).
  * `model` (string): Model / nama spesifik kendaraan (contoh: Prius, Ioniq 5).
  * `tahunProduksi` (int): Tahun pembuatan kendaraan.
* **Method**:
  * Constructor lengkap dan kosong.
  * `setMerek`, `setModel`, `setTahunProduksi` (Setter).
  * `getMerek`, `getModel`, `getTahunProduksi` (Getter).
  * `displayKendaraan()`: Mencetak properti dasar kendaraan.

### b. Kelas `MobilBensin` (Turunan dari `Kendaraan`)
* **Atribut**:
  * `kapasitasMesinCC` (int): Ukuran kubikasi mesin pembakaran dalam satuan cc.
  * `kapasitasTangkiLiter` (double): Volume maksimum bahan bakar yang bisa diisi.
  * `jenisBahanBakar` (string): Tipe oktan/cetane bahan bakar (contoh: Pertamax).
* **Method**:
  * Constructor yang meneruskan parameter ke `Kendaraan`.
  * Setter & Getter untuk seluruh atribut di atas.
  * `displayMobilBensin()`: Menampilkan info Kendaraan + spesifik bensin.

### c. Kelas `MobilListrik` (Turunan dari `Kendaraan`)
* **Atribut**:
  * `kapasitasBateraikWh` (double): Kapasitas penyimpanan daya listrik baterai.
  * `tipeSoketCharger` (string): Tipe colokan charging (contoh: CCS2, Type 2).
  * `dayaMotorListrikKW` (int): Keluaran tenaga motor listrik.
* **Method**:
  * Constructor yang meneruskan parameter ke `Kendaraan`.
  * Setter & Getter.
  * `displayMobilListrik()`: Menampilkan info Kendaraan + spesifik kelistrikan.

### d. Kelas `MobilHybrid` (Turunan dari `MobilBensin` & `MobilListrik` -> Hybrid Inheritance)
* **Atribut**:
  * `modeBerkendara` (string): Mode operasi hybrid (contoh: Series-Parallel).
  * `dayaGabunganHP` (int): Tenaga maksimal kombinasi mesin bensin + motor listrik.
  * `harga` (double): Harga jual kendaraan.
* **Method**:
  * Constructor yang merangkai inisialisasi semua parent.
  * Setter & Getter.
  * `displayMobilHybrid()`: Menampilkan perpaduan seluruh properti bensin dan listrik.

### e. Kelas `DetailShowroom`
* **Atribut**:
  * `luasAreaM2` (double): Total luasan ruang pameran.
  * `kapasitasMaks` (int): Total batas tampung mobil.
* **Method**:
  * Constructor, Setter & Getter.
  * `displayDetail()`: Menampilkan kapasitas detail gedung.

### f. Kelas `Showroom`
* **Atribut**:
  * `namaShowroom` (string): Nama entitas bisnis.
  * `alamatLengkap` (string): Alamat operasional gedung.
  * `detailShowroom` (DetailShowroom): Objek implementasi **Composition**.
  * `daftarMobilBensin` (List/Vector): Koleksi **Aggregation** mobil bensin.
  * `daftarMobilListrik` (List/Vector): Koleksi **Aggregation** mobil listrik.
  * `daftarMobilHybrid` (List/Vector): Koleksi **Aggregation** mobil hybrid.
* **Method**:
  * Constructor, Setter & Getter.
  * `setDetailShowroom(luas, maks)`: Melakukan setting objek komponen dalam class.
  * `addMobilBensin`, `addMobilListrik`, `addMobilHybrid`: Memasukkan data ke dalam list.
  * `displayShowroom()`: Menampilkan seluruh isi state showroom secara lengkap.

## 4. Penjelasan Desain Program
1. **Hybrid Inheritance**: Digunakan untuk mengatasi turunan bertingkat silang. `Kendaraan` mewariskan ke `MobilBensin` dan `MobilListrik`. Lalu, `MobilHybrid` mewarisi properti gabungan dari `MobilBensin` dan `MobilListrik`. Dalam eksekusinya:
   - **C++**: Menggunakan `virtual public Kendaraan` untuk menyelesaikan Diamond Problem.
   - **Python**: Menggunakan resolusi *Multiple Inheritance* native lewat MRO.
   - **Java**: Dilakukan pewarisan terhadap `MobilBensin` sembari melakukan replikasi manual/implementasi langsung atribut `MobilListrik` karena Java terikat *Single Class Inheritance*.
2. **Composition**: `Showroom` melakukan instansiasi terhadap `DetailShowroom` (`detailShowroom = new DetailShowroom()`) di dalam tubuh constructor-nya. Ini berarti ketika instansi Showroom hancur, instansi DetailShowroom tersebut secara hierarkis logika juga akan hilang.
3. **Aggregation / Array of Objects**: `Showroom` hanya menampung referensi objek mobil (lewat method `addMobil...`) ke dalam array (Vector di C++, List di Python, ArrayList di Java). Mobil-mobil ini eksis dan diinstansiasi di luar (misal di fungsi `main`).

## 5. Penjelasan Alur
Program berjalan secara lurus (sekuensial):
1. Sistem akan menginisialisasi dan membangkitkan (instansiasi) objek `Showroom` (termasuk membangkitkan komposisi `DetailShowroom` di dalamnya) dengan nilai statis kosong dari dummy.
2. Program mencetak (print) *state* isi memori pameran (`Showroom`) saat ini (kondisi awal/kosong).
3. Objek-objek kendaraan riil (Dummy 1, 2, dan 3) dibuat pada area global fungsi main satu per satu (`MobilBensin`, `MobilListrik`, dan `MobilHybrid`).
4. Setelah objek mobil jadi, referensinya dimasukkan ke dalam daftar array objek `Showroom` masing-masing menggunakan fungsi agregator `addMobil...`.
5. Akhirnya, program mencetak ulang *state* isi memori pameran (`Showroom`) untuk membuktikan masuknya objek-objek tersebut ke dalam database statis program (kondisi sesudah ditambahkan). 

## 6. Dokumentasi
- **C++**:
<img width="727" height="887" alt="cpp1" src="https://github.com/user-attachments/assets/f4464e5b-209b-431b-a8a8-26921aee5410" /><br>
<img width="490" height="891" alt="cpp2" src="https://github.com/user-attachments/assets/29944cb3-15f6-48dc-b135-bea295087bc0" /><br>
<img width="452" height="582" alt="cpp3" src="https://github.com/user-attachments/assets/cb172d74-8dd9-4310-bb8c-f37f96aa031b" /><br>

- **Python**:
<img width="445" height="847" alt="py2" src="https://github.com/user-attachments/assets/8830ae44-d74a-459e-8c83-371e8484369f" /><br>
<img width="1085" height="900" alt="py1" src="https://github.com/user-attachments/assets/fb86c06d-d4eb-4236-b39e-7706fe2a7237" /><br>
<img width="382" height="410" alt="py3" src="https://github.com/user-attachments/assets/e03fb4ab-a475-4b73-9092-5ba2a55f3d99" /><br>

- **Java**: 
<img width="772" height="908" alt="java2" src="https://github.com/user-attachments/assets/79ba63b0-b1c1-4a4f-a747-24eef2644fe3" /><br>
<img width="740" height="896" alt="java1" src="https://github.com/user-attachments/assets/9cbad10c-fed3-441f-8812-5c650d43edca" /><br>
<img width="521" height="367" alt="java3" src="https://github.com/user-attachments/assets/469f0ffa-d689-4426-8a6f-7832207c67f5" /><br>
