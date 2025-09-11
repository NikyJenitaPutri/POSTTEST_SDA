#include <iostream>
using namespace std;

int main(){
    int matriks[3][3];

    //Input matriks 
    cout << "Masukkan elemen matriks 3x3 : " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "M[" << i << "][" << j << "] = ";
            cin >> matriks[i][j];
        }
    }

    int jumlahDiagonalUtama = 0, jumlahDiagonalSekunder = 0;

    //Tampilkan matriks
    cout << "\nMatriks 3x3 : " << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }

    //Hitung digonal utama
    cout << "\nJumlah diagonal utama = ";
    for (int i = 0; i < 3; i++){
        cout << matriks[i][i];
        jumlahDiagonalUtama += matriks[i][i]; 
        if (i < 2) cout << " + ";
    }
    cout << " = " << jumlahDiagonalUtama << endl;

    //Hitung digonal sekunder
    cout << "\nJumlah diagonal sekunder = ";
    for (int i = 0; i < 3; i++){
        cout << matriks[i][2 - i];
        jumlahDiagonalSekunder += matriks[i][2 - i]; 
        if (i < 2) cout << " + ";
    }
    cout << " = " << jumlahDiagonalSekunder << endl;

    return 0;    
}