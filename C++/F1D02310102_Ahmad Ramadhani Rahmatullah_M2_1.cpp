#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(){

	string nama, NIM;
	cout <<"Masukkan Nama	: ";
	getline (cin, nama);
	
	
	cout <<"Masukkan NIM	: ";
	cin >> NIM;
	cout << "--------------------------------------------" << endl;
	cout << "Yooo!! " << nama << ", Kamu tipe mahasiswa seperti Apa?" << endl;
	cout << "1. Mahasiswa Kupu-kupu\n" << "2. Mahasiswa Kura-kura\n" << "3. Mahasiswa Kuda-kuda" << endl;
	cout << "Masukkan pilihan kamu: ";
	
	int x;
	cin >> x;
	
	int thr;
	switch (x){
		case 1:
			thr = 500000;
			break;
		case 2:
			thr = 850000;
			break;
		case 3:
			thr = 1000000;
			break;
		default:
			cout << "Input yang anda masukan salah!";
			break;
	}
	
	system("cls");
	
	int waktukuliah;
	char y;
	int kuliahmalam;
	int durasikuliah;
	
	if (x == 1){
		cout << "--------------------------------------------" << endl;
		cout << "Selamat Datang " << nama << " - " << " Mahasiswa Kuliah-Pulang" << endl;
		cout << "Kasian banget ya kamu" << endl;
		cout << "--------------------------------------------" << endl;
		cout << "Berapa jam waktu kuliahmu Ramadhan ini? ";
		cin >> waktukuliah;
		cout << "--------------------------------------------" << endl;
		cout << "THR buat kamu sebesar 		: Rp. " << thr << endl;
		cout << "Durasi kuliah minggu ini	: " << waktukuliah * 3600 << " Detik" << endl;
		cout << "Apakah kamu pernah kuliah sampai malam? (Y/N) : ";
		cin >> y;
		
		system("cls");
		
		switch (y){
			
			// Y case
			case 89:
				cout << "\nKamu memang rajin!!" << endl;
				cout << "Holil ingin memberimu lebih banyak THR" << endl;
				cout << "Masukkan total waktu kuliah malam kamu (detik): ";
				cin >> kuliahmalam;
				
				durasikuliah = (waktukuliah * 3600) + kuliahmalam;
				
				if (kuliahmalam >= 3600 && kuliahmalam <= 7200){
					thr = thr + 200000;
				} else if (kuliahmalam > 7200 && kuliahmalam <= 10800){
					thr = thr + 500000;
				} else if (kuliahmalam > 10800){
					thr = thr * 2;				
				} else {
					cout << "input yang anda masukkan tidak valid" << endl;
				}
				
				cout << "\n--------------------------------------------" << endl;
				cout << "Total THR " << nama << " Ramadhan Ini : " << thr << endl;
				
				int jam, menit;
				jam = 0;
				menit = 0;
				
				while (durasikuliah >= 60){
					menit = menit + 1;
					durasikuliah = durasikuliah  - 60;
				} 
				
				while (menit >= 60){
					jam = jam + 1;
					menit = menit - 60;
				}
				
				cout << "Durasi Kuliah Ramadan ini : " << jam << " Jam, " << menit  << " menit, " << durasikuliah << " detik.";
				break;
				
			// N case	
			case 78:
				cout << "--------------------------------------------" << endl;
				cout << "Total THR " << nama << " Ramadhan Ini : " << thr << endl;
				cout << "Durasi Kuliah Ramadan ini : " << waktukuliah << " Jam " << " 0 menit " << " 0 detik.";
				break;
				
			default:
				cout << "Input yang anda masukkan salah";
				break;
		} 
		
	} else if (x == 2){
		cout << "--------------------------------------------" << endl;
		cout << "Selamat Datang " << nama << " - " << " Mahasiswa Kuliah-Rapat" << endl;
		cout << "Kasian banget ya kamu" << endl;
		cout << "--------------------------------------------" << endl;
		cout << "Berapa jam waktu kuliahmu Ramadhan ini? ";
		cin >> waktukuliah;
		cout << "--------------------------------------------" << endl;
		cout << "THR buat kamu sebesar 		: Rp. " << thr << endl;
		cout << "Durasi kuliah minggu ini	: " << waktukuliah * 3600 << " Detik" << endl;
		cout << "Apakah kamu pernah kuliah sampai malam? (Y/N) : ";
		cin >> y;
		
		system("cls");
		
		switch (y){
			
			// Y case
			case 89:
				cout << "\nKamu memang rajin!!" << endl;
				cout << "Holil ingin memberimu lebih banyak THR" << endl;
				cout << "Masukkan total waktu kuliah malam kamu (detik): ";
				cin >> kuliahmalam;
				
				durasikuliah = (waktukuliah * 3600) + kuliahmalam;
				
				if (kuliahmalam >= 3600 && kuliahmalam <= 7200){
					thr = thr + 200000;
				} else if (kuliahmalam > 7200 && kuliahmalam <= 10800){
					thr = thr + 500000;
				} else if (kuliahmalam > 10800){
					thr = thr * 2;				
				} else {
					cout << "input yang anda masukkan tidak valid" << endl;
				}
				
				cout << "\n--------------------------------------------" << endl;
				cout << "Total THR " << nama << " Ramadhan Ini : " << thr << endl;
				
				int jam, menit;
				jam = 0;
				menit = 0;
				
				while (durasikuliah >= 60){
					menit = menit + 1;
					durasikuliah = durasikuliah  - 60;
				} 
				
				while (menit >= 60){
					jam = jam + 1;
					menit = menit - 60;
				}
				
				cout << "Durasi Kuliah Ramadan ini : " << jam << " Jam, " << menit  << " menit, " << durasikuliah << " detik.";
				break;
		
			// N case	
			case 78:
				cout << "--------------------------------------------" << endl;
				cout << "Total THR " << nama << " Ramadhan Ini : " << thr << endl;
				cout << "Durasi Kuliah Ramadan ini : " << waktukuliah << " Jam " << " 0 menit " << " 0 detik.";
				break;
			default:
				cout << "Input yang anda masukkan salah";
				break;
		}
		
	} else if (x == 3){
		cout << "--------------------------------------------" << endl;
		cout << "Selamat Datang " << nama << " - " << " Mahasiswa Kuliah-Dagang" << endl;
		cout << "Kasian banget ya kamu" << endl;
		cout << "--------------------------------------------" << endl;
		cout << "Berapa jam waktu kuliahmu Ramadhan ini? ";
		cin >> waktukuliah;
		cout << "--------------------------------------------" << endl;
		cout << "THR buat kamu sebesar 		: Rp. 1000000" << endl;
		cout << "Durasi kuliah minggu ini	: " << waktukuliah * 3600 << " Detik" << endl;
		cout << "Apakah kamu pernah kuliah sampai malam? (Y/N) : ";
		cin >> y;
		
		system("cls");
		
		switch (y){
			
			// Y case
			case 89:
				cout << "\nKamu memang rajin!!" << endl;
				cout << "Holil ingin memberimu lebih banyak THR" << endl;
				cout << "Masukkan total waktu kuliah malam kamu (detik): ";
				cin >> kuliahmalam;
				
				durasikuliah = (waktukuliah * 3600) + kuliahmalam;
				
				if (kuliahmalam >= 3600 && kuliahmalam <= 7200){
					thr = thr + 200000;
				} else if (kuliahmalam > 7200 && kuliahmalam <= 10800){
					thr = thr + 500000;
				} else if (kuliahmalam > 10800){
					thr = thr * 2;				
				} else {
					cout << "input yang anda masukkan tidak valid" << endl;
				}
				
				cout << "\n--------------------------------------------" << endl;
				cout << "Total THR " << nama << "Ramadhan Ini : " << thr << endl;
				
				int jam, menit;
				jam = 0;
				menit = 0;
				
				while (durasikuliah >= 60){
					menit = menit + 1;
					durasikuliah = durasikuliah  - 60;
				} 
				
				while (menit >= 60){
					jam = jam + 1;
					menit = menit - 60;
				}
				
				cout << "Durasi Kuliah Ramadan ini : " << jam << " Jam, " << menit  << " menit, " << durasikuliah << " detik.";
				break;
				
			// N case	
			case 78:
				cout << "--------------------------------------------" << endl;
				cout << "Total THR " << nama << " Ramadhan Ini : " << thr << endl;
				cout << "Durasi Kuliah Ramadhan ini : " << waktukuliah << " Jam " << " 0 menit " << " 0 detik.";
				cout << "--------------------------------------------" << endl;
				break;
			default:
				cout << "Input yang anda masukkan salah";
				break;
		}
	}
	
	return 0;	
}