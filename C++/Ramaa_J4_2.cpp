#include <iostream>
using namespace std;

int faktorial(int n) {
    if(n == 0)
        return 1;
    else
        return n * faktorial(n - 1);
}

int permutasi(int n, int r) {
    return faktorial(n) / faktorial(n - r);
}

int kombinasi(int n, int r) {
    return faktorial(n) / (faktorial(r) * faktorial(n - r));
}

void spl(int a[3][3], int b[3]) {
    float matriks[3][4], x[3];
    int i, j, k, l;

    for(i = 0 ; i < 3 ; i++) {
        for(j = 0 ; j < 3; j++) {
            matriks[i][j] = a[i][j];
        }
        matriks[i][3] = b[i];
    }

    cout << "Hasil Augmented matriks" << endl;
    for(i = 0 ; i < 3 ; i++) {
        for(j = 0 ; j < 4 ; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    for(i = 0 ; i < 3 ; i++) {
        for(j = 0; j < 3 ; j++) {
            if(j > i) {
                float ratio = matriks[j][i]/matriks[i][i];
                for(k = 0; k < 4 ; k++) {
                    matriks[j][k] -= ratio * matriks[i][k];
                }
            }
        }
    }

    cout << "Matriks Segitiga Atas | SPL" << endl;
    for(i = 0 ; i < 3 ; i++) {
        for(j = 0 ; j < 3 ; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << "| " << matriks[i][3] << endl;
    }

    x[2] = matriks[2][3]/matriks[2][2];
    for(i = 1 ; i >= 0 ; i--) {
        x[i] = matriks[i][3];
        for(j = i + 1 ; j < 3 ; j++) {
            x[i] = x[i] - matriks[i][j]*x[j];
        }
        x[i] = x[i]/matriks[i][i];
    }

    cout << "x : " << x[0] << endl;
    cout << "y : " << x[1] << endl;
    cout << "z : " << x[2] << endl;
}

int main() {
    int pilihan, n, r, a[3][3], b[3];
    cout << "1. Permutasi" << endl;
    cout << "2. Kombinasi" << endl;
    cout << "3. SPL" << endl;
    cout << "Pilih: ";
    cin >> pilihan;
    switch(pilihan) {
        case 1:
            cout << "Masukan n: ";
            cin >> n;
            cout << "Masukan r: ";
            cin >> r;
            cout << "Hasil Permutasi: " << permutasi(n, r) << endl;
            break;
        case 2:
            cout << "Masukan n: ";
            cin >> n;
            cout << "Masukan r: ";
            cin >> r;
            cout << "Hasil Kombinasi: " << kombinasi(n, r) << endl;
            break;
        case 3:
            cout << "Masukan nilai matriks 3x3" << endl;
            for(int i = 0 ; i < 3 ; i++) {
                for(int j = 0 ; j < 3 ; j++) {
                    cin >> a[i][j];
                }
            }
            cout << "Masukan nilai B" << endl;
            for(int i = 0 ; i < 3 ; i++) {
                cin >> b[i];
            }
            spl(a, b);
            break;
    }
    return 0;
}
