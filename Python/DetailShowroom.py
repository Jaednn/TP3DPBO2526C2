class DetailShowroom: # deklarasi class DetailShowroom
    def __init__(self, luas_area_m2: float = 0.0, kapasitas_maks: int = 0): # constructor dengan nilai default
        self.__luas_area_m2 = luas_area_m2 # inisialisasi atribut luas area
        self.__kapasitas_maks = kapasitas_maks # inisialisasi atribut kapasitas maksimal
        
    # --- Setter ---
    def set_luas_area_m2(self, luas: float): # mengubah value atribut luas area
        self.__luas_area_m2 = luas
        
    def set_kapasitas_maks(self, maks: int): # mengubah value atribut kapasitas maksimal
        self.__kapasitas_maks = maks
        
    # --- Getter ---
    def get_luas_area_m2(self) -> float: # mengembalikan nilai luas area
        return self.__luas_area_m2
        
    def get_kapasitas_maks(self) -> int: # mengembalikan nilai kapasitas maksimal
        return self.__kapasitas_maks
        
    # --- Method ---
    def display_detail(self): # menampilkan data detail showroom
        print(f"Luas Area      : {self.__luas_area_m2} m2") # cetak luas area
        print(f"Kapasitas Maks : {self.__kapasitas_maks} mobil") # cetak kapasitas maksimal
