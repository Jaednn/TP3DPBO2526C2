from MobilBensin import MobilBensin # import class MobilBensin
from MobilListrik import MobilListrik # import class MobilListrik
from MobilHybrid import MobilHybrid # import class MobilHybrid
from DetailShowroom import DetailShowroom # import class DetailShowroom

class Showroom: # deklarasi class Showroom
    def __init__(self, nama_showroom: str, alamat: str): # constructor
        self.__nama_showroom = nama_showroom # inisialisasi atribut nama showroom
        self.__alamat = alamat # inisialisasi atribut alamat
        self.__detail_showroom = DetailShowroom() # inisialisasi komposisi DetailShowroom
        self.__daftar_mobil_bensin = [] # inisialisasi list (agregasi) mobil bensin
        self.__daftar_mobil_listrik = [] # inisialisasi list (agregasi) mobil listrik
        self.__daftar_mobil_hybrid = [] # inisialisasi list (agregasi) mobil hybrid
        
    # --- Setter ---
    def set_nama_showroom(self, nama: str): # mengubah value atribut nama showroom
        self.__nama_showroom = nama
        
    def set_alamat(self, alamat: str): # mengubah value atribut alamat
        self.__alamat = alamat
        
    def set_detail_showroom(self, luas: float, maks: int): # mengubah value komposisi DetailShowroom
        self.__detail_showroom.set_luas_area_m2(luas) # atur luas
        self.__detail_showroom.set_kapasitas_maks(maks) # atur kapasitas
        
    # --- Getter ---
    def get_nama_showroom(self) -> str: # mengembalikan nilai nama showroom
        return self.__nama_showroom
        
    def get_alamat(self) -> str: # mengembalikan nilai alamat
        return self.__alamat
        
    def get_detail_showroom(self) -> DetailShowroom: # mengembalikan object DetailShowroom
        return self.__detail_showroom
        
    # --- Method ---
    def add_mobil_bensin(self, mobil: MobilBensin): # menambah objek MobilBensin ke list
        self.__daftar_mobil_bensin.append(mobil) # push/append ke list
        
    def add_mobil_listrik(self, mobil: MobilListrik): # menambah objek MobilListrik ke list
        self.__daftar_mobil_listrik.append(mobil) # push/append ke list
        
    def add_mobil_hybrid(self, mobil: MobilHybrid): # menambah objek MobilHybrid ke list
        self.__daftar_mobil_hybrid.append(mobil) # push/append ke list
        
    def hapus_mobil_bensin(self, index: int): # menghapus berdasarkan index (1-based)
        if 0 < index <= len(self.__daftar_mobil_bensin):
            del self.__daftar_mobil_bensin[index-1]
            print("Data Mobil Bensin berhasil dihapus!")
        else:
            print("Index tidak valid!")
            
    def hapus_mobil_listrik(self, index: int): # menghapus berdasarkan index (1-based)
        if 0 < index <= len(self.__daftar_mobil_listrik):
            del self.__daftar_mobil_listrik[index-1]
            print("Data Mobil Listrik berhasil dihapus!")
        else:
            print("Index tidak valid!")
            
    def hapus_mobil_hybrid(self, index: int): # menghapus berdasarkan index (1-based)
        if 0 < index <= len(self.__daftar_mobil_hybrid):
            del self.__daftar_mobil_hybrid[index-1]
            print("Data Mobil Hybrid berhasil dihapus!")
        else:
            print("Index tidak valid!")

    def display_showroom(self): # menampilkan data keseluruhan showroom
        print("="*40) # cetak garis pemisah
        print("INFORMASI SHOWROOM") # cetak judul
        print("="*40) # cetak garis pemisah
        print(f"Nama Showroom  : {self.__nama_showroom}") # cetak nama showroom
        print(f"Alamat Lengkap : {self.__alamat}") # cetak alamat showroom
        self.__detail_showroom.display_detail() # memanggil display dari DetailShowroom
        
        print("\n--- DAFTAR MOBIL BENSIN ---") # cetak judul list bensin
        if not self.__daftar_mobil_bensin: print("Kosong") # cek jika list kosong
        for i, mobil in enumerate(self.__daftar_mobil_bensin): # looping data mobil bensin
            print(f"[{i+1}]") # cetak nomor urut
            mobil.display_mobil_bensin() # panggil method display_mobil_bensin
            
        print("\n--- DAFTAR MOBIL LISTRIK ---") # cetak judul list listrik
        if not self.__daftar_mobil_listrik: print("Kosong") # cek jika list kosong
        for i, mobil in enumerate(self.__daftar_mobil_listrik): # looping data mobil listrik
            print(f"[{i+1}]") # cetak nomor urut
            mobil.display_mobil_listrik() # panggil method display_mobil_listrik
            
        print("\n--- DAFTAR MOBIL HYBRID ---") # cetak judul list hybrid
        if not self.__daftar_mobil_hybrid: print("Kosong") # cek jika list kosong
        for i, mobil in enumerate(self.__daftar_mobil_hybrid): # looping data mobil hybrid
            print(f"[{i+1}]") # cetak nomor urut
            mobil.display_mobil_hybrid() # panggil method display_mobil_hybrid
        print("="*40) # cetak garis pemisah
