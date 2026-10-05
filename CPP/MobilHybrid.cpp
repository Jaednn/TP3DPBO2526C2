#pragma once // mencegah double inclusion
#include "MobilBensin.cpp" // import parent class MobilBensin
#include "MobilListrik.cpp" // import parent class MobilListrik

// Multiple Inheritance
class MobilHybrid : public MobilBensin, public MobilListrik // deklarasi class MobilHybrid
{
    private: // modifier private
        string modeBerkendara; // deklarasi atribut mode berkendara
        int dayaGabunganHP; // deklarasi atribut daya gabungan
        double harga; // deklarasi atribut harga

    public: // modifier public
        MobilHybrid() {} // default constructor
        
        MobilHybrid(string merek, string model, int tahun, 
                    int cc, double liter, string bahan,
                    double kwh, string soket, int kw,
                    string mode, int hp, double harga) // constructor lengkap
            : Kendaraan(merek, model, tahun), // inisialisasi class virtual terdalam secara eksplisit
              MobilBensin(merek, model, tahun, cc, liter, bahan), // inisialisasi parent MobilBensin
              MobilListrik(merek, model, tahun, kwh, soket, kw) // inisialisasi parent MobilListrik
        {
            this->modeBerkendara = mode; // inisialisasi atribut mode berkendara
            this->dayaGabunganHP = hp; // inisialisasi atribut daya gabungan
            this->harga = harga; // inisialisasi atribut harga
        }

        // --- Setter ---
        void setModeBerkendara(const string& mode) { this->modeBerkendara = mode; } // mengubah value atribut mode berkendara
        void setDayaGabunganHP(int hp) { this->dayaGabunganHP = hp; } // mengubah value atribut daya gabungan
        void setHarga(double harga) { this->harga = harga; } // mengubah value atribut harga

        // --- Getter ---
        string getModeBerkendara() const { return modeBerkendara; } // mengembalikan nilai mode berkendara
        int getDayaGabunganHP() const { return dayaGabunganHP; } // mengembalikan nilai daya gabungan
        double getHarga() const { return harga; } // mengembalikan nilai harga

        // --- Method ---
        void displayMobilHybrid() const // menampilkan data mobil hybrid
        {
            displayKendaraan(); // panggil method parent Kendaraan karena ambiguous jika lewat Bensin/Listrik tanpa specifier
            cout << "Kapasitas Mesin: " << kapasitasMesinCC << " cc\n"; // cetak kapasitas mesin
            cout << "Kapasitas Tangki: " << kapasitasTangkiLiter << " L\n"; // cetak kapasitas tangki
            cout << "Bahan Bakar    : " << jenisBahanBakar << "\n"; // cetak jenis bahan bakar
            cout << "Kapasitas Batere: " << kapasitasBateraikWh << " kWh\n"; // cetak kapasitas baterai
            cout << "Tipe Soket     : " << tipeSoketCharger << "\n"; // cetak tipe soket
            cout << "Daya Motor     : " << dayaMotorListrikKW << " kW\n"; // cetak daya motor listrik
            cout << "Mode Berkendara: " << modeBerkendara << "\n"; // cetak mode berkendara
            cout << "Daya Gabungan  : " << dayaGabunganHP << " HP\n"; // cetak daya gabungan
            cout << "Harga (Rp)     : " << harga << "\n"; // cetak harga
        }
}; // akhir dari class MobilHybrid
