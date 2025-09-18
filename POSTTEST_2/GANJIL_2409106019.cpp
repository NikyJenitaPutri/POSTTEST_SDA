#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Struct data untuk item
struct Item
{
    string namaItem;
    int jumlah;
    string tipe;
};

// Node untuk linked list
struct Node
{
    string jenis; // identitas atau item
    string nama; // kalau identitas
    string nim; // kalau identitas
    Item data; // kalau item
    Node *next;
};


// untuk ambil dua digit terakhir dari NIM
int getLastTwoDigits(const string &nim) {
    int len = nim.length();
    if (len == 0) return 0;
    if (len == 0) return nim[0] - '0';
    string lasTwo = nim. substr(len - 2);
    return stoi(lasTwo);
}

// untuk ambil digit terakhir dari NIM
int getLastDigit(const string &nim) {
    if (nim.empty()) return 0;
    char c = nim.back();
    if (isdigit(c)) return c - '0';
    return 0;
}

// untuk cetak border tabel
void printBorder() {
    cout << "+----+-------------------+--------------+---------+\n";
}

// untuk menampilkan inventory
void tampilkanInventory(Node* head) {
    cout << "\n===== INVENTORY GAME =====" << endl;
    if (head == nullptr || head->next == nullptr) {
        cout << "Inventory kosong." << endl;
        return;
    }

    // Header tabel
    printBorder();
    cout << "| " << left << setw(3) << "No"
         << "| " << setw(18) << "Nama Item"
         << "| " << setw(13) << "Tipe"
         << "| " << setw(8) << "Jumlah" << "|\n";
    printBorder();

    // Isi tabel
    Node* temp = head->next; // skip node identitas
    int idx = 1;
    while (temp != nullptr) {
        cout << "| "<< left << setw(3) << idx
             << "| "<< setw(18) << temp->data.namaItem
             << "| "<< setw(13) << temp->data.tipe
             << "| "<< setw(8) << temp->data.jumlah << "|\n";
        temp = temp->next;
        idx++;
    }
    printBorder();
}

// untuk menambahkan item di akhir
void addLast(Node*& head, Node*& tail, const string &nama, const string &tipe, int jumlah) {
    Node* newNode = new Node;
    newNode->jenis = "item";
    newNode->data.namaItem = nama;
    newNode->data.tipe = tipe;
    newNode->data.jumlah = jumlah;
    newNode->next = nullptr;

    if (tail != nullptr) {
        tail->next = newNode;
    } else{
        head = newNode;
    }
    tail = newNode;
    cout << "Item '" << nama << "' berhasil ditambahkan di akhir dengan tipe " << tipe << " dan jumlah = " << jumlah << endl;  
}


// untuk menambahkan item di awal
void addFirst(Node*& head, Node*& tail, const string &nama, const string &tipe, int jumlah) {
    Node* newNode = new Node;
    newNode->jenis = "item";
    newNode->data.namaItem = nama;
    newNode->data.tipe = tipe;
    newNode->data.jumlah = jumlah;
    newNode->next = head->next;
    head->next = newNode;
    if (tail == nullptr) tail = newNode;
    cout << "Item '" << nama << "' berhasil ditambahkan di awal dengan tipe " << tipe << " dan jumlah = " << jumlah << endl;  
}

//untuk menyisipkan item pada posisi tertentu
void addSpecific (Node*& head, Node*& tail, int posisi, const string &nama, const string &tipe, int jumlah) {
    if (posisi < 1) {
        cout << "Posisi tidak valid" << endl;
        return;
    }
    Node* temp = head;
    int count = 0;
    while (temp != nullptr && count < posisi - 1)    
    {
        temp = temp->next;
        count++;
    }
    if (temp == nullptr) {
        addLast(head, tail, nama, tipe, jumlah);
        cout << "Item ditambahkan di akhir" << endl;
    } else {
        Node* newNode = new Node;
        newNode->jenis = "item";
        newNode->data.namaItem = nama;
        newNode->data.tipe = tipe;
        newNode->data.jumlah = jumlah;
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == nullptr) tail = newNode;
        cout << "Item disisipkan di posisi " << posisi << endl;
    } 
}

// untuk hapus item terakhir
void deleteLast(Node*& head, Node*& tail) {
    if (head == nullptr || head->next == nullptr) {
        cout << "Inventory masih kosong, tidak ada yang dapat dihapus." << endl;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr && temp->next != tail) {
        temp = temp->next;
    }
    delete tail;
    if(temp == head) {
        tail = nullptr;
        head->next = nullptr;
    } else {
        temp->next = nullptr;
        tail = temp;
    }
    cout << "Item terakhir berhasil dihapus." << endl;   
}

// untuk hapus item di awal
void deleteFirst(Node*& head, Node*& tail) {
    if (head == nullptr || head->next == nullptr) {
        cout << "Inventory masih kosong, tidak ada yang dapat dihapus." << endl;
        return;
    }
    Node* del = head->next;
    head->next = del->next;
    if (del == tail) tail = nullptr;
    delete del;
    cout << "Item pertama berhasil dihapus." << endl;
}

//cari berdasarkan nama item, jika ditemukan kurangi jumlah 1, jika 0 hapus node
void gunakanItem(Node*& head, Node*& tail, const string &nama) {
    if (head == nullptr) {
        cout << "inventory kosong" << endl;
        return;
    }
    Node* temp = head->next;
    Node*prev = head;

    string target = nama;
    for (auto &c : target) c = tolower(c);

    while (temp != nullptr) {
        string cur =temp->data.namaItem;
        for (auto &c : cur) c = tolower(c);

        if (cur == target) {
            temp->data.jumlah -= 1;
            cout << "Menggunakan 1x '" << temp->data.namaItem << "'. Sisa : " << temp->data.jumlah << endl;
            if (temp->data.jumlah <= 0) {
                prev->next = temp->next;
                if (temp == tail) tail = (prev == head ? nullptr : prev);
                delete temp;
                cout << "Item habis dan di hapus dari inventory." << endl;
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Item dengan nama '" << nama << "' tidak ditemukan." << endl;
}

// untuk membersihkan seluruh list
void clearAll(Node*& head) {
    Node* cur = head;
    while (cur != nullptr) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
    head = nullptr;
}

// untuk menampilkan menu
int tampilkanMenu(Node* identitas, int posisiSisip) {
    int pilihan;
    cout << "\n*************************************************" << endl;
    cout << "| " << setw(46) << left << "MANAJEMEN INVENTORY GAME" << "|" << endl;
    cout << "| " << setw(46) << ("[ " + identitas->nama + " - " + identitas->nim + " ]") << "|" << endl;;
    cout << "*************************************************" << endl;
    cout << "| " << setw(46) << "1. Tambah Item Baru di Akhir" << "|" << endl;
    cout << "| " << setw(46) << "2. Tambah Item Baru di Awal" << "|" << endl; // menu tambahan
    cout << "| " << setw(46) << ("3. Sisipkan Item (posisi = " + to_string(posisiSisip) + ")") << "|" << endl;
    cout << "| " << setw(46) << "4. Hapus Item di Akhir" << "|" << endl;
    cout << "| " << setw(46) << "5. Hapus Item di Awal" << "|" << endl; // menu tambahan
    cout << "| " << setw(46) << "6. Gunakan Item" << "|" << endl;
    cout << "| " << setw(46) << "7. Tampilkan Inventory" << "|" << endl;
    cout << "| " << setw(46) << "0. Keluar" << "|" << endl;
    cout << "*************************************************" << endl;
    cout << "Pilih menu: ";

    if (!(cin >> pilihan)) {
        cin.clear();
        string skip; getline(cin, skip);
        pilihan = -1;
    }
    cin.ignore();
    cout << "*************************************************" << endl;
    return pilihan;
};

int main() {
    Node* head = new Node; // node identitas
    Node* tail = nullptr;

    cout << "\n=== PROGRAM MANAJEMEN INVENTORY GAME ===\n";
    cout << "Masukkan Nama : ";
    getline(cin, head->nama);
    cout << "Masukkan NIM : ";
    getline(cin, head->nim);
    head->jenis = "identitas";
    head->next = nullptr;

    int jumlahAwal = getLastTwoDigits(head->nim);
    int posisiSisip = getLastDigit(head->nim) + 1;

    int pilihan;
    do {
        pilihan = tampilkanMenu(head, posisiSisip);

        if (pilihan == 1) {
            string namaItem, tipe;
            cout << "Masukkan nama item: ";
            getline(cin, namaItem);
            cout << "Masukkan tipe item : ";
            getline(cin, tipe);
            addLast(head, tail, namaItem, tipe, jumlahAwal);
        
        }else if (pilihan == 2) {
            string namaItem, tipe;
            cout << "Masukkan nama item: ";
            getline(cin, namaItem);
            cout << "Masukkan tipe item : ";
            getline(cin, tipe);
            addFirst(head, tail, namaItem, tipe, jumlahAwal);
            }

        else if (pilihan == 3) {
            string namaItem, tipe;
            cout << "Masukkan nama item untuk disisipkan: ";
            getline(cin, namaItem);
            cout << "Masukkan tipe item: ";
            getline(cin, tipe);
            addSpecific(head, tail, posisiSisip, namaItem, tipe, jumlahAwal);

        } else if (pilihan == 4) {
            deleteLast(head, tail);

        } else if (pilihan == 5) {
            deleteFirst(head, tail);
            
        }  else if (pilihan == 6) {
            string namaItem;
            cout << "Masukkan nama item yang akan digunakan: ";
            getline(cin, namaItem);
            gunakanItem(head, tail, namaItem);

        } else if (pilihan == 7) {
            tampilkanInventory(head);

        } else if (pilihan == 0) {
            cout << "=== Terimakasih Sudah Menggunakan Program. Anda Keluar Dari Program ===\n";

        } else {
            cout << "Pilihan tidak valid" << endl;
        }

    } while (pilihan != 0);

    clearAll(head);
    tail = nullptr;
    return 0;

}