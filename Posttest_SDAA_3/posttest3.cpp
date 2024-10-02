#include <iostream>
#include <string>
using namespace std;

const int menu_maks = 20;

struct item_menu{
    int id;
    string nama;
    int harga;
    item_menu* next;
};

item_menu* head = nullptr;
int penghitung_id = 1;

void tambah_menu(){
    item_menu* item = new item_menu;
    item->id = penghitung_id++;

    cout << "Masukkan nama makanan : ";
    cin.ignore();
    getline(cin, item->nama);
    cout << "Masukkan harga makanan : ";
    cin >> item->harga;

    item->next = nullptr;

    if (head==nullptr){
        head = item;
    }
    else{
        item_menu* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = item;
    }

    system("cls");
    cout << "Item berhasil ditambahkan!" << endl;
}

void lihat_menu(){
    if (head == nullptr) {
        cout << "Menu kosong." << endl;
        return;
    }

    system("cls");
    cout << "\nDaftar Menu: " << endl;

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

void ubah_menu(){
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
    } 
    else {
        system("cls");
        cout << "Item dengan ID tersebut tidak ditemukan.\n";
    }
}

void hapus_menu(){
    lihat_menu();
    int id;
    cout << "Masukkan ID makanan yang ingin dihapus: ";
    cin >> id;

    if (head == nullptr) {
        system("cls");
        cout << "Menu kosong." << endl;
        return;
    }

    if (head->id == id) {
        item_menu* temp = head;
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
        system("cls");
        cout << "Item dengan ID tersebut tidak ditemukan." << endl;
    } else {
        item_menu* item_dihapus = temp->next;
        temp->next = item_dihapus->next;
        delete item_dihapus;
        system("cls");
        cout << "Item berhasil dihapus!" << endl;
    }
}

int main(){
    while(true){
        cout << "Pengelolaan Menu Restoran" << endl;
        cout << "1. Tambah Menu" << endl;
        cout << "2. Lihat Menu" << endl;
        cout << "3. Ubah Menu" << endl;
        cout << "4. Hapus Menu" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih Menu : ";
        int pilih;
        cin >> pilih;
        if(pilih == 1){
            system("cls");
            tambah_menu();
        }
        else if(pilih == 2){
            system("cls");
            lihat_menu();
        }
        else if(pilih == 3){
            system("cls");
            ubah_menu();
        }
        else if(pilih == 4){
            system("cls");
            hapus_menu();
        }
        else if(pilih == 5){
            system("cls");
            cout << "Anda keluar" << endl;
            break;
        }
        else{
            system("cls");
            cout << "Menu tidak tersedia" << endl;
        }
    }
}