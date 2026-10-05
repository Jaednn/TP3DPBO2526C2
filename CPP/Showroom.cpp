#pragma once // mencegah double inclusion
#include <iostream> // library IO
#include <vector> // library array dinamis / vector
#include "MobilHybrid.cpp" // import parent class MobilHybrid (yang otomatis bawa Bensin dan Listrik)
#include "DetailShowroom.cpp" // import class DetailShowroom

class Showroom // deklarasi class Showroom
{
    private: // modifier private
        string namaShowroom; // deklarasi atribut nama showroom
        string alamatLengkap; // deklarasi atribut alamat lengkap
        DetailShowroom detailShowroom; // deklarasi atribut objek DetailShowroom (Komposisi)
        vector<MobilBensin> daftarMobilBensin; // deklarasi list array objek MobilBensin (Agregasi)
        vector<MobilListrik> daftarMobilListrik; // deklarasi list array objek MobilListrik (Agregasi)
        vector<MobilHybrid> daftarMobilHybrid; // deklarasi list array objek MobilHybrid (Agregasi)

    public: // modifier public
        Showroom() {} // default constructor
        
        Showroom(string nama, string alamat) // constructor parametrik
        {
            this->namaShowroom = nama; // inisialisasi atribut nama showroom
            this->alamatLengkap = alamat; // inisialisasi atribut alamat lengkap
        }

        // --- Setter ---
        void setNamaShowroom(const string& nama) { this->namaShowroom = nama; } // mengubah value atribut nama showroom
        void setAlamatLengkap(const string& alamat) { this->alamatLengkap = alamat; } // mengubah value atribut alamat lengkap
        void setDetailShowroom(double luas, int maks) // mengubah value detail showroom
        {
            detailShowroom.setLuasAreaM2(luas); // set properti bagian komposisi
            detailShowroom.setKapasitasMaks(maks); // set properti bagian komposisi
        }

        // --- Getter ---
        string getNamaShowroom() const { return namaShowroom; } // mengembalikan nilai nama showroom
        string getAlamatLengkap() const { return alamatLengkap; } // mengembalikan nilai alamat lengkap
        DetailShowroom getDetailShowroom() const { return detailShowroom; } // mengembalikan object DetailShowroom

        // --- Method ---
        void addMobilBensin(const MobilBensin& mobil) { daftarMobilBensin.push_back(mobil); } // menambah objek MobilBensin ke list
        void addMobilListrik(const MobilListrik& mobil) { daftarMobilListrik.push_back(mobil); } // menambah objek MobilListrik ke list
        void addMobilHybrid(const MobilHybrid& mobil) { daftarMobilHybrid.push_back(mobil); } // menambah objek MobilHybrid ke list

        void hapusMobilBensin(int index) { // menghapus MobilBensin berdasarkan index (1-based)
            if (index > 0 && index <= (int)daftarMobilBensin.size()) {
                daftarMobilBensin.erase(daftarMobilBensin.begin() + index - 1);
                cout << "Data Mobil Bensin berhasil dihapus!\n";
            } else {
                cout << "Index tidak valid!\n";
            }
        }
        
        void hapusMobilListrik(int index) { // menghapus MobilListrik berdasarkan index (1-based)
            if (index > 0 && index <= (int)daftarMobilListrik.size()) {
                daftarMobilListrik.erase(daftarMobilListrik.begin() + index - 1);
                cout << "Data Mobil Listrik berhasil dihapus!\n";
            } else {
                cout << "Index tidak valid!\n";
            }
        }
        
        void hapusMobilHybrid(int index) { // menghapus MobilHybrid berdasarkan index (1-based)
            if (index > 0 && index <= (int)daftarMobilHybrid.size()) {
                daftarMobilHybrid.erase(daftarMobilHybrid.begin() + index - 1);
                cout << "Data Mobil Hybrid berhasil dihapus!\n";
            } else {
                cout << "Index tidak valid!\n";
            }
        }

        void displayShowroom() const // menampilkan keseluruhan isi showroom
        {
            cout << "========================================\n"; // cetak garis batas
            cout << "INFORMASI SHOWROOM\n"; // cetak judul 
            cout << "========================================\n"; // cetak garis batas
            cout << "Nama Showroom  : " << namaShowroom << "\n"; // cetak nama showroom
            cout << "Alamat Lengkap : " << alamatLengkap << "\n"; // cetak alamat showroom
            detailShowroom.displayDetail(); // memanggil method display komponen
            
            cout << "\n--- DAFTAR MOBIL BENSIN ---\n"; // cetak judul list
            if (daftarMobilBensin.empty()) cout << "Kosong\n"; // cetak empty handling
            for (size_t i = 0; i < daftarMobilBensin.size(); ++i) // loop tiap entri
            {
                cout << "[" << i + 1 << "]\n"; // cetak penanda nomor
                daftarMobilBensin[i].displayMobilBensin(); // panggil method objek
            }

            cout << "\n--- DAFTAR MOBIL LISTRIK ---\n"; // cetak judul list
            if (daftarMobilListrik.empty()) cout << "Kosong\n"; // cetak empty handling
            for (size_t i = 0; i < daftarMobilListrik.size(); ++i) // loop tiap entri
            {
                cout << "[" << i + 1 << "]\n"; // cetak penanda nomor
                daftarMobilListrik[i].displayMobilListrik(); // panggil method objek
            }

            cout << "\n--- DAFTAR MOBIL HYBRID ---\n"; // cetak judul list
            if (daftarMobilHybrid.empty()) cout << "Kosong\n"; // cetak empty handling
            for (size_t i = 0; i < daftarMobilHybrid.size(); ++i) // loop tiap entri
            {
                cout << "[" << i + 1 << "]\n"; // cetak penanda nomor
                daftarMobilHybrid[i].displayMobilHybrid(); // panggil method objek
            }
            cout << "========================================\n"; // cetak garis batas penutup
        }
}; // akhir dari class Showroom
