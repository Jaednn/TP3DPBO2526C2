from Kendaraan import Kendaraan # import class Kendaraan

class MobilBensin(Kendaraan): # deklarasi class MobilBensin yang inherit dari Kendaraan
    def __init__(self, merek: str, model: str, tahun_produksi: int, kapasitas_mesin_cc: int, kapasitas_tangki_liter: float, jenis_bahan_bakar: str): # constructor
        Kendaraan.__init__(self, merek, model, tahun_produksi) # memanggil constructor class parent secara eksplisit
        self.__kapasitas_mesin_cc = kapasitas_mesin_cc # inisialisasi atribut kapasitas mesin
        self.__kapasitas_tangki_liter = kapasitas_tangki_liter # inisialisasi atribut kapasitas tangki
        self.__jenis_bahan_bakar = jenis_bahan_bakar # inisialisasi atribut jenis bahan bakar
        
    # --- Setter ---
    def set_kapasitas_mesin_cc(self, cc: int): # mengubah value atribut kapasitas mesin
        self.__kapasitas_mesin_cc = cc
        
    def set_kapasitas_tangki_liter(self, liter: float): # mengubah value atribut kapasitas tangki
        self.__kapasitas_tangki_liter = liter
        
    def set_jenis_bahan_bakar(self, bahan: str): # mengubah value atribut jenis bahan bakar
        self.__jenis_bahan_bakar = bahan
        
    # --- Getter ---
    def get_kapasitas_mesin_cc(self) -> int: # mengembalikan nilai kapasitas mesin
        return self.__kapasitas_mesin_cc
        
    def get_kapasitas_tangki_liter(self) -> float: # mengembalikan nilai kapasitas tangki
        return self.__kapasitas_tangki_liter
        
    def get_jenis_bahan_bakar(self) -> str: # mengembalikan nilai jenis bahan bakar
        return self.__jenis_bahan_bakar
        
    # --- Method ---
    def display_mobil_bensin(self): # menampilkan data mobil bensin
        self.display_kendaraan() # memanggil method display parent
        print(f"Kapasitas Mesin: {self.__kapasitas_mesin_cc} cc") # cetak kapasitas mesin
        print(f"Kapasitas Tangki: {self.__kapasitas_tangki_liter} L") # cetak kapasitas tangki
        print(f"Bahan Bakar    : {self.__jenis_bahan_bakar}") # cetak jenis bahan bakar
