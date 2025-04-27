#include <iostream>
using namespace std;

int main() {
    string menu[4] = {"Crepes", "Jagung", "Cilok", "Jus"}, input;
    double harga[4] = {12, 12, 5, 7}, total = 0;

    cout << "Masukkan 5 menu sekaligus (diseparate dengan spasi): ";
    for (int i = 0; i < 5; ++i) {
        cin >> input;
        
		if (input[0] > 97 && input[0] < 122){
        	input[0] -= 32; 
		}
		
        bool cek = false;
        for (int j = 0; j < 4; ++j) {
            if (input == menu[j]) {
                total += harga[j];
                cek = true;
                break;
            }
        }
        if (!cek) { 
            total += harga[3];
        }
    }

    cout << "Harga Sebelum Tax : " << total << endl;
    total += total * 0.07;
    cout << "Harga Sesudah Tax : " << total << endl;

    return 0;
}
