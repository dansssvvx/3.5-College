// simple calculator implementation on c++

#include <iostream>
using namespace std;

int function(int a, int b, char d){
    int c;

    if ( d == '+'){
        c = a + b;
    } else if ( d == '-' ){
         c = a - b;
    } else if ( d == '/' ){
        c = a / b;    
    } else if (d == '*' ){
        c = a * b;
    } else{
        cout << "operation error!"
             << "please input valid operatoin"
             << "(- + / *)";
    }
    
    cout << c;

    return c;
} 

int main(){
	int pilihan, num, num1;
	char op;    
    cout << "choose function\n"
         << "1. calculator\n"
         << "2. exit\n"
         << ">> "; cin >> pilihan;
    
    if (pilihan == 1 || pilihan == 2){
    	if (pilihan != 2){
    		cout << "pls input the number\n"
    			 << "syntax, (number, operation, number)\n"
    			 << "ex : 4+5\n"
    			 << " >> "; cin >> num; cin >> op; cin >> num1;
    			
    		function (num, num1, op);
    	} else {
    		return 0;
		}
	} else {
		cout << "wrong number to input\n"
			 << "pls input the right numb\n";
	}
         
    

}
