#include <iostream>
using namespace std;

struct Penumpang {
    string nama;
    string kelas[3] = {"EKONOMI", "BISNIS", "RAJA"};
};

struct KAP {
    char nama;
    string kelas;
    Penumpang isi[50];
    int banyakpenumpang = 0;
    bool aktif = true;
} gerbong[26];

string kelas[3] = {"EKONOMI", "BISNIS", "RAJA"};
int banyakgerbong;
bool gerbongTerlepas = false; 

void head();
void inputgerbong();
void info();
void menu();
void tambahpenumpang();
void infogerbong();
void lepasgerbong();
void hapuspenumpang();

void head() {
    cout << " /\\_/\\  PT KAP (KERETA API PEMROGRAMMER)\n";
    cout << "( o.o ) PROGRAM SISTEM TIKET DAN GERBONG KERETA\n";
    cout << " > ^ <  DIBUAT OLEH PJ MODUL 5 ALPRO 2024\n";
    for (int i = 0; i < 47; i++) {
        cout << "=";
    }
    cout << "\n";
}

void inputgerbong() {
    cout << "Masukkan Jumlah Gerbong: ";
    cin >> banyakgerbong;
    if (banyakgerbong <= 25 && banyakgerbong > 0) {
        for (int i = 0; i < banyakgerbong; i++) {
            gerbong[i].nama = 'B' + i;
            gerbong[i].kelas = kelas[i % 3];
        }
        menu();
    } else {
        cout << "Jumlah gerbong harus antara 1 dan 25!" << endl;
        inputgerbong();
    }
}

void info() {
    cout << "A-";
    bool gerbongada = false;

    for (int i = 0; i < banyakgerbong; i++) {
        if (gerbong[i].aktif) {
            cout << gerbong[i].nama << gerbong[i].banyakpenumpang;
        } else {
            cout << "- X -";
            gerbongada = true;

            for (int j = i + 1; j < banyakgerbong; j++) {
                if (gerbong[j].aktif) {
                    cout << "-" << gerbong[j].nama << gerbong[j].banyakpenumpang;
                } else {
                    cout << "-" << gerbong[j].nama;
                }
            }
            break;
        }

        if (i < banyakgerbong - 1 && !gerbongada) {
            cout << "-";
        }
    }
    cout << endl;
}

void menu() {
    system("cls");
    head();
    info();

    cout << "Menu:\n1. Tambah Penumpang\n2. Hapus Penumpang\n3. Info Gerbong";
    if (!gerbongTerlepas) {
        cout << "\n4. Lepas Gerbong";
    }
    cout << "\nInput (1,2,3";
    if (!gerbongTerlepas) {
        cout << ",4";
    }
    cout << "): ";
    
    int pilihan;
    cin >> pilihan;

    if (gerbongTerlepas && (pilihan == 4)) {
        cout << "Inputan yang anda pilih tidak terdapat dalam menu!!" << endl;
        system("pause");
        menu();
        return;
    }

    switch (pilihan) {
        case 1:
            tambahpenumpang();
            break;
        case 2:
            hapuspenumpang();
            break;
        case 3:
            infogerbong();
            break;
        case 4:
            if (!gerbongTerlepas) {
                lepasgerbong();
                break;
            }
        default:
            cout << "Inputan yang anda pilih tidak terdapat dalam menu!!" << endl;
            system("pause");
            menu();
    }
}

KAP TP(KAP gerbong, string nama, string pilihanKelas) {
    if (gerbong.kelas == pilihanKelas) {
        gerbong.isi[gerbong.banyakpenumpang].nama = nama;
        gerbong.banyakpenumpang++;
    }
    return gerbong;
}

void tambahpenumpang() {
    system("cls");
    head();
    info();
    cout << "Masukkan nama penumpang: ";
    string nama;
    getline(cin >> ws, nama);

    cout << "Pilih kelas tiket (EKONOMI, BISNIS, RAJA): ";
    string pilihankelas;
    cin >> pilihankelas;

    bool kelasTersedia = false;
    cout << "Gerbong kelas " << pilihankelas << " yang tersedia: ";
    for (int i = 0; i < banyakgerbong; i++) {
        if (gerbong[i].kelas == pilihankelas && gerbong[i].aktif) {
            cout << gerbong[i].nama << " ";
            kelasTersedia = true;
        }
    }

    if (!kelasTersedia) {
        cout << "TIDAK ADA" << endl;
        system("pause");
        menu();
        return;
    }

    cout << endl;
    cout << "Pilih lokasi gerbong: ";
    char pilih;
    cin >> pilih;

    bool gerbongada = false;

    for (int i = 0; i < banyakgerbong; i++) {
        if (gerbong[i].nama == pilih && gerbong[i].aktif) {
            if (gerbong[i].kelas != pilihankelas) {
                cout << "Kelas gerbong tidak sesuai dengan kelas tiket yang dipilih. Silakan coba lagi.\n";
                system("pause");
                tambahpenumpang();
                return;
            }
            gerbong[i] = TP(gerbong[i], nama, pilihankelas);
            gerbongada = true;
            break;
        }
    }

    if (!gerbongada) {
        cout << "Gerbong yang anda masukkan salah atau tidak aktif!\n";
    } else {
        cout << "Penumpang berhasil ditambahkan!" << endl;
    }

    system("pause");
    menu();
}

void infogerbong() {
    system("cls");
    head();
    info();

    int ekonomi = 0, bisnis = 0, raja = 0;

    for (int i = 0; i < banyakgerbong; i++) {
        if (gerbong[i].aktif) {
            for (int j = 0; j < gerbong[i].banyakpenumpang; j++) {
                if (gerbong[i].kelas == "EKONOMI") {
                    ekonomi++;
                } else if (gerbong[i].kelas == "BISNIS") {
                    bisnis++;
                } else if (gerbong[i].kelas == "RAJA") {
                    raja++;
                }
            }
        }
    }

    cout << "Jumlah Penumpang EKONOMI: " << ekonomi << " BISNIS: " << bisnis << " RAJA: " << raja << endl;

    for (int i = 0; i < banyakgerbong; i++) {
        if (gerbong[i].aktif) {
            cout << "Gerbong " << gerbong[i].nama << " (" << gerbong[i].kelas << ") :" << endl;
            if (gerbong[i].banyakpenumpang == 0) {
                cout << "Kosong" << endl;
            } else {
                for (int j = 0; j < gerbong[i].banyakpenumpang; j++) {
                    cout << j + 1 << ". " << gerbong[i].isi[j].nama << endl;
                }
            }
        } else {
        	break;
            cout << "Gerbong " << gerbong[i].nama << " telah dilepas." << endl;
        }
    }

    system("pause");
    menu();
}

bool valid(string kelas) {
    return kelas == "EKONOMI" || kelas == "BISNIS" || kelas == "RAJA";
}

void hapuspenumpang() {
    system("cls");
    head();
    info();

    cout << "Masukkan nama penumpang yang ingin dihapus: ";
    string nama;
    getline(cin >> ws, nama);

    string pilihankelas;
    do {
        cout << "Masukkan kelas tiket (EKONOMI, BISNIS, RAJA): ";
        cin >> pilihankelas;
        if (!valid(pilihankelas)) {
            cout << "Harap Masukkan kelas tiket EKONOMI, BISNIS, atau RAJA." << endl;
        }
    } while (!valid(pilihankelas));

    bool penumpangada = false;
    int nomor = 0;

    for (int i = 0; i < banyakgerbong; i++) {
        if (gerbong[i].aktif && gerbong[i].kelas == pilihankelas) {
            for (int j = 0; j < gerbong[i].banyakpenumpang; j++) {
                if (gerbong[i].isi[j].nama == nama) {
                    if (!penumpangada) {
                        cout << "Penumpang ditemukan!" << endl;
                    }
                    nomor++;
                    cout << nomor << ". " << gerbong[i].isi[j].nama << " (" << gerbong[i].kelas << ") di gerbong " << gerbong[i].nama << endl;
                    penumpangada = true;
                }
            }
        }
    }

    if (penumpangada) {
        int pilihan;
        cout << "Ingin menghapus penumpang nomor berapa: ";
        cin >> pilihan;

        if (pilihan > 0 && pilihan <= nomor) {
            nomor = 0;
            for (int i = 0; i < banyakgerbong; i++) {
                if (gerbong[i].aktif && gerbong[i].kelas == pilihankelas) {
                    for (int j = 0; j < gerbong[i].banyakpenumpang; j++) {
                        if (gerbong[i].isi[j].nama == nama) {
                            nomor++;
                            if (nomor == pilihan) {
                                for (int k = j; k < gerbong[i].banyakpenumpang - 1; k++) {
                                    gerbong[i].isi[k] = gerbong[i].isi[k + 1];
                                }
                                gerbong[i].banyakpenumpang--;
                                cout << "Penumpang berhasil dihapus!" << endl;
                                break;
                            }
                        }
                    }
                    if (nomor == pilihan) {
                        break;
                    }
                }
            }
        } else {
            cout << "Nomor penumpang tidak valid!" << endl;
        }
    } else {
        cout << "Tidak ditemukan, penumpang dengan nama " << nama << " di kelas " << pilihankelas << endl;
    }
 
    system("pause");
    menu();
}

void lepasgerbong() {
    cout << "Masukkan nama gerbong yang ingin dilepas: ";
    char lepas;
    cin >> lepas;

    bool gerbongditemukan = false;
    for (int i = 0; i < banyakgerbong; i++) {
        if (gerbong[i].nama == lepas) {
            gerbong[i].aktif = false;
            for (int j = i + 1; j < banyakgerbong; j++) {
                gerbong[j].aktif = false;
                gerbong[j].banyakpenumpang = 0;
            }
            gerbongditemukan = true;
            break;
        }
    }

    if (gerbongditemukan) {
        gerbongTerlepas = true; 
        cout << "Gerbong berhasil dilepas!" << endl;
    } else {
        cout << "Gerbong yang anda masukkan tidak terdapat dalam Kereta!" << endl;
    }

    system("pause");
    menu();
}

int main() {
    head();
    inputgerbong();
    return 0;
}