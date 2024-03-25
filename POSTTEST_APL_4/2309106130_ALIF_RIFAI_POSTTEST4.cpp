#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
using namespace std;


struct rilisAnime {
    string hari;
    string bulan;
    string tahun;
};

struct anime {
    string namaAnime;
    string genreAnime;
    string ratingAnime;
    string episodeAnime;
    struct rilisAnime rilis;
};

anime anm[10];
int jumlahAnime = 0, index;

void backToMenu() {
    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.get();
}
    
void tambahkan_dataAnime() {
    system("cls");

    string tambah;

    cout << "|=================================================|\n";
    cout << "|    < < < < < Penambahan Data Anime > > > > >    |\n";  
    cout << "|=================================================|\n\n";
    if (jumlahAnime < 10) {
        cout << "Masukkan nama anime: ";
        cin.ignore();
        getline(cin, anm[jumlahAnime].namaAnime);
        cout << "Masukkan genre anime: ";
        getline(cin, anm[jumlahAnime].genreAnime);
        cout << "Masukkan rating anime: ";
        cin >> anm[jumlahAnime].ratingAnime;
        cout << "Masukkan jumlah episode anime: ";
        cin >> anm[jumlahAnime].episodeAnime;
        cout << "Masukkan tanggal rilis animenya (DD): ";
        cin >> anm[jumlahAnime].rilis.hari;
        cout << "Masukkan bulan rilis animenya (MM): ";
        cin >> anm[jumlahAnime].rilis.bulan;
        cout << "Masukkan tahun rilis animenya (YY): ";
        cin >> anm[jumlahAnime].rilis.tahun;
        cout << "_________________________________________________\n";

        jumlahAnime++;

        cout << "\nApakah anda ingin menambah data anime lagi? input y jika iya, klik apapun jika tidak! ";
        cin.ignore(); 
        char tambah = getch();
        if (tambah == 'y' || tambah == 'Y') {
            tambahkan_dataAnime();
        } else {
            cin.ignore(); 
            return;
        }

    }
    else {
        cout << "\nData anime anda sudah penuh!\n";
    }
}

void lihat_dataAnime(){
    system("cls");
    cout << "|=================================================|\n";
    cout << "|        < < < < < Data anime anda > > > > >      |\n";  
    cout << "|=================================================|\n\n";
    if (jumlahAnime != 0) {
        for(int i = 0; i < jumlahAnime; i++){
            cout << i+1 << ". "<< "Nama Anime: " << anm[i].namaAnime << "\n";
            cout << "   Genre Anime: " << anm[i].genreAnime << "\n";
            cout << "   Rating Anime: " << anm[i].ratingAnime << "\n";
            cout << "   Jumlah episode Anime: " << anm[i].episodeAnime << "\n";
            cout << "   Data rilisnya Anime: " << anm[i].rilis.hari << " - " << anm[i].rilis.bulan << " - " << anm[i].rilis.tahun << "\n";
            cout << "==================================================" << endl;
        } 
    }else {
        cout << "\nData anime belum ditambahkan!.\n";
    }
}

void ubah_dataAnime() {
    system("cls");
    lihat_dataAnime();

    string ubah;

    if (jumlahAnime > 0) {
        while (true) {
            cout << "\nApakah anda ingin megubah data anime anda y/n? ";
            cin >> ubah;

            system("cls");
            if (ubah == "y" || ubah == "Y") {
                cout << "|=================================================|\n";
                cout << "|     < < < < Perubahan Data Anime > > > > >      |\n";  
                cout << "|=================================================|\n\n";

                if (jumlahAnime != 0) {
                    for(int i = 0; i < jumlahAnime; i++){
                        cout << i+1 << ". "<< "Nama Anime: " << anm[i].namaAnime << "\n";
                        cout << "   Genre Anime: " << anm[i].genreAnime << "\n";
                        cout << "   Rating Anime: " << anm[i].ratingAnime << "\n";
                        cout << "   Jumlah episode Anime: " << anm[i].episodeAnime << "\n";
                        cout << "   Data rilisnya Anime: " << anm[i].rilis.hari << " - " << anm[i].rilis.bulan << " - " << anm[i].rilis.tahun << "\n";
                        cout << "==================================================" << endl;
                    } 
                } else {
                    cout << "\nData anime belum ditambahkan!.\n";
                    break;
                }
                cout << "\nMasukkan nomor data anime yang ingin diubah: ";
                cin >> index;
                if (index < 0 || index > jumlahAnime) {
                    cout << "\nInputan yang anda masukkan salah!!!\n";
                    continue;
                }else {
                    system("cls");
                    cout << "|=================================================|\n";
                    cout << "|     < < < < Perubahan Data Anime > > > > >      |\n";  
                    cout << "|=================================================|\n\n";

                    cout << "Masukkan nama anime: ";
                    cin.ignore();
                    getline(cin, anm[index - 1].namaAnime);
                    cout << "Masukkan genre anime: ";
                    getline(cin, anm[index - 1].genreAnime);
                    cout << "Masukkan rating anime: ";
                    cin >> anm[index - 1].ratingAnime;
                    cout << "Masukkan jumlah episode anime: ";
                    cin >> anm[index - 1].episodeAnime;
                    cout << "Masukkan tanggal rilis animenya (DD): ";
                    cin >> anm[index - 1].rilis.hari;
                    cout << "Masukkan bulan rilis animenya (MM): ";
                    cin >> anm[index - 1].rilis.bulan;
                    cout << "Masukkan tahun rilis animenya (YY): ";
                    cin >> anm[index - 1].rilis.tahun;
                    cout << "_________________________________________________\n";
                }
                cout << "Data anime berhasil dirubah.\n";
                break;

            } else if (ubah == "n" || ubah == "N") {
                break; 
            } else {
                cout << "\nINPUTAN INVALID BRO!!!\n";
            }
        }
    }else {
        cout << "\nBelum ada data anime untuk diubah." << endl;
        return;
    } 
}

void hapus_dataAnime() {
    system("cls");
    lihat_dataAnime();

    string hapus;

    if (jumlahAnime > 0) {
        while (true) {
            cout << "\nApakah anda ingin menghapus data anime y/n? ";
            cin >> hapus;

            system("cls");
            if (hapus == "y" || hapus == "Y") {
                cout << "|=================================================|\n";
                cout << "|    < < < < Penghapusan Data Anime > > > > >     |\n";  
                cout << "|=================================================|\n\n";

                if (jumlahAnime != 0) {
                    for(int i = 0; i < jumlahAnime; i++){
                        cout << i+1 << ". "<< "Nama Anime: " << anm[i].namaAnime << "\n";
                        cout << "   Genre Anime: " << anm[i].genreAnime << "\n";
                        cout << "   Rating Anime: " << anm[i].ratingAnime << "\n";
                        cout << "   Jumlah episode Anime: " << anm[i].episodeAnime << "\n";
                        cout << "   Data rilisnya Anime: " << anm[i].rilis.hari << " - " << anm[i].rilis.bulan << " - " << anm[i].rilis.tahun << "\n";
                        cout << "==================================================" << endl;
                    } 
                } else {
                    cout << "\nData anime belum ditambahkan!.\n";
                    break;
                }

                cout << "\nMasukkan nomor data anime yang ingin dihapus: ";
                cin >> index;
                
                if (index <= 0 || index > jumlahAnime) {
                    cout << "\nNomor data anime yang Anda masukkan tidak valid!\n";
                    continue;
                } else {
                    for (int i = index - 1; i < jumlahAnime - 1; i++) {
                        anm[i] = anm[i + 1];
                    }
                    jumlahAnime--;
                }

                cout << "Data anime berhasil dihapus.\n";
                break;

            } else if (hapus == "n" || hapus == "N") {
                break; 

            } else {
                cout << "\nINPUTAN INVALID BRO!!!\n";
            }
        }
    } else {
        cout << "\nBelum ada data anime yang bisa dihapus!\n";
        return;
    }
}

bool login(){    // FUNGSI BANG
    system("cls");
    string nama = "alif";
    string id;
    string password = "130";
    string pw;
    bool benar;
    string pilihan_login;
    int hitung;

    
    hitung = 1;
        
    system("cls");

    while(!benar && hitung <= 3){
        cout << "|==========================================|\n";
        cout << "|  < < Selamat Datang di Program ini! > >  |\n";
        cout << "|==========================================|\n";
        cout << "|    Silahkan login terlebih dahulu...     |\n";
        cout << "|==========================================|\n\n";
        cout << "1. Login\n";
        cout << "2. Keluar\n";
        cout << "Masukkan pilihan anda: "; cin >> pilihan_login;
        
        if(pilihan_login == "1"){

            system("cls");  
            while (hitung <= 3){
                cout << "Masukkan ID Anda : ";
                cin >> id;
                cout << "Masukkan Password Anda : ";
                cin >> pw;

                if (id == nama and pw == password) {

                    benar = true;
                    break;

                }else {
                    system("cls");
                    cin.ignore();
                    cout << "\nID atau Password anda Salah\n";
                    system("cls");

                    hitung = hitung + 1;

                    if(hitung == 4){
                    
                    system("cls");
                    cout << "\nSilahkan Coba lagi nanti!\n";
                    exit(0);
                    }   
                }
            }    
        } 
        else if(pilihan_login == "2") {
            system("cls");
            cout << "|=======================================|\n";
            cout << "| = = Terima Kasih Telah Berkunjung = = |\n";
            cout << "|=======================================|\n";
            exit(0);
        } else {
            system("cls");
            cout << "Pilihan yang anda masukkan tidak valid. Coba lagi.";
            system("cls");
        }
    }
}

int menu() {
    int pilihan;

    system("cls");
    while (true) {
        try {
            cout << "|======================================================|\n";
            cout << "| < = = = Selamat Datang di program CRUD Anime = = = > |\n";
            cout << "|======================================================|\n";
            cout << "| [1]. Tambahkan anime yang anda inginkan              |\n";
            cout << "| [2]. Lihat data Anime                                |\n";
            cout << "| [3]. Ubah data Anime yang anda inginkan              |\n";
            cout << "| [4]. Delete anime yang anda inginkan                 |\n";
            cout << "| [5]. Kembali ke tampilan login                       |\n";
            cout << "| [0]. Keluar Program                                  |\n";
            cout << "|======================================================|\n";
            cout << "\nMasukkan pilihan anda [1/2/3/4/0]: ";
            cin >> pilihan;

            if (cin.fail()) {
                cin.clear(); 
                while (cin.get() != '\n'); 
                throw "\nHARAP MASUKKAN BILANGAN INTEGER"; 
            }
            switch (pilihan) {
                case 1:
                    tambahkan_dataAnime();
                    system("cls");
                    break;

                case 2:
                    cin.ignore();
                    system("cls");
                    lihat_dataAnime();
                    backToMenu();
                    system("cls");
                    break;

                case 3:
                    cin.ignore();
                    ubah_dataAnime();
                    backToMenu();
                    system("cls");
                    break;

                case 4:
                    cin.ignore();
                    hapus_dataAnime();
                    backToMenu();
                    system("cls");
                    break;

                case 5:
                    cin.ignore();
                    system("cls");
                    login();
                    system("cls");
                    break;

                case 0:
                    system("cls");
                    cout << "|====================================================|\n";
                    cout << "| = = Terima kasih telah menggunakan program ini = = |\n";
                    cout << "|====================================================|\n";
                    exit(0);
                
                default:
                    cout << "\nINPUTAN ANDA INVALID\n" << endl;
                    system("cls");
                    continue;
            }
        } 
        catch(const char* gagal) { 
            cin.clear();
            cout << gagal << endl;
            system("cls");
            continue;
        }
    }
}

int main(){
    login();
    menu();
    return 0;
}