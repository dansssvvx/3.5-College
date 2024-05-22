#include<iostream>
#include<conio.h>

#define RESET   "\033[0m"
#define MAGENTA "\033[35m"
using namespace std;

int main(){

	//Menu
	int pilihan;
	char key;
	
	//Pohon Cemara
	int tinggi2;
    int lebar;
    int spasi; 
    int x; 
    
	//Motif Bangun datar
	char huruf = 'A';
	int tinggi;
	char huruf2;
	int Angka;
	int batas = 1;
	
	//Pola Bilangan
	int y = 1;
	int n;
    bool prima;
					
	do{
	
	system ("cls");
	cout << "Selamat Datang:D \nSilahkan Gerakkan menu dengan tombol up & down dan tekan enter untuk memilih \n";
	for (int i = 1; i <= 5; ++i){
		if (i == pilihan){
			cout << MAGENTA;
			switch(i){
				case 1:
					cout << RESET << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << "|           MOTIF BATIK           |" << endl;
					cout << "|              HOLIL              |" << endl;
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					break;
				case 2:
					cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << "|           POHON CEMARA          |" << endl;
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
					break;
				case 3:
					cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << "|           BANGUN DATAR          |" << endl;
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;	
					break;
				case 4:
					cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << "|         POLA BILANGAN          |" << endl;
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
					break;
				case 5:
					cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << "|              KELUAR             |" << endl;
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
					break;
				} 
				cout << RESET;
				} else {
					switch(i){
						case 1:
							cout  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
							cout << "|           MOTIF BATIK           |" << endl;
							cout << "|              HOLIL              |" << endl;
							cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
							break;
						case 2:
							cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
							cout << "|           POHON CEMARA          |" << endl;
							cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
							break;
						case 3:
							cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
							cout << "|           BANGUN DATAR          |" << endl;
							cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;	
							break;
						case 4:
							cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
							cout << "|         POLA BILANGAN          |" << endl;
							cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
							break;						
						case 5:
							cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
							cout << "|              KELUAR             |" << endl;
							cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
							break;
					
				}
			}
				
		}	
		
	
	key = _getch();
	
	switch(key) {
		case 72 :
			if (pilihan > 2)
			pilihan--;
			break;
		case 80 :
		if (pilihan < 5)
			pilihan++;
			break;
	}
	
	} while (key != 13);
	
	switch (pilihan){
			
		case 2: //pohon cemara
		system ("cls");
			cout << "------------------------------" << endl;
			cout << "|          MOTIF             |" << endl;
			cout << "|       POHON CEMARA         |" << endl;
			cout << "------------------------------" << endl;
    
    		cout << "Masukkan Tinggi : "; 
			cin >> tinggi2;
    		cout << "Masukkan Lebar : "; 
			cin >> lebar;
    
    		spasi = lebar * 5; 
            x = 1;
			 
    		for (int a = 1; a <= tinggi2; a++) { 
            	for (int i = x; i <= lebar; i++) { 
                	for (int j = spasi; j >= i; j--) 
                    	cout << " "; 
  
                	for (int k = 1; k <= i; k++) 
                    	cout << "* "; 
  
                	cout << endl; 
            	} 
  
            x = x + 2; 
            lebar = lebar + 2; 
        	} 
  
       
        	for (int i = 1; i <= 4; i++) { 
  
            	for (int j = spasi - 3; j >= 1; j--) 
                	cout << " "; 
  
            	for (int k = 1; k <= 4; k++) 
                	cout << "* "; 
  
            	cout << endl; 
        	} 
			break;
		
		case 3: //bangun datar
		system ("cls");
			cout << "------------------------" << endl;
			cout << "|        MOTIF         |" << endl;
			cout << "|    BANGUN DATAR      |" << endl;
			cout << "------------------------" << endl;
			cout <<"     pola persegi :)     " << endl;
			cout << "Masukkan Jumlah Baris: ";
			int jumlahbaris;
    		cin >> jumlahbaris;


    		for (int i = 0; i < jumlahbaris; ++i) {
        		char huruf1 = 'A';
        		for (int j = 0; j < jumlahbaris; ++j) {
            		if (j <= i)
                		cout << huruf1 << " ";
            		else
                		cout << huruf << " ";
            			huruf1++;
        		}
        		huruf++;
        		cout << endl;
    		}
    		
    		cout << "------------------------" << endl;
			cout << "     Pola Segitiga :|   " <<  endl;
			cout << "Masukkan Jumlah Baris: ";
			cin >> tinggi;
	
			huruf2 = (tinggi % 2 == 0) ? 'A' : 'B';
			Angka = (tinggi % 2 == 0) ? 2 : 1;
	
			for (int i = 0; i < tinggi; i++){
				for (int j = 0; j < tinggi - i - 1; j++){
					cout << " ";
				}
		
				for (int j = 0; j <= i; j++){
					if ( i % 2 == 0) {
						cout << huruf2 << " ";
					} else {
						cout << Angka << " ";
					}
				}
		
				if ( i % 2 == 0){
					huruf2 += 2;
				} else {
					Angka += 2;
				}
		
				cout << endl;
			}	

			cout << "------------------------" << endl;
			cout << "   Pola persegi lagi :)" <<  endl;
			cout << "Masukkan jumlah kolom: ";
    		int kolom;
			cin >> kolom;
			
    		for (int i = 0; i < kolom; ++i) {
        		for (int j = 0; j < kolom; ++j) {
            		if (batas < 10)
                		cout << "0";
            		cout << batas++ << " ";
        		}
        			cout << endl;
    		}
    		
			
		break;
			
		case 4: //Pola Bilangan
		system ("Cls");
			cout << "------------------------" << endl;
			cout << "|     POLA BILANGAN   |" << endl;
			cout << "------------------------" << endl;
			
			int n;
    		cout << "Masukan Nilai ke n: ";
    		cin >> n;
    		
    		if ( n % 2 == 0 ){
    			for (int i = 1; i<= n; ++i){
    				bool prima = true;	
    				
    				for (int j = 2; j * j <= i; ++j){
    					if (i % j == 0){
    						prima = false;
    						break;
						}	
					}
				
				if (prima) {
					if (n < 51) {
						 if ( i == 3 ){
                			cout << "(" << i << "*" << "n" << " = " << i * n << ")" << " ";
                		} else if ( i == 13 ) {
                			cout << "(" << i << "*" << "n" << " = " << i * n << ")" << " ";
                		} else if ( i == 23 ) {
               				cout << "(" << i << "*" << "n" << " = " << i * n << ")" << " ";
                		} else if ( i == 31 ) {
                			cout << "(" << i << "*" << "n" << " = " << i * n << ")" << " ";
                		} else if ( i == 37 ) {
                			cout << "(" << i << "*" << "n" << " = " << i * n << ")" << " ";
                		} else if ( i == 43 ) {
               			 	cout << "(" << i << "*" << "n" << " = " << i * n << ")" << " ";
                		} else 
                			cout << "<" << i << ">" << " ";
            		} else
            			cout << "<" << i << ">" << " ";
					}
				}	
					
			} else {
				for (int i = 0; i < n; i++) {
					if (i==0){
            			cout<<y<<", ";
        			}else{
            			y=y+(y*10);
            			cout<<y<<", ";
					}
        		}
    		}
				
		   			
	
			break;
			
		case 5://exit
			system("Cls");
			cout << "Terimakasih:) ";
			break;
			
		default:
			cout << "Input yang anda masukan salah" << endl;
			break;
		}
	}
