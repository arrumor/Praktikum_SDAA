#include <iostream>
#include <string>
using namespace std;

struct item_menu {
    int id;
    string nama;
    int harga;
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
        cout << "ID: " << temp->id << " | Nama: " << temp->nama << " | Harga: " << temp->harga << endl;
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


int main() {
    while (true) {
        cout << ">> Pengelolaan Restoran <<" << endl;
        cout << "1. Tambah Menu" << endl;
        cout << "2. Lihat Menu" << endl;
        cout << "3. Ubah Menu" << endl;
        cout << "4. Hapus Menu" << endl;
        cout << "5. Kembalikan Menu yang Dihapus" << endl;
        cout << "6. Kelola Antrian Pelanggan" << endl;
        cout << "7. Urutkan Harga Menu (Ascending)" << endl;
        cout << "8. Urutkan Harga Menu (Descending)" << endl;
        cout << "9. Keluar" << endl;
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
            system("cls");
            merge_sort(&head);
            cout << "Menu diurutkan berdasarkan harga (Ascending)" << endl;
            lihat_menu();
        } else if (pilih == 8) {
            system("cls");
            quick_sort(&head);
            cout << "Menu diurutkan berdasarkan harga (Descending)" << endl;
            lihat_menu();
        } else if (pilih == 9) {
            system("cls");
            cout << "Anda keluar" << endl;
            break;
        } else {
            system("cls");
            cout << "Menu tidak tersedia" << endl;
        }
    }
    return 0;
}