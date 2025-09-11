#include <iostream>
using namespace std;

struct Mahasiswa 
{
    string Nama;
    string NIM;
    float IPK;
};

int main(){
    Mahasiswa mhs[5]; //array of struct
    int n = 5;

    //Input data mahasiswa
    cout << "Masukkan data 5 mahasiswa : " << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i+1 << endl;
        cout << "Nama : ";
        cin >> ws;
        getline(cin, mhs[i].Nama);
        cout << "NIM : ";
        cin >> mhs[i].NIM;
        cout << "IPK : ";
        cin >> mhs[i].IPK;
    }

    //Cari mahasiswa dengan IPK tertinggi
    float IPK_Tertinggi = mhs[0].IPK;
    for (int i = 1; i < n; i++) {
        if (mhs[i].IPK > IPK_Tertinggi) {
            IPK_Tertinggi = mhs[i].IPK;
        }
    }

    //Menampilkan mahasiswa dengan IPK tertinggi
    cout << "\nMahasiswa dengan IPK tertinggi (" << IPK_Tertinggi << ") :" << endl;
    for (int i = 0; i < n; i++) {
        if(mhs[i].IPK == IPK_Tertinggi){
            cout << "Nama : " << mhs[i].Nama << endl;
            cout << "NIM : " << mhs[i].NIM << endl;
            cout << "IPK : " << mhs[i].IPK << endl;
        }
    }
    return 0;
}