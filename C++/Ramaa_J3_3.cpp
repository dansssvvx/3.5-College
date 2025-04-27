#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

int main(){
	
	int banyak;
	char kembangapi[26];
	int radius[26];
	bool meledak[26] = {false};
	
	cout << "Banyak kembang api: "; cin >> banyak;
	if (banyak > 26){
		cout << "Jumlah kembang api yang dimasukkan terlalu banyak! (Max 26)";
		return 0;
	}
	
	for (int i = 0; i < banyak; i++){
		cout << setw(2) << " ? ";
	}
	cout << endl;
	
	for(int i = 0; i < banyak; i++){
		kembangapi[i] = 'A' + i;
	}
	
	for (int i = 0; i < banyak; i++){
		cout << setw(1) << "[" << kembangapi[i] << "]";
	}
	cout << endl;
	
	for (int i = 0; i < banyak; i++){
		radius[i] = getch() - '0';
		cout << setw(1) << " " << radius[i] << " ";
	}
	cout << endl;
	
	char ledak; 
	cout << "Kembang api yang diledakkan (nama kembang api) gunakan UPPERCASE: "; cin >> ledak;
	
	
	for(int i = 0; i < banyak; i++){
		if(kembangapi[i] == ledak){
			meledak[i] = true;
			
			for(int j = i-radius[i]; j <= i+radius[i]; j++){
				if(j >= 0 && j < banyak){
					meledak[j] = true;
				}
			}
			break;
		}
	}
	
	cout << "Jumlah kembang api yang tersisa: " << endl;
	for (int i = 0; i < banyak; i++){
		if(!meledak[i] && radius[i] != 0){
			cout << setw(2) << " ? ";
		}
		else{
			cout << setw(2) << " X ";
		}
	}
	cout << endl;
	
	for (int i = 0; i < banyak; i++){
		if(!meledak[i] && radius[i] != 0){
			cout << setw(1) << "[" << kembangapi[i] << "]";
		}
		else{
			cout << setw(1) << "[ ]";
		}
	}
	cout << endl;
	
	for (int i = 0; i < banyak; i++){
		if(!meledak[i] && radius[i] != 0){
			cout << setw(1) << " " << radius[i] << " ";
		}
		else{
			cout << setw(1) << "   ";
		}
	}
	cout << endl;
	
	return 0;
}
