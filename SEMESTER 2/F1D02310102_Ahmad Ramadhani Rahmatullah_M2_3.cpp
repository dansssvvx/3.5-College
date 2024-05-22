#include <iostream>
using namespace std;

int main() {
    cout << "Masukkan Radius Bulan: ";

    int r = 0;
    cin >> r;

    if (r <= 0) {
        cout << "Radius harus lebih besar dari 0." << endl;
        return 1;
    }

    int mask = r * 3;
    int operation = -1;

    while (true) {
        system("Cls");
        for (int y = 0; y < (r * 2) + 1; ++y) {
            for (int x = 0; x < (r * 2) + 1; ++x) {
                if (((x - r) * (x - r)) + (((y - r) * (y - r)) * 2) < r * r
                    && (x + 2) % 2 == 0){
                    cout << "\e[" << y << ";" << x << "H" << "*";
                }

                if (((x - mask) * (x - mask)) + (((y - r) *  (y - r)) * 2) < r * r
                    && (x + 2) % 2 == 0) {
                    cout << "\e[" << y << ";" << x << "H" << " ";
                }
            }
        }

        cout << endl;
        system("Cls");

        mask += operation;
        if (mask < 0) {
            operation = 1;
           system("Cls");
        } else if (mask > (r * 3)) {
            operation = -1;
            system("Cls"); 
        }
    }

    return 0;
}
