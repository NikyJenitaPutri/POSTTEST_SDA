#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk antrian (queue)
struct Node {
    string document;
    Node* next;
};

// Fungsi enqueue → menambahkan dokumen ke antrian (rear/tail)
void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr}; // Buat node baru, next = nullptr
    // 1. Jika queue kosong (front == nullptr)
    if (front == nullptr) {
        front = rear = newNode; // front dan rear sama-sama menunjuk ke node baru
    } else {
        // 2. Jika tidak kosong
        rear->next = newNode; // Sambungkan node baru ke rear lama
        rear = newNode; // Update rear ke node baru
    } 
}

// Fungsi dequeue → mengambil dokumen dari depan antrian
string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // Jika queue kosong, kembalikan string kosong

    // 1. Simpan data dari front node
    Node* temp = front;
    string doc = temp->document;

    // 2. Geser front ke front->next
    front = front->next;

    // 3. Jika front menjadi nullptr, set rear juga ke nullptr
    if (front == nullptr) rear = nullptr;

    // 4. Delete node lama dan return data
    delete temp;

    return doc;  // Kembalikan nama dokumen yang diambil
}

// Fungsi untuk memproses semua dokumen dalam antrian
void processAllDocuments(Node*& front, Node*& rear) {
    // Loop selama masih ada node di queue
    while (front != nullptr) {

        // Format: "Memproses: [nama_dokumen]"
        cout << "Memproses: " << dequeue(front, rear) << endl;
    }
}

int main() {
    Node* front = nullptr; // Pointer ke elemen pertama (head) queue
    Node* rear = nullptr; // Pointer ke elemen terakhir (tail) queue

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}
