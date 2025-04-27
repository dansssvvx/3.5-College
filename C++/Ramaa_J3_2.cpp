#include <iostream>
using namespace std;

int main(){
	char pesan[8000];
	int key, n = 0;
	
	cout << "Masukkan Pesan: "; cin.getline(pesan, 8000);
	cout << "Masukkan Key Caesar Cipher: "; cin >> key;
	
    while (pesan[n] != '\0') {
        n++;
    }
    char temp;
	for (int i = 0; i < n / 2; i++) {
    	temp = pesan[i];
    	pesan[i] = pesan[n - i - 1];
    	pesan[n - i - 1] = temp;
	}


    cout << "\nHasil enkripsi dengan caesar cipher: " << endl << pesan;

    for (int i = 0; pesan[i] != '\0'; ++i){
        char ch = pesan[i];

        if (ch >= 'a' && ch <= 'z'){
            ch = ch + key;

            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }

            pesan[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z'){
            ch = ch + key;

            if (ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }

            pesan[i] = ch;
        }
    }

    cout << "\nHasil enkripsi dengan reverse cipher + caesar cipher: " << endl << pesan;
		
		return 0;
}
	
                                                                    