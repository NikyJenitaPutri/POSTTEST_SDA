#include <iostream>
using namespace std;

// Struktur node untuk circular doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Fungsi untuk menukar posisi head dan tail
void exchangeHeadAndTail(Node *&head_ref) {
    // Hanya berjalan jika ada 1 node
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }

    Node* head = head_ref; 
    Node* tail = head_ref->prev; // Tail adalah prev dari head

    // Buat kondisi jika hanya 2 node, cukup swap head_ref
    if (head->next == tail ) {
        head_ref = tail;
        return;
    }

    // Simpan neighbor ( yaitu head_next dan tail_prev)
    Node* headNext = head->next; // node setelah head
    Node* tailPrev = tail->prev; // node sebelum tail

    // update koneksi
    tail->next = headNext;
    headNext->prev = tail;
    head->prev = tailPrev;
    tailPrev->next = head;
    tail->prev = head;
    head->next = tail;

    // Update head_ref ke tail 
    head_ref = tail;
}

// Fungsi untuk menampilkan isi list (traversal circular)
void printList(Node *head_ref) 
{
    if (head_ref == nullptr) 
    {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

// Fungsi untuk menambahkan node di akhir circular doubly linked list
void insertEnd(Node *&head_ref, int data) 
{
    Node *newNode = new Node{data, nullptr, nullptr};

    // Jika list kosong, buat node menunjuk dirinya sendiri
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    // Temukan tail
    Node *tail = head_ref->prev;

    // Update koneksi circular
    newNode->next = head_ref;   // node baru mengarah ke head
    newNode->prev = tail;       // node baru mengarah ke tail
    head_ref->prev = newNode;   // head mengarah balik ke node baru
    tail->next = newNode;       // tail mengarah ke node baru
}

int main() {
    Node *head = nullptr;

    // Buat list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    // Expected output: 5 2 3 4 1
    printList(head);

    return 0;
}
