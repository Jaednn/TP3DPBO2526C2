import java.util.ArrayList; // import library ArrayList dinamis

public class Showroom { // deklarasi class Showroom
    private String namaShowroom; // deklarasi atribut nama showroom
    private String alamatLengkap; // deklarasi atribut alamat lengkap
    private DetailShowroom detailShowroom; // deklarasi komposisi DetailShowroom
    private ArrayList<MobilBensin> daftarMobilBensin; // deklarasi list agregasi MobilBensin
    private ArrayList<MobilListrik> daftarMobilListrik; // deklarasi list agregasi MobilListrik
    private ArrayList<MobilHybrid> daftarMobilHybrid; // deklarasi list agregasi MobilHybrid

    public Showroom(String nama, String alamat) { // constructor
        this.namaShowroom = nama; // inisialisasi nama
        this.alamatLengkap = alamat; // inisialisasi alamat
        this.detailShowroom = new DetailShowroom(); // inisialisasi objek komponen
        this.daftarMobilBensin = new ArrayList<>(); // inisialisasi memori array list
        this.daftarMobilListrik = new ArrayList<>(); // inisialisasi memori array list
        this.daftarMobilHybrid = new ArrayList<>(); // inisialisasi memori array list
    }

    // --- Setter ---
    public void setNamaShowroom(String nama) { this.namaShowroom = nama; } // mengubah value atribut nama showroom
    public void setAlamatLengkap(String alamat) { this.alamatLengkap = alamat; } // mengubah value atribut alamat lengkap
    public void setDetailShowroom(double luas, int maks) { // mengubah value atribut objek detail
        this.detailShowroom.setLuasAreaM2(luas); // set luas
        this.detailShowroom.setKapasitasMaks(maks); // set kapasitas
    }

    // --- Getter ---
    public String getNamaShowroom() { return this.namaShowroom; } // mengembalikan nilai nama showroom
    public String getAlamatLengkap() { return this.alamatLengkap; } // mengembalikan nilai alamat lengkap
    public DetailShowroom getDetailShowroom() { return this.detailShowroom; } // mengembalikan object DetailShowroom

    // --- Method ---
    public void addMobilBensin(MobilBensin mobil) { this.daftarMobilBensin.add(mobil); } // menambah objek ke list
    public void addMobilListrik(MobilListrik mobil) { this.daftarMobilListrik.add(mobil); } // menambah objek ke list
    public void addMobilHybrid(MobilHybrid mobil) { this.daftarMobilHybrid.add(mobil); } // menambah objek ke list

    public void hapusMobilBensin(int index) { // hapus objek dari list
        if (index > 0 && index <= this.daftarMobilBensin.size()) {
            this.daftarMobilBensin.remove(index - 1);
            System.out.println("Data Mobil Bensin berhasil dihapus!");
        } else {
            System.out.println("Index tidak valid!");
        }
    }

    public void hapusMobilListrik(int index) { // hapus objek dari list
        if (index > 0 && index <= this.daftarMobilListrik.size()) {
            this.daftarMobilListrik.remove(index - 1);
            System.out.println("Data Mobil Listrik berhasil dihapus!");
        } else {
            System.out.println("Index tidak valid!");
        }
    }

    public void hapusMobilHybrid(int index) { // hapus objek dari list
        if (index > 0 && index <= this.daftarMobilHybrid.size()) {
            this.daftarMobilHybrid.remove(index - 1);
            System.out.println("Data Mobil Hybrid berhasil dihapus!");
        } else {
            System.out.println("Index tidak valid!");
        }
    }

    public void displayShowroom() { // menampilkan keseluruhan isi showroom
        System.out.println("========================================"); // cetak garis pemisah
        System.out.println("INFORMASI SHOWROOM"); // cetak judul
        System.out.println("========================================"); // cetak garis pemisah
        System.out.println("Nama Showroom  : " + this.namaShowroom); // cetak nama
        System.out.println("Alamat Lengkap : " + this.alamatLengkap); // cetak alamat
        this.detailShowroom.displayDetail(); // panggil method objek komponen
        
        System.out.println("\n--- DAFTAR MOBIL BENSIN ---"); // cetak sub-judul
        if (this.daftarMobilBensin.isEmpty()) System.out.println("Kosong"); // handling empty list
        for (int i = 0; i < this.daftarMobilBensin.size(); i++) { // looping
            System.out.println("[" + (i + 1) + "]"); // cetak nomor urut
            this.daftarMobilBensin.get(i).displayMobilBensin(); // panggil method item
        }

        System.out.println("\n--- DAFTAR MOBIL LISTRIK ---"); // cetak sub-judul
        if (this.daftarMobilListrik.isEmpty()) System.out.println("Kosong"); // handling empty list
        for (int i = 0; i < this.daftarMobilListrik.size(); i++) { // looping
            System.out.println("[" + (i + 1) + "]"); // cetak nomor urut
            this.daftarMobilListrik.get(i).displayMobilListrik(); // panggil method item
        }

        System.out.println("\n--- DAFTAR MOBIL HYBRID ---"); // cetak sub-judul
        if (this.daftarMobilHybrid.isEmpty()) System.out.println("Kosong"); // handling empty list
        for (int i = 0; i < this.daftarMobilHybrid.size(); i++) { // looping
            System.out.println("[" + (i + 1) + "]"); // cetak nomor urut
            this.daftarMobilHybrid.get(i).displayMobilHybrid(); // panggil method item
        }
        System.out.println("========================================"); // cetak garis pemisah akhir
    }
} // akhir dari class Showroom
