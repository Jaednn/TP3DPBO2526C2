public class DetailShowroom { // deklarasi class DetailShowroom
    private double luasAreaM2; // deklarasi atribut luas area
    private int kapasitasMaks; // deklarasi atribut kapasitas maksimal

    public DetailShowroom() { // default constructor
        this.luasAreaM2 = 0.0; // nilai awal
        this.kapasitasMaks = 0; // nilai awal
    }
    
    public DetailShowroom(double luas, int maks) { // constructor lengkap
        this.luasAreaM2 = luas; // inisialisasi atribut luas area
        this.kapasitasMaks = maks; // inisialisasi atribut kapasitas maksimal
    }

    // --- Setter ---
    public void setLuasAreaM2(double luas) { this.luasAreaM2 = luas; } // mengubah value atribut luas area
    public void setKapasitasMaks(int maks) { this.kapasitasMaks = maks; } // mengubah value atribut kapasitas maksimal

    // --- Getter ---
    public double getLuasAreaM2() { return this.luasAreaM2; } // mengembalikan nilai luas area
    public int getKapasitasMaks() { return this.kapasitasMaks; } // mengembalikan nilai kapasitas maksimal

    // --- Method ---
    public void displayDetail() { // menampilkan data detail showroom
        System.out.println("Luas Area      : " + this.luasAreaM2 + " m2"); // cetak luas area
        System.out.println("Kapasitas Maks : " + this.kapasitasMaks + " mobil"); // cetak kapasitas maksimal
    }
} // akhir dari class DetailShowroom
