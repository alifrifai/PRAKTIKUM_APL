#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

const int MAX_ANIME = 10;
int index;

void tambahkan_anime(string anime[], string genre[], float rating[], int episode[], int& dataAnime) {
    system("cls");
    if (dataAnime < MAX_ANIME) {
        cin.ignore(); 
        cout << "Masukkan nama anime: ";
        getline(cin, anime[dataAnime]);
        cout << "Masukkan genre anime: ";
        getline(cin, genre[dataAnime]);
        cout << "Masukkan rating anime: ";
        cin >> rating[dataAnime];
        cin.ignore();
        cout << "Masukkan jumlah episode anime: ";
        cin >> episode[dataAnime];
        cin.ignore();
        cout << "_________________________________________\n";
        dataAnime++;
    } else {
        cout << "Data anime anda sudah penuh!" << endl;
    }
}

void tampilkan_dataAnime(const string anime[], const string genre[], const float rating[], const int episode[], int dataAnime) {
    cout << "|=================================================|\n";
    cout << "|        < < < < < Data anime anda > > > > >      |\n";  
    cout << "|=================================================|\n\n";
    for (int i = 0; i < dataAnime; ++i) {
        cout << "Nama anime: " << anime[i] << endl;
        cout << "Genre anime: " << genre[i] << endl;
        cout << "Rating anime: " << rating[i] << endl;
        cout << "Jumlah episode anime: " << episode[i] << " Episode" << endl;
        cout << "==================================================" << endl;
    }
        cout << "Data anime yang telah ditambahkan adalah: " << dataAnime << " Anime" << endl;
        cout << "==================================================" << endl;
}

void ubah_dataAnime(string anime[], string genre[], float rating[], int episode[], int dataAnime) {
    system("cls");

    tampilkan_dataAnime(anime, genre, rating, episode, dataAnime);
    if (dataAnime == 0) {
        cout << "Tidak ada data anime untuk diubah." << endl;
        return;
    }

    cout << "Masukkan indeks anime yang ingin diubah: ";
    cin >> index;

    if (index < 0 || index >= dataAnime) {
        cout << "Indeks tidak valid. Coba lagi." << endl;
        return;
    }
    cin.ignore();

    cout << "\nMasukkan nama anime baru: ";
    getline(cin, anime[index]);

    cout << "Masukkan genre anime baru: ";
    getline(cin, genre[index]);

    cout << "Masukkan rating anime baru: ";
    cin >> rating[index];
    cin.ignore();

    cout << "Masukkan jumlah episode anime baru: ";
    cin >> episode[index];
    cin.ignore();

    cout << "=================================================" << endl;
    cout << "Data anime berhasil diubah." << endl;
}

void hapus_dataAnime(string anime[], string genre[], float rating[], int episode[], int& dataAnime) {
    system("cls");
    tampilkan_dataAnime(anime, genre, rating, episode, dataAnime);

    if (dataAnime == 0) {
        cout << "Tidak ada data anime untuk dihapus." << endl;
        return;
    }

    cout << "index dimulai dari 0!\n";
    cout << "Masukkan indeks data anime yang ingin dihapus: ";
    cin >> index;

    if (index < 0 || index >= dataAnime) {
        cout << "Indeks tidak valid. Coba lagi." << endl;
        return;
    }

    for (int i = index; i < dataAnime - 1; ++i) {
        anime[i] = anime[i + 1];
        genre[i] = genre[i + 1];
        rating[i] = rating[i + 1];
        episode[i] = episode[i + 1];
    }
    dataAnime--;

    cout << "Data anime berhasil dihapus." << endl;
}


int main() {

    int pilihan;
    string anime[MAX_ANIME], genre[MAX_ANIME];
    float rating[MAX_ANIME];
    int episode[MAX_ANIME];
    int dataAnime = 0;

    system("cls");
    string nama = "alif";
    string id;
    string password = "130";
    string pw;
    bool benar;
    int hitung;


    hitung = 1;

    while(!benar && hitung <= 3){
        
        system("cls");
        cout << "|==========================================|\n";
        cout << "|  < < Selamat Datang di Program ini! > >  |\n";
        cout << "|==========================================|\n";
        cout << "|    Silahkan login terlebih dahulu...     |\n";
        cout << "|==========================================|\n\n";
        cout << "Masukkan ID Anda : ";
        cin >> id;
        cout << "Masukkan Password Anda : ";
        cin >> pw;


        if (id == nama and pw == password) {

            benar = true;
            continue;

        }
        else if(id != nama or pw != password) {

            cout << "\nID atau Password anda Salah\n";
            cout << "_\n";

            hitung = hitung + 1;

            if(hitung == 4){
            
            system("cls");
            cout << "\nSilahkan Coba lagi nanti!\n";
            exit(0);
            }   
        }
    }

    system("cls");
    while (true) {
        cout << "\n|======================================================|\n";
        cout << "| < = = = Selamat Datang di program CRUD Anime = = = > |\n";
        cout << "|======================================================|\n";
        cout << "| [1]. Tambahkan anime yang anda inginkan              |\n";
        cout << "| [2]. Lihat data Anime                                |\n";
        cout << "| [3]. Ubah data Anime yang anda inginkan              |\n";
        cout << "| [4]. Delete anime yang anda inginkan                 |\n";
        cout << "| [0]. Keluar Program                                  |\n";
        cout << "|======================================================|\n";
        cout << "\nMasukkan pilihan anda [1/2/3/4/0]: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahkan_anime(anime, genre, rating, episode, dataAnime);
                cout << "\nTekan Enter untuk kembali ke menu...";
                cin.get(); 
                system("cls");
                break;

            case 2:
                cin.ignore();
                system("cls");
                tampilkan_dataAnime(anime, genre, rating, episode, dataAnime);
                cout << "\nTekan Enter untuk kembali ke menu...";
                cin.get();
                system("cls");
                break;

            case 3:
                ubah_dataAnime(anime, genre, rating, episode, dataAnime);
                cout << "\nTekan Enter untuk kembali ke menu...";
                cin.get();
                system("cls");
                break;

            case 4:
                cin.ignore();
                hapus_dataAnime(anime, genre, rating,episode, dataAnime);
                cout << "\nTekan Enter untuk kembali ke menu...";
                cin.get();
                system("cls");
                break;

            case 0:
                system("cls");
                cout << "|====================================================|\n";
                cout << "| = = Terima kasih telah menggunakan program ini = = |\n";
                cout << "|====================================================|\n";
                exit(0);

            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
                cout << "\nTekan Enter untuk kembali ke menu...";
                cin.get();
                system("cls");
                break;
        }
    }

    return 0;
}
