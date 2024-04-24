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

void selectionsearchASC(anime arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j].namaAnime > arr[maxIndex].namaAnime) {
                maxIndex = j;
            }
        }
        swap(arr[i], arr[maxIndex]);
    }
}

void insertionsearchDESC(anime arr[], int n) {
    for (int i = 1; i < n; ++i) {
        anime key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].ratingAnime > key.ratingAnime) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(anime arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j].namaAnime > arr[j + 1].namaAnime) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void tambahkan_dataAnime(int *jumlahAnime) {
    system("cls");

    string tambah;

    cout << "|=================================================|\n";
    cout << "|    < < < < < Penambahan Data Anime > > > > >    |\n";  
    cout << "|=================================================|\n\n";
    if (*jumlahAnime < 10) {
        cout << "Masukkan nama anime: ";
        cin.ignore();
        getline(cin, anm[*jumlahAnime].namaAnime);
        cout << "Masukkan genre anime: ";
        getline(cin, anm[*jumlahAnime].genreAnime);
        cout << "Masukkan rating anime: ";
        cin >> anm[*jumlahAnime].ratingAnime;
        cout << "Masukkan jumlah episode anime: ";
        cin >> anm[*jumlahAnime].episodeAnime;
        cout << "Masukkan tanggal rilis animenya (DD): ";
        cin >> anm[*jumlahAnime].rilis.hari;
        cout << "Masukkan bulan rilis animenya (MM): ";
        cin >> anm[*jumlahAnime].rilis.bulan;
        cout << "Masukkan tahun rilis animenya (YY): ";
        cin >> anm[*jumlahAnime].rilis.tahun;
        cout << "_________________________________________________\n";

        (*jumlahAnime)++;

        cout << "\nApakah anda ingin menambah data anime lagi? input y jika iya, klik apapun jika tidak! ";
        cin.ignore(); 
        char tambah = getch();
        if (tambah == 'y' || tambah == 'Y') {
            tambahkan_dataAnime(jumlahAnime);
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
        anime *ptr_anime = anm;
        cin.ignore();
        for(int i = 0; i < jumlahAnime; i++, ptr_anime++){
            cout << i+1 << ". "<< "Nama Anime: " << ptr_anime->namaAnime << "\n";
            cout << "   Genre Anime: " << ptr_anime->genreAnime << "\n";
            cout << "   Rating Anime: " << ptr_anime->ratingAnime << "\n";
            cout << "   Jumlah episode Anime: " << ptr_anime->episodeAnime << "\n";
            cout << "   Data rilisnya Anime: " << ptr_anime->rilis.hari << " - " << ptr_anime->rilis.bulan << " - " << ptr_anime->rilis.tahun << "\n";
            cout << "==================================================" << endl;
        } 
    } else {
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

int sequentialSearchAscending(anime arr[], int n, string key) {
    for (int i = 0; i < n; ++i) {
        if (arr[i].namaAnime == key) {
            return i;
        }
    }
    return -1;
}

int interpolationSearchDescending(anime arr[], int n, string key) {
    int low = 0;
    int high = n - 1;
    while (low <= high && key >= arr[low].namaAnime && key <= arr[high].namaAnime) {
        // Interpolation formula
        int pos = low + ((double)(high - low) / (arr[high].namaAnime[0] - arr[low].namaAnime[0])) * (key[0] - arr[low].namaAnime[0]);

        if (arr[pos].namaAnime == key) {
            return pos;
        }

        if (arr[pos].namaAnime < key) {
            high = pos - 1;
        } else {
            low = pos + 1;
        }
    }
    return -1;
}


void login(){
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
            cout << "| [5]. Mengurutkan data anime                          |\n";
            cout << "| [6]. Mencari data anime                              |\n";
            cout << "| [7]. Kembali ke tampilan login                       |\n";
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
                    tambahkan_dataAnime(&jumlahAnime);
                    system("cls");
                    break;

                case 2:
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
                    try {
                        system("cls");
                        cout << "|=======================================|\n";
                        cout << "|        Mengurutkan data anime         |\n";
                        cout << "|=======================================|\n";
                        cout << "| [1]. Selection Sort (Nama anime Desc) |\n";
                        cout << "| [2]. Insertion Sort (Rating anime     |\n";
                        cout << "| [3]. Bubble Sort (Nama anime Asc)     |\n";
                        cout << "|=======================================|\n";
                        cout << "\nMasukkan pilihan sorting [1/2/3]: ";
                        int sortingOption;
                        cin >> sortingOption;
                        if (cin.fail()) {
                            cin.clear(); 
                            while (cin.get() != '\n'); 
                            throw "\nHARAP MASUKKAN BILANGAN INTEGER"; 
                        }
                        switch (sortingOption) {
                            case 1:
                                selectionsearchASC(anm, jumlahAnime);
                                break;
                            case 2:
                                insertionsearchDESC(anm, jumlahAnime);
                                break;
                            case 3:
                                bubbleSort(anm, jumlahAnime);
                                break;
                            default:
                                cout << "\nInput tidak valid!\n";
                                backToMenu();
                                system("cls");
                                return -1;
                        }
                    } catch(const char* gagal) { 
                        cin.clear();
                        cout << gagal << endl;
                        system("cls");
                        continue;
                    }
                    cout << "\nData anime setelah diurutkan:\n";
                    lihat_dataAnime();
                    backToMenu();
                    system("cls");
                    break;

                case 6:
                    try {
                        system("cls");
                        cout << "|========================================|\n";
                        cout << "|           Mencari data anime           |\n";
                        cout << "|========================================|\n";
                        cout << "| [1]. Sequential Search (ascending)     |\n";
                        cout << "| [2]. Interpolation Search (descending) |\n";
                        cout << "|========================================|\n";
                        cout << "\nMasukkan pilihan pencarian [1/2]: ";
                        int searchOption;
                        cin >> searchOption;
                        if (cin.fail()) {
                            cin.clear(); 
                            while (cin.get() != '\n'); 
                            throw "\nHARAP MASUKKAN BILANGAN INTEGER"; 
                        }
                        string keyword;
                        cout << "Masukkan nama anime yang ingin dicari: ";
                        cin.ignore();
                        getline(cin, keyword);
                        int result;
                        switch (searchOption) {
                            case 1:
                                result = sequentialSearchAscending(anm, jumlahAnime, keyword);
                                break;
                            case 2:
                                result = interpolationSearchDescending(anm, jumlahAnime, keyword);
                                break;
                            default:
                                cout << "\nInput tidak valid!\n";
                                backToMenu();
                                system("cls");
                                return -1;
                        }
                        if (result != -1) {
                            system("cls");
                            cout << "\nData anime ditemukan pada indeks: " << result + 1 << endl;
                            cout << "\nDetail Anime:" << endl;
                            cout << "Nama Anime: " << anm[result].namaAnime << "\n";
                            cout << "Genre Anime: " << anm[result].genreAnime << "\n";
                            cout << "Rating Anime: " << anm[result].ratingAnime << "\n";
                            cout << "Jumlah episode Anime: " << anm[result].episodeAnime << "\n";
                            cout << "Data rilisnya Anime: " << anm[result].rilis.hari << " - " << anm[result].rilis.bulan << " - " << anm[result].rilis.tahun << "\n";
                        } else {
                            cout << "\nData anime tidak ditemukan.\n";
                        }
                        backToMenu();
                        system("cls");
                    } catch(const char* gagal) { 
                        cin.clear();
                        cout << gagal << endl;
                        system("cls");
                        continue;
                    }
                    break;

                case 7:
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