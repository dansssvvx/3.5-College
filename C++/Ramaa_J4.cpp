#include <iostream>
using namespace std;

int banyakgerbong;
char b = 'B';
int penumpang = 0;

struct KAP{
	char gerbong[26];
	
	struct KAP2{
		string kelas[3] ={"EKONOMI", "BISNIS", "RAJA"};
	};
	
};

//struct KAP2 ekonomi, bisnis, raja;
struct KAP kereta;

void info();
void menu();
void inputgerbong();
void tambahpenumpang();

void head(){
	cout << " /\\_/\\  PT KAP (KERETA API PEMROGRAMMER)\n";
	cout << "( o.o ) PROGRAM SISTEM TIKET DAN GERBONG KERETA\n";
	cout << " > ^ <  DIBUAT OLEH PJ MODUL 5 ALPRO 2024\n";
	for (int i = 0; i < 47; i++){
		cout << "=";	
	}
	cout << "\n";
}

void menu(){
	int pilihan;
	cout << "\nMenu:" << endl;
	cout << "1. Tambah Penumpang" << endl;
	cout << "2. Hapus Penumpang" << endl;
	cout << "3. Info Gerbong" << endl;
	cout << "4. Lepas Gerbong" << endl;
	cout << "Input (1,2,3,4): "; cin >> pilihan;
	switch(pilihan){
		case 1:
			tambahpenumpang();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			break;			
	}
}

void inputgerbong(){
	kereta.gerbong[0] = b;
	cout << "Masukkan jumlah gerbong kereta penumpang: "; 
	cin >> banyakgerbong;
	if (banyakgerbong > 25){
		cout << "Jumlah maksimal gerbong adalah 26" << endl;
		system("pause");
		return;
	} else{
		system("cls");
		head();
		info();
		menu();
	}
}

void info(){
	cout << "A-";
	for(int i = 0; i < banyakgerbong; i++){
		cout << b << penumpang;
		if (i < banyakgerbong - 1){
			cout << "-";	
		}
		kereta.gerbong[i] = b;
		b++;
	}
}

void tambahpenumpang(){
	head();
	info();
	cout << "Masukkan nama penumpang: ";
	cin >> 
};

//void infogerbong(){
//	system("cls");
//	head();
//	info();
//	for int(i = 0; i < 3; i++){
//	cout << "Jumlah Penumpang" << kereta.kelas[i] << ":" << penumpang.kelas
//}
	
//}

int main(){
	head();
	inputgerbong();
	return 0;
}
