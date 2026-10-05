from MobilBensin import MobilBensin # import class MobilBensin
from MobilListrik import MobilListrik # import class MobilListrik

class MobilHybrid(MobilBensin, MobilListrik): # deklarasi class turunan ganda (Multiple Inheritance)
    def __init__(self, merek: str, model: str, tahun_produksi: int, 
                 kapasitas_mesin_cc: int, kapasitas_tangki_liter: float, jenis_bahan_bakar: str,
                 kapasitas_baterai_kwh: float, tipe_soket_charger: str, daya_motor_listrik_kw: int,
                 mode_berkendara: str, daya_gabungan_hp: int, harga: float): # constructor parameter lengkap
        # Inisialisasi parent classes
        MobilBensin.__init__(self, merek, model, tahun_produksi, kapasitas_mesin_cc, kapasitas_tangki_liter, jenis_bahan_bakar) # memanggil constructor MobilBensin
        MobilListrik.__init__(self, merek, model, tahun_produksi, kapasitas_baterai_kwh, tipe_soket_charger, daya_motor_listrik_kw) # memanggil constructor MobilListrik
        
        self.__mode_berkendara = mode_berkendara # inisialisasi atribut mode berkendara
        self.__daya_gabungan_hp = daya_gabungan_hp # inisialisasi atribut daya gabungan
        self.__harga = harga # inisialisasi atribut harga
        
    # --- Setter ---
    def set_mode_berkendara(self, mode: str): # mengubah value atribut mode berkendara
        self.__mode_berkendara = mode
        
    def set_daya_gabungan_hp(self, hp: int): # mengubah value atribut daya gabungan
        self.__daya_gabungan_hp = hp
        
    def set_harga(self, harga: float): # mengubah value atribut harga
        self.__harga = harga
        
    # --- Getter ---
    def get_mode_berkendara(self) -> str: # mengembalikan nilai mode berkendara
        return self.__mode_berkendara
        
    def get_daya_gabungan_hp(self) -> int: # mengembalikan nilai daya gabungan
        return self.__daya_gabungan_hp
        
    def get_harga(self) -> float: # mengembalikan nilai harga
        return self.__harga
        
    # --- Method ---
    def display_mobil_hybrid(self): # menampilkan data mobil hybrid
        # Menampilkan data dari semua parent
        self.display_kendaraan() # memanggil method display base class
        print(f"Kapasitas Mesin: {self.get_kapasitas_mesin_cc()} cc") # cetak kapasitas mesin
        print(f"Kapasitas Tangki: {self.get_kapasitas_tangki_liter()} L") # cetak kapasitas tangki
        print(f"Bahan Bakar    : {self.get_jenis_bahan_bakar()}") # cetak jenis bahan bakar
        print(f"Kapasitas Batere: {self.get_kapasitas_baterai_kwh()} kWh") # cetak kapasitas baterai
        print(f"Tipe Soket     : {self.get_tipe_soket_charger()}") # cetak tipe soket charger
        print(f"Daya Motor     : {self.get_daya_motor_listrik_kw()} kW") # cetak daya motor listrik
        print(f"Mode Berkendara: {self.__mode_berkendara}") # cetak mode berkendara
        print(f"Daya Gabungan  : {self.__daya_gabungan_hp} HP") # cetak daya gabungan
        print(f"Harga (Rp)     : {self.__harga}") # cetak harga
