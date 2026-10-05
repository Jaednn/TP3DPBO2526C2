from Kendaraan import Kendaraan # import class Kendaraan

class MobilListrik(Kendaraan): # deklarasi class MobilListrik yang inherit dari Kendaraan
    def __init__(self, merek: str, model: str, tahun_produksi: int, kapasitas_baterai_kwh: float, tipe_soket_charger: str, daya_motor_listrik_kw: int): # constructor
        Kendaraan.__init__(self, merek, model, tahun_produksi) # memanggil constructor class parent secara eksplisit
        self.__kapasitas_baterai_kwh = kapasitas_baterai_kwh # inisialisasi atribut kapasitas baterai
        self.__tipe_soket_charger = tipe_soket_charger # inisialisasi atribut tipe soket
        self.__daya_motor_listrik_kw = daya_motor_listrik_kw # inisialisasi atribut daya motor listrik
        
    # --- Setter ---
    def set_kapasitas_baterai_kwh(self, kwh: float): # mengubah value atribut kapasitas baterai
        self.__kapasitas_baterai_kwh = kwh
        
    def set_tipe_soket_charger(self, soket: str): # mengubah value atribut tipe soket
        self.__tipe_soket_charger = soket
        
    def set_daya_motor_listrik_kw(self, kw: int): # mengubah value atribut daya motor listrik
        self.__daya_motor_listrik_kw = kw
        
    # --- Getter ---
    def get_kapasitas_baterai_kwh(self) -> float: # mengembalikan nilai kapasitas baterai
        return self.__kapasitas_baterai_kwh
        
    def get_tipe_soket_charger(self) -> str: # mengembalikan nilai tipe soket
        return self.__tipe_soket_charger
        
    def get_daya_motor_listrik_kw(self) -> int: # mengembalikan nilai daya motor listrik
        return self.__daya_motor_listrik_kw
        
    # --- Method ---
    def display_mobil_listrik(self): # menampilkan data mobil listrik
        self.display_kendaraan() # memanggil method display parent
        print(f"Kapasitas Batere: {self.__kapasitas_baterai_kwh} kWh") # cetak kapasitas baterai
        print(f"Tipe Soket     : {self.__tipe_soket_charger}") # cetak tipe soket charger
        print(f"Daya Motor     : {self.__daya_motor_listrik_kw} kW") # cetak daya motor listrik
