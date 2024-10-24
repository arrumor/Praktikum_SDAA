#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

struct item_menu {
    int id;
    string nama;
    int harga;
    int stok;
    item_menu* next;
};

struct stackNode {
    item_menu data;
    stackNode* next;
};

item_menu* head = nullptr;
stackNode* top = nullptr;
int penghitung_id = 1;

void push(stackNode** top, item_menu item) {
    stackNode* newNode = new stackNode();
    newNode->data = item;
    newNode->next = *top;
    *top = newNode;
}

item_menu pop(stackNode** top) {
    if (*top == nullptr) {
        cout << "Stack kosong, tidak ada menu yang bisa dikembalikan.\n";
        item_menu empty;
        empty.id = -1;
        return empty;
    }
    stackNode* temp = *top;
    item_menu item_dikembalikan = temp->data;
    *top = (*top)->next;
    delete temp;
    return item_dikembalikan;
}

struct Pelanggan {
    string nama;
    int no_antrian;
};

struct Node {
    Pelanggan data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;
int no_antrian = 1;

void tambah_menu() {
    item_menu* item = new item_menu;
    item->id = penghitung_id++;

    cout << "Masukkan nama makanan: ";
    cin.ignore();
    getline(cin, item->nama);
    cout << "Masukkan harga makanan: ";
    cin >> item->harga;
    cout << "Masukkan stok makanan: ";
    cin >> item->stok;

    item->next = nullptr;

    if (head == nullptr) {
        head = item;
    } else {
        item_menu* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = item;
    }

    system("cls");
    cout << "Item berhasil ditambahkan!" << endl;
}

void lihat_menu() {
    if (head == nullptr) {
        cout << "Menu kosong." << endl;
        return;
    }

    cout << "Daftar Menu: " << endl;

    item_menu* temp = head;
    while (temp != nullptr) {
        cout << "ID: " << temp->id << " | Nama: " << temp->nama << " | Harga: " << temp->harga << " | Stok: " << temp->stok << endl; // Display stock
        temp = temp->next;
    }
}

item_menu* cari_menu(int id) {
    item_menu* temp = head;
    while (temp != nullptr) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void ubah_menu() {
    lihat_menu();
    int id;
    cout << "Masukkan ID makanan yang ingin diupdate: ";
    cin >> id;

    item_menu* item = cari_menu(id);
    if (item) {
        cout << "Masukkan nama makanan baru: ";
        cin.ignore();
        getline(cin, item->nama);
        cout << "Masukkan harga makanan baru: ";
        cin >> item->harga;
        cout << "Masukkan stok makanan baru: ";
        cin >> item->stok;
        system("cls");
        cout << "Item berhasil diperbarui!\n";
    } else {
        cout << "Item dengan ID tersebut tidak ditemukan.\n";
    }
}

void hapus_menu() {
    lihat_menu();
    int id;
    cout << "Masukkan ID makanan yang ingin dihapus: ";
    cin >> id;

    if (head == nullptr) {
        cout << "Menu kosong." << endl;
        return;
    }

    if (head->id == id) {
        item_menu* temp = head;
        push(&top, *head);
        head = head->next;
        delete temp;
        system("cls");
        cout << "Item berhasil dihapus!" << endl;
        return;
    }

    item_menu* temp = head;
    while (temp->next != nullptr && temp->next->id != id) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Item dengan ID tersebut tidak ditemukan." << endl;
    } else {
        item_menu* item_dihapus = temp->next;
        push(&top, *item_dihapus);
        temp->next = item_dihapus->next;
        delete item_dihapus;
        system("cls");
        cout << "Item berhasil dihapus!" << endl;
    }
}

void kembalikan_menu() {
    item_menu dikembalikan = pop(&top);
    if (dikembalikan.id == -1) {
        return; 
    }

    item_menu* item = new item_menu;
    item->id = dikembalikan.id;
    item->nama = dikembalikan.nama;
    item->harga = dikembalikan.harga;
    item->stok = dikembalikan.stok;
    item->next = nullptr;

    if (head == nullptr) {
        head = item;
    } else {
        item_menu* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = item;
    }

    system("cls");
    cout << "Item berhasil dikembalikan!" << endl;
}

Node* createNode() {
    Node* newNode = new Node();
    cout << "Masukkan nama pelanggan: "; 
    cin >> newNode->data.nama;
    newNode->data.no_antrian = no_antrian++;
    newNode->next = nullptr;
    system("cls");
    cout << "Pelanggan berhasil ditambahkan ke antrian" << endl;
    return newNode;
}

void display(Node* front) {
    if (!front) {
        cout << "Antrian Kosong\n";
        return;
    }
    while (front) {
        cout << "Nama: " << front->data.nama << " | No Antrian: " << front->data.no_antrian << "\n";
        cout << "-----------------------------\n";
        front = front->next;
    }
}

void enqueue(Node** front, Node** rear) {
    Node* nodeBaru = createNode();
    if (!*front) {
        *front = nodeBaru;
    } else {
        (*rear)->next = nodeBaru;
    }
    *rear = nodeBaru;
}

void dequeue(Node** front) {
    if (!*front) {
        cout << "Antrian Kosong\n";
        return;
    }
    Node* temp = *front;
    *front = (*front)->next;
    delete temp;
    system("cls");
    cout << "Pelanggan berhasil dihapus dari antrian" << endl;
}

void kelola_antrian() {
    int menu;
    while (true) {
        cout << ">> Kelola Antrian Pelanggan <<" << endl;
        cout << "1. Tambah Antrian" << endl;
        cout << "2. Selesaikan Antrian" << endl;
        cout << "3. Tampilkan Antrian" << endl;
        cout << "4. Kembali ke Menu Utama" << endl; 
        cout << "Masukkan pilihan: ";
        cin >> menu;
        switch (menu) {
            case 1: 
                system("cls");
                enqueue(&front, &rear); 
                break;
            case 2: 
                system("cls");
                dequeue(&front); 
                break;
            case 3: 
                system("cls");
                display(front); 
                break;
            case 4: 
                system("cls");
                return;
            default: cout << "Pilihan tidak ada\n";
        }
    }
}

item_menu* sorted_merge(item_menu* a, item_menu* b) {
    item_menu* result = nullptr;

    if (a == nullptr)
        return b;
    else if (b == nullptr)
        return a;

    if (a->harga <= b->harga) {
        result = a;
        result->next = sorted_merge(a->next, b);
    } else {
        result = b;
        result->next = sorted_merge(a, b->next);
    }
    return result;
}

void split(item_menu* source, item_menu** front_ref, item_menu** back_ref) {
    item_menu* fast;
    item_menu* slow;
    slow = source;
    fast = source->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front_ref = source;
    *back_ref = slow->next;
    slow->next = nullptr;
}

void merge_sort(item_menu** head_ref) {
    item_menu* head = *head_ref;
    item_menu* a;
    item_menu* b;

    if ((head == nullptr) || (head->next == nullptr)) {
        return;
    }

    split(head, &a, &b);

    merge_sort(&a);
    merge_sort(&b);

    *head_ref = sorted_merge(a, b);
}

item_menu* partition(item_menu* low, item_menu* high, item_menu** newLow, item_menu** newHigh) {
    item_menu* pivot = high;
    item_menu* prev = nullptr, *cur = low, *tail = pivot;

    while (cur != pivot) {
        if (cur->harga > pivot->harga) {
            if ((*newLow) == nullptr) (*newLow) = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) prev->next = cur->next;
            item_menu* temp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if ((*newLow) == nullptr) (*newLow) = pivot;
    (*newHigh) = tail;

    return pivot;
}

item_menu* get_tail(item_menu* cur) {
    while (cur != nullptr && cur->next != nullptr) cur = cur->next;
    return cur;
}

item_menu* quick_sort_recur(item_menu* low, item_menu* high) {
    if (!low || low == high) return low;

    item_menu* newLow = nullptr, *newHigh = nullptr;
    item_menu* pivot = partition(low, high, &newLow, &newHigh);

    if (newLow != pivot) {
        item_menu* temp = newLow;
        while (temp->next != pivot) temp = temp->next;
        temp->next = nullptr;

        newLow = quick_sort_recur(newLow, temp);

        temp = get_tail(newLow);
        temp->next = pivot;
    }

    pivot->next = quick_sort_recur(pivot->next, newHigh);

    return newLow;
}

void quick_sort(item_menu** head_ref) {
    (*head_ref) = quick_sort_recur(*head_ref, get_tail(*head_ref));
}

int length(item_menu* head) {
    int count = 0;
    item_menu* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

int jumpSearch(item_menu* head, int x) {
    int n = length(head);
    int step = sqrt(n);
    int prev = 0;
    item_menu* temp = head;

    while (temp != nullptr && temp->harga < x) {
        prev = step;
        step += sqrt(n);
        for (int i = 0; i < step && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (prev >= n) {
            return -1;
        }
    }

    temp = head;
    for (int i = 0; i < prev && temp != nullptr; i++) {
        temp = temp->next;
    }

    while (temp != nullptr && temp->harga < x) {
        prev++;
        temp = temp->next;
    }

    if (temp != nullptr && temp->harga == x) {
        return prev;
    }

    return -1;
}

void cari_menu_harga() {
    int harga;
    cout << "Masukkan harga yang ingin dicari: ";
    cin >> harga;
    int index = jumpSearch(head, harga);
    if (index >= 0) {
        item_menu* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        cout << "Menu ditemukan: ID: " << temp->id << " | Nama: " << temp->nama << " | Harga: " << temp->harga << " | Stok: " << temp->stok << endl;
    } else {
        cout << "Menu dengan harga " << harga << " tidak ditemukan." << endl;
    }
}

int min(int x, int y) {
    return (x <= y) ? x : y;
}

int fibMonaccianSearch(item_menu* head, int x, int n) {
    item_menu* temp = head;
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);

        temp = head;
        for (int j = 0; j < i; j++) {
            temp = temp->next;
        }

        if (temp->stok < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (temp->stok > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            return i;
        }
    }

    temp = head;
    for (int j = 0; j < offset + 1; j++) {
        temp = temp->next;
    }

    if (fibMMm1 && temp->stok == x) return offset + 1;
    return -1;
}

void cari_menu_stok() {
    int stok;
    cout << "Masukkan stok yang ingin dicari: ";
    cin >> stok;
    int n = length(head);
    int index = fibMonaccianSearch(head, stok, n);
    if (index >= 0) {
        item_menu* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        cout << "Menu ditemukan: ID: " << temp->id << " | Nama: " << temp->nama << " | Harga: " << temp->harga << " | Stok: " << temp->stok << endl;
    } else {
        cout << "Menu dengan stok " << stok << " tidak ditemukan." << endl;
    }
}

const int NO_OF_CHARS = 256;

void badCharHeuristic(string str, int size, int badChar[NO_OF_CHARS]) {
    for (int i = 0; i < NO_OF_CHARS; i++) {
        badChar[i] = -1;
    }
    for (int i = 0; i < size; i++) {
        badChar[(int)str[i]] = i;
    }
}

void search_menu_nama(item_menu* head, string pat) {
    int m = pat.size();
    item_menu* temp = head;
    bool found = false;

    while (temp != nullptr) {
        int n = temp->nama.size();
        int badChar[NO_OF_CHARS];
        badCharHeuristic(pat, m, badChar);
        int s = 0;

        while (s <= (n - m)) {
            int j = m - 1;
            while (j >= 0 && pat[j] == temp->nama[s + j]) {
                j--;
            }
            if (j < 0) {
                cout << "Menu ditemukan: ID: " << temp->id << " | Nama: " << temp->nama << " | Harga: " << temp->harga << " | Stok: " << temp->stok << endl;
                found = true;
                break;
            } else {
                s += max(1, j - badChar[temp->nama[s + j]]);
            }
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Menu dengan nama \"" << pat << "\" tidak ditemukan." << endl;
    }
}

int main() {
    while (true) {
        cout << ">> Pengelolaan Restoran <<" << endl;
        cout << "1. Tambah Menu" << endl;
        cout << "2. Lihat Menu" << endl;
        cout << "3. Ubah Menu" << endl;
        cout << "4. Hapus Menu" << endl;
        cout << "5. Kembalikan Menu yang Dihapus" << endl;
        cout << "6. Kelola Antrian Pelanggan" << endl;
        cout << "7. Search & Sort" << endl;
        cout << "8. Keluar" << endl;
        cout << "Pilih Menu: ";
        int pilih;
        cin >> pilih;
        if (pilih == 1) {
            system("cls");
            tambah_menu();
        } else if (pilih == 2) {
            system("cls");
            lihat_menu();
        } else if (pilih == 3) {
            system("cls");
            ubah_menu();
        } else if (pilih == 4) {
            system("cls");
            hapus_menu();
        } else if (pilih == 5) {
            system("cls");
            kembalikan_menu();
        } else if (pilih == 6) {
            system("cls");
            kelola_antrian();
        } else if (pilih == 7) {
            while(true) {
                cout << "Menu Search & Sort" << endl;
                cout << "1. Sort Harga Makanan (Ascending)" << endl;
                cout << "2. Sort Harga Makanan (Descending)" << endl;
                cout << "3. Search Nama Makanan" << endl;
                cout << "4. Search Harga Makanan" << endl;
                cout << "5. Search Stok Makanan" << endl;
                cout << "6. Kembali ke Menu Utama" << endl;
                cout << "Pilih Menu: ";
                int pilih1;
                cin >> pilih1;
                if (pilih1 == 1) {
                    system("cls");
                    merge_sort(&head);
                    lihat_menu();
                    cout << "Menu berhasil diurutkan berdasarkan harga (Ascending)" << endl;
                } else if (pilih1 == 2) {
                    system("cls");
                    quick_sort(&head);
                    lihat_menu();
                    cout << "Menu berhasil diurutkan berdasarkan harga (Descending)" << endl;
                } else if (pilih1 == 3) {
                    system("cls");
                    string pat;
                    cout << "Masukkan nama makanan yang ingin dicari: ";
                    cin.ignore();
                    getline(cin, pat);
                    search_menu_nama(head, pat);
                } else if (pilih1 == 4) {
                    system("cls");
                    cari_menu_harga();
                } else if (pilih1 == 5) {
                    system("cls");
                    cari_menu_stok();
                } else if (pilih1 == 6) {
                    system("cls");
                    break;
                } else {
                    system("cls");
                    cout << "Menu tidak tersedia" << endl;
                }
            }
        } else if (pilih == 8) {
            system("cls");
            cout << "Terima kasih telah menggunakan program ini!" << endl;
            break;
        } else {
            system("cls");
            cout << "Menu tidak tersedia" << endl;
        }
    }
    return 0;
}