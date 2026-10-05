from Showroom import Showroom # import class Showroom
from MobilBensin import MobilBensin # import class MobilBensin
from MobilListrik import MobilListrik # import class MobilListrik
from MobilHybrid import MobilHybrid # import class MobilHybrid

def main(): # fungsi utama program
    # Instansiasi Showroom statis
    showroom = Showroom("Nusantara Auto Gallery", "Jl. Sudirman No. 88, Jakarta Selatan") # membuat objek showroom
    showroom.set_detail_showroom(1500.5, 50) # set komposisi detail showroom
    
    # Inisialisasi Data Dummy
    mobil1 = MobilBensin("Toyota", "Innova Zenix V Gasoline", 2023, 1987, 52.0, "Pertamax (RON 92)") # instansiasi objek mobil bensin
    showroom.add_mobil_bensin(mobil1) # tambahkan ke list showroom
    mobil2 = MobilListrik("Hyundai", "Ioniq 5 Signature Long Range", 2023, 72.6, "CCS2", 160) # instansiasi objek mobil listrik
    showroom.add_mobil_listrik(mobil2) # tambahkan ke list showroom
    mobil3 = MobilHybrid("Toyota", "Prius PHEV GR Sport", 2024, 1987, 43.0, "Pertamax Turbo (RON 98)", 13.6, "Type 2", 120, "Series-Parallel PHEV", 220, 850000000) # instansiasi objek mobil hybrid
    showroom.add_mobil_hybrid(mobil3) # tambahkan ke list showroom

    while True: # loop menu interaktif
        print("\n=== MENU SHOWROOM MOBIL ===") # cetak header menu
        print("1. Lihat Semua Data Mobil") # cetak opsi 1
        print("2. Tambahkan Data Mobil Bensin") # cetak opsi 2
        print("3. Tambahkan Data Mobil Listrik") # cetak opsi 3
        print("4. Tambahkan Data Mobil Hybrid") # cetak opsi 4
        print("5. Hapus Data Mobil") # cetak opsi 5
        print("6. Keluar") # cetak opsi 6
        
        try: # blok try untuk menangkap error input
            pilihan = int(input("Pilih menu: ")) # membaca input angka dari user
        except ValueError: # menangkap error jika input bukan angka
            print("Input tidak valid. Harap masukkan angka.") # cetak pesan error
            continue # skip sisa loop dan mulai dari awal menu
            
        if pilihan == 1: # mengecek jika user memilih opsi 1
            showroom.display_showroom() # memanggil method untuk menampilkan semua isi showroom
        elif pilihan == 2: # mengecek jika user memilih opsi 2
            print("\n-- Tambah Mobil Bensin --") # cetak header tambah data
            merek = input("Merek        : ") # input string merek
            model = input("Model        : ") # input string model
            tahun = int(input("Tahun        : ")) # input int tahun
            cc = int(input("Mesin (cc)   : ")) # input int kapasitas cc
            liter = float(input("Tangki (L)   : ")) # input float kapasitas tangki
            bahan = input("Bahan Bakar  : ") # input string bahan bakar
            baru = MobilBensin(merek, model, tahun, cc, liter, bahan) # instansiasi objek MobilBensin baru
            showroom.add_mobil_bensin(baru) # menambahkan objek baru ke agregasi showroom
            print("Data Mobil Bensin berhasil ditambahkan!") # cetak notifikasi berhasil
        elif pilihan == 3: # mengecek jika user memilih opsi 3
            print("\n-- Tambah Mobil Listrik --") # cetak header tambah data
            merek = input("Merek        : ") # input string merek
            model = input("Model        : ") # input string model
            tahun = int(input("Tahun        : ")) # input int tahun
            kwh = float(input("Baterai (kWh): ")) # input float kapasitas baterai
            soket = input("Tipe Soket   : ") # input string tipe soket
            kw = int(input("Daya (kW)    : ")) # input int daya listrik
            baru = MobilListrik(merek, model, tahun, kwh, soket, kw) # instansiasi objek MobilListrik baru
            showroom.add_mobil_listrik(baru) # menambahkan objek baru ke agregasi showroom
            print("Data Mobil Listrik berhasil ditambahkan!") # cetak notifikasi berhasil
        elif pilihan == 4: # mengecek jika user memilih opsi 4
            print("\n-- Tambah Mobil Hybrid --") # cetak header tambah data
            merek = input("Merek        : ") # input string merek
            model = input("Model        : ") # input string model
            tahun = int(input("Tahun        : ")) # input int tahun
            cc = int(input("Mesin (cc)   : ")) # input int kapasitas cc
            liter = float(input("Tangki (L)   : ")) # input float kapasitas tangki
            bahan = input("Bahan Bakar  : ") # input string bahan bakar
            kwh = float(input("Baterai (kWh): ")) # input float kapasitas baterai
            soket = input("Tipe Soket   : ") # input string tipe soket
            kw = int(input("Daya (kW)    : ")) # input int daya motor
            mode = input("Mode Hybrid  : ") # input string mode berkendara
            hp = int(input("Gabungan (HP): ")) # input int daya gabungan
            harga = float(input("Harga (Rp)   : ")) # input float harga jual
            baru = MobilHybrid(merek, model, tahun, cc, liter, bahan, kwh, soket, kw, mode, hp, harga) # instansiasi objek MobilHybrid baru
            showroom.add_mobil_hybrid(baru) # menambahkan objek baru ke agregasi showroom
            print("Data Mobil Hybrid berhasil ditambahkan!") # cetak notifikasi berhasil
        elif pilihan == 5: # mengecek jika user memilih opsi 5 (hapus)
            print("\n-- Hapus Data Mobil --") # cetak header menu hapus
            print("1. Bensin\n2. Listrik\n3. Hybrid") # opsi list tipe
            try: # blok penanganan input
                tipe = int(input("Pilih tipe (1-3): ")) # input angka pilihan tipe
                index = int(input("Masukkan urutan nomor (index) data yang ingin dihapus: ")) # input index array (1-based)
                if tipe == 1: # jika tipe bensin
                    showroom.hapus_mobil_bensin(index) # memanggil prosedur hapus berdasarkan index
                elif tipe == 2: # jika tipe listrik
                    showroom.hapus_mobil_listrik(index) # memanggil prosedur hapus berdasarkan index
                elif tipe == 3: # jika tipe hybrid
                    showroom.hapus_mobil_hybrid(index) # memanggil prosedur hapus berdasarkan index
                else: # fallback untuk salah pilih tipe
                    print("Tipe tidak valid!") # cetak error
            except ValueError: # fallback untuk error casting input ke int
                print("Input tidak valid!") # cetak error input non angka
        elif pilihan == 6: # mengecek jika user memilih opsi 6
            print("\nTerima kasih telah menggunakan sistem Showroom Nusantara!") # cetak pamitan
            break # menghentikan perulangan tak terbatas secara paksa
        else: # fallback default handling out of range option
            print("Pilihan tidak valid.") # pesan error menu tidak ada

if __name__ == "__main__": # entry point aplikasi
    main() # memanggil fungsi main
