class Kendaraan: # deklarasi class base Kendaraan
    def __init__(self, merek: str, model: str, tahun_produksi: int): # constructor
        self.__merek = merek # inisialisasi atribut merek
        self.__model = model # inisialisasi atribut model
        self.__tahun_produksi = tahun_produksi # inisialisasi atribut tahun_produksi
        
    # --- Setter ---
    def set_merek(self, merek: str): # mengubah value atribut merek
        self.__merek = merek 
        
    def set_model(self, model: str): # mengubah value atribut model
        self.__model = model
        
    def set_tahun_produksi(self, tahun_produksi: int): # mengubah value atribut tahun produksi
        self.__tahun_produksi = tahun_produksi
        
    # --- Getter ---
    def get_merek(self) -> str: # mengembalikan nilai merek
        return self.__merek
        
    def get_model(self) -> str: # mengembalikan nilai model
        return self.__model
        
    def get_tahun_produksi(self) -> int: # mengembalikan nilai tahun produksi
        return self.__tahun_produksi
        
    # --- Method ---
    def display_kendaraan(self): # menampilkan data kendaraan
        print(f"Merek          : {self.__merek}") # cetak merek
        print(f"Model          : {self.__model}") # cetak model
        print(f"Tahun Produksi : {self.__tahun_produksi}") # cetak tahun produksi
