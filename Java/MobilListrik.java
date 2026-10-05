public class MobilListrik extends Kendaraan { // deklarasi class MobilListrik turunan Kendaraan
    protected double kapasitasBateraikWh; // deklarasi atribut kapasitas baterai
    protected String tipeSoketCharger; // deklarasi atribut tipe soket
    protected int dayaMotorListrikKW; // deklarasi atribut daya motor listrik

    public MobilListrik() {} // default constructor
    
    public MobilListrik(String merek, String model, int tahun, double kwh, String soket, int kw) { // constructor lengkap
        super(merek, model, tahun); // memanggil constructor parent
        this.kapasitasBateraikWh = kwh; // inisialisasi atribut kapasitas baterai
        this.tipeSoketCharger = soket; // inisialisasi atribut tipe soket
        this.dayaMotorListrikKW = kw; // inisialisasi atribut daya motor listrik
    }

    // --- Setter ---
    public void setKapasitasBateraikWh(double kwh) { this.kapasitasBateraikWh = kwh; } // mengubah value atribut kapasitas baterai
    public void setTipeSoketCharger(String soket) { this.tipeSoketCharger = soket; } // mengubah value atribut tipe soket
    public void setDayaMotorListrikKW(int kw) { this.dayaMotorListrikKW = kw; } // mengubah value atribut daya motor listrik

    // --- Getter ---
    public double getKapasitasBateraikWh() { return this.kapasitasBateraikWh; } // mengembalikan nilai kapasitas baterai
    public String getTipeSoketCharger() { return this.tipeSoketCharger; } // mengembalikan nilai tipe soket
    public int getDayaMotorListrikKW() { return this.dayaMotorListrikKW; } // mengembalikan nilai daya motor listrik

    // --- Method ---
    public void displayMobilListrik() { // menampilkan data mobil listrik
        this.displayKendaraan(); // panggil method parent
        System.out.println("Kapasitas Batere: " + this.kapasitasBateraikWh + " kWh"); // cetak kapasitas baterai
        System.out.println("Tipe Soket     : " + this.tipeSoketCharger); // cetak tipe soket
        System.out.println("Daya Motor     : " + this.dayaMotorListrikKW + " kW"); // cetak daya motor listrik
    }
} // akhir dari class MobilListrik
