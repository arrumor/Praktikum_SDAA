#include <iostream>
using namespace std;


int main(){
    int n;
    int m;
    cout << "Masukkan jumlah baris: ";
    cin >> n;
    cout << "Masukkan jumlah kolom: ";
    cin >> m;
    int arr[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i][j] = i + j;
            cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}