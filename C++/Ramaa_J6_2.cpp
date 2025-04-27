#include <iostream>
using namespace std;

struct Game {
	
	struct Objek {
//		1. Player 1
//		2. Player 2
//		3. Leviathan
//		4. Phoenix
//		5. Health Potion
//		6. Buff Potion
		string nama;
		int hp, atk, def, turn;
		
		struct Skill {
			bool aktif = false;
		} skill;
		
	} objek[6];
	
	struct Map {
		string nama;	
	} map;
	
} game;

string centerText(string teks) {
	cout << "\t\t\t " << teks << endl;
	return teks;
}

void bar() {
	cout << "|+|=============================================|+|" << endl;
}

void phoneixModel() {
	bar();
	cout << "\t\t    ///,        ////" << endl;
	cout << "\t\t    \\ /,      / .>." << endl;
	cout << "\t\t     \\  /,   _/` /." << endl;
	cout << "\t\t      \\_ /_/  /." << endl;
	cout << "\t\t       \\/_  .<" << endl;
	cout << "\t\t       /<<<<\\\\" << endl;
	cout << "\t\t      /,)^>>.\\\\" << endl;
	cout << "\t\t      (/   \\\\ /\\\\\\" << endl;
	cout << "\t\t           //  ```` " << endl;
	cout << "\t\t          ((``" << endl;
	bar();
	centerText("Phoenix");
	bar();
}

void leviathanModel() {
	bar();
	cout << endl;
	cout << "\t\t         ,--._,-." << endl;
	cout << "\t\t       ,_\\.--.,.--./" << endl;
	cout << "\t\t    ((@@/  /         \\" << endl;
	cout << "\t\t   (.`\\@@/  / (|)' '(|) \\" << endl;
	cout << "\t\t  *'@@  /|''\\--,:_:,--/" << endl;
	cout << "\t\t/ @,--/|(~`\\_ V   V _/" << endl;
	cout << "\t\t|\"---< | \\    \\\\ ___ //" << endl;
	cout << "\t\t|>----<\\ @)    ;~~~;" << endl;
	cout << "\t\t\\(>-----<\\@\")" << endl;
	bar();
	centerText("Leviathan");
	bar();
}

string square(string teks) {
	bar();
	cout << "| |\t\t\t " << teks << " \t\t\t| |";
	bar();
	return teks;
}

int map(int lokasi) {
	char indeks;
	if (lokasi == 1 ){
		indeks = '!';
	} else {
		indeks = '#';
	}
	
	cout << "\t\t\t  (" << indeks << ")" << endl;
	cout << "\t\t\t   |" << endl;
	cout << "\t\t\t   |" << endl;
	cout << "\t\t\t  (" << indeks << ")" << endl;
	cout << "\t\t\t   |" << endl;
	cout << "\t\t\t   |" << endl;
	cout << "\t\t\t  (" << indeks << ")" << endl;
	cout << "\t\t\t  / \\_" << endl;
	cout << "\t\t\t /    \\_" << endl;
	cout << "\t\t\t/      ("<< indeks << ")" << endl;
	return lokasi;
}

int main() {
	int a = 0;
	map (a);
	return 0;
}
