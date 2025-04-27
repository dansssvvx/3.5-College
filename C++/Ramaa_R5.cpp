#include <iostream>
using namespace std;

const int maks = 100; 
int banyakbuku = 0; 

struct Buku {  
	string judul, penulis;
	int tahunterbit;
} buku[maks]; 

void tampilanbuku(), tumpukbuku(), ambiltumpukbuku(); 

void garis () {
	for(int i = 0; i < 50; i++) {
		cout << "-"; 
	}
	cout << endl;
}

void head() {
	garis();
	cout << "|\t\tTumpuk saja buku ini\t\t |" <<  endl;
	cout << "|\teh kek pernah denger ya di mana gitu\t |" <<  endl;
	garis();
}

void menu() {
	system("cls"); // membersihkan layar terminal
	head();
	
	int pilihan; 
	cout << "TUMPUKAN BUKU:" << endl;
	tampilanbuku();
	cout << "MENU: " << endl;
	cout << "1. TUMPUK BUKU" << endl;
	cout << "2. AMBIL TUMPUKAN BUKU" << endl;
	cout << "PILIHAN >> ";
	cin >> pilihan;

	switch(pilihan) {
		case 1:
			tumpukbuku();
			break;
		case 2:
			ambiltumpukbuku();
		default:
			cout << "inputan tidak valid" << endl;
			system("pause");
			menu();
	}

}

void tampilanbuku() {
    if(banyakbuku == 0) { 
    } else {
        for(int i = banyakbuku - 1; i >= 0; i--) {
        	cout << buku[i].judul << " - " << buku[i].penulis << "(" << buku[i].tahunterbit << ")" << endl;
        }
    }
}


void tumpukbuku() {
	system("cls");
	head();
	
	for(int i = banyakbuku; i < maks; i++) {
		cout << "Masukkan judul buku: ";
		getline(cin >> ws, buku[i].judul);
		cout << "Masukkan penulis buku: ";
		getline (cin >> ws, buku[i].penulis);
		cout << "Masukkan tahun terbit: ";
		cin >> buku[i].tahunterbit;
		cout << "buku berhasil ditumpuk!" << endl;
		banyakbuku++;
		system("pause");
		menu();
	}
}

void ambiltumpukbuku() {
	if(banyakbuku > 0) {
		banyakbuku --;
		cout << "Buku \"" << buku[banyakbuku].judul << " - " << buku[banyakbuku].penulis << "(" << buku[banyakbuku].tahunterbit << ")" <<  "\" telah diambil dari tumpukan." << endl;
	} else {
		cout << "Tumpukan buku kosong." << endl;
	}
	system("pause");
	menu();
}


int main() {
	menu();
	return 0;
}
