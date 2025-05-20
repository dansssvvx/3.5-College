#include <iostream>
#include <iomanip>
using namespace std;


int pilihan;
bool condition = false;

void CoalescedHashing(), LichEisch(), ProgressiveOverflow(), Bucket(), PembagianLinier(), ResolusiKolisi();

int main() {
	ResolusiKolisi();
	
}


void cls() {
	system("cls");
}

bool FailureHandling(int a, int b) {

	if (pilihan < a || pilihan > b) {
		cout << "pilihan yang anda masukkan salah" << endl;
		return false;
	}
	return true;
}

void head() {
	cout << R"(
	
 __       __                                                                                          __                  __  __            __ 
/  \     /  |                                                                                        /  |                /  |/  |          /  |
$$  \   /$$ |  ______   _______    ______       __   ______   _____  ____    ______   _______        $$ |   __   ______  $$ |$$/   _______ $$/ 
$$$  \ /$$$ | /      \ /       \  /      \     /  | /      \ /     \/    \  /      \ /       \       $$ |  /  | /      \ $$ |/  | /       |/  |
$$$$  /$$$$ | $$$$$$  |$$$$$$$  | $$$$$$  |    $$/ /$$$$$$  |$$$$$$ $$$$  |/$$$$$$  |$$$$$$$  |      $$ |_/$$/ /$$$$$$  |$$ |$$ |/$$$$$$$/ $$ |
$$ $$ $$/$$ | /    $$ |$$ |  $$ | /    $$ |    /  |$$    $$ |$$ | $$ | $$ |$$    $$ |$$ |  $$ |      $$   $$<  $$ |  $$ |$$ |$$ |$$      \ $$ |
$$ |$$$/ $$ |/$$$$$$$ |$$ |  $$ |/$$$$$$$ |    $$ |$$$$$$$$/ $$ | $$ | $$ |$$$$$$$$/ $$ |  $$ |      $$$$$$  \ $$ \__$$ |$$ |$$ | $$$$$$  |$$ |
$$ | $/  $$ |$$    $$ |$$ |  $$ |$$    $$ |    $$ |$$       |$$ | $$ | $$ |$$       |$$ |  $$ |      $$ | $$  |$$    $$/ $$ |$$ |/     $$/ $$ |
$$/      $$/  $$$$$$$/ $$/   $$/  $$$$$$$/__   $$ | $$$$$$$/ $$/  $$/  $$/  $$$$$$$/ $$/   $$/       $$/   $$/  $$$$$$/  $$/ $$/ $$$$$$$/  $$/ 
                                         /  \__$$ |                                                                                            
                                         $$    $$/                                                                                             
                                          $$$$$$/                                             )";
	cout << endl;
}

void ResolusiKolisi() {
	do {
		cls();
		head();
		
		cout << " --- Teknik Resolusi Kolisi --- " << endl;
		cout << "1. Coalesced-Hashing" << endl;
		cout << "2. LICH & EISCH" << endl;
		cout << "3. Progressive Overflow" << endl;
		cout << "4. Bucket" << endl;
		cout << "5. Pembagian Linier" << endl;
		
		cout  << ">> ";

		cin >> pilihan;
		condition = FailureHandling(1, 5);

	} while(!condition);

	switch(pilihan) {
		case 1: CoalescedHashing(); break;
//		case 2: LichEisch(); break;
//		case 3: ProgressiveOverflow(); break;
//		case 4: Bucket(); break;
//		case 5: PembagianLinier(); break;
	}

}

void CoalescedHashing(){
	int count, capacity;
	
	cout << "--- CoalescedHashing ---" << endl << endl;
	cout << "Silahkan Inputkan Kapasitas : "; cin >> capacity;
	cout << "Silahkan Inputkan banyak data : "; cin >> count;
	
	int record[count];
	
	for (int i = 0; i < count; i++){
		
		if (i == 0){
			cout << "Silahkan Inputkan data ke-" << i+1 << " : "; cin >> record[i];	
		 } else {
			cout << "-----------//------------ " << i+1 << " : "; cin >> record[i];
		 }	
		
	}
	
	cout << "+-------+---------+-------------------+" << endl;
	cout << "| " << left << setw(5) << "index"
		 << " | " << setw(6) << "Rekaman"
		 << " | " << setw(16) << "Medan Penghubung" << " | " << endl;
	cout << "+-------+---------+-------------------+" << endl;
	
	for (int j = 0; j < capacity; j++){
		bool terisi = false;
		
		int hasil = record[j] % capacity;
		cout << "| " << left << setw(5) << j;
		if(hasil == j){
	 			 cout<< " | " << setw(6) << record[j]
	 			 << " | " << setw(16) << "^" << " | " << endl;
			cout << "+-------+---------+-------------------+" << endl;
		}
	
	}
	
	
	
}