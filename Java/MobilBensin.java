public class MobilBensin extends Kendaraan { // deklarasi class MobilBensin turunan Kendaraan
    protected int kapasitasMesinCC; // deklarasi atribut kapasitas mesin
    protected double kapasitasTangkiLiter; // deklarasi atribut kapasitas tangki
    protected String jenisBahanBakar; // deklarasi atribut jenis bahan bakar

    public MobilBensin() {} // default constructor
    
    public MobilBensin(String merek, String model, int tahun, int cc, double liter, String bahan) { // constructor lengkap
        super(merek, model, tahun); // memanggil constructor parent
        this.kapasitasMesinCC = cc; // inisialisasi atribut kapasitas mesin
        this.kapasitasTangkiLiter = liter; // inisialisasi atribut kapasitas tangki
        this.jenisBahanBakar = bahan; // inisialisasi atribut jenis bahan bakar
    }

    // --- Setter ---
    public void setKapasitasMesinCC(int cc) { this.kapasitasMesinCC = cc; } // mengubah value atribut kapasitas mesin
    public void setKapasitasTangkiLiter(double liter) { this.kapasitasTangkiLiter = liter; } // mengubah value atribut kapasitas tangki
    public void setJenisBahanBakar(String bahan) { this.jenisBahanBakar = bahan; } // mengubah value atribut jenis bahan bakar

    // --- Getter ---
    public int getKapasitasMesinCC() { return this.kapasitasMesinCC; } // mengembalikan nilai kapasitas mesin
    public double getKapasitasTangkiLiter() { return this.kapasitasTangkiLiter; } // mengembalikan nilai kapasitas tangki
    public String getJenisBahanBakar() { return this.jenisBahanBakar; } // mengembalikan nilai jenis bahan bakar

    // --- Method ---
    public void displayMobilBensin() { // menampilkan data mobil bensin
        this.displayKendaraan(); // panggil method parent
        System.out.println("Kapasitas Mesin: " + this.kapasitasMesinCC + " cc"); // cetak kapasitas mesin
        System.out.println("Kapasitas Tangki: " + this.kapasitasTangkiLiter + " L"); // cetak kapasitas tangki
        System.out.println("Bahan Bakar    : " + this.jenisBahanBakar); // cetak jenis bahan bakar
    }
} // akhir dari class MobilBensin
