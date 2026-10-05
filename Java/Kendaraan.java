public class Kendaraan { // deklarasi class base Kendaraan
    protected String merek; // deklarasi atribut merek
    protected String model; // deklarasi atribut model
    protected int tahunProduksi; // deklarasi atribut tahun produksi

    public Kendaraan() {} // default constructor kosong
    
    public Kendaraan(String merek, String model, int tahunProduksi) { // constructor lengkap
        this.merek = merek; // inisialisasi atribut merek
        this.model = model; // inisialisasi atribut model
        this.tahunProduksi = tahunProduksi; // inisialisasi atribut tahun produksi
    }

    // --- Setter ---
    public void setMerek(String merek) { this.merek = merek; } // mengubah value atribut merek
    public void setModel(String model) { this.model = model; } // mengubah value atribut model
    public void setTahunProduksi(int tahun) { this.tahunProduksi = tahun; } // mengubah value atribut tahun produksi

    // --- Getter ---
    public String getMerek() { return this.merek; } // mengembalikan nilai merek
    public String getModel() { return this.model; } // mengembalikan nilai model
    public int getTahunProduksi() { return this.tahunProduksi; } // mengembalikan nilai tahun produksi

    // --- Method ---
    public void displayKendaraan() { // menampilkan data kendaraan
        System.out.println("Merek          : " + this.merek); // cetak merek
        System.out.println("Model          : " + this.model); // cetak model
        System.out.println("Tahun Produksi : " + this.tahunProduksi); // cetak tahun produksi
    }
} // akhir dari class Kendaraan
