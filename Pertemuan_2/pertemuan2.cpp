#include <iostream>
using namespace std;

// int angka[5] = {1, 2, 3, 4, 5};
struct mahasiswa
{
    string nama;
    int umur;
    string jurusan;
};


int main(){
    // satu dimensi
    // for(int i = 0; i < 5; i++){
    //     cout << angka[i] ;
    // }
    // cout << endl;

    // dua dimensi
    // for(int i = 0; i < 2; i++){
    //     for(int j = 0; j < 2; j++){
    //         cout << angka2[i][j] << endl;
    //     }
    // }

    // int arr[4][4];
    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; i < 4; j++) {
    //         arr[i][j] = i + j;
    //     }
    // }
    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    // cout << endl;
    // }

    // int arr[3][3][3];
    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         for (int k = 0; k < 3; k++) {
    //             arr[i][j][k] = i + j + k;
    //         }
    //     }
    // }
    // for (int i = 0; i < 3; i++) {
    //     cout << "layer ke" << i << endl;
    //     for (int j = 0; j < 3; j++) {
    //         for (int k = 0; k < 3; k++) {
    //             cout << arr[i][j][k] << " ";
    //         }
    //     cout << endl;
    //     }
    // cout << endl;
    // }

    // struct alamat {
    //     string nama; // “John Doe”
    //     long int nomor_rumah; // 33
    //     string nama_jalan; // “Awang Long”
    //     string kota; // “Samarinda Ulu”
    //     long kode_pos; // 75123
    // };

    // alamat data;
    // data.nama = "John Doe";
    // data.nomor_rumah = 33;
    // cout << data.nama << endl;
    // cout << data.nomor_rumah << endl;   

    // int a = 42;
    // int *ptr;
    // ptr = &a;
    // cout << "Nilai dari a: " << &a << endl;
    // cout << "Nilai dari ptr: " << ptr << endl;
    
    // int a = 42;
    // int *ptr = &a;
    // cout << "Nilai dari a melalui pointer: " << *ptr << endl;
    // *ptr = 100;
    // cout << "Nilai baru dari a: " << a << endl;

    // int v[] = {1, 2, 3, 4};
    // int* p1 = v; // pointer ke elemen paling awal pada array (implisit)
    // int* p2 = &v[0]; // pointer ke elemen paling awal pada array
    // int* p3 = &v[1]; // pointer ke satu nilai setelah elemen akhir
    // cout << "Nilai dari p1: " << p1 << endl;
    // cout << "Nilai dari p2: " << p2 << endl;
    // cout << "Nilai dari p3: " << p3 << endl;
}