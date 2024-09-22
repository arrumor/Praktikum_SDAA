#include <iostream>
#include <string>
using namespace std;

const int menu_maks = 20;

struct item_menu{
    int id;
    string nama;
    int harga;
};

item_menu menu[menu_maks];
int jumlah_menu = 0;
int penghitung_id = 1;

void tambah_menu(){
    if(jumlah_menu >= menu_maks){
        cout << "Menu penuh, tidak bisa menambahkan item baru." << endl;
        return;
    }

    item_menu item;
    item.id = penghitung_id++;
    cout << "Masukkan nama makanan : ";
    cin.ignore();
    getline(cin, item.nama);
    cout << "Masukkan harga makanan : ";
    cin >> item.harga;

    menu[jumlah_menu] = item;
    jumlah_menu++;

    system("cls");
    cout << "Item berhasil ditambahkan!" << endl;
}

void lihat_menu(){
    if(jumlah_menu == 0){
        cout << "Menu kosong." << endl;
        return;
    }
    system("cls");
    cout << "\nDaftar Menu : " << endl;
    for(int i = 0; i < jumlah_menu; i++){
        cout << "ID : " << menu[i].id << " | Nama : " << menu[i].nama << " | Harga : " << menu[i].harga << endl;
    }
}

item_menu* cari_menu(int id) {
    for (int i = 0; i < jumlah_menu; i++) {
        if (menu[i].id == id) {
            return &menu[i];
        }
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

    item_menu* item = cari_menu(id);

    if (item) {

        int index = item - menu; 
        
        for (int i = index; i < jumlah_menu - 1; i++) {
            menu[i] = menu[i + 1];
        }

        jumlah_menu--;
        system("cls");
        cout << "Item berhasil dihapus!" << endl;
    } 
    else {
        system("cls");
        cout << "Item dengan ID tersebut tidak ditemukan." << endl;
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