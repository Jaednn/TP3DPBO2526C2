#pragma once // mencegah double inclusion
#include <iostream> // library standar IO
using namespace std; // menggunakan standar namespace

class DetailShowroom // deklarasi class DetailShowroom
{
    private: // modifier private
        double luasAreaM2; // deklarasi atribut luas area
        int kapasitasMaks; // deklarasi atribut kapasitas maksimal

    public: // modifier public
        DetailShowroom() // default constructor
        {
            this->luasAreaM2 = 0.0; // nilai awal nol
            this->kapasitasMaks = 0; // nilai awal nol
        }
        
        DetailShowroom(double luas, int maks) // constructor lengkap
        {
            this->luasAreaM2 = luas; // inisialisasi atribut luas area
            this->kapasitasMaks = maks; // inisialisasi atribut kapasitas maksimal
        }

        // --- Setter ---
        void setLuasAreaM2(double luas) { this->luasAreaM2 = luas; } // mengubah value atribut luas area
        void setKapasitasMaks(int maks) { this->kapasitasMaks = maks; } // mengubah value atribut kapasitas maksimal

        // --- Getter ---
        double getLuasAreaM2() const { return luasAreaM2; } // mengembalikan nilai luas area
        int getKapasitasMaks() const { return kapasitasMaks; } // mengembalikan nilai kapasitas maksimal

        // --- Method ---
        void displayDetail() const // menampilkan data detail showroom
        {
            cout << "Luas Area      : " << luasAreaM2 << " m2\n"; // cetak luas area
            cout << "Kapasitas Maks : " << kapasitasMaks << " mobil\n"; // cetak kapasitas maksimal
        }
}; // akhir dari class DetailShowroom
