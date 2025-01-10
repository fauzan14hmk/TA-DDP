#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//Muhammad Fauzan Hamka
//2400018139
struct Produk {
    string nama;
    int harga;
};

void tampilkanProduk(Produk daftarProduk[], int jumlahProduk) {
    cout << "\nDaftar Produk:\n";
    for (int i = 0; i < jumlahProduk; i++) {
        cout << i + 1 << ". " << daftarProduk[i].nama << " - Rp" << daftarProduk[i].harga << endl;
    }
}

int hitungTotalHarga(Produk daftarProduk[], int jumlahBeli[], int jumlahProduk) {
    int total = 0;
    for (int i = 0; i < jumlahProduk; i++) {
        total += jumlahBeli[i] * daftarProduk[i].harga;
    }
    return total;
}

void cetakStruk(string namaPembeli, Produk daftarProduk[], int jumlahBeli[], int jumlahProduk, int totalHarga, int bayar, int kembalian) {
    ofstream file("struk_sembako.txt");

    file << "\n------------------------------------------------------------\n";
    file << "Pembelian atas nama: " << namaPembeli << endl;
    file << "------------------------------------------------------------\n";
    file << "| NO | Nama Produk | Jumlah | Harga   | Total Harga       |\n";
    file << "------------------------------------------------------------\n";

    for (int i = 0; i < jumlahProduk; i++) {
        if (jumlahBeli[i] > 0) {
            int totalPerItem = jumlahBeli[i] * daftarProduk[i].harga;
            file << "| " << setw(2) << i + 1 << " | " << setw(10) << daftarProduk[i].nama
                 << " | " << setw(6) << jumlahBeli[i] << " | " << setw(7) << daftarProduk[i].harga
                 << " | " << setw(15) << totalPerItem << " |\n";
        }
    }

    file << "------------------------------------------------------------\n";
    file << "| TOTAL                                      | " << setw(15) << totalHarga << " |\n";
    file << "------------------------------------------------------------\n";
    file << "Bayar: " << bayar << endl;
    file << "Kembalian: " << kembalian << endl;
    file << "------------------------------------------------------------\n";

    file.close();

    cout << "\nStruk telah dicetak ke file struk_sembako.txt\n";
}

//Muhammad Dzakwan
//2400018125
int main() {
    Produk daftarProduk[] = {
        {"Beras", 12000},
        {"Minyak Goreng", 14000},
        {"Gula", 13000},
        {"Telur", 2000},
        {"Mie Instan", 2500},
        {"Kopi Sachet", 1500},
        {"Teh Celup", 5000}
    };

    const int jumlahProduk = sizeof(daftarProduk) / sizeof(daftarProduk[0]);
    int jumlahBeli[jumlahProduk] = {0};
    string namaPembeli;

    cout << "=========================================" << endl;
    cout << "  SELAMAT DATANG DI TOKO SEMBAKO  " << endl;
    cout << "=========================================" << endl;

    cout << "Pembelian atas nama: ";
    cin >> namaPembeli;

    char tambahLagi;
    do {
        tampilkanProduk(daftarProduk, jumlahProduk);

        int pilihan, jumlah;
        cout << "Pilih produk (1-" << jumlahProduk << "): ";
        cin >> pilihan;
        cout << "Jumlah: ";
        cin >> jumlah;

        if (pilihan >= 1 && pilihan <= jumlahProduk) {
            jumlahBeli[pilihan - 1] += jumlah;
        } else {
            cout << "Pilihan tidak valid!\n";
        }

        cout << "Ada tambahan lagi [Y/T]: ";
        cin >> tambahLagi;
    } while (tambahLagi == 'Y' || tambahLagi == 'y');

    int totalHarga = hitungTotalHarga(daftarProduk, jumlahBeli, jumlahProduk);

    int bayar, kembalian;
    cout << "Total Harga: Rp" << totalHarga << endl;
    cout << "Bayar: ";
    cin >> bayar;
    kembalian = bayar - totalHarga;

    cetakStruk(namaPembeli, daftarProduk, jumlahBeli, jumlahProduk, totalHarga, bayar, kembalian);

    return 0;
}

