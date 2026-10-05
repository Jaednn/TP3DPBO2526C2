import java.util.Scanner; // import utilitas scanner input IO

public class Main { // deklarasi class Main tempat eksekusi program
    public static void main(String[] args) { // fungsi utama entry point
        // Instansiasi Showroom statis
        Showroom showroom = new Showroom("Nusantara Auto Gallery", "Jl. Sudirman No. 88, Jakarta Selatan"); // instansiasi
                                                                                                            // objek
        showroom.setDetailShowroom(1500.5, 50); // set objek komponen detail showroom

        // Dummy 1: Mobil Bensin
        MobilBensin mBensin = new MobilBensin("Toyota", "Innova Zenix V Gasoline", 2023, 1987, 52.0,
                "Pertamax (RON 92)"); // instansiasi
        showroom.addMobilBensin(mBensin); // masuk ke agregasi

        // Dummy 2: Mobil Listrik
        MobilListrik mListrik = new MobilListrik("Hyundai", "Ioniq 5 Signature Long Range", 2023, 72.6, "CCS2", 160); // instansiasi
        showroom.addMobilListrik(mListrik); // masuk ke agregasi

        // Dummy 3: Mobil Hybrid
        MobilHybrid mHybrid = new MobilHybrid("Toyota", "Prius PHEV GR Sport", 2024, 1987, 43.0,
                "Pertamax Turbo (RON 98)", 13.6, "Type 2", 120, "Series-Parallel PHEV", 220, 850000000); // instansiasi
        showroom.addMobilHybrid(mHybrid); // masuk ke agregasi

        Scanner sc = new Scanner(System.in); // inisialisasi scanner input
        int pilihan = 0; // deklarasi pilihan

        do { // loop perulangan setidaknya sekali
            System.out.println("\n=== MENU SHOWROOM MOBIL ==="); // header menu
            System.out.println("1. Lihat Semua Data Mobil"); // opsi 1
            System.out.println("2. Tambahkan Data Mobil Bensin"); // opsi 2
            System.out.println("3. Tambahkan Data Mobil Listrik"); // opsi 3
            System.out.println("4. Tambahkan Data Mobil Hybrid"); // opsi 4
            System.out.println("5. Hapus Data Mobil"); // opsi 5
            System.out.println("6. Keluar"); // opsi 6
            System.out.print("Pilih menu: "); // cetak dialog masukan

            if (sc.hasNextInt()) { // jika tipe input valid (angka)
                pilihan = sc.nextInt(); // baca masukan integer
                sc.nextLine(); // consume sisa enter (newline buffer)
            } else { // handling error string
                System.out.println("Input tidak valid. Harap masukkan angka."); // cetak peringatan
                sc.next(); // buang token kotor
                continue; // paksa iterasi berikutnya
            }

            if (pilihan == 1) { // menu lihat data
                showroom.displayShowroom(); // panggil cetak
            } else if (pilihan == 2) { // tambah bensin
                System.out.println("\n-- Tambah Mobil Bensin --"); // info header
                System.out.print("Merek        : ");
                String merek = sc.nextLine(); // baca token string
                System.out.print("Model        : ");
                String model = sc.nextLine(); // baca token string
                System.out.print("Tahun        : ");
                int tahun = sc.nextInt(); // input angka
                System.out.print("Mesin (cc)   : ");
                int cc = sc.nextInt(); // input angka
                System.out.print("Tangki (L)   : ");
                double liter = sc.nextDouble(); // input pecahan
                sc.nextLine(); // konsumsi buffer sisa
                System.out.print("Bahan Bakar  : ");
                String bahan = sc.nextLine(); // baca sisa kalimat raw
                MobilBensin baru = new MobilBensin(merek, model, tahun, cc, liter, bahan); // generate instance
                showroom.addMobilBensin(baru); // panggil function add
                System.out.println("Data Mobil Bensin berhasil ditambahkan!"); // pesan berhasil
            } else if (pilihan == 3) { // tambah listrik
                System.out.println("\n-- Tambah Mobil Listrik --"); // info header
                System.out.print("Merek        : ");
                String merek = sc.nextLine(); // baca token string
                System.out.print("Model        : ");
                String model = sc.nextLine(); // baca token string
                System.out.print("Tahun        : ");
                int tahun = sc.nextInt(); // input angka
                System.out.print("Baterai (kWh): ");
                double kwh = sc.nextDouble(); // input pecahan
                sc.nextLine(); // konsumsi buffer sisa
                System.out.print("Tipe Soket   : ");
                String soket = sc.nextLine(); // baca token string
                System.out.print("Daya (kW)    : ");
                int kw = sc.nextInt(); // input angka
                MobilListrik baru = new MobilListrik(merek, model, tahun, kwh, soket, kw); // generate instance
                showroom.addMobilListrik(baru); // panggil add method
                System.out.println("Data Mobil Listrik berhasil ditambahkan!"); // pesan operasi sukses
            } else if (pilihan == 4) { // tambah hybrid
                System.out.println("\n-- Tambah Mobil Hybrid --"); // info header
                System.out.print("Merek        : ");
                String merek = sc.nextLine(); // baca baris string
                System.out.print("Model        : ");
                String model = sc.nextLine(); // baca baris string
                System.out.print("Tahun        : ");
                int tahun = sc.nextInt(); // input bil bulat
                System.out.print("Mesin (cc)   : ");
                int cc = sc.nextInt(); // input bil bulat
                System.out.print("Tangki (L)   : ");
                double liter = sc.nextDouble(); // input bil pecahan
                sc.nextLine(); // handle residual char
                System.out.print("Bahan Bakar  : ");
                String bahan = sc.nextLine(); // input teks bebas
                System.out.print("Baterai (kWh): ");
                double kwh = sc.nextDouble(); // input pecahan
                sc.nextLine(); // skip newline flag
                System.out.print("Tipe Soket   : ");
                String soket = sc.nextLine(); // masukan terminal baca raw string
                System.out.print("Daya (kW)    : ");
                int kw = sc.nextInt(); // number primitive scanner
                sc.nextLine(); // empty buffer enter return
                System.out.print("Mode Hybrid  : ");
                String mode = sc.nextLine(); // teks line terminal
                System.out.print("Gabungan (HP): ");
                int hp = sc.nextInt(); // bilangan 10
                System.out.print("Harga (Rp)   : ");
                double harga = sc.nextDouble(); // double mem
                MobilHybrid baru = new MobilHybrid(merek, model, tahun, cc, liter, bahan, kwh, soket, kw, mode, hp,
                        harga); // class constructor instance init
                showroom.addMobilHybrid(baru); // agregasi operasi assign
                System.out.println("Data Mobil Hybrid berhasil ditambahkan!"); // printout sukses report
            } else if (pilihan == 5) { // aksi delete index array item
                System.out.println("\n-- Hapus Data Mobil --"); // UI text header menu
                System.out.println("1. Bensin\n2. Listrik\n3. Hybrid"); // option list string format prompt
                System.out.print("Pilih tipe (1-3): "); // display promt form
                int tipe = sc.nextInt(); // prompt logic
                System.out.print("Masukkan urutan nomor (index) data yang ingin dihapus: "); // pesan aksi lanjutan menu
                                                                                             // flow
                int index = sc.nextInt(); // terminal listen event wait num loop
                if (tipe == 1)
                    showroom.hapusMobilBensin(index); // if selection call func params arg
                else if (tipe == 2)
                    showroom.hapusMobilListrik(index); // condition evaluate params index deletion operation function
                else if (tipe == 3)
                    showroom.hapusMobilHybrid(index); // true handler deletion void param idx
                else
                    System.out.println("Tipe tidak valid!"); // output handle miss input false index range form prompt
            } else if (pilihan != 6) { // kondisi default guard switch out of scope case error
                System.out.println("Pilihan tidak valid."); // message cetak stdout err terminal io text out display
                                                            // char print console return stream end ln newline return
                                                            // loop
            }
        } while (pilihan != 6); // terminasi proses loop break point exit exit(0) out loop scope iter while
                                // false kondisi false do

        System.out.println("\nTerima kasih telah menggunakan sistem Showroom Nusantara!"); // pesan salam akhir proses
                                                                                           // system terminal command
                                                                                           // out log EOF
        sc.close(); // destroy io reader garbage collector
    } // akhir scope fungsi
} // akhir class main
