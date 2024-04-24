#include <iostream>
#include <limits>
#include <algorithm> // Untuk binary_search dan sort

using namespace std;

const int maxSekolah = 100;

struct Sekolah {
    string nama;
};

void tampilkanMenu();
bool login();
void tambahSekolah(Sekolah* database[], int& jumlahSekolah);
void tampilkanSemuaSekolah(Sekolah* database[], int& jumlahSekolah);
void ubahNamaSekolah(Sekolah* database[], int jumlahSekolah);
void hapusSekolah(Sekolah* database[], int& jumlahSekolah);
int sequentialSearch(Sekolah* database[], int jumlahSekolah, const string& namaSekolah);
int binarySearch(Sekolah* database[], int jumlahSekolah, const string& namaSekolah);
void bubbleSortDesc(Sekolah* database[], int jumlahSekolah);
void selectionSortAsc(Sekolah* database[], int jumlahSekolah);
void insertionSortAsc(Sekolah* database[], int jumlahSekolah);

void tampilkanMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Tambah Sekolah" << endl;
    cout << "2. Tampilkan Semua Sekolah" << endl;
    cout << "3. Urutkan Sekolah" << endl;
    cout << "4. Ubah Nama Sekolah" << endl;
    cout << "5. Hapus Sekolah" << endl;
    cout << "6. Cari Sekolah" << endl;
    cout << "7. Keluar" << endl;
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

void tambahSekolah(Sekolah* database[], int& jumlahSekolah) {
    if (jumlahSekolah >= maxSekolah) {
        cout << "Database sekolah penuh." << endl;
        return;
    }
    database[jumlahSekolah] = new Sekolah;
    cout << "\nMasukkan nama sekolah: ";
    cin.ignore();
    getline(cin, database[jumlahSekolah]->nama);
    jumlahSekolah++;
    cout << "Sekolah berhasil ditambahkan." << endl;
}

void tampilkanSemuaSekolah(Sekolah* database[], int& jumlahSekolah) {
    cout << "\nDaftar Sekolah:" << endl;
    for (int i = 0; i < jumlahSekolah; ++i) {
        cout << i + 1 << ". " << (*database[i]).nama << endl;
    }
}

void ubahNamaSekolah(Sekolah* database[], int jumlahSekolah) {
    if (jumlahSekolah == 0) {
        cout << "\nDatabase sekolah kosong." << endl;
        return;
    }
    int index;
    cout << "\nPilih nomor sekolah yang ingin diubah: ";
    if (!(cin >> index) || index < 1 || index > jumlahSekolah) {
        cout << "Nomor sekolah tidak valid." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cout << "Masukkan nama baru untuk sekolah " << index << ": ";
    cin.ignore();
    getline(cin, database[index - 1]->nama);
    cout << "Nama sekolah berhasil diubah." << endl;
}

void hapusSekolah(Sekolah* database[], int& jumlahSekolah) {
    if (jumlahSekolah == 0) {
        cout << "\nDatabase sekolah kosong." << endl;
        return;
    }
    int index;
    cout << "\nPilih nomor sekolah yang ingin dihapus: ";
    if (!(cin >> index) || index < 1 || index > jumlahSekolah) {
        cout << "Nomor sekolah tidak valid." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    delete database[index - 1];
    for (int i = index - 1; i < jumlahSekolah - 1; ++i) {
        database[i] = database[i + 1];
    }
    jumlahSekolah--;
    cout << "Sekolah berhasil dihapus." << endl;
}

int sequentialSearch(Sekolah* database[], int jumlahSekolah, const string& namaSekolah) {
    for (int i = 0; i < jumlahSekolah; ++i) {
        if (database[i]->nama == namaSekolah) {
            return i;
        }
    }
    return -1;
}

int binarySearch(Sekolah* database[], int jumlahSekolah, const string& namaSekolah) {
    int left = 0, right = jumlahSekolah - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (database[mid]->nama == namaSekolah) {
            return mid;
        } else if (database[mid]->nama < namaSekolah) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

void bubbleSortDesc(Sekolah* database[], int jumlahSekolah) {
    for (int i = 0; i < jumlahSekolah - 1; ++i) {
        for (int j = 0; j < jumlahSekolah - i - 1; ++j) {
            if (database[j]->nama < database[j + 1]->nama) {
                swap(database[j], database[j + 1]);
            }
        }
    }
}

void selectionSortAsc(Sekolah* database[], int jumlahSekolah) {
    int minIndex;
    for (int i = 0; i < jumlahSekolah - 1; ++i) {
        minIndex = i;
        for (int j = i + 1; j < jumlahSekolah; ++j) {
            if (database[j]->nama < database[minIndex]->nama) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(database[i], database[minIndex]);
        }
    }
}

void insertionSortAsc(Sekolah* database[], int jumlahSekolah) {
    int j;
    for (int i = 1; i < jumlahSekolah; ++i) {
        Sekolah* key = database[i];
        j = i - 1;
        while (j >= 0 && database[j]->nama > key->nama) {
            database[j + 1] = database[j];
            j = j - 1;
        }
        database[j + 1] = key;
    }
}

int main() {
    cout << "Selamat datang di program data sekolah" << endl;

    if (!login()) {
        return 1;
    }

    Sekolah* database[maxSekolah];
    int jumlahSekolah = 0;
    int menu;
    string namaSekolah;
    int index;

    do {
        tampilkanMenu();

        while (!(cin >> menu)) {
            cout << "Masukkan angka sebagai pilihan menu." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (menu) {
            case 1:
                tambahSekolah(database, jumlahSekolah);
                break;
            case 2:
                tampilkanSemuaSekolah(database, jumlahSekolah);
                break;
            case 3:
                tampilkanSemuaSekolah(database, jumlahSekolah);
                int sortMenu;
                cout << "\nPilih cara pengurutan:" << endl;
                cout << "1. Bubble Sort (Descending)" << endl;
                cout << "2. Selection Sort (Ascending)" << endl;
                cout << "3. Insertion Sort (Ascending)" << endl;
                cout << "Pilih menu: ";
                cin >> sortMenu;
                switch (sortMenu) {
                    case 1:
                        bubbleSortDesc(database, jumlahSekolah);
                        cout << "Data sekolah berhasil diurutkan dengan Bubble Sort (Descending)." << endl;
                        break;
                    case 2:
                        selectionSortAsc(database, jumlahSekolah);
                        cout << "Data sekolah berhasil diurutkan dengan Selection Sort (Ascending)." << endl;
                        break;
                    case 3:
                        insertionSortAsc(database, jumlahSekolah);
                        cout << "Data sekolah berhasil diurutkan dengan Insertion Sort (Ascending)." << endl;
                        break;
                    default:
                        cout << "Menu tidak valid." << endl;
                        break;
                }
                tampilkanSemuaSekolah(database, jumlahSekolah);
                break;
            case 4:
                ubahNamaSekolah(database, jumlahSekolah);
                break;
            case 5:
                hapusSekolah(database, jumlahSekolah);
                break;
            case 6:
                cout << "\nData sekolah yang telah diinput:" << endl;
                tampilkanSemuaSekolah(database, jumlahSekolah);
                cout << "\nPilih jenis pencarian:" << endl;
                cout << "1. Sequential Search" << endl;
                cout << "2. Binary Search" << endl;
                cout << "Pilih metode pencarian (atau ketik 0 untuk kembali ke menu): ";
                int searchMethod;
                cin >> searchMethod;
                switch (searchMethod) {
                    case 1:
                        // Urutkan data secara ascending sebelum menampilkan
                        insertionSortAsc(database, jumlahSekolah);
                        cout << "\nData sekolah setelah diurutkan secara ascending:" << endl;
                        tampilkanSemuaSekolah(database, jumlahSekolah);
                        cout << "\nMasukkan nama sekolah yang ingin dicari: ";
                        cin.ignore();
                        getline(cin, namaSekolah);
                        index = sequentialSearch(database, jumlahSekolah, namaSekolah);
                        break;
                    case 2:
                        // Urutkan data secara descending sebelum menampilkan
                        bubbleSortDesc(database, jumlahSekolah);
                        cout << "\nData sekolah setelah diurutkan secara descending:" << endl;
                        tampilkanSemuaSekolah(database, jumlahSekolah);
                        cout << "\nMasukkan nama sekolah yang ingin dicari: ";
                        cin.ignore();
                        getline(cin, namaSekolah);
                        index = binarySearch(database, jumlahSekolah, namaSekolah);
                        break;
                    case 0:
                        // Kembali ke menu utama
                        break;
                    default:
                        cout << "Pilihan pencarian tidak valid." << endl;
                        break;
                }
                if (searchMethod != 0) {
                    if (index != -1) {
                        cout << "Sekolah ditemukan pada indeks " << index + 1 << endl;
                    } else {
                        cout << "Sekolah tidak ditemukan." << endl;
                    }
                }
                break;
            case 7:
                cout << "\nTerima kasih telah menggunakan program data sekolah" << endl;
                cout << "Keluar dari program..." << endl;
                break;
            default:
                cout << "Menu tidak valid." << endl;
        }
    } while (menu != 7);

    for (int i = 0; i < jumlahSekolah; ++i) {
        delete database[i];
    }

    return 0;
}
