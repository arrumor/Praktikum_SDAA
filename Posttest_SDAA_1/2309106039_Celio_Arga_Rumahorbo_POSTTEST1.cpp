#include <iostream>
using namespace std;

void hanoi(int n, char awal, char tujuan, char sementara, int &hitung) {
    if (n == 1) {
        cout << "Pindahkan piringan 1 dari menara " << awal << " ke menara " << tujuan << endl;
        hitung++;
        return;
    }
    
    hanoi(n - 1, awal, sementara, tujuan, hitung);
    
    cout << "Pindahkan piringan " << n << " dari menara " << awal << " ke menara " << tujuan << endl;
    hitung++;
    
    hanoi(n - 1, sementara, tujuan, awal, hitung);
}

int main() {
    int n;
    int hitung = 0;
    
    cout << "Masukkan jumlah piringan: ";
    cin >> n;
    
    cout << "Langkah-langkah untuk memindahkan " << n << " piringan:" << endl;
    hanoi(n, 'A', 'C', 'B', hitung);
    
    cout << "\nTotal langkah yang diperlukan: " << hitung << endl;
    
    return 0;
}
