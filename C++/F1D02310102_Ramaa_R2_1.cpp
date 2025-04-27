#include <iostream>
using namespace std;

int main() {
    char huruf;
    int angka;
 
    cout << "Masukkan alamat dari rumah fia : ";
    cin >> huruf >> angka;

    if (huruf == 'D') {
        if (angka % 2 != 1){
            cout << "Alamat yang anda masukkan salah";
            return 0;   
        } 
    }
    
    for (char i = 'A'; i <= huruf; ++i) {
        for (int j = 1; j <= 10; ++j) {
            if (i == 'D') {
                if (j % 2 != 0) {
                    cout << "Melewati Rumah " << i << j << "\n";
                }   
            } else {
                cout << "Melewati Rumah " << i << j << "\n";
            }
            
            if (i == huruf && j == angka) {
                cout << "Rumah Fia yaitu "<< huruf << angka << " Berhasil ditemukan!";
                return 0; 
            }
        }  
    }
}
