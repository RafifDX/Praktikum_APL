#include <iostream>
#include <iomanip>

using namespace std;


int main(){
    cout<<"Selamat datang di program konversi mata uang"<<endl;

    string nama, nim;
    int salah = 0;
    bool lanjut = true;

    while (lanjut){
        cout<<"\nMasukkan Nama : ";
        cin>>nama;
        cout<<"Masukkan NIM : ";
        cin>>nim;

        if (nama != "Rafif" || nim != "2309106044"){
            salah++;
            if (salah == 3){
                cout<<"Anda telah salah memasukkan sebanyak 3 kali"<<endl;
                cout<<"Program berhenti";
                break;
            }
            cout<<"Nama atau NIM salah. Coba lagi."<<endl;
            continue;

        }

        int menu;
        double rupiah, dollar, euro, yen;

        cout<<"\nMenu konversi mata uang"<<endl;
        cout<<"1. Konversi Rupiah ke (Dollar, Euro, Yen)"<<endl;
        cout<<"2. Konversi Dollar ke (Rupiah, Euro, Yen)"<<endl;
        cout<<"3. Konversi Euro ke (Rupiah, Dollar, Yen)"<<endl;
        cout<<"4. Konversi Yen ke (Rupiah, Dollar, Euro)"<<endl;
        cout<<"Pilih menu: ";
        cin>>menu;

        switch(menu){
            case 1:
                cout<<"\nMasukkan jumlah rupiah: ";
                cin>>rupiah;
                dollar = rupiah / 15700;
                euro = rupiah / 17018;
                yen = rupiah / 104;
                cout<<fixed<<setprecision(2);
                cout<<rupiah<<" Rupiah setara dengan: "<<endl;
                cout<<dollar<<" Dollar"<<endl;
                cout<<euro<<" Euro"<<endl;
                cout<<yen<<" Yen"<<endl;
                break;
            
            case 2:
                cout<<"\nMasukkan jumlah Dollar: ";
                cin>>dollar;
                rupiah = dollar * 15700;
                euro = dollar * 92 / 100;
                yen = dollar * 150;
                cout<<fixed<<setprecision(2);
                cout<<dollar<<" Dollar setara dengan: "<<endl;
                cout<< rupiah<<" Rupiah"<<endl;
                cout<<euro<<" Euro"<<endl;
                cout<<yen<<" Yen"<<endl;
                break;
            
            case 3:
                cout<<"\nMasukkan jumlah Euro: ";
                cin>>euro;
                rupiah = euro * 17018;
                dollar = euro * 108 / 100;
                yen = euro * 162;
                cout<<fixed<<setprecision(2);
                cout<<euro<<" Euro setara dengan: "<<endl;
                cout<< rupiah<<" Rupiah"<<endl;
                cout<<dollar<<" Dollar"<<endl;
                cout<<yen<<" Yen"<<endl;
                break;

            case 4:
                cout<<"\nMasukkan jumlah Yen: ";
                cin>>yen;
                rupiah = yen * 104;
                dollar = yen / 150;
                euro = yen / 162;
                cout<<fixed<<setprecision(2);
                cout<<yen<<" Yen setara dengan: "<<endl;
                cout<< rupiah<<" Rupiah"<<endl;
                cout<<dollar<<" Dollar"<<endl;
                cout<<euro<<" Euro"<<endl;
                break;

                default:
                cout<<"Menu tidak valid\n";

        }
        
        char ulang;
        cout<<"\nApakah Anda ingin mengulang program? (y/n): ";
        cin>>ulang;

        if (ulang != 'y'){
            lanjut = false;
            cout<<"\nTerima kasih telah menggunakan program konversi mata uang";
        }
        
    }

    return 0;
}