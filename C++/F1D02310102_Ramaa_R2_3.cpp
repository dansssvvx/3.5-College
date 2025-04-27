#include <iostream>
using namespace std;

int main() {
    int kendaraan;
    cout << "Masukkan jumlah kendaraan yang lewat: ";
    cin >> kendaraan;

    int plat[kendaraan];
	int jumgenap = 0;
    int jumganjil = 0;
    int genap = 0;
    int ganjil = 0;
    
    for (int i = 0; i < kendaraan; ++i) {
        cout << "Masukkan nomor plat kendaraan ke-" << i+1 << ": ";
        cin >> plat[i];
        if (plat[i] % 2 == 0){
        	jumgenap += plat[i];
        	genap++;
		} else {
			jumganjil += plat[i];
			ganjil++;
		}
    }

	cout << "Jadi setelah mengamati " << kendaraan << " kendaraan, hasilnya sbb:" << endl;
	cout << "Fajar melihat " << ganjil << " kendaraan berplat ganjil dengan jumlah " << jumganjil << " dan rata-rata " << double (jumganjil) / ganjil << endl;
	cout << "Khalid melihat " << genap << " kendaraan berplat genap dengan jumlah " << jumgenap << " dan rata-rata " << double (jumgenap) /genap << endl;
    
    return 0;
}
