#pragma once // mencegah double inclusion
#pragma GCC diagnostic ignored "-Wvirtual-move-assign" // mengabaikan warning bawaan g++ terkait operasi hapus vector pada virtual inheritance
#include "Kendaraan.cpp" // import parent class

// menggunakan virtual inheritance untuk mengatasi diamond problem pada hybrid inheritance
class MobilBensin : virtual public Kendaraan // deklarasi class MobilBensin
{
    protected: // modifier protected
        int kapasitasMesinCC; // deklarasi atribut kapasitas mesin
        double kapasitasTangkiLiter; // deklarasi atribut kapasitas tangki
        string jenisBahanBakar; // deklarasi atribut jenis bahan bakar

    public: // modifier public
        MobilBensin() {} // default constructor
        
        MobilBensin(string merek, string model, int tahun, int cc, double liter, string bahan) // constructor lengkap
            : Kendaraan(merek, model, tahun) // memanggil constructor parent
        {
            this->kapasitasMesinCC = cc; // inisialisasi atribut kapasitas mesin
            this->kapasitasTangkiLiter = liter; // inisialisasi atribut kapasitas tangki
            this->jenisBahanBakar = bahan; // inisialisasi atribut jenis bahan bakar
        }

        // --- Setter ---
        void setKapasitasMesinCC(int cc) { this->kapasitasMesinCC = cc; } // mengubah value atribut kapasitas mesin
        void setKapasitasTangkiLiter(double liter) { this->kapasitasTangkiLiter = liter; } // mengubah value atribut kapasitas tangki
        void setJenisBahanBakar(const string& bahan) { this->jenisBahanBakar = bahan; } // mengubah value atribut jenis bahan bakar

        // --- Getter ---
        int getKapasitasMesinCC() const { return kapasitasMesinCC; } // mengembalikan nilai kapasitas mesin
        double getKapasitasTangkiLiter() const { return kapasitasTangkiLiter; } // mengembalikan nilai kapasitas tangki
        string getJenisBahanBakar() const { return jenisBahanBakar; } // mengembalikan nilai jenis bahan bakar

        // --- Method ---
        void displayMobilBensin() const // menampilkan data mobil bensin
        {
            displayKendaraan(); // panggil method parent
            cout << "Kapasitas Mesin: " << kapasitasMesinCC << " cc\n"; // cetak kapasitas mesin
            cout << "Kapasitas Tangki: " << kapasitasTangkiLiter << " L\n"; // cetak kapasitas tangki
            cout << "Bahan Bakar    : " << jenisBahanBakar << "\n"; // cetak jenis bahan bakar
        }
}; // akhir dari class MobilBensin
