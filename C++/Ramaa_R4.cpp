#include <iostream>
using namespace std;

void tambahsoal();
void maingame();

int banyaksoal = 0;
string soal[100];
string jawaban[100];

void head(){
	cout << "=====================================" << endl;
	cout << "| QUIZZIZ PAKE S                    |" << endl;
	cout << "| PROGRAM INI DIBUAT OLEH MICHAEL E |" << endl;
	cout << "=====================================" << endl;
}

void menu(){
	system("cls");
	head();
	int pilihan;
	cout << "1. Tambah Soal" << endl << "2. Main" << endl << "3. Keluar" << endl << "Pilihan: "; cin >> pilihan;
	switch(pilihan){
		case 1:
			tambahsoal();
			break;
		case 2:
			maingame();
			break;
		case 3:
			return;
			break;
		default:
			cout << "Pilihan yang anda masukan salah";
	}
}

void tambahsoal(){
	system("cls");
	head();
	string soalinput;
	string jawabaninput;
	char pilihan;

	for (int i = banyaksoal; i <= 100; i++){
		cout << "Soal ke- " << i + 1 << endl;
		cout << "Masukkan soal: " << endl;
		cout << ">>> "; getline(cin >> ws, soalinput);
		soal[i] = soalinput;

		cout << "Masukkan Jawaban: " << endl;
		cout << ">>> " ; getline (cin, jawabaninput);
		jawaban[i] = jawabaninput;
	
		cout << "Masukkan soal lagi(Y/N): " << endl;
		cout << ">>> "; cin >> pilihan;
		
		banyaksoal += 1;
		
		if (pilihan == 'y' || pilihan == 'Y'){
			system("cls");
			head();
		} else if(pilihan == 'n' || pilihan == 'N'){
			menu();
			return;
		} else {
			cout << "pilihan yang anda masukan salah!" << endl;
			cout << "Program akan otomatis kembali ke menu!" << endl;
			system("pause");
			menu();
			return;
		}
	}
}

void maingame(){
	int skor = 0;
	string jawabaninput;
	
	for (int i = 0; i < banyaksoal; i++){
		system("cls");
		head();
		cout << "SOAL KE-" << i+1 << " (Skor saat ini : " << skor << ")" << endl;
		cout << "-------------------------------------" << endl;
		cout << soal[i] << endl;
		cout << "jawab: " << endl;
		cout << ">>> "; getline(cin >> ws, jawabaninput);
		if (jawabaninput == jawaban[i] ){
			cout << "!!SELAMAT JAWABANMU BENAR!!" << endl;
			skor += 1;
			system("pause");
		} else {
			cout << "YAHAHAHA JAWABANMU SALAH" << endl;
			system("pause");
		}
	}
	system("cls");
	head();
	cout << "Permainan selesai!" << endl;
	cout << "Skormu adalah " << skor << "/ " << banyaksoal << endl;
	system("pause");
	menu();
	return;
}

int main(){
	menu();
}