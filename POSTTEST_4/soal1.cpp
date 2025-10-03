#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Fungsi untuk menambahkan (push) elemen ke stack
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top}; // Membuat node baru dengan data dan menunjuk ke node sebelumnya
    top = newNode;  // Update top agar menunjuk ke node baru
}

// Fungsi untuk menghapus (pop) elemen dari stack
char pop(Node*& top) {
    if (top == nullptr) return '\0'; // Return null character jika stack kosong
    Node* temp = top; // Simpan pointer sementara ke node paling atas
    char poppedValue = temp->data; // Ambil data dari node teratas
    top = top->next; // Geser top ke node berikutnya
    delete temp; // Hapus node lama dari memori
    return poppedValue; // Kembalikan karakter yang di-pop
}

// Fungsi untuk membalik string dengan stack
string reverseString(string s) {
    Node* stackTop = nullptr; // Pointer ke top stack, awalnya kosong
    string reversed = "";   // String hasil pembalikan

    // 1. Push setiap karakter dari string s ke dalam stack.
    for (char c : s) {
        push(stackTop, c); // Masukkan tiap karakter ke stack
    }

    // 2. Pop setiap karakter dari stack dan tambahkan ke string `reversed`
    while (stackTop != nullptr) {
        reversed += pop(stackTop); // Ambil karakter dari stack dan tambahkan ke string hasil
    }

    return reversed; // Kembalikan string hasil yang sudah terbalik
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; // Output: ataD rukurts
    return 0;
}
