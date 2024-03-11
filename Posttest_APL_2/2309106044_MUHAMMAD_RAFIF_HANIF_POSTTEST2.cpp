#include <iostream>
#include <algorithm>

using namespace std;

const int maxSekolah = 100;

struct Sekolah {
    string nama;
};

void tampilkanMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Tambah Sekolah" << endl;
    cout << "2. Tampilkan Semua Sekolah" << endl;
    cout << "3. Ubah Nama Sekolah" << endl;
    cout << "4. Hapus Sekolah" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih menu: ";
}

bool login() {
    string nama, nim;
    int salah = 0;
    while (true) {
        cout << "\nMasukkan Nama : ";
        cin >> nama;
        cout << "Masukkan NIM : ";
        cin >> nim;

        if (nama == "Rafif" && nim == "2309106044") {
            return true; 
        } else {
            salah++;
            if (salah == 3) {
                cout << "Anda telah salah memasukkan sebanyak 3 kali" << endl;
                cout << "Program berhenti" << endl;
                return false;
            }
            cout << "Nama atau NIM salah. Coba lagi." << endl;
        }
    }
}

void tambahSekolah(Sekolah database[], int &jumlahSekolah) {
    if (jumlahSekolah >= maxSekolah) {
        cout << "Database sekolah penuh." << endl;
        return;
    }
    cout << "\nMasukkan nama sekolah: ";
    cin.ignore(); 
    getline(cin, database[jumlahSekolah].nama); 
    jumlahSekolah++;
    cout << "Sekolah berhasil ditambahkan." << endl;
}

void tampilkanSemuaSekolah(Sekolah database[], int jumlahSekolah) {
    if (jumlahSekolah == 0) {
        cout << "\nDatabase sekolah kosong." << endl;
        return;
    }
    cout << "\nDaftar Sekolah:" << endl;
    for (int i = 0; i < jumlahSekolah; ++i) {
        cout << i + 1 << ". " << database[i].nama << endl;
    }
}

void ubahNamaSekolah(Sekolah database[], int jumlahSekolah) {
    if (jumlahSekolah == 0) {
        cout << "\nDatabase sekolah kosong." << endl;
        return;
    }
    int index;
    cout << "\nPilih nomor sekolah yang ingin diubah: ";
    cin >> index;
    if (index < 1 || index > jumlahSekolah) {
        cout << "Nomor sekolah tidak valid." << endl;
        return;
    }
    cout << "Masukkan nama baru untuk sekolah " << index << ": ";
    cin.ignore(); 
    getline(cin, database[index - 1].nama); 
    cout << "Nama sekolah berhasil diubah." << endl;
}

void hapusSekolah(Sekolah database[], int &jumlahSekolah) {
    if (jumlahSekolah == 0) {
        cout << "\nDatabase sekolah kosong." << endl;
        return;
    }
    int index;
    cout << "\nPilih nomor sekolah yang ingin dihapus: ";
    cin >> index;
    if (index < 1 || index > jumlahSekolah) {
        cout << "Nomor sekolah tidak valid." << endl;
        return;
    }
    for (int i = index - 1; i < jumlahSekolah - 1; ++i) {
        database[i] = database[i + 1];
    }
    jumlahSekolah--;
    cout << "Sekolah berhasil dihapus." << endl;
}

int main() {
    cout << "Selamat datang di program data sekolah" << endl;

    if (!login()) { 
        return 1;
    }

    Sekolah database[maxSekolah];
    int jumlahSekolah = 0;
    int menu;

    do {
        tampilkanMenu();
        cin >> menu;

        switch (menu) {
            case 1:
                tambahSekolah(database, jumlahSekolah);
                break;
            case 2:
                tampilkanSemuaSekolah(database, jumlahSekolah);
                break;
            case 3:
                ubahNamaSekolah(database, jumlahSekolah);
                break;
            case 4:
                hapusSekolah(database, jumlahSekolah);
                break;
            case 5:
                cout << "\nTerima kasih telah menggunakan program data sekolah" << endl;
                cout << "Keluar dari program..." << endl;
                break;
            default:
                cout << "Menu tidak valid." << endl;
        }
    } while (menu != 5);

    return 0;
}
