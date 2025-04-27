#include <iostream>
using namespace std;

int main (){
    int banyak;
    cout << "Berapa banyak kata yang mau dicek: "; cin >> banyak;
    string kata, palindrom;
    bool ada = false;
    
    if (!banyak){
    	cout << "Input yang anda masukan haruslah angka!!";
    	return 0;
	}

    for (int i = 0; i < banyak; i++) {
        cout << "Masukkan kata ke-" << i+1 << ": ";
		cin >> kata;
		
        int x = 0;
        int y = kata.length() - 1;
        bool cek = true;
        while (x < y) {
            if (kata[x] != kata[y]) {
                cek = false;
                break;
            }
            x++;
            y--;
        }
        if (cek) {
            ada = true;
            palindrom += kata + "\n";
        }
    }

    if (ada) {
        cout << endl << "Kata yang palindrom: " << endl << palindrom << endl;
	} else {
		cout << "Tidak ada kata palindrom.";
	}

    return 0;	
}
