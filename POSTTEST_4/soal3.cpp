#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};
    // 1. Jika queue kosong (front == nullptr), set front dan rear ke newNode
    if (front == nullptr) {
        front = rear = newNode;
    } else {
        // 2. Jika tidak kosong, sambungkan rear->next ke newNode
        rear->next = newNode;
        // lalu update rear ke node baru
        rear = newNode;
    }
}

// Fungsi dequeue → mengambil dokumen dari depan antrian
string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // Queue kosong

    // 1. Simpan data dari front node
    Node* temp = front;
    string doc = temp->document;

    // 2. Geser front ke front->next
    front = front->next;

    // 3. Jika front menjadi nullptr, set rear juga ke nullptr
    if (front == nullptr) rear = nullptr;

    // 4. Delete node lama dan return data
    delete temp;

    return doc; // kembalikan dokumen
}

void processAllDocuments(Node*& front, Node*& rear) {
    // Loop hingga queue kosong, dequeue dan print setiap dokumen
    while (front != nullptr) {

        // Format: "Memproses: [nama_dokumen]"
        cout << "Memproses: " << dequeue(front, rear) << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}
