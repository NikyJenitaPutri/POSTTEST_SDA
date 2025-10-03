#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk stack (linked list)
struct Node {
    char data;
    Node* next;
};

// fungsi push stack
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top}; // Buat node baru, next-nya menunjuk ke top lama
    top = newNode; // Update top agar menunjuk ke node baru
}

// fungsi pop stack
char pop(Node*& top) {
    if (top == nullptr) return '\0'; // Jika stack kosong, kembalikan karakter null
    Node* temp = top; // Simpan node teratas
    char poppedValue = temp->data; // Ambil data dari node teratas
    top = top->next; // Geser top ke node berikutnya
    delete temp; // Hapus node lama dari memori
    return poppedValue; // Kembalikan karakter yang di-pop
}

// fungsi cek keseimbangan bracket
bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr; // Stack kosong pada awalnya

    // 1. Loop setiap karakter dalam `expr`
    for (char c : expr) {

         // 2. Jika karakter adalah kurung buka '(', '{', '[', push ke stack
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);

        // 3. Jika karakter adalah kurung tutup ')', '}', ']', cek:
        } else if (c == ')' || c == '}' || c == ']') {
            // a. Apakah stack kosong? Jika ya, return false
            if (stackTop == nullptr) return false; 

            // b. Pop stack, lalu cek apakah kurung tutup cocok dengan kurung buka. Jika tidak, return false.
            char topChar = pop(stackTop); 
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false ; // Tidak cocok -> tidak seimbang
            }
        }
    }
    // 4. Setelah loop selesai, jika stack kosong, return true. Jika tidak, return false.
    // Kalau kosong berarti semua kurung seimbang
    // Kalau masih ada sisa kurung buka -> tidak seimbang
    return stackTop == nullptr;
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    // Expected output: Seimbang
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}
