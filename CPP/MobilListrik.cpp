#pragma once // mencegah double inclusion
#pragma GCC diagnostic ignored "-Wvirtual-move-assign" // mengabaikan warning bawaan g++ terkait operasi hapus vector pada virtual inheritance
#include "Kendaraan.cpp" // import parent class

// menggunakan virtual inheritance untuk mengatasi diamond problem pada hybrid inheritance
class MobilListrik : virtual public Kendaraan // deklarasi class MobilListrik
{
    protected: // modifier protected
        double kapasitasBateraikWh; // deklarasi atribut kapasitas baterai
        string tipeSoketCharger; // deklarasi atribut tipe soket
        int dayaMotorListrikKW; // deklarasi atribut daya motor listrik

    public: // modifier public
        MobilListrik() {} // default constructor
        
        MobilListrik(string merek, string model, int tahun, double kwh, string soket, int kw) // constructor lengkap
            : Kendaraan(merek, model, tahun) // memanggil constructor parent
        {
            this->kapasitasBateraikWh = kwh; // inisialisasi atribut kapasitas baterai
            this->tipeSoketCharger = soket; // inisialisasi atribut tipe soket
            this->dayaMotorListrikKW = kw; // inisialisasi atribut daya motor listrik
        }

        // --- Setter ---
        void setKapasitasBateraikWh(double kwh) { this->kapasitasBateraikWh = kwh; } // mengubah value atribut kapasitas baterai
        void setTipeSoketCharger(const string& soket) { this->tipeSoketCharger = soket; } // mengubah value atribut tipe soket
        void setDayaMotorListrikKW(int kw) { this->dayaMotorListrikKW = kw; } // mengubah value atribut daya motor listrik

        // --- Getter ---
        double getKapasitasBateraikWh() const { return kapasitasBateraikWh; } // mengembalikan nilai kapasitas baterai
        string getTipeSoketCharger() const { return tipeSoketCharger; } // mengembalikan nilai tipe soket
        int getDayaMotorListrikKW() const { return dayaMotorListrikKW; } // mengembalikan nilai daya motor listrik

        // --- Method ---
        void displayMobilListrik() const // menampilkan data mobil listrik
        {
            displayKendaraan(); // panggil method parent
            cout << "Kapasitas Batere: " << kapasitasBateraikWh << " kWh\n"; // cetak kapasitas baterai
            cout << "Tipe Soket     : " << tipeSoketCharger << "\n"; // cetak tipe soket
            cout << "Daya Motor     : " << dayaMotorListrikKW << " kW\n"; // cetak daya motor listrik
        }
}; // akhir dari class MobilListrik
