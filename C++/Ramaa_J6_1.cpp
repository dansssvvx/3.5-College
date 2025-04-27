#include <iostream>
using namespace std;

struct Fungsi {
	string nama, argumen[6];
	int jumlahargumen;
};

struct Stack {
	string tipe, nilai;
	Fungsi fungsi;
} stack[9];

string reg[6] = {"RDI", "RSI", "RDX", "RCX", "R8", "R9"};
int jumlahstack = 0, jumlahfungsi = 0;

void pala()
{
	cout << "##       ########    ###    ########  ##    ##      ######   ########    ###     ######   ##    ##     ##          ###    ##    ##   #######   ##     ##  ########\n";
	cout << "##       ##         ## ##   ##     ## ###   ##     ##    ##     ##      ## ##   ##    ##  ##   ##      ##         ## ##    ##  ##   ##     ##  ##     ##     ##\n";
	cout << "##       ##        ##   ##  ##     ## ####  ##     ##           ##     ##   ##  ##        ##  ##       ##        ##   ##    ####    ##     ##  ##     ##     ##\n";
	cout << "##       ######## ##     ## ########  ## ## ##      ######      ##    ##     ## ##        #####        ##       ##     ##    ##     ##     ##  ##     ##     ##\n";
	cout << "##       ##       ######### ##   ##   ##  ####           ##     ##    ######### ##        ##  ##       ##       #########    ##     ##     ##  ##     ##     ##\n";
	cout << "##       ##       ##     ## ##    ##  ##   ###     ##    ##     ##    ##     ## ##    ##  ##   ##      ##       ##     ##    ##     ##     ##  ##     ##     ##\n";
	cout << "######## ######## ##     ## ##     ## ##    ##      ######      ##    ##     ##  ######   ##    ##     ######## ##     ##    ##      #######    #######      ##\n";
}

void menuawal(Stack stack[], string reg[], int &jumlahstack, int &jumlahfungsi);

void adddata(Stack stack[], string reg[], int &jumlahstack, int &jumlahfungsi)
{
	int banyakstack;
	char pilihan, pilihan2;
	cout << "How many stack? : ";
	cin >> banyakstack;

	if (banyakstack <= 0 || banyakstack > 9) {
		cout << "max stack adalah 9!" << endl;
		system("pause");
		system("cls");
		menuawal(stack, reg, jumlahstack, jumlahfungsi);
		return;
	}

	int i = 0;
	do {
		if (i < banyakstack) {
			cout << "You will add function? (Y/N) : ";
			cin >> pilihan;

			if (pilihan == 'y' || pilihan == 'Y') {
				cout << "Have an argument? (Y/N) : ";
				cin >> pilihan2;
				if (pilihan2 == 'y' || pilihan2 == 'Y') {
					int banyakarg;
					cout << "How many arguments? : ";
					cin >> banyakarg;

					if (banyakarg > 0 && banyakarg <= 6) {
						stack[i].tipe = "function";
						cout << "Function "<< jumlahfungsi+1 <<" to push: ";
						cin >> stack[i].fungsi.nama;
						stack[i].fungsi.jumlahargumen = banyakarg;
						jumlahfungsi++;

						for (int j = 0; j < banyakarg; ++j) {
							cout << "Argument - " << j + 1 << " to push : ";
							cin >> stack[i].fungsi.argumen[j];
						}
						jumlahfungsi++;
					} else {
						cout << "Invalid number of arguments. Please enter a number between 1 and 6." << endl;
						continue;
					}
				} else if (pilihan2 == 'n' || pilihan2 == 'N') {
					stack[i].tipe = "function";
					cout << "Function " << jumlahfungsi+1  << " to push: ";
					cin >> stack[i].fungsi.nama;
					stack[i].fungsi.jumlahargumen = 0;
					jumlahfungsi++;
				} else {
					cout << "Invalid input!" << endl;
					continue;
				}
			} else if (pilihan == 'n' || pilihan == 'N') {
				stack[i].tipe = "value";
				cout << "Value "<< jumlahfungsi+1 <<" to push: ";
				cin >> stack[i].nilai;
				jumlahfungsi++;
			} else {
				cout << "Invalid input!" << endl;
				continue;
			}
			i++;
			jumlahstack++;
		}
	} while (i < banyakstack);

	menuawal(stack, reg, jumlahstack, jumlahfungsi);
}

void modedebug(Stack stack[], string reg[], int &jumlahstack, int &jumlahfungsi)
{
	string perintahdebug;
	int indeks = 0;

	cout << "Mode debug >> ";
	cin.ignore();
	getline(cin, perintahdebug);

	while (true) {
		if (perintahdebug == "info stack" || perintahdebug == "info" || perintahdebug == "is") {
			if (jumlahstack < 1) {
				system("cls");
				cout << "-------------------------------- REGISTER --------------------------------\n";
				cout << "No Registers!\n";
				cout << "---------------------------------- STACK ---------------------------------\n";
				cout << "No Stack!\n";
				system("pause");
				menuawal(stack, reg, jumlahstack, jumlahfungsi);
			}

			while (indeks < jumlahstack) {
				system("cls");
				cout << "-------------------------------- REGISTER --------------------------------\n";
				for (int j = 0; j < 6; j++) {
					cout << reg[j] << "\t: ";
					if (stack[indeks].tipe == "value") {
						cout << "0" << endl;
					} else {
						if (stack[indeks].fungsi.argumen[j] != "") {
							cout << stack[indeks].fungsi.argumen[j] << endl;
						} else {
							cout << "0" << endl;
						}
					}
				}
				cout << "---------------------------------- STACK ---------------------------------\n";
				for (int i = 0; i < jumlahstack; i++) {
					if (i == indeks) cout << "=> ";
					else cout << "   ";

					if (stack[i].tipe == "value") cout << &stack[i].nilai << "\t" << stack[i].nilai << endl;
					else cout << &stack[i].fungsi.nama << "\t" << stack[i].fungsi.nama << endl;
				}

				cout << "Command debug >> ";
				getline(cin, perintahdebug);

				if (perintahdebug == "ni" || perintahdebug == "next" || perintahdebug == "next instruction") {
					indeks++;
				} else {
					cout << "Invalid Command!\n";
				}
			}

			system("cls");
			cout << "-------------------------------- REGISTER --------------------------------\n";
			cout << "No Register!\n";
			cout << "---------------------------------- STACK ---------------------------------\n";
			cout << "No Stack!\n";
			system("pause");
			menuawal(stack, reg, jumlahstack, jumlahfungsi);
		} else {
			cout << "Invalid Command\n";
		}
		cout << "Mode debug >> ";
		getline(cin, perintahdebug);
	}
}

void menuawal(Stack stack[], string reg[], int &jumlahstack, int &jumlahfungsi)
{
	system("cls");
	pala();
	int pilihan;
	cout << "1. Add Data" << endl;
	cout << "2. Mode Debug" << endl;
	cout << "3. Exit" << endl;
	cout << ">> ";

	cin >> pilihan;

	switch (pilihan) {
		case 1:
			adddata(stack, reg, jumlahstack, jumlahfungsi); // Pass the arguments here
			break;
		case 2:
			modedebug(stack, reg, jumlahstack, jumlahfungsi);
			break;
		case 3:
			exit(0);
		default:
			cout << "Invalid input!" << endl;
			menuawal(stack, reg, jumlahstack, jumlahfungsi);
	}
}

int main()
{
	Stack stack[9];
	string reg[6] = {"RDI", "RSI", "RDX", "RCX", "R8", "R9"};
	int jumlahstack = 0, jumlahfungsi = 0;
	menuawal(stack, reg, jumlahstack, jumlahfungsi);
	return 0;
}

