#include<iostream>
using namespace std;

int main(){
	int AB; 
	int CD;
	int tinggi;
	
	cout << "Program penghitung luas trapesium" << endl;
	cout << "Masukkan sisi atas (cm): " ;
	cin >> AB;
	cout << endl << "Masukkan sisi bawah (cm): ";
	cin >> CD;
	cout << endl << "Masukkan tinggi (cm):  ";
	cin >> tinggi;
	
	cout << endl << "Luas Trapesium: " << 0.5 * (AB+CD) * tinggi << " cm";
	return 0;
}