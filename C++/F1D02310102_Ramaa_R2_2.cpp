#include <iostream>
using namespace std;

int main (){
    string pilihan;
    char y;
    int x = 0;
    
    
        cout << "Mau teh atau kopi?" << endl << "Jawab: ";
        cin >> pilihan;
        
        if (pilihan == "teh"){
            do {
				cout << "Memasukkan gula batu....." << endl;
            	cout << "Jumlah gula batu yang sudah dimasukkan: " << ++x << endl;
            	cout << "Apakah mau lagi? (Y/N): ";
            	cin >> y;
            } while (y == 'y' || y == 'Y');
            	if (y == 'n' || y == 'N'){
            		cout << "Jadi minuman yang dipilih indi adalah " << pilihan << endl;
        			cout << pilihan << " yang dipilih indi memiliki " << x << " buah gula batu";	
				} else {
					cout << "input yang anda masukkan salah";
					return 0; 
				}
				
        } else if (pilihan == "kopi"){
            x = -1;
            do{
				cout << "Memasukkan krimer........" << endl;
            	cout << "Jumlah krimer yang sudah dimasukkan: " << (x += 2) << endl;
            	cout << "Apakah mau lagi? (Y/N): ";
            	cin >> y;
        	} while (y == 'y' || y == 'Y');
        		if (y == 'n' || y == 'N'){
            		cout << "Jadi minuman yang dipilih indi adalah " << pilihan << endl;
        			cout << pilihan << " yang dipilih indi memiliki " << x << " sendok krimer";	
				} else {
					cout << "input yang anda masukkan salah";
					return 0; 
				}
				
        } else {
            cout << "Input yang anda masukkan salah" << endl;
            return 0;
        }
    
    return 0;
}
