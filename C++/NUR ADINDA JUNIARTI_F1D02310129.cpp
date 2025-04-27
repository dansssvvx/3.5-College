#include <iostream>
using namespace std;

const int MAX = 100;

struct Warga {
	string NIK;
	string nama;
	int umur;
	char kelamin;
};

struct RukunTetangga {
	Warga warga[MAX];
	int banyakWarga;
	string ketuaRT;
};

struct Desa {
	RukunTetangga RT[MAX];
	int banyakRT;
	string namadesa;
	string kepalaDesa;
};

Desa desa[MAX];

void menu(), buatdesa(), aturdesa(int nomorDesa), aturrt(int nomorDesa), tambahrt(int nomorDesa);
void aturMenuRT(int nomorDesa, int nomorRT), aturKetuaRT(int nomorDesa, int nomorRT), ubahDataWarga(int nomorDesa, int nomorRT);
void hapusWarga(int nomorDesa, int nomorRT), aturKepalaDesa(int nomorDesa), tampilkanRTdanWarga(int nomorDesa);

bool RTada[MAX][MAX] = {false};

void menu() {
	system("cls");
	int pilihan;
	cout << "0. Tambah Desa" << endl;

	for (int i = 0; i < MAX; i++) {
		if (!desa[i].namadesa.empty()) {
			cout << i + 1 << ". Atur Desa " << desa[i].namadesa  << endl;
		}
	}
	cout << "-1. Keluar" << endl;
	cout << "Pilih menu: ";
	cin >> pilihan;

	switch (pilihan) {
		case 0:
			buatdesa();
			break;
		case -1:
			return;
		default:
			if (pilihan > 0 && pilihan <= MAX && !desa[pilihan - 1].namadesa.empty()) {
				aturdesa(pilihan - 1);
			} else {
				cout << "Pilihan yang anda masukkan salah! Silahkan coba lagi" << endl;
				system("pause");
				menu();
			}
			break;
	}
}

void buatdesa() {
	for (int i = 0; i < MAX; i++) {
		if (desa[i].namadesa.empty()) {
			cout << "Masukkan Nama desa baru: ";
			cin.ignore();
			getline(cin, desa[i].namadesa);
			desa[i].banyakRT = 0;
			cout << "Desa berhasil ditambahkan!" << endl;
			system("pause");
			menu();
		}
	}
	cout << "Jumlah desa sudah mencapai batas maksimal!" << endl;
	system("pause");
	menu();
}

void aturdesa(int nomorDesa) {
	system("cls");

	int pilihan;
	cout << "Desa " << desa[nomorDesa].namadesa << endl;
	cout << "1. Atur Kepala Desa" << endl;
	cout << "2. Atur RT" << endl;
	cout << "3. Tampilkan seluruh RT dan warganya" << endl;
	cout << "0. Kembali" << endl;
	cout << "Pilih menu: ";
	cin >> pilihan;

	switch (pilihan) {
		case 1:
			aturKepalaDesa(nomorDesa);
			break;
		case 2:
			aturrt(nomorDesa);
			break;
		case 3:
			tampilkanRTdanWarga(nomorDesa);
			break;
		case 0:
			menu();
			break;
		default:
			cout << "Pilihan yang anda masukkan salah! Silahkan coba lagi" << endl;
			system("pause");
			aturdesa(nomorDesa); 
	}
}

void aturrt(int nomorDesa) {
	system("cls");

	cout << "Desa " << desa[nomorDesa].namadesa << endl; 

	for (int i = 0; i < MAX; i++) {
		if (RTada[nomorDesa][i]) {
			cout << i + 1 << ". RT " << (i + 1) << endl;
		}
	}

	cout << "-1. Kembali" << endl;
	cout << "Pilih menu: ";

	int pilihan;
	cin >> pilihan;

	switch (pilihan) {
		case 0:
			tambahrt(nomorDesa); 
			break;
		case -1:
			aturdesa(nomorDesa);
		default:
			if (pilihan > 0 && pilihan <= MAX && RTada[nomorDesa][pilihan - 1]) {
				aturMenuRT(nomorDesa, pilihan);
			} else {
				cout << "Pilihan yang anda masukkan salah! Silahkan coba lagi" << endl;
				system("pause");
				aturrt(nomorDesa); 
			}
			break;
	}
}

void tambahrt(int nomorDesa) {
	char pilihan;

	for (int i = 0; i < MAX; i++) {
		if (!RTada[nomorDesa][i]) {
			cout << "Yakin ingin menambahkan RT " << (i + 1) << " di Desa " << desa[nomorDesa].namadesa << "? (y/n) : ";
			cin >> pilihan;

			if (pilihan == 'y' || pilihan == 'Y') {
				RTada[nomorDesa][i] = true;
				desa[nomorDesa].banyakRT++; 
				cout << "RT " << (i + 1) << " berhasil dibuat di Desa " << desa[nomorDesa].namadesa << "!" << endl;
				system("pause");
				aturrt(nomorDesa);
			} else if (pilihan == 'n' || pilihan == 'N') {
				cout << "Pembuatan RT dibatalkan." << endl;
				system("pause");
				aturrt(nomorDesa);
			}
			break;
		}
	}
}

void aturMenuRT(int nomorDesa, int nomorRT) {
	system("cls");

	if (desa[nomorDesa].RT[nomorRT - 1].banyakWarga > 0) {
		cout << "RT " << nomorRT << " yang diketuai oleh " << desa[nomorDesa].RT[nomorRT - 1].ketuaRT << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "No\t NIK\t\t\t\t Nama\t\t\t\t\t Umur\t\t Jenis Kelamin" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < desa[nomorDesa].RT[nomorRT - 1].banyakWarga; i++) {
			cout << i + 1 << ".\t " << desa[nomorDesa].RT[nomorRT - 1].warga[i].NIK << "\t\t\t\t " << desa[nomorDesa].RT[nomorRT - 1].warga[i].nama << "\t\t\t\t\t " << desa[nomorDesa].RT[nomorRT - 1].warga[i].umur << "\t\t ";

			if (desa[nomorDesa].RT[nomorRT - 1].warga[i].kelamin == 'L' || desa[nomorDesa].RT[nomorRT - 1].warga[i].kelamin == 'l') {
				cout << "Laki-Laki";
			} else {
				cout << "Perempuan";
			}

			cout << endl;
		}

		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	} else {
		cout << "RT " << nomorRT << " Masih Kosong!" << endl << endl;
	}

	cout << "1. Atur Ketua RT" << endl;
	cout << "2. Tambah Warga ke RT" << endl;
	cout << "3. Ubah Data Warga" << endl;
	cout << "4. Hapus Warga" << endl;
	cout << "5. Kembali" << endl;
	cout << "Pilih menu: ";

	int pilihan;
	cin >> pilihan;

	switch (pilihan) {
		case 1:
			aturKetuaRT(nomorDesa, nomorRT);
			break;
		case 2:
			if (desa[nomorDesa].RT[nomorRT - 1].banyakWarga < MAX) {
				Warga wargaBaru;
				cout << "Masukkan NIK Warga : ";
				cin >> wargaBaru.NIK;
				cout << "Masukkan Nama Warga : ";
				getline (cin >> ws, wargaBaru.nama);
				cout << "Masukkan Umur Warga: ";
				cin >> wargaBaru.umur;
				cout << "Masukkan Jenis Kelamin Warga (L/P): ";
				cin >> wargaBaru.kelamin;

				desa[nomorDesa].RT[nomorRT - 1].warga[desa[nomorDesa].RT[nomorRT - 1].banyakWarga] = wargaBaru;
				desa[nomorDesa].RT[nomorRT - 1].banyakWarga++;

				cout << "Warga berhasil ditambahkan ke RT " << nomorRT << endl;
				system("pause");
				aturMenuRT(nomorDesa, nomorRT);
			} else {
				cout << "RT sudah penuh, tidak bisa menambahkan warga lagi" << endl;
				system("pause");
				aturMenuRT(nomorDesa, nomorRT);
			}
			break;
		case 3:
			ubahDataWarga(nomorDesa, nomorRT);
			break;
		case 4:
			hapusWarga(nomorDesa, nomorRT);
			break;
		case 5:
			aturrt(nomorDesa);
			break;
		default:
			cout << "Pilihan yang anda masukkan salah! Silahkan coba lagi" << endl;
			system("pause");
			aturMenuRT(nomorDesa, nomorRT);
			break;
	}
}

void aturKetuaRT(int nomorDesa, int nomorRT) {
	cout << endl << "Masukkan NIK untuk menentukan Ketua RT " << nomorRT << ": ";
	string NIKKetua;
	cin >> NIKKetua;

	bool found = false;
	for (int i = 0; i < desa[nomorDesa].RT[nomorRT - 1].banyakWarga; i++) {
		if (desa[nomorDesa].RT[nomorRT - 1].warga[i].NIK == NIKKetua) {
			desa[nomorDesa].RT[nomorRT - 1].ketuaRT = desa[nomorDesa].RT[nomorRT - 1].warga[i].nama;
			found = true;
			break;
		}
	}

	if (found) {
		cout << "Ketua RT " << nomorRT << " berhasil diatur!" << endl;
	} else {
		cout << "NIK tidak ditemukan dalam daftar warga RT " << nomorRT << ". Silakan coba lagi." << endl;
	}

	system("pause");
	aturMenuRT(nomorDesa, nomorRT);
}

void ubahDataWarga(int nomorDesa, int nomorRT) {
	cout << endl <<"Masukkan NIK Warga yang ingin diubah datanya: ";
	string NIKWarga;
	cin >> NIKWarga;

	bool found = false;
	for (int i = 0; i < desa[nomorDesa].RT[nomorRT - 1].banyakWarga; i++) {
		if (desa[nomorDesa].RT[nomorRT - 1].warga[i].NIK == NIKWarga) {
			found = true;

			cout << "Masukkan nama baru: ";
			getline(cin >> ws, desa[nomorDesa].RT[nomorRT - 1].warga[i].nama);
			cout << "Masukkan umur baru: ";
			cin >> desa[nomorDesa].RT[nomorRT - 1].warga[i].umur;
			cout << "Masukkan jenis kelamin baru (L/P): ";
			cin >> desa[nomorDesa].RT[nomorRT - 1].warga[i].kelamin;

			cout << "Data warga dengan NIK " << NIKWarga << " berhasil diubah!" << endl;
			break;
		}
	}

	if (!found) {
		cout << "NIK tidak ditemukan dalam daftar warga RT " << nomorRT << ". Silakan coba lagi." << endl;
	}

	system("pause");
	aturMenuRT(nomorDesa, nomorRT);
}

void hapusWarga(int nomorDesa, int nomorRT) {
	cout << endl << "Masukkan NIK Warga yang ingin dihapus: ";
	string NIKWarga;
	cin >> NIKWarga;

	bool found = false;
	for (int i = 0; i < desa[nomorDesa].RT[nomorRT - 1].banyakWarga; i++) {
		if (desa[nomorDesa].RT[nomorRT - 1].warga[i].NIK == NIKWarga) {
			found = true;
			
			for (int j = i; j < desa[nomorDesa].RT[nomorRT - 1].banyakWarga - 1; j++) {
				desa[nomorDesa].RT[nomorRT - 1].warga[j] = desa[nomorDesa].RT[nomorRT - 1].warga[j + 1];
			}
			desa[nomorDesa].RT[nomorRT - 1].banyakWarga--;
			cout << "Warga dengan NIK " << NIKWarga << " berhasil dihapus!" << endl;
			break;
		}
	}

	if (!found) {
		cout << "NIK tidak ditemukan dalam daftar warga RT " << nomorRT << ". Silakan coba lagi." << endl;
	}

	system("pause");
	aturMenuRT(nomorDesa, nomorRT);
}

void aturKepalaDesa(int nomorDesa) {
	cout << endl << "Masukkan NIK untuk menentukan Kepala Desa: ";
	string NIKKepalaDesa;
	cin >> NIKKepalaDesa;

	bool found = false;
	for (int i = 0; i < desa[nomorDesa].banyakRT; i++) {
		for (int j = 0; j < desa[nomorDesa].RT[i].banyakWarga; j++) {
			if (desa[nomorDesa].RT[i].warga[j].NIK == NIKKepalaDesa) {
				desa[nomorDesa].kepalaDesa = desa[nomorDesa].RT[i].warga[j].nama;
				found = true;
				break;
			}
		}
		if (found) break;
	}

	if (found) {
		cout << "Kepala Desa " << desa[nomorDesa].namadesa << " berhasil diatur!" << endl;
	} else {
		cout << "NIK tidak ditemukan dalam daftar warga di desa " << desa[nomorDesa].namadesa << ". Silakan coba lagi." << endl;
	}

	system("pause");
	aturdesa(nomorDesa);
}

void tampilkanRTdanWarga(int nomorDesa) {
	system("cls");
	cout << "desa " << desa[nomorDesa].namadesa << " yang diketuai oleh " << desa[nomorDesa].kepalaDesa << endl;

	if (desa[nomorDesa].banyakRT == 0) {
		cout << "Belum ada RT di desa ini." << endl;
	} else {
		for (int i = 0; i < desa[nomorDesa].banyakRT; i++) {
			if (RTada[nomorDesa][i]) {
				cout << "RT " << (i + 1) << " - Ketua RT: " << desa[nomorDesa].RT[i].ketuaRT << endl;
				if (desa[nomorDesa].RT[i].banyakWarga == 0) {
					cout << "  Tidak ada warga di RT ini." << endl;
				} else {
					cout << "  Daftar Warga: " << endl;
					for (int j = 0; j < desa[nomorDesa].RT[i].banyakWarga; j++) {
						cout << "  " << (j + 1) << ". " << desa[nomorDesa].RT[i].warga[j].nama
						     << " - NIK: " << desa[nomorDesa].RT[i].warga[j].NIK
						     << ", Umur: " << desa[nomorDesa].RT[i].warga[j].umur
						     << ", Kelamin: " << (desa[nomorDesa].RT[i].warga[j].kelamin == 'L' ? "Laki-laki" : "Perempuan") << endl;
					}
				}
				cout << endl;
			}
		}
	}

	cout << "Tekan Enter untuk kembali...";
	cin.ignore();
	cin.get();
	aturdesa(nomorDesa);
}

int main() {
	menu();
	return 0;
}
