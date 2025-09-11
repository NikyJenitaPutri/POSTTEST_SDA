#include <iostream>
using namespace std;

//Fungsi untuk membalik array menggunakan pointer
void balikArray(int *arr, int n) {
    int *awal = arr;
    int *akhir = arr + n - 1;
    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

int main() {
    int arr[7];

    //Isi array dengan kelipatan 3
    for (int i = 0; i < 7; i++) {
        arr[i] = (i + 1) * 3;
    }

    //Tampilkan sebelum dibalik 
    cout << "Array sebelum dibalik : ";
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //Panggil fungsi untuk membalik array
    balikArray(arr, 7);

    //Tampilkan sesudah dibalik 
    cout << "Array sesudah dibalik : ";
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}