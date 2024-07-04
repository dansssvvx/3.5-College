#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

using namespace std;	

string player;
int banyakuser = 0, skor = 0;
string fname [144] = {"DEVITA AMALIA MULYONO", "I NYOMAN SUDARSANA", "KHOLIQ MITRA RAHARJA", "LALU ADITYA PRATAMA JELINDRA", "MUHAMMAD RAECHAN ULWAN ZACKY", "MUHAMMAD ADHITYA  NUGRAHA", "MUHAMMAD IHDAL FAHRONI", "MUZAYYAN ROZAAN", "NENGAH ANGGI JUWITA SARI", "ROMAN IBRAHIMA ARCHISAPPE CHARENI", "AHMAD BUDI SETIAWAN", "ANDRA AUFARISQUE DJAYADI", "ANGGIRI DAHLIA CANDRA", "AUDINA JELITA", "FAKHRURRIZAL ADHIRAJASA", "GIAN KAUSARI", "I DEWA GEDE BAGUS WIDIARTHA UTAMA", "I MADE INDRA DWI PAYANA", "IDA BAGUS AMANTA PRADIPA KRISHNA", "KANIA PUTRI ROHIMATUZ AZZAHRA HAMDANI", "KEVIN MUAMMAR GATHFAN", "L. APRILIO APRIZIANO", "LALU AQSHA NAYAKA MAULANA", "LINDA JULIVIA", "M. RIZKI JUNIARDI", "MUHAMMAD ABIYYU RAMADHAN", "MUHAMMAD ALFATH MAVIANZA", "MUHAMMAD ANSHAR PUTRA", "MUHAMMAD FAWAZ HADIMATULLOH", "MUHAMMAD IQBAL TAUFIQ", "MUSTOFA ARIF", "PINKA DIMA CALISTA", "SAUFAN RIDHO", "SYA\'BANUL MUKARAM", "ZARIZKY MEIDYANSYAH", "AHMAD MUSLIHUL KHAIR", "AZIZAH NURUL INDAH AMRIANI", "FADLULLAH HASAN", "KURNIA DWI SURYA", "RAKASYA YOGA SURYA PRATAMA", "SINDI SUTRISNO EKA", "ZAMZAMI SATRIA TEGAR", "ADITYA", "ANDREW NATHANIEL KOYLAL", "BAIQ ALFIA ZAHIRA", "DATU REKSA HAMZA PUTRA", "FADILA RAHMANIA", "FITRI NUFA DASTANA", "I PUTU YUDHA MADHA NAKULA PUTRA GAMBEK", "JULIA ARIYANI", "KARINA SEPTIA SUWANDI", "M. ALI ABIDILLAH KHOTAMI", "NURMIFTAH AZIS", "RENI SOPIANI", "WICAKSONO HADIDUL MANNAN", "YUSRI ABDI", "AHMAD RAMADHANI RAHMATULLAH", "ANJI SOHIB ALAWI", "CHRISTIAN HADI CANDRA", "DZAKANOV INSHOOFI", "IZZAT NAZHIEFA", "LALU KAISAR PANJI MALAKA", "LALU MUHAMMAD RIZALDI KURNIAWAN", "M. WAHYU HILAL ABROOR", "MUHAMMAD ARAFA YAHFAZKA", "NUR ADINDA JUNIARTI", "R. RAFI YUDI PRAMANA", "RENGGANIS CAHYA ANDINI", "SUCITASARI RAHMADANI", "UMAM ALPARIZI", "M. BAYU AJI", "MUHAMMAD FARUK WIRA PRABUANA JAMALUDIN", "AMALIA MIRASAFITRI", "BAGUS ESA WIJAYA KUSUMA", "HILYA FITRI", "NABILA ZAHIRANI", "ROBI\'ATUL IZZATI", "VALERINA JESIKA DEWI", "ADITIA RAHMAT MAULANA", "AYU DIANA", "BAIQ KUSTINA AMRIANA", "DIDY ARDIYANTO", "FARID NANDA SYAUQI", "INTAN NURGITASARI", "KAMILIA ROSADA", "MIKA KHAIRAN DJUBIKIT", "NAUFAL IHSANUL ISLAM", "PUDAEL ZIKRI", "WIWIK PUTRI", "APRIESNA ZULHAN", "ALIFAH RIZKI SAPUTRI", "ARYA RAYAN UTAMA", "CINDY NATASYA AULIA PUTRI", "FIKI ANDRIAN", "LALU AHMAD PURWADI", "LALU MAULANA RIZKI HIDAYAT", "LUTFI ALFARIZI", "M. DANUARTA WIRAGUNA", "MUHAMMAD RIDHO ADIL FURQON", "NURACHMAD HIDAYAT PUTRA CENDANA", "RAFFI FATHONI", "SALSA REIKE MAHARANI", "SULTAN KUSUMA JAYA", "YUDHI FAJAR PRATAMA", "MAULIDA CITRA ILLIYYIN", "ZAHRATU SYITA", "ADITIAS ZULMATORIQ", "AZIZAH INDRIANI PUTRI", "DANANG ADIWIJAYA", "DODI WIJAYA", "FIQRO NAJIAH", "I NYOMAN SWARDI JAYA PUTRA", "JUAN JORDAN ANUGRAH", "KANDA RIFQI ALFAZ", "LALU RIFQI RAMADHAN", "MUHAMMAD RENDI MAULA", "AYU LIZA PUTRI WIWAHA", "BAIQ ADELIA DWI SAVITRI", "ALYSA MELIANA", "NAUFAL PRAMUDYA ANANDA", "PUTU PASEK PANDU PITRA PRATAMA", "WADIS FREANDLY", "YURIAN FATHUR FAJAR", "AHMAD MADANI", "ALYA DWI PANGESTI", "BAIQ MUTIA DEWI EDELWEIS", "FAIRUZA LUTHFIANA", "I PUTU ANANTA SUGIARTHA", "LALU ENGGUR WIRE WANGSE", "LALU MUHAMMAD FARHAN", "M. KHALID AL REJEKI", "MUHAMMAD AFIF DHIYAULHAQ", "NANANG ALFIAN RIZKI FAKHRONI", "PRAYADI GIRI PURNAMA", "RAFLY RIDHO\' SUKARDI", "SEFTIYANDI", "SYAZWANI", "KAZIYA DWI FADIA RUSDI", "MUH. RIZKY DESTIAWANSYAH", "RIFKY AKBAR UTOMO PUTRA" };


struct who {
    string namalengkap;
    string nama;
    char jeniskelamin;
    char kelas;
} orang [144];

struct Player {
    string nama;
    int skor;
} p [100];

void startmenu (string player), play(), data(), login (), guide(), board(), creditsmenu();

void t() {
    cout << "\t\t";
}

void garis() {
    t(); cout << "-------------------------------------------------------------------------------------------------------------------\n";
}

void head() {
    t(); cout << GREEN << "   _____  _    _  ______   _____  _____   __          __ _    _   ____   _  _____     _____  _______   ___   ____  " << endl;
    t(); cout << "  / ____|| |  | ||  ____| / ____|/ ____|  \\ \\        / /| |  | | / __ \\ ( )/ ____|   |_   _||__   __| |__ \\ |___ \\ " << endl;
    t(); cout << " | |  __ | |  | || |__   | (___ | (___     \\ \\  /\\  / / | |__| || |  | ||/| (___       | |     | |       ) |  __) |" << endl;
    t(); cout << " | | |_ || |  | ||  __|   \\___ \\ \\___ \\     \\ \\/  \\/ /  |  __  || |  | |   \\___ \\      | |     | |      / /  |__ < " << endl;
    t(); cout << " | |__| || |__| || |____  ____) |____) |     \\  /\\  /   | |  | || |__| |   ____) |    _| |_    | |     / /_  ___) |" << endl;
    t(); cout << "  \\_____| \\____/ |______||_____/|_____/       \\/  \\/    |_|  |_| \\____/   |_____/    |_____|   |_|    |____||____/ \n" << endl;
    t(); t(); t(); cout << "\tGuess the name - Informatics '23";
	t(); cout << RESET << endl;
    garis();
}

void start() {
    t(); cout << "  ___  _               _   " << endl;
    t(); cout << "/ __|| |_  __ _  _ _ | |_ " << endl;
    t(); cout << " \\__ \\|  _|/ _` || '_||  _|" << endl;
    t(); cout << " |___/ \\__|\\__,_||_|   \\__|" << endl;
    t(); cout << endl;
}

void exitMenu() {
    t(); t(); t(); t(); t(); t(); cout << "\t  ___ __ __(_)| |_ \n";
    t(); t(); t(); t(); t(); t(); cout << "\t / -_)\\ \\ /| ||  _|\n";
    t(); t(); t(); t(); t(); t(); cout << "\t \\___|/_\\_\\|_| \\__|\n";
    cout << endl;
}

void leaderboard() {    
    t(); t(); cout << "  _                _            _                        _ \n";
    t(); t(); cout << " | | ___  __ _  __| | ___  _ _ | |__  ___  __ _  _ _  __| |\n";
    t(); t(); cout << " | |/ -_)/ _` |/ _` |/ -_)| '_|| '_ \\/ _ \\/ _` || '_|/ _` |\n";
    t(); t(); cout << " |_|\\___|\\__,_|\\__,_|\\___||_|  |_.__/\\___/\\__,_||_|  \\__,_|\n";
    cout << endl;
}

void credits() {
    t(); t(); t(); t(); t(); cout << "                   _  _  _       \n";
    t(); t(); t(); t(); t(); cout << "  __  _ _  ___  __| |(_)| |_  ___\n";
    t(); t(); t(); t(); t(); cout << " / _|| '_|/ -_)/ _` || ||  _|(_-<\n";
    t(); t(); t(); t(); t(); cout << " \\__||_|  \\___|\\__,_||_| \\__|/__/\n";
    cout << endl;                                                                  
}

void menu() {
    int pilih = 0;
    char key;

    do {
        system("cls");

        head();
        cout << "\n\n";

        for (int i = 0; i <= 3; i++) {
            if (i == pilih) {
                cout << GREEN;
                switch(i) {
                    case 0:
                        start();
                        break;
                    case 1:
                        leaderboard();
                        break;
                    case 2:
                        credits();
                        break;
                    case 3:
                        exitMenu();
                        break;
                }
                cout << RESET;
            } else {
                switch(i) {
                    case 0:
                        start();
                        break;
                    case 1:
                        leaderboard();
                        break;
                    case 2:
                        credits();
                        break;
                    case 3:
                        exitMenu();
                        break;
                }
            }
        }

        key = _getch();

        switch(key) {
            case 72: 
                if (pilih > 0) {
                    pilih--;
                }
                break;
            case 80: 
                if (pilih < 3) {
                    pilih++;
                }
                break;
        }
    } while (key != 13); 

	garis();
	
    system("cls");
    switch(pilih) {
        case 0:
			login();
            break;
        case 1:
        	board();
            break;
        case 2:
        	creditsmenu();
            break;
        case 3:
        	return;
            break;
    }
    getch();
}

void login (){
	system("cls");
	head();
	
	t(); cout << "Silahkan Masukkan nama anda : "; 
	getline (cin >> ws, player);
	
	for (int i = banyakuser ; i < 100; i++){
		p[i].nama = player;
	}
	banyakuser++;
	
	startmenu (player);
}

void startmenu (string player){
	int pilih;
	
	do{
	system("cls");
	head();	
	t(); t(); t();cout << "\tHello, " << player << ". Welcomee!! " << GREEN << "\\(^-^)/! " << RESET << endl;
	garis();
	t(); cout << GREEN << "(1). Main game\n";
	t(); cout << "(2). Data\n";
	t(); cout << "(3). Guide\n";
	t(); cout << "(4). Exit\n" << RESET << endl;;
	t(); cout << ">> "; cin >> pilih;
    
	} while (pilih < 0 || pilih > 4);
	 
	switch(pilih){
		case 1:
			garis();
			t(); cout << "Program akan dimulai dalam 5 detik lagi\n";
			t(); cout << "loading";
			for (int i = 0; i < 10; ++i) {
       		this_thread::sleep_for(chrono::milliseconds(500));

       		cout << " .";
   			}
   			garis();
			play();
			break;
		case 2:
			data();
			break;
		case 4:
			menu();
			break;
		case 3:
			guide();
			break;
	}
}

void play(){
	system("cls");
	head();
	int index;
	
	string coba;
	srand(time(0));
	index = rand() % 144;
	
	string jawaban = orang[index].nama;
	int kesempatan = jawaban.length();
	
	do{
		t(); t(); t(); t(); cout << GREEN << "SKOR = " << skor << RESET << endl;
		t(); cout << "TOTAL WORDS = " << jawaban.length() << " --------------------------------------------------------------------------------------- " << "ATTEMPS = " << kesempatan << endl << endl; 
		t(); cout << RESET << "GUESS THE WORDS : ";
		cin >> coba;
		
		for (auto &c : coba) c = toupper(c);
		
		 for (size_t i = 0; i < coba.length(); ++i) {
            
			if (i < jawaban.length() && coba[i] == jawaban[i]) {
              t(); t(); t(); t(); cout << "\t" << GREEN << coba[i] << "\n" << RESET;
            } else if (jawaban.find(coba[i]) != string::npos) {
                t(); t(); t(); t(); cout << "\t" << YELLOW << coba[i] << "\n" << RESET;
            } else {
                t(); t(); t(); t(); cout << "\t" << RED << coba[i] << "\n" << RESET;
            }
        }
        cout << endl;
				
		char a;
		
		if (coba ==  "hint1" || coba == "HINT1"){
			t(); cout << "Orang yang anda coba tebak adalah anak kelas " << orang[index].kelas << endl; 
		} else if(coba == "hint2" || coba == "HINT2"){
			t(); cout << "Orang yang anda coba tebak berjenis kelamin " << orang[index].jeniskelamin << endl;
		} else if(coba == "giveup" || coba == "GIVEUP"){
			t(); cout << "Menyerah ? Kenapa Selemah itu ?" << endl;
			t(); cout << "Orang yang anda coba tebak adalah : "  << orang[index].nama << endl;
			t(); cout << "Nama Lengkap : " << fname[index] << endl;  
			t(); cout << "Kelas : " << orang[index].kelas << endl;
			t(); cout << "Jenis Kelamin : " << orang[index].jeniskelamin << RESET << endl;
			system("pause");
			startmenu(player);
		}
		
		if (coba == jawaban ){
			skor += 5;
			t(); cout << GREEN << "apakah ingin bermain lagi ? ( Y/N || random input will make the game starts ) : "; cin >> a;
			
			if ( a == 'N' || a == 'n' ){
				for (int i = banyakuser ; i < 100; i++){
					p[i].skor = skor;
				}
				skor = 0;
				menu();
			} else{
				t(); cout << "Program akan dimulai lagi......" << endl;
				t(); cout << "Loading";
				for (int i = 0; i < 10; ++i) {
	       		this_thread::sleep_for(chrono::milliseconds(500));
	       		cout << " .";
	       		play();
	   			}
			}
		} else {
			kesempatan--;
		}
		
	} while (kesempatan > 0 && coba != jawaban);
	
	p[banyakuser - 1].skor = skor;
	if (kesempatan == 0){
		t(); cout << "Orang yang anda coba tebak adalah : "  << orang[index].nama << endl;
		t(); cout << "Nama Lengkap : " << fname[index] << endl;  
		t(); cout << "Kelas : " << orang[index].kelas << endl;
		t(); cout << "Jenis Kelamin : " << orang[index].jeniskelamin << RESET << endl;
		system("pause");
		startmenu(player);
				
	}
}

void data(){
	system("cls");
	head();
	t(); t(); t(); cout << "\t  NAMA \t-\tKELAS\t-\tJENISKELAMIN\n\n\n";
	for(int i = 0; i < 144; i++){
		t(); cout << i+1 << ". " << orang[i].nama << "\t-\t" << orang[i].kelas << "\t-\t" << orang[i].jeniskelamin << endl;  
	}
	system("pause");
	startmenu(player);
}

void guide(){
	system("cls");
	head();
	t(); t(); t(); cout << "\tHOW TO PLAY WORD LADDER GAME?\n" << endl;
	
	
	t(); t(); t(); t();cout << "  _.--,-```-.    \n";
	t(); t(); t(); t();cout << " /    /      '.  \n";
	t(); t(); t(); t();cout << "/  ../         ; \n";
	t(); t(); t(); t();cout << "\\  ``\\   ``-    \'\n";
	t(); t(); t(); t();cout << " \\ ___\\/    \\   :\n";
	t(); t(); t(); t();cout << "       \\    :   |\n";
	t(); t(); t(); t();cout << "       |    ;  . \n";
	t(); t(); t(); t();cout << "      ;   ;   :  \n";
	t(); t(); t(); t();cout << "     /   :   :   \n";
	t(); t(); t(); t();cout << "     `---'.  |   \n";
	t(); t(); t(); t();cout << "      `--..`;    \n";
	t(); t(); t(); t();cout << "    .--,_        \n";
	t(); t(); t(); t();cout << "    |    |`.     \n";
	t(); t(); t(); t();cout << "    `-- -`, ;\n";    
	t(); t(); t(); t();cout << "      '---`\"\n";     
    cout << endl;         

	
	t(); cout << "Anda harus menebak kata yang tersembunyi dalam beberapa percobaan dan warna huruf berubah untuk menunjukkan seberapa\n"; 
	t(); t(); t(); t(); cout << "dekat Anda.\n\n";
	t(); t(); cout << "\tUntuk memulai permainan, cukup masukkan kata apa saja, misalnya:\n\n";
	
	t(); t(); t(); t(); cout << RED << "    B" << GREEN << "A" << RED << "YU\n\n" << RESET;
	t(); t(); cout << RED << "\tB, Y, U " << RESET << "Berwarna merah. Artinya tidak ada dalam kata target sama sekali.\n";
	t(); t(); t(); cout << GREEN << "A " << RESET << "berwarna hijau. Artinya ada dikata dan tempat yang benar.\n\n";
	t(); t(); cout << "\tAnda pun mencoba untuk menemukan huruf yang cocok dalam kata target.\n\n";
	t(); t(); t(); t(); cout << RED << "    YUDI\n" << RESET;
	t(); t(); t(); t(); cout << GREEN << "    RA" << RED << "J" << GREEN << "A\n\n" << RESET;
	t(); t(); t(); t(); cout << "Sangat dekat!\n\n";
	
	t(); t(); t(); t(); cout << GREEN << "    RAMA\n\n" << RESET;
	t(); t(); cout << "\tselamat, jawaban anda benar!. hehehehe gmn ? cukup mudah bukan :D! \n\n";
	
	t(); cout << "Mungkin dalam beberapa kasus, ada huruf yang berwarna " << YELLOW << "Kuning " << RESET << " itu artinya ada dikata, namun berada ditempat yang salah!\n\n";
	t(); cout << "Extra Feature :\n"; 
	t(); cout << "1. " << GREEN << "\"hint1\" " << RESET << " untuk menampilkan Kelas orang yang anda coba tebak. \n"; 
	t(); cout << "2. " << GREEN <<"\"hint2\" " << RESET << " untuk menampilkan jenis kelamin orang yang anda coba tebak. \n"; 
	t(); cout << "3. " << RED <<"\"giveup\" " << RESET << " untuk menampilkan Kelas orang yang anda coba tebak. \n\n"; 
	t(); cout << "jika menggunakan salah satu command diatas, maka kesempatanmu akan berkurang :)\n";
	garis();
	system("pause");
	startmenu(player);
	
}

void board() {
    system("cls");
    head();
    
    t(); t(); t(); t(); cout << "Leaderboard:\n";
    
    if (banyakuser == 0) {
        t(); cout << "Belum ada Pemain Saat ini. \n";
    } else {
        for (int i = 0; i < banyakuser; i++) {
            t(); cout << i + 1 << ". Nama: " << p[i].nama << ", Skor: " << p[i].skor << endl;
        }

        // Inisialisasi topp dengan pointer ke pemain pertama
        Player *topp = &p[0];
        for (int i = 1; i < banyakuser; i++) {
            if (p[i].skor > topp->skor) {
                topp = &p[i];
            }
        }

        t(); cout << "Top Pemain dengan skor tertinggi: " << topp->nama << " dengan skor " << topp->skor << endl;
    }
    
    system("pause");
    system("cls");
    menu();
}

void creditsmenu() {
	system("cls");
	head();
    string a[] = {
        "THANKS TO:\n", 
        "\tALLAH SWT",
		"\tWORDLE.ORG",
		"\tMBA AGNA", 
		"\tBANG KHOLIL",
		"\tMIKE BERG, HONGLI LAI, YIANNIS AMANDRAVELLOS (main contributor of DEV C++)\n",
        "TEAM: \n",
        "\tAHMAD RAMADHANI RAHMATULLAH",
        "\tFAKHRURRIZAL ADHIRAJASA",
        "\tM. BAYU AJI",
        "\tYUDHI FAJAR PRATAMA\n",
        "PJ PENGINPUTAN NAMA : \n",
        "\tFAKHRURRIZAL ADHIRAJASA (PJ KLS A)",
        "\tM. BAYU AJI (PJ KLS B, DAN D)",
        "\tYUDHI FAJAR PRATAMA (PJ KLS C)",
        "\tAHMAD RAMADHANI RAHMATULLAH (COOKED) GOSONG CHEF :x\n",
//        "-------------------"
    };

    for (const auto& line : a) {
        t(); cout << line << endl;
        this_thread::sleep_for(chrono::seconds(1)); 
    }
    
    system ("pause");
    system ("cls");
    menu();
}

int main() {
	string b [144] = {"DEVITA", "OMING", "KHOLIQ", "ADIT", "JAKI", "ADHIT", "IDAL", "YAYAN", "ENJI", "ROMAN", "IWAN", "ANDRA", "ANGGI", "DINA", "RAJA", "GIAN", "BAGUS", "INDRA", "AMANTA", "RARA", "KEVIN", "ARIL", "AQSHA", "LINDA", "ARDI", "ABI", "ALFATH", "AAN", "FAWAS", "IQBAL", "ARIF", "CALISTA", "SAUFAN", "BANU", "JARIS", "KHAIR", "INDAH", "IFAD", "RANIA", "YOGA", "SINDI", "TEGAR", "ADIT", "DRU", "FIA", "REKSA", "FADILA", "NUFA", "YUDHA", "NINI", "KARIN", "ALI", "MIFTAH", "RENI", "WICAK", "ABDI", "RAMA", "ANJI", "CHRIS", "ZAKA", "IZZAT", "KAISAR", "ALDI", "WAHYU", "FAZA", "DINDA", "RAFI", "GANIS", "SUCI", "UMAM", "BAYU", "WIRA", "AMEL", "BAGUS", "HILYA", "NABILA", "IZZA", "VALERINE", "ADIT", "AYU", "NANA", "DIDY", "FARID", "INTAN", "OCHA", "MIKA", "NAUFAL", "DAEL", "WIWIK", "ZULHAN", "ALIFAH", "RAYAN", "CINDY", "FIKI", "BAGAS", "MAULANA", "LUTFI", "ARTA", "RIDHO", "DANANG", "RAFFI", "SALSA", "SULTAN", "YUDHI", "MAULIDA", "ZAHRA", "IRFAN", "NAYLA", "RIZAL", "MAJDI", "TORIQ", "INDI", "DANANG", "DODI", "OPIQ", "JAYE", "JUAN", "KANDA", "QIQI", "RENDI", "AYU", "ADEL", "ALYSA", "NAUFAL", "PANDU", "WADIS", "FAJAR", "MADANI", "ALYA", "MUTIA", "FIA", "ANANTA", "ENGGUR", "AAN", "KHALID", "AFIF", "NANANG", "GIRI", "RIDHO", "YANDI", "ANIS", "KAZIYA", "DESTI", "RIFKY"};
	char c [144] = {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D'};
	char d [144] = {'P', 'L', 'L', 'L', 'P', 'L', 'L', 'L', 'P', 'L', 'L', 'L', 'P', 'P', 'L', 'L', 'L', 'L', 'L', 'P', 'L', 'L', 'L', 'P', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'P', 'L', 'L', 'L', 'L', 'P', 'L', 'P', 'L', 'P', 'L', 'L', 'L', 'P', 'L', 'P', 'P', 'L', 'P', 'P', 'L', 'P', 'P', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'P', 'L', 'P', 'P', 'L', 'L', 'L', 'P', 'L', 'P', 'P', 'P', 'P', 'L', 'P', 'P', 'L', 'L', 'P', 'P', 'L', 'L', 'L', 'P', 'L', 'P', 'L', 'P', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'P', 'L', 'L', 'P', 'P', 'L', 'P', 'L', 'L', 'L', 'P', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'P', 'P', 'P', 'L', 'L', 'P', 'L', 'L', 'P', 'P', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'P', 'L', 'L'};
	
	for (int i = 0; i < 144; i++){
//		orang[i].namalengkap = a[i];
		orang[i].nama = b[i];
		orang[i].kelas = c[i];
		orang[i].jeniskelamin = d[i];
	}
	
//	string jawaban;
//
//	index = rand() % 144;
//	jawaban[orang[index].nama.length()];
//	char jawab[orang[index].nama.length() + 1 ];
//	
//	jawab[orang[index].nama.length()] = '\0';
	
	menu();

    return 0;
}
