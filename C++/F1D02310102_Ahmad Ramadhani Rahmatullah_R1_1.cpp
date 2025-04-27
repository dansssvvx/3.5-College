#include<iostream>
using namespace std;

int main(){
	char menu = 'A, B, C' ;
	int jumlah;
	int harga;
	int uang;
	int uangindi;
	
	cout << "indi pergi kejalan majapahit bersama fia untuk berburu takjil. Indi berniat untuk mentraktir fia.\n";
	cout << "Ternyata, di situ khalid dan yusri sedang ebrjualan takjil bersama teman-temannya yang lain.\n";
	cout << "Mereka menjual; \n";
	cout << "1 (A). Es Buah Rp 5.000\n";
	cout << "2 (B). Sosis Bakar Rp. 10.000\n";
	cout << "3 (C). Nasi goreng Rp. 15.000\n";
	cout << "Takjil dipilih dengan A, B, dan C\n";
	cout << "Indi dan fia ingin membeli barang yang sama, mereka memilih [A/B/C] dengan jumlah [berapa] ";
	cin >> menu >> jumlah;
	cout << "Indi kemudian mengambil dompetnya dan melihat jumlah uang yang dimilikinya adalah [berapa] ";
	cin >> uangindi;
	
	menu = menu - 16 ;
	
	switch (menu) {
		case 49:
			harga = 5000;
			break;
		case 50:
			harga = 10000;
			break;
		case 51:
			harga = 15000;
			break;
	}
	
	cout << "\nSummary" << endl << "Takjil yang diberi oleh indi dan fia adalah takjil nomor " << menu <<" Sebanyak " << jumlah << " dengan total Rp. " << harga*jumlah << endl;
	cout << "Uang yang dibawa indi adalah Rp. " << uangindi << endl;
	uangindi = uangindi - harga*jumlah;
	cout << "Setelah membayar, uang indi sisa Rp. " << uangindi << endl; 
	
	int uangfia;
	cout << "\nSaat ingin pulang, fia ingin membelikan sesuatu juga untuk indi, jadi dia mengeluarkan dompetnya dan melihat jumlah uang yang dimilikinya adalah ";
	cin >> uangfia;
	uangfia = uangfia - 5000;
	cout << "Ia pun membeli cilok seharga Rp 5.000 sehingga uang fia sisa Rp. " << uangfia <<  endl;
	
	cout << "\nTernyata dompet indi dan fia warna dan bentuknya persis sama" << endl;
	cout << "Saat ingin pulang, mereka berdua bertemu dengan rafi, afif, rama dan yurian, sehingga mereka mengobrol terlebih dahulu" << endl;
	cout << "Indi menitipkan dompetnya ke fia untuk sementara, Kemudian mereka pun pulang dan ternyata dompet indi dan fia tertukar" << endl;
	
	int temp = uangindi;
	uangindi = uangfia;
	uangfia = temp;
	
	cout << "Jadi saat ini dompet yang dibawa indi berisi Rp. " << uangindi << endl;
	cout << "Dan dompet yang dibawa fia berisi Rp. " << uangfia;
 	return 0;
}