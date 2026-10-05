#pragma once // mencegah double inclusion
#include <iostream> // library standar IO
#include <string> // library string
using namespace std; // menggunakan standar namespace

class Kendaraan // deklarasi class base Kendaraan
{
    protected: // modifier protected agar bisa diakses child class (dibutuhkan untuk virtual inheritance / hybrid)
        string merek; // deklarasi atribut merek
        string model; // deklarasi atribut model
        int tahunProduksi; // deklarasi atribut tahun produksi

    public: // modifier public
        Kendaraan() {} // default constructor kosong
        
        Kendaraan(string merek, string model, int tahunProduksi) // constructor lengkap
        {
            this->merek = merek; // inisialisasi atribut merek
            this->model = model; // inisialisasi atribut model
            this->tahunProduksi = tahunProduksi; // inisialisasi atribut tahun produksi
        }

        // --- Setter ---
        void setMerek(const string& merek) { this->merek = merek; } // mengubah value atribut merek
        void setModel(const string& model) { this->model = model; } // mengubah value atribut model
        void setTahunProduksi(int tahun) { this->tahunProduksi = tahun; } // mengubah value atribut tahun produksi

        // --- Getter ---
        string getMerek() const { return merek; } // mengembalikan nilai merek
        string getModel() const { return model; } // mengembalikan nilai model
        int getTahunProduksi() const { return tahunProduksi; } // mengembalikan nilai tahun produksi

        // --- Method ---
        void displayKendaraan() const // menampilkan data kendaraan
        {
            cout << "Merek          : " << merek << "\n"; // cetak merek
            cout << "Model          : " << model << "\n"; // cetak model
            cout << "Tahun Produksi : " << tahunProduksi << "\n"; // cetak tahun produksi
        }
}; // akhir dari class Kendaraan
