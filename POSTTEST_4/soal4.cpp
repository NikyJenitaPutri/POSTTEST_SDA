#include <iostream>
using namespace std;

// Definisi struktur Node untuk Circular Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Fungsi untuk menyisipkan data ke dalam CDLL dalam urutan terurut (ascending)
void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr}; // Buat node baru

    // Kasus 1: List masih kosong
    if (head_ref == nullptr) {
        newNode->next = newNode; // Node menunjuk dirinya sendiri (next)
        newNode->prev = newNode; // Node menunjuk dirinya sendiri (prev)
        head_ref = newNode; // Head menunjuk ke node baru
        return;
    }

    // Simpan pointer head dan tail untuk mempermudah
    Node* head = head_ref; // Pointer ke node head
    Node* tail = head_ref->prev; // Tail adalah node sebelum head (karena circular)
 
    // Kasus 2: Data baru lebih kecil dari head (sisipkan di awal)
    // 1. Jika data < head_ref->data, sisipkan sebelum head dan update head_ref
     if (data < head->data) {
        newNode->next = head;  // next newNode → head lama
        newNode->prev = tail; // prev newNode → tail lama
        head->prev = newNode; // prev head lama → newNode
        tail->next = newNode; // next tail → newNode
        head_ref = newNode; // Update head_ref ke node baru
        return;
    }

    // Kasus 3: Cari posisi yang tepat (tengah/akhir)
    // 1. Gunakan pointer current mulai dari head_ref
    Node* current = head;

    // 2. Loop: while (current->next != head_ref && current->next->data < data)
    // Loop sampai menemukan node dengan nilai >= data
    // atau kembali lagi ke head
    while (current->next != head_ref && current->next->data < data) {
        current = current->next;
    }

    // 3. Setelah loop, sisipkan newNode setelah current
    newNode->next = current->next; // next newNode → node setelah current
    newNode->prev = current;  // prev newNode → current

    // 4. Pastikan update semua pointer next dan prev dengan benar
    current->next->prev = newNode; // prev node setelah current → newNode
    current->next = newNode; // next current → newNode
  
}

// Fungsi untuk mencetak Circular Doubly Linked List
void printList(Node *head_ref)
{
    if (head_ref == nullptr) // Jika list kosong
    {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref; // Mulai dari head
    do
    {
        cout << current->data << " ";
        current = current->next; // Pindah ke node berikutnya
    } while (current != head_ref);  // Berhenti jika kembali ke head
    cout << endl;
}

int main()
{
    Node *head = nullptr; // Awalnya list kosong

    // Test sorted insert
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (sorted): ";
    // Expected output: 10 20 30 40
    printList(head);

    return 0;
}
