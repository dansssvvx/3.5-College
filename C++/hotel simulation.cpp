#include <iostream>
#include <conio.h>
using namespace std;

const int MAKS_LANTAI = 4;
const int RUANG_PER_LANTAI = 4;

struct Tamu {
	string nama;
	bool member;
	int nik;
	int lantai;
	int ruang;
	int lamaInap;
	int lamaInapAsli;

	Tamu(string n = "", int id = 0, int l = 0, int r = 0, bool m = false, int inap = 0, int inapAsli = 0)
		: nama(n), nik(id), member(m), lantai(l), ruang(r), lamaInap(inap), lamaInapAsli(inapAsli) {}
};
struct Hotel {
	string ruang[MAKS_LANTAI][RUANG_PER_LANTAI];
	Tamu tamu[MAKS_LANTAI * RUANG_PER_LANTAI];
	int jumlahTamu = 0;
	int penghasilan;
	int hari;

	Hotel() : jumlahTamu(0), penghasilan(0), hari(1) {
		for (int i = 0; i < MAKS_LANTAI; ++i) {
			for (int j = 0; j < RUANG_PER_LANTAI; ++j) {
				ruang[i][j] = "kosong";
			}
		}
	}
};

void Header() {
	cout << "================================" << endl;
	cout << "|          MY STAY             |" << endl;
	cout << "|  SIMULASI PENGINAPAN HOTEL   |" << endl;
	cout << "================================" << endl;
}

void MenuUtama(Hotel *hotel) {
	system("cls");
	Header();
	cout << "Penghuni: " << hotel->jumlahTamu << "             Hari: " << hotel->hari << endl;
	cout << "Penghasilan: " << hotel->penghasilan << endl;
	cout << endl;
	cout << "1. Tambah Tamu" << endl;
	cout << "2. Cek Tamu" << endl;
	cout << "3. Skip Hari" << endl;
	cout << "4. Mulai Simulasi" << endl;
	cout << "5. Keluar" << endl;
	cout << "Pilih: ";
}

void TambahTamu(Hotel *hotel) {
	system("cls");
	string nama;
	int lantai, nik, ruangPilih, hariNginap;
	char memberChar;
	bool member;

	Header();
	cout << endl;
	cout << "Nama: ";
	getline(cin >> ws, nama);

	cout << "NIK: ";
	cin >> nik;
	for (int i = 0; i < hotel->jumlahTamu; ++i) {
		if (hotel->tamu[i].nik == nik) {
			cout << "Tamu dengan nik " << nik << " sudah ada!" << endl;
			system("pause");
			return;
		}
	}
	cout << "Lantai (1, 2, 3, 4): ";
	cin >> lantai;

	if (lantai < 1 || lantai > 4) {
		cout << "Lantai tidak valid!" << endl;
		system("pause");
		return;
	}

	cout << "Ruang 1 " << hotel->ruang[lantai - 1][0] << endl;
	cout << "Ruang 2 " << hotel->ruang[lantai - 1][1] << endl;
	cout << "Ruang 3 " << hotel->ruang[lantai - 1][2] << endl;
	cout << "Ruang 4 " << hotel->ruang[lantai - 1][3] << endl;
	cout << "===============" << endl;
	cout << "Ruang: ";
	cin >> ruangPilih;

	if (ruangPilih < 1 || ruangPilih > 4 || hotel->ruang[lantai - 1][ruangPilih - 1] != "kosong") {
		cout << "Ruang tidak valid atau sudah terisi!" << endl;
		system("pause");
		return;
	}

	hotel->ruang[lantai - 1][ruangPilih - 1] = "ditempatkan oleh " + nama;

	cout << "Pemesanan Berhasil" << endl;
	cout << "Member(Y/N): ";
	cin >> memberChar;
	member = (memberChar == 'Y' || memberChar == 'y');

	if (member) {
		cout << nama << " Menjadi Member" << endl;
	}

	do {
		cout << "Lama penginapan (hari): ";
		cin >> hariNginap;
		if (hariNginap <= 0) {
			cout << "mau nginap apa tidak?\n";
			system("pause");
		}
	} while (hariNginap <= 0);

	hotel->tamu[hotel->jumlahTamu] = Tamu(nama, nik, lantai, ruangPilih, member, hariNginap, hariNginap);
	hotel->jumlahTamu++;

	cout << nama << " telah menginap dilantai " << lantai << " Ruang " << ruangPilih << " selama " << hariNginap << " hari\n";
	system("pause");
}

void CekTamu(Hotel *hotel) {
	system("cls");
	Header();

	bool selesai = false;
	int pilihanLantai;
	int pilihan = 1;
	bool selesaiRuangan = false;

	while (!selesai) {
		system("cls");
		Header();
		cout << "Cek tamu per lantai" << endl;
		cout << "1. Lantai 1 (200.000/malam)" << endl;
		cout << "2. Lantai 2 (250.000/malam)" << endl;
		cout << "3. Lantai 3 (300.000/malam)" << endl;
		cout << "4. Lantai 4 (350.000/malam)" << endl;
		cout << "Pilih lantai: ";
		cin >> pilihanLantai;

		if (pilihanLantai < 1 || pilihanLantai > 4) {
			cout << "Pilihan lantai tidak valid!" << endl;
			system("pause");
			continue;
		}

		while (!selesaiRuangan) {
			system("cls");
			Header();

			cout << "Lantai " << pilihanLantai << endl;
			cout << "  _____   _____  \n";
			cout << "  |     | |     | \n";
			cout << "  |     | |     | \n";
			cout << "  |  " << (pilihan == 1 ? "\033[35m" : "\033[0m") << "1" << (pilihan == 1 ? "\033[0m" : " ") << "\t| |" << (pilihan == 2 ? "\033[35m" : "\033[0m") << "  2" << (pilihan == 2 ? "\033[0m" : "") << "  |\n";
			cout << "  |     | |     | \n";
			cout << "  |---||| |||---| \n";
			cout << "  |             |\n";
			cout << "  |             |\n";
			cout << "  |             =\n";
			cout << "  |             =\n";
			cout << "  |             |\n";
			cout << "  |             |\n";
			cout << "  |---||| |||---|\n";
			cout << "  |     | |     |\n";
			cout << "  |  " << (pilihan == 3 ? "\033[35m" : "\033[0m") << "3" << (pilihan == 3 ? "\033[0m" : "") << "  | | " << (pilihan == 4 ? "\033[35m" : "\033[0m") << " 4" << (pilihan == 4 ? "\033[0m" : "") << "  |\n";
			cout << "  |     | |     |\n";
			cout << "  || ||\n";

			// Menampilkan informasi ruangan
			cout << "Daftar Kamar:" << endl;
			for (int j = 0; j < RUANG_PER_LANTAI; ++j) {
				if (pilihan == j + 1) {
					cout << "Nomor Kamar: " << j + 1 << endl;
					cout << "Status: " << hotel->ruang[pilihanLantai - 1][j] << endl;
					for (int k = 0; k < hotel->jumlahTamu; ++k) {
						if (hotel->tamu[k].lantai == pilihanLantai && hotel->tamu[k].ruang == j + 1) {
							int harga = 0;
							switch (hotel->tamu[k].lantai) {
								case 1:
									harga = 200000;
									break;
								case 2:
									harga = 250000;
									break;
								case 3:
									harga = 300000;
									break;
								case 4:
									harga = 350000;
									break;
								default:
									harga = 0;
									break;
							}
							if (hotel->tamu[k].member) {
								harga += 50000;
							}
							cout << "  Nama: " << hotel->tamu[k].nama << endl;
							cout << "  NIK: " << hotel->tamu[k].nik << endl;
							cout << "  Member: " << (hotel->tamu[k].member ? "Ya" : "Tidak") << endl;
							cout << "  Lama inap: " << hotel->tamu[k].lamaInap << " hari" << endl;
							cout << "  Pembayaran: Rp " << harga * hotel->tamu[k].lamaInap << endl;
							cout << "------------------------" << endl;
						}
					}
				}
			}
			char tombol = _getch();

			switch (tombol) {
				case 'a':
				case 'A':
				case 75: // Panah atas
					pilihan = (pilihan == 1) ? 4 : pilihan - 1;
					break;
				case 'd':
				case 'D':
				case 77: // Panah bawah
					pilihan = (pilihan == 4) ? 1 : pilihan + 1;
					break;
				case 13: // Tombol Enter untuk memilih
					selesaiRuangan = true;
					break;
			}
		}
		system("pause");
		return; // Menambahkan return untuk mengakhiri fungsi setelah menampilkan tamu
	}
}

void SkipHari(Hotel *hotel) {
	system("cls");
	Header();
	hotel->hari++;

	cout << "Selamat anda sudah melewati hari yang melelahkan, teruslah semangat tuanku." << endl;

	for (int i = 0; i < hotel->jumlahTamu; ++i) {
		hotel->tamu[i].lamaInap--; // Kurangi jumlah hari inap untuk setiap tamu

		if (hotel->tamu[i].lamaInap == 0) {
			// Jika sudah selesai menginap
			int harga = 0;
			switch (hotel->tamu[i].lantai) {
				case 1:
					harga = 200000;
					break;
				case 2:
					harga = 250000;
					break;
				case 3:
					harga = 300000;
					break;
				case 4:
					harga = 350000;
					break;
				default:
					harga = 0;
					break;
			}
			if (hotel->tamu[i].member) {
				harga += 50000;
			}

			int lamaInapAsli = hotel->tamu[i].lamaInap;
			int totalBiaya = harga * lamaInapAsli;
			cout << hotel->tamu[i].nama << " telah keluar, Selamat anda mendapatkan uang Rp " << totalBiaya << "." << endl;
			hotel->penghasilan += totalBiaya;
			hotel->ruang[hotel->tamu[i].lantai - 1][hotel->tamu[i].ruang - 1] = "kosong";

			for (int j = i; j < hotel->jumlahTamu - 1; ++j) {
				hotel->tamu[j] = hotel->tamu[j + 1];
			}
			hotel->jumlahTamu--;
			i--;
		}
	}

	cout << "=========================" << endl;
	system("pause");
}

void MulaiSimulasi(Hotel *hotel) {
	system("cls");
	string nama;
	bool ditemukan = false;

	Header();
	cout << "Simulasi dimulai....!!!" << endl;
	cout << "Masukkan nama: ";
	getline(cin >> ws, nama);

	for (int i = 0; i < hotel->jumlahTamu; ++i) {
		if (hotel->tamu[i].nama == nama && hotel->tamu[i].member) {
			cout << "Selamat Anda Telah Memasuki fasilitas hotel" << endl;
			cout << "=========================" << endl;
			cout << "Selamat Datang " << hotel->tamu[i].nama << " di Hotel MyStay, Anda ingin Pergi kemana???" << endl;
			ditemukan = true;

			bool lanjut = true;
			while (lanjut) {
				cout << "1. Kolam  Rp.20000 " << endl;
				cout << "2. Game Center Rp.20000" << endl;
				cout << "3. Gym Rp.10000" << endl;
				cout << "4. Sauna Rp.15000" << endl;
				cout << "5. Bioskop Rp.25000" << endl;
				cout << ">>> ";
				int pilihan;
				cin >> pilihan;

				switch (pilihan) {
					case 1:
						cout << "==================" << endl;
						cout << hotel->tamu[i].nama << " telah menggunakan kolam, dia keliatan asik berenang." << endl;
						hotel->penghasilan += 20000;
						break;
					case 2:
						cout << "==================" << endl;
						cout << hotel->tamu[i].nama << " telah menggunakan Game Center, dia keliatan asik main game." << endl;
						hotel->penghasilan += 20000;
						break;
					case 3:
						cout << "==================" << endl;
						cout << hotel->tamu[i].nama << " telah menggunakan Gym, dia keliatan asik berolahraga." << endl;
						hotel->penghasilan += 10000;
						break;
					case 4:
						cout << "==================" << endl;
						cout << hotel->tamu[i].nama << " telah menggunakan Sauna, dia keliatan rileks." << endl;
						hotel->penghasilan += 15000;
						break;
					case 5:
						cout << "==================" << endl;
						cout << hotel->tamu[i].nama << " telah menggunakan Bioskop, dia keliatan menikmati film." << endl;
						hotel->penghasilan += 25000;
						break;
					default:
						cout << "Pilihan tidak valid!" << endl;
						continue;
				}
				system("pause");
				cout << "Apakah ingin pergi lagi?(Y/N): ";
				char lagi;
				cin >> lagi;
				if (lagi == 'N' || lagi == 'n') {
					lanjut = false;
					cout << hotel->tamu[i].nama << " telah kembali ke ruangan nya......." << endl;
				}
			}
			break; // Exit the loop once the member is found and processed
		}
	}

	if (!ditemukan) {
		cout << "Nama tidak terdaftar atau bukan member!" << endl;
	}
	system("pause");
}

void Menu() {
	Hotel hotel;
	int pilihan;

	while (true) {
		MenuUtama(&hotel);
		cin >> pilihan;

		switch (pilihan) {
			case 1:
				TambahTamu(&hotel);
				break;
			case 2:
				CekTamu(&hotel);
				break;
			case 3:
				SkipHari(&hotel);
				break;
			case 4:
				MulaiSimulasi(&hotel);
				break;
			case 5:
				return;
			default:
				cout << "Pilihan tidak valid!" << endl;
				system("pause");
		}
	}
}
int main() {
	Menu();
	return 0;
}
