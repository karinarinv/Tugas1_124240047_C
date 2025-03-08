#include <iostream>
#include <iomanip>
using namespace std;

int menu;
char pilihan;
string kodeCari, namaCari;

struct Roti {
    string nama;
    string kode;
    int harga;
};

Roti daftarRoti[] = {
    {"Bika Ambon", "001", 300000},
    {"Brownies", "002", 200000},
    {"Lapis Legit", "003", 350000},
    {"Roti Blueband", "004", 150000},
    {"Roti Wisman", "005", 110000}
};

void DaftarRoti(Roti* roti, int jumlah) {
    cout << endl << "Daftar Roti:" << endl;
    cout << setfill('=') << setw(40) << "" << setfill(' ') << endl;
    cout << setw(15) << left << "Nama" << setw(10) << "Kode" << setw(10) << "Harga" << endl;
    cout << setfill('=') << setw(40) << "" << setfill(' ') << endl;

    for (int i = 0; i < jumlah; i++) {
        Roti* ptr = (roti + i); 
        cout << setw(15) << left << ptr->nama
             << setw(10) << ptr->kode
             << ptr->harga << endl;
    }
    cout << setfill('=') << setw(40) << "" << setfill(' ') << endl;
}

void KodeRoti(Roti roti[], int jumlah, string kodeCari) {
    bool ditemukan = false;
    for (int i = 0; i < jumlah; i++) {
        if (roti[i].kode == kodeCari) {
            cout << "Nama  : " << roti[i].nama << endl; 
            cout << "Kode  : " << roti[i].kode << endl; 
            cout << "Harga : " << roti[i].harga << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "belum masuk stok kata ci mehong!" << endl;
    }
}

void NamaRoti(Roti roti[], int jumlah, string namaCari) {
    int awal = 0, akhir = jumlah - 1, tengah;
    bool ditemukan = false;

    while (awal <= akhir && !ditemukan) {
        tengah = (awal + akhir) / 2;
        if (roti[tengah].nama == namaCari) {
            ditemukan = true;
        } else if (roti[tengah].nama > namaCari) {
            akhir = tengah - 1;
        } else {
            awal = tengah + 1;
        }
    }

    if (ditemukan) {
        cout << "Nama  : " << roti[tengah].nama << endl;
        cout << "Kode  : " << roti[tengah].kode << endl;
        cout << "Harga : " << roti[tengah].harga << endl;
    } else {
        cout << "cek toko sebelah!" << endl;
    }
}

void quickSort(Roti roti[], int awal, int akhir, bool ascending) {
    int low = awal, high = akhir;
    int pivot = roti[(awal + akhir) / 2].harga;

    do {
        if (ascending) {
            while (roti[low].harga < pivot) 
            low++;
            while (roti[high].harga > pivot) 
            high--;
        } else {
            while (roti[low].harga > pivot) 
            low++;
            while (roti[high].harga < pivot) 
            high--;
        }

        if (low <= high) {
            swap(roti[low], roti[high]);
            low++;
            high--;
        }
    } while (low <= high);

    if (awal < high) quickSort(roti, awal, high, ascending);
    if (low < akhir) quickSort(roti, low, akhir, ascending);
}

void bubbleSort(Roti roti[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (roti[j].harga < roti[j + 1].harga) {
                swap(roti[j], roti[j + 1]);
            }
        }
    }
}

void keluar() {
    cout << "Datang kembali :)" << endl;
}

int main() {
    int jumlahRoti = sizeof(daftarRoti) / sizeof(daftarRoti[0]);

    do {
        cout << setfill('=') << setw(40) << " " << endl;
        cout << setfill(' ') << setw(10) << " " << "TOKO ROTI CI MEHONG" << endl;
        cout << setfill('=') << setw(40) << " " << endl;

        cout << "Semangat pagi! //lempar kaleng wisman//" << endl;
        cout << " " << endl;

        cout << "1. Tampilkan Roti"         << endl;
        cout << "2. Cari berdasarkan Kode"  << endl;
        cout << "3. Cari berdasarkan Nama " << endl;
        cout << "4. Sort Harga Roti (asc)"  << endl;
        cout << "5. Sort Harga Roti (desc)" << endl; 
        cout << "6. Exit"                   << endl;
        cout << setfill('=') << setw(40) << " " << setfill(' ') << endl;
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu) { 
            case 1:
                DaftarRoti(daftarRoti, jumlahRoti);
                break;
            case 2:
                cout << "Masukkan Kode: "; cin >> kodeCari;
                KodeRoti(daftarRoti, jumlahRoti, kodeCari);
                break;
            case 3:
                cout << "Masukkan Nama Roti: "; cin.ignore(); //ngebug mulu disini
                getline(cin, namaCari);
                NamaRoti(daftarRoti, jumlahRoti, namaCari);
                break;

            case 4:
                quickSort(daftarRoti, 0, jumlahRoti - 1, true);
                DaftarRoti(daftarRoti, jumlahRoti);
                break;

            case 5:
                bubbleSort(daftarRoti, jumlahRoti);
                DaftarRoti(daftarRoti, jumlahRoti);
                break;
           

            case 6:
                keluar();
                return 0;
                default:
                cout << "Menunya cuma sampai 6 kocak" << endl;
        }

        cout << "Silahkan lihat-lihat lagi (y/n) : ";
        cin >> pilihan;
    } 
    while (pilihan == 'y' || pilihan == 'Y');
    return 0;
}
