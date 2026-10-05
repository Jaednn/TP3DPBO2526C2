// Catatan: Java tidak mendukung multiple inheritance secara langsung untuk class.
// Oleh karena itu, class ini meng-extends MobilBensin, dan menduplikasi atribut MobilListrik.
public class MobilHybrid extends MobilBensin { // deklarasi class MobilHybrid turunan MobilBensin
    // Atribut duplikat dari MobilListrik karena limitasi single inheritance Java
    private double kapasitasBateraikWh; // deklarasi atribut kapasitas baterai
    private String tipeSoketCharger; // deklarasi atribut tipe soket
    private int dayaMotorListrikKW; // deklarasi atribut daya motor listrik
    
    // Atribut spesifik MobilHybrid
    private String modeBerkendara; // deklarasi atribut mode berkendara
    private int dayaGabunganHP; // deklarasi atribut daya gabungan
    private double harga; // deklarasi atribut harga

    public MobilHybrid() {} // default constructor
    
    public MobilHybrid(String merek, String model, int tahun, 
                       int cc, double liter, String bahan,
                       double kwh, String soket, int kw,
                       String mode, int hp, double harga) { // constructor lengkap
        super(merek, model, tahun, cc, liter, bahan); // memanggil constructor parent (MobilBensin)
        
        // Inisialisasi atribut listrik
        this.kapasitasBateraikWh = kwh; // inisialisasi atribut kapasitas baterai
        this.tipeSoketCharger = soket; // inisialisasi atribut tipe soket
        this.dayaMotorListrikKW = kw; // inisialisasi atribut daya motor listrik
        
        // Inisialisasi atribut hybrid
        this.modeBerkendara = mode; // inisialisasi atribut mode berkendara
        this.dayaGabunganHP = hp; // inisialisasi atribut daya gabungan
        this.harga = harga; // inisialisasi atribut harga
    }

    // --- Setter --- (listrik)
    public void setKapasitasBateraikWh(double kwh) { this.kapasitasBateraikWh = kwh; } // mengubah value atribut kapasitas baterai
    public void setTipeSoketCharger(String soket) { this.tipeSoketCharger = soket; } // mengubah value atribut tipe soket
    public void setDayaMotorListrikKW(int kw) { this.dayaMotorListrikKW = kw; } // mengubah value atribut daya motor listrik

    // --- Getter --- (listrik)
    public double getKapasitasBateraikWh() { return this.kapasitasBateraikWh; } // mengembalikan nilai kapasitas baterai
    public String getTipeSoketCharger() { return this.tipeSoketCharger; } // mengembalikan nilai tipe soket
    public int getDayaMotorListrikKW() { return this.dayaMotorListrikKW; } // mengembalikan nilai daya motor listrik

    // --- Setter --- (hybrid)
    public void setModeBerkendara(String mode) { this.modeBerkendara = mode; } // mengubah value atribut mode berkendara
    public void setDayaGabunganHP(int hp) { this.dayaGabunganHP = hp; } // mengubah value atribut daya gabungan
    public void setHarga(double harga) { this.harga = harga; } // mengubah value atribut harga

    // --- Getter --- (hybrid)
    public String getModeBerkendara() { return this.modeBerkendara; } // mengembalikan nilai mode berkendara
    public int getDayaGabunganHP() { return this.dayaGabunganHP; } // mengembalikan nilai daya gabungan
    public double getHarga() { return this.harga; } // mengembalikan nilai harga

    // --- Method ---
    public void displayMobilHybrid() { // menampilkan data mobil hybrid
        this.displayKendaraan(); // panggil method display Kendaraan
        System.out.println("Kapasitas Mesin: " + this.kapasitasMesinCC + " cc"); // cetak kapasitas mesin
        System.out.println("Kapasitas Tangki: " + this.kapasitasTangkiLiter + " L"); // cetak kapasitas tangki
        System.out.println("Bahan Bakar    : " + this.jenisBahanBakar); // cetak jenis bahan bakar
        System.out.println("Kapasitas Batere: " + this.kapasitasBateraikWh + " kWh"); // cetak kapasitas baterai
        System.out.println("Tipe Soket     : " + this.tipeSoketCharger); // cetak tipe soket
        System.out.println("Daya Motor     : " + this.dayaMotorListrikKW + " kW"); // cetak daya motor listrik
        System.out.println("Mode Berkendara: " + this.modeBerkendara); // cetak mode berkendara
        System.out.println("Daya Gabungan  : " + this.dayaGabunganHP + " HP"); // cetak daya gabungan
        System.out.println("Harga (Rp)     : " + this.harga); // cetak harga
    }
} // akhir dari class MobilHybrid
