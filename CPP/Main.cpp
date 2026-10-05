#include <iostream> // library standar IO
#include <limits> // library batas IO
#include "Showroom.cpp" // import object induk agregator

using namespace std; // menggunakan standar namespace

int main() // entry point program
{
    // Instansiasi Showroom berdasarkan data statis showroom
    Showroom showroom("Nusantara Auto Gallery", "Jl. Sudirman No. 88, Jakarta Selatan"); // instansiasi objek
    showroom.setDetailShowroom(1500.5, 50); // set komposisi
    
    // Inisialisasi Data Dummy
    MobilBensin mBensin("Toyota", "Innova Zenix V Gasoline", 2023, 1987, 52.0, "Pertamax (RON 92)"); // instansiasi 
    showroom.addMobilBensin(mBensin); // menambahkan ke agregasi
    MobilListrik mListrik("Hyundai", "Ioniq 5 Signature Long Range", 2023, 72.6, "CCS2", 160); // instansiasi
    showroom.addMobilListrik(mListrik); // menambahkan ke agregasi
    MobilHybrid mHybrid("Toyota", "Prius PHEV GR Sport", 2024, 1987, 43.0, "Pertamax Turbo (RON 98)", 13.6, "Type 2", 120, "Series-Parallel PHEV", 220, 850000000); // instansiasi
    showroom.addMobilHybrid(mHybrid); // menambahkan ke agregasi

    int pilihan; // variabel navigasi menu
    
    do // akan berulang setidaknya satu kali
    {
        cout << "\n=== MENU SHOWROOM MOBIL ===\n"; // print header menu
        cout << "1. Lihat Semua Data Mobil\n"; // print pilihan 1
        cout << "2. Tambahkan Data Mobil Bensin\n"; // print pilihan 2
        cout << "3. Tambahkan Data Mobil Listrik\n"; // print pilihan 3
        cout << "4. Tambahkan Data Mobil Hybrid\n"; // print pilihan 4
        cout << "5. Hapus Data Mobil\n"; // print pilihan 5
        cout << "6. Keluar\n"; // print pilihan 6
        cout << "Pilih menu: "; // print dialog form

        if (!(cin >> pilihan)) // jika input error / tidak berbentuk angka
        {
            cout << "Input tidak valid.\n"; // pesan error handling non num
            cin.clear(); // hapus mode error status di stream cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // membuang buffer lama
            continue; // lanjut evaluasi loop baru
        }

        if (pilihan == 1) // opsi lihat data
        {
            showroom.displayShowroom(); // panggil prosedur tampil data
        }
        else if (pilihan == 2) // opsi tambah bensin
        {
            string merek, model, bahan; // deklarasi variabel penampung teks
            int tahun, cc; // deklarasi variabel penampung angka bulat
            double liter; // deklarasi variabel penampung angka pecahan
            
            cin.ignore(); // menetralkan sisa buffer enter (newline) dari input sebelumnya
            cout << "\n-- Tambah Mobil Bensin --\n"; // cetak header proses
            cout << "Merek        : "; getline(cin, merek); // input string lengkap dengan spasi
            cout << "Model        : "; getline(cin, model); // input string lengkap dengan spasi
            cout << "Tahun        : "; cin >> tahun; // input angka bulat tahun
            cout << "Mesin (cc)   : "; cin >> cc; // input angka bulat cc
            cout << "Tangki (L)   : "; cin >> liter; // input angka pecahan kapasitas tangki
            cin.ignore(); // buang karakter newline hasil enter sebelum ambil string lagi
            cout << "Bahan Bakar  : "; getline(cin, bahan); // input string utuh bahan bakar
            
            MobilBensin baru(merek, model, tahun, cc, liter, bahan); // instansiasi objek mobil bensin baru dari data input
            showroom.addMobilBensin(baru); // panggil prosedur masukkan ke list agregasi
            cout << "Data Mobil Bensin berhasil ditambahkan!\n"; // notifikasi eksekusi sukses
        }
        else if (pilihan == 3) // opsi tambah listrik
        {
            string merek, model, soket; // deklarasi variabel penampung teks
            int tahun, kw; // deklarasi variabel penampung angka bulat
            double kwh; // deklarasi variabel penampung angka pecahan
            
            cin.ignore(); // menetralkan buffer
            cout << "\n-- Tambah Mobil Listrik --\n"; // cetak header proses
            cout << "Merek        : "; getline(cin, merek); // input raw string
            cout << "Model        : "; getline(cin, model); // input raw string
            cout << "Tahun        : "; cin >> tahun; // input primitive int
            cout << "Baterai (kWh): "; cin >> kwh; // input primitive double
            cin.ignore(); // flush out character enter terminal
            cout << "Tipe Soket   : "; getline(cin, soket); // input raw string
            cout << "Daya (kW)    : "; cin >> kw; // input primitive int
            
            MobilListrik baru(merek, model, tahun, kwh, soket, kw); // bikin instance objek dari masukan terminal
            showroom.addMobilListrik(baru); // eksekusi logic simpan
            cout << "Data Mobil Listrik berhasil ditambahkan!\n"; // printout operasi berhasil
        }
        else if (pilihan == 4) // opsi tambah hybrid
        {
            string merek, model, bahan, soket, mode; // menyiapkan memory container string
            int tahun, cc, kw, hp; // menyiapkan tipe basic number container
            double liter, kwh, harga; // menyimpan pecahan buffer mem
            
            cin.ignore();  // bersihkan stream pipe newline flag
            cout << "\n-- Tambah Mobil Hybrid --\n"; // format tampilan konsol label
            cout << "Merek        : "; getline(cin, merek); // baca karakter keyboard lengkap satu baris
            cout << "Model        : "; getline(cin, model); // rekam buffer model string
            cout << "Tahun        : "; cin >> tahun; // angka baca cin stream std iter
            cout << "Mesin (cc)   : "; cin >> cc; // input numerik 10 base
            cout << "Tangki (L)   : "; cin >> liter; // format desimal point format cin
            cin.ignore(); // amankan buffer pipe char std iter
            cout << "Bahan Bakar  : "; getline(cin, bahan); // load string teks kalimat user terminal
            cout << "Baterai (kWh): "; cin >> kwh; // rekam masukan keyboard desimal
            cin.ignore(); // drop residual bit enter form terminal prompt
            cout << "Tipe Soket   : "; getline(cin, soket); // scan kalimat mode terminal
            cout << "Daya (kW)    : "; cin >> kw; // read input num std 
            cin.ignore(); // fix bug skipping input getline string c++ standard lib buffer problem
            cout << "Mode Hybrid  : "; getline(cin, mode); // terminal capture word
            cout << "Gabungan (HP): "; cin >> hp; // form input 
            cout << "Harga (Rp)   : "; cin >> harga; // float desimal nominal stream
            
            MobilHybrid baru(merek, model, tahun, cc, liter, bahan, kwh, soket, kw, mode, hp, harga); // konstruksi instansi
            showroom.addMobilHybrid(baru); // panggil penampung agregasi push dynamic array container 
            cout << "Data Mobil Hybrid berhasil ditambahkan!\n"; // status flag text success operation display
        }
        else if (pilihan == 5) // opsi hapus data
        {
            int tipe, index; // form var container scope memory local
            cout << "\n-- Hapus Data Mobil --\n"; // render ui menu 
            cout << "1. Bensin\n2. Listrik\n3. Hybrid\nPilih tipe (1-3): "; // message interface logic text CLI display
            cin >> tipe; // terminal io command read terminal mode wait 
            cout << "Masukkan urutan nomor (index) data yang ingin dihapus: "; // pesan logic hapus target prompt array index range handler message string print func
            cin >> index; // operasi baca input pengguna number
            
            if (tipe == 1) showroom.hapusMobilBensin(index); // eksekusi route fungsi method berdasarkan tipe 1 call bensin param int
            else if (tipe == 2) showroom.hapusMobilListrik(index); // evaluate opsi kondisi ke 2 switch flow panggil listrik index data method
            else if (tipe == 3) showroom.hapusMobilHybrid(index); // proses argumen pemanggilan delete function objek internal array state collection instance 
            else cout << "Tipe tidak valid!\n"; // default handler guard message failure exception warning std iostream terminal text return newline
        }
        else if (pilihan != 6) // jika memilih case yg salah
        {
            cout << "Pilihan tidak valid.\n"; // cetak error prompt warning form terminal out stream buffer CLI text
        }

    } while (pilihan != 6); // loop exit jika pilihan 6 true evaluasi blok condition loop while statement scope terminal break EOF continue program return point zero

    cout << "\nTerima kasih telah menggunakan sistem Showroom Nusantara!\n"; // text pesan terminal keluar
    return 0; // return status OK
}
