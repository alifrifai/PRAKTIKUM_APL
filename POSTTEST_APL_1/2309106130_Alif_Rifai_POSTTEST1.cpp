#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {

    system("cls");
    string nama = "alif";
    string id;
    string password = "2309106130";
    string pw;
    bool benar;
    int hitung;

    cout << "<<=======================================>>\n";
    cout << "  Selamat Datang di Program Konversi Suhu \n";
    cout << "<<=======================================>>\n";

    hitung = 1;

    while(!benar && hitung <= 3){
        
        cout << "\nMasukkan ID Anda : ";
        cin >> id;
        cout << "Masukkan Password Anda : ";
        cin >> pw;


        if (id == nama and pw == password) {

            benar = true;
            cout << "\n<< Silahkan lanjut ke program konversi suhu >>\n";
            continue;

        }
        else if(id != nama or pw != password) {

            cout << "\nID atau Password anda Salah\n";
            cout << "___________________________________\n";

        hitung = hitung + 1;

        if(hitung == 4){
            
            system("cls");
            cout << "\nSilahkan Coba lagi nanti!\n";
            exit(0);
        }   
        }
    }

    int menu;

    system("cls");
        int pilihan;
        float celcius;
        float reamur;
        float fahrenheit;
        float kelvin;

        cout << "\n<< Selamat datang di Program konversi Suhu >>\n";
        cout << "______________________________________________\n";

        while (true) {
        
        cout << "\n[1]. Konversi Celcius ke (Reamur, Farenheit, Kelvin)\n" ;
        cout << "[2]. Konversi Reamur ke (Celcius, Farenheit, Kelvin)\n";
        cout << "[3]. Konversi Farenheit ke (Celcius, Reamur, Kelvin)\n";
        cout << "[4]. Konversi Kelvin ke (Celcius, Reamur, Farenheit)\n";
        cout << "[0]. Keluar Program\n";

        cout << "\n[Note: Inputan harus berupa bilangan integer!]";
        cout << "\n Masukkan Pilihan Anda [1/2/3/4/0]: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: 
                cout << "\n[Note: Inputan harus berupa bilangan integer atau float!] ";
                cout << "\n Masukkuan suhu celcius yang ingin di konversi : ";
                cin >> celcius;

                cout << "\n" << celcius << "C dalam Reamur adalah : " << celcius * 4/5 << "R\n";
                cout << celcius << "C dalam Fahrenheit adalah : " << celcius * 9/5 + 32 << "F\n";
                cout << celcius << "C dalam Kelvin adalah : " << celcius + 273 << "K\n";
                cout << "_______________________________________________________\n";
                break;

            case 2:
                cout << "\n[Note: Inputan harus berupa bilangan integer atau float!] ";
                cout << "\n Masukkuan suhu reamur yang ingin di konversi : ";
                cin >> reamur;

                cout << "\n" << reamur << "R dalam Celcius adalah : " << reamur * 5/4 << "C\n";
                cout << reamur << "R dalam Fahrenheit adalah : " << reamur * 9/4 + 32 << "F\n";
                cout << reamur << "R dalam Kelvin adalah : " << reamur * 5/4 + 273 << "K\n";
                cout << "_______________________________________________________\n";
                break;

            case 3:
                cout << "\n[Note: Inputan harus berupa bilangan integer atau float!] ";
                cout << "\n Masukkuan suhu fahrenheit yang ingin di konversi : ";
                cin >> fahrenheit;

                cout << "\n" << fahrenheit << "F dalam Celcius adalah : " << (fahrenheit - 32) * 5/9 << "C\n";
                cout << fahrenheit << "F dalam Reamur adalah : " << (fahrenheit - 32) * 4/9 << "R\n";
                cout << fahrenheit << "F dalam Kelvin adalah : " << (fahrenheit - 32) * 5/9 +273 << "K\n";
                cout << "_______________________________________________________\n";
                break;

            case 4:
                cout << "\n[Note: Inputan harus berupa bilangan integer atau float!] ";
                cout << "\n Masukkuan suhu kelvin yang ingin di konversi : ";
                cin >> kelvin;

                cout << "\n" << kelvin << "K dalam Celcius adalah : " << kelvin - 273 << "C\n";
                cout << kelvin << "K dalam Reamur adalah : " << (kelvin - 273) * 4/5 << "R\n";
                cout << kelvin << "K dalam Fahrenheit adalah : " << (kelvin - 273) * 9/5 + 32 << "F\n";
                cout << "_______________________________________________________\n";
                break;

            case 0:
            system("cls");
                cout << "\nTerima Kasih telah menggunakan program ini.\n";
                cout << "____________________________________________\n";
                exit(0);
                
            default:
                cout << "\nPilihan Anda Tidak ada di Menu!\n";
                cout << "_______________________________________________________\n";
                continue;
        }       
        }
    return 0;
}