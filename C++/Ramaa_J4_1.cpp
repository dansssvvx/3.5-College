#include <iostream>
using namespace std;

const int maxx = 100;
string usernames[maxx] = {"admin"};
string passwords[maxx] = {"admin"};
int banyakuser = 1;

bool member[maxx] = {false}; 
string makanan[maxx];
int banyakmakanan = 0;

int harga[maxx];
int banyakharga = 0;

int totalbiaya[maxx] = {0};


void head() {
    cout << "=========================================\n";
    cout << "=============Rental PS Rijal=============\n";
    cout << "=========================================\n\n";
}

void loginhead() {
    cout << "=========================================\n";
    cout << "==================LOGIN==================\n";
    cout << "=========================================\n\n";
}

void signinhead() {
    cout << "=========================================\n";
    cout << "=================SIGN-IN=================\n";
    cout << "=========================================\n\n";
}

int menu(){
    system("cls");
    head();
    int pilihan;
    cout << "1. Login" << endl;
    cout << "2. Sign In" << endl;
    cout << "3. Exit" << endl;
    cout << ">> ";
    cin >> pilihan;
    return pilihan;
}

void dataPenyewa() {
    system("cls");
    head();
    cout << "Data Penyewa:\n";
    for(int i = 1; i < banyakuser; i++) {
        if(member[i]) {
            totalbiaya[i] = totalbiaya[i];
        }
        cout << "Username: " << usernames[i] << ", Total Biaya: " << totalbiaya[i] << endl;
    }
    system("pause");
}

void daftarMember(string username) {
    system("cls");
    head();
    for(int i = 0; i < banyakuser; i++) {
        if(usernames[i] == username) {
            if(member[i]) {
                cout << "Anda sudah terdaftar sebagai member." << endl;
            } else {
                char konfirmasi;
                cout << "Apakah Anda yakin ingin mendaftar sebagai member? (y/t): ";
                cin >> konfirmasi;
                if(konfirmasi == 'y' || konfirmasi == 'Y') {
                    member[i] = true;
                    cout << "Selamat, Anda sekarang adalah member dan akan mendapatkan potongan harga 20%!" << endl;
                } else {
                    cout << "Pendaftaran member dibatalkan." << endl;
                }
            }
            system("pause");
            return;
        }
    }
}

void menuRentalPS() {
    while (true) {
        system("cls");
        head();
        int pilihan, jam;
        cout << "Harga rental PS" << endl;
        cout << "1. PS 3: 1 jam (Rp. 5.000)" << endl;
        cout << "2. PS 4: 1 jam (Rp. 10.000)" << endl;
        cout << "3. PS 5: 1 jam (Rp. 15.000)" << endl;
        cout << "4. Kembali" << endl;
        cout << ">> ";
        cin >> pilihan;
        if (pilihan == 4) {
            return;
        }
        
        if (pilihan < 1 || pilihan > 3) {
            cout << "Pilihan tidak valid" << endl;
            system("pause");
            continue;
        }
        
        int hargarental;
        cout << "Jumlah jam: ";
        cin >> jam;
        
        if (jam <= 0) {
            cout << "Jumlah jam harus lebih dari 0" << endl;
            system("pause");
            continue;
        }

        switch(pilihan) {
            case 1:
                hargarental = 5000 * jam;
                break;
            case 2:
                hargarental = 10000 * jam;
                break;
            case 3:
                hargarental = 15000 * jam;
                break;
        }
        
        if (member[banyakuser - 1]) {
        	if (jam >= 3 && jam < 6){
        	hargarental -= hargarental * 0.1;	
			} else if (jam >= 6){
			hargarental -= hargarental * 0.2;
			}
        }

        totalbiaya[banyakuser - 1] += hargarental; 

        cout << "Total harga rental: Rp. " << hargarental << endl;
        cout << "Rental PS Berhasil...." << endl;
        system("pause");
        break;
    }
}

void menuMemesanMakanan(){
    while (true) {
        system("cls");
        int pilihan, jumlah;
        head();
        cout << "List Makanan/Minuman\n";
        if(banyakmakanan == 0) {
            cout << "Makanan Belum Tersedia\n";
            system("pause");
            return;
        } else {
            for(int i = 0; i < banyakmakanan; i++) {
                cout << i+1 << ". " << makanan[i] << " (Rp. " << harga[i] << ")" << endl;
            }
        }
        cout << "Pilih makanan >> "; cin >> pilihan;
        if(pilihan < 1 || pilihan > banyakmakanan) {
            cout << "Pilihan tidak valid." << endl;
            system("pause");
            continue;
        }
        cout << "Jumlah pesanan >> "; cin >> jumlah;
        system("cls");
        cout << "Makanan yang dipilih adalah: " << makanan[pilihan-1] << endl;
        cout << "Harga: Rp. " << harga[pilihan-1] << endl;
        cout << "Jumlah: " << jumlah << endl;
        cout << "Makanan berhasil dipesan!" << endl;
        totalbiaya[banyakuser - 1] += harga[pilihan-1] * jumlah; 
        system("pause");
        break;
    }
}

void masukanmakanan(){
    system("cls");    
    head();
    cout << "Masukkan makanan/minuman: ";
    getline(cin >> ws, makanan[banyakmakanan]);
    banyakmakanan++;
    cout << "Masukan harga makanan: ";
    cin >> harga[banyakharga];
    banyakharga++;
    cout << "Makanan berhasil ditambahkan!" << endl;
    return;
}

void hapusMakanan() {
    while (true) {
        int pilihan;
        head();
        
        if(banyakmakanan == 0) {
            cout << "Makanan Belum Tersedia\n";
            system("pause");
            return;
        } else {
            for(int i = 0; i < banyakmakanan; i++) {
                cout << i+1 << ". " << makanan[i] << " (Rp. " << harga[i] << ")" << endl;
            }
        }
        cout << "Pilih makanan untuk dihapus >> "; cin >> pilihan;
        if(pilihan < 1 || pilihan > banyakmakanan) {
            cout << "Pilihan tidak valid." << endl;
            system("pause");
            continue;
        }
        
        for(int i = pilihan-1; i < banyakmakanan-1; i++) {
            makanan[i] = makanan[i+1];
            harga[i] = harga[i+1];
        }
        banyakmakanan--;
        banyakharga--;
        cout << "Makanan berhasil dihapus!" << endl;
        system("pause");
        break;
    }
}

void jualMakanan() {
    while (true) {
        int pilih;
        system("cls");
        head();
        cout << "List Makanan/minuman" << endl;
        if (banyakmakanan == 0){
            cout << "Makanan/Minuman belum tersedia\n" << endl;
        }else {
            for(int i = 0; i < banyakmakanan; i++) {
                cout << "~ " << makanan[i] << " (Rp. " << harga[i] << ")" << endl;
            }
        }
        cout << "\n1. Masukan Makanan" << endl;
        cout << "2. Hapus Makanan" << endl;
        cout << "3. Kembali" << endl;
        cout << ">> "; cin >> pilih;
        switch(pilih){
            case 1:
                masukanmakanan();
                break;
            case 2: 
                hapusMakanan();
                break;
            case 3:
                return;
            default:
                cout << "pilihan yang anda masukan salah" << endl;
                system("pause");
                break;      
        }
    }
}

bool login(string &username) {
    system("cls");
    loginhead();
    string password;
    cout << "Masukkan username: ";
    getline(cin >> ws, username);
    cout << "Masukkan password: ";
    getline(cin >> ws, password);
    for(int i = 0; i < banyakuser; i++) {
        if(username == usernames[i] && password == passwords[i]) {
            cout << "Login berhasil!" << endl;
            system("pause");
            return true;
        }
    }
    cout << "Username atau password salah." << endl;
    system("pause");
    return false;
}

void signIn() {
    system("cls");
    signinhead();
    string username, password;
    cout << "Masukan Username: ";
    getline(cin >> ws, username);
    
    for(int i = 0; i < banyakuser; i++) {
        if(username == usernames[i]) {
            cout << "Username sudah ada." << endl;
            system("pause");
            return;
        }
    }
    cout << "Masukan password: ";
    getline(cin >> ws, password);
    usernames[banyakuser] = username;
    passwords[banyakuser] = password;
    banyakuser++;
    cout << "sign in..." << endl;
    system("pause");
}

int menuSetelahLogin(string username) {
    while(true) {
        system("cls");
        head();
        int pilihan;
        if(username == "admin") {
            cout << "1. Jual Makanan" << endl;
            cout << "2. Data Penyewa" << endl;
            cout << "3. Log Out" << endl;
        } else {
            cout << "1. Melakukan Rental PS" << endl;
            cout << "2. Memesan Makanan" << endl;
            cout << "3. Daftar Member" << endl;
            cout << "4. Log Out" << endl;
        }
        cout << ">> ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                if(username == "admin") {
                    jualMakanan();
                } else {
                    menuRentalPS();
                }
                break;
            case 2:
                if(username == "admin") {
                    dataPenyewa();
                } else {
                    menuMemesanMakanan();
                }
                break;
            case 3:
                if(username == "admin") {
                    cout << "Anda telah memilih Log Out." << endl;
                    return 0; 
                } else {
                    daftarMember(username);
                }
                break;
            case 4:
                if(username != "admin") {
                    cout << "Anda telah memilih Log Out." << endl;
                    return 0; 
                }
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                continue; 
        }
        system("pause");
    }
    return 0;
}

int main() {
    while(true) {
        int pilihan = menu();
        switch(pilihan) {
            case 1: {
                string username;
                if(login(username)) {
                    int pilihanSetelahLogin = menuSetelahLogin(username);
                    if(pilihanSetelahLogin == 0) 
                        continue;
                }
                break;
            }
            case 2:
                signIn();
                break;
            case 3:
                cout << "Anda telah memilih Exit. Program akan ditutup." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }
    return 0;
}
