#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int main () {
	int baris;
	int kolom;
	
	cout << "====================== BERMAIN DENGAN MATRIKS ======================" << endl;
	cout << "Masukkan Jumlah Baris Matriks: "; cin >> baris; 
	cout << "Masukkan Jumlah Kolom Matriks: "; cin >> kolom;
	cout << "Masukkan Elemen Matriks: " << endl;
	int elemen[baris][kolom];
    for(int i = 0; i < baris; i++){
        for(int j = 0; j < kolom; j++){
            cin >> elemen[i][j];
        }
    }
	
	if (baris %2 == 0 && kolom %2 == 0){
		cout << "\nHasil Rotasi 90 Derajat Searah Jarum Jam: "<< endl;	
    	for (int i = 0 ; i < baris ; i++){
        	for (int j = kolom - 1; j >= 0 ; j-- ){
            	cout << elemen[j][i] << " ";
        	}
        	cout << endl;
    	}

    	cout << "\nHasil Pencerminan Terhadap Sumbu X: " << endl;
    	for (int i = baris - 1; i >= 0; i--){
        	for (int j = kolom - 1; j >= 0; j--){
            	cout << elemen[i][j] << " ";
        	}
        	cout << endl;
    	}
    		
	} else if (baris %2 == 1 && kolom %2 == 1){
		cout << "\nHasil Rotasi 90 Derajat Searah Jarum Jam: "<< endl;	
		for (int i = 0 ; i < baris ; i++){
        	for (int j = kolom - 1; j >= 0 ; j-- ){
            	cout << elemen[i][j] << " ";
        	}
        	cout << endl;
		}
		
		cout << "\nHasil Pencerminan Terhadap Sumbu X: " << endl;
		for (int i = baris - 1; i >= 0; i--){
			for (int j = kolom - 1; j >= 0; j--){
				cout << elemen[i][j] << " ";
			}
			cout << endl;
		}

	} else {
		cout << "\nBaris dan kolom yang anda masukkan kurang tepat!.";
	}

}

	