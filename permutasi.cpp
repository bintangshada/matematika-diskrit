#include <iostream>
#include <string>
#include <map>

using namespace std;

int faktorial(int x) {
    if (x <= 1) return 1;
    return x * faktorial(x - 1);
}

int p(int n, int r) {
    int penyebut = n - r;
    int n_faktorial = faktorial(n);
    int n_r_faktorial = faktorial(penyebut);
    int hasil = n_faktorial / n_r_faktorial;
    return hasil;
}

int permutasiDenganPengulangan(const string& str) {
    map<char, int> frekuensi;
    std::size_t n = str.length(); // Menggunakan std::size_t untuk menghindari peringatan konversi
    system("cls");
    cout << "Menghitung frekuensi setiap karakter dalam string \"" << str << "\"\n\n";
    for (char c : str) {
        frekuensi[c]++;
    }

    for (auto& pair : frekuensi) {
        cout << "Karakter '" << pair.first << "' muncul " << pair.second << " kali.\n";
    }

    int pembilang = faktorial(static_cast<int>(n));
    cout << "\nPembilang (faktorial dari panjang string " << n << "): " << pembilang << endl;
    cout << "Rumus: " << n << "! = " << pembilang << endl;

    int penyebut = 1;

    cout << "\nMenghitung penyebut berdasarkan frekuensi karakter\n";
    for (auto& pair : frekuensi) {
        penyebut *= faktorial(pair.second);
        cout << "\nFaktorial dari frekuensi karakter '" << pair.first << "' (" << pair.second << "): " << faktorial(pair.second) << endl;
        cout << "Rumus: " << pair.second << "! = " << faktorial(pair.second) << endl;
    }

    cout << "\nPenyebut (hasil kali faktorial dari frekuensi karakter): " << penyebut << endl;

    int hasil = pembilang / penyebut;
    cout << "\nRumus: " << pembilang << " / " << penyebut << " = " << hasil << endl;
    cout << "Hasil permutasi dengan pengulangan: " << hasil << endl;
    return hasil;
}

int main() {
    string kata;
    int pilih;
    do {
        system("cls");
        cout << "Pilih Menu\n";
        cout << "1. Materi Permutasi\n";
        cout << "2. Contoh soal\n";
        cout << "3. Rumus Permutasi\n";
        cout << "4. Keluar\n";
        cin >> pilih;
        switch(pilih) {
            case 1: {
                system("cls");
                cout << "PERMUTASI\n\n";
                cout << "Permutasi adalah jumlah urutan berbeda dari pengaturan objek-objek\n";
                cout << "Permutasi merupakan bentuk khusus aplikasi kaidah perkalian.\n";
                cout << "\nMisalkan jumlah objek adalah n, maka\n";
                cout << "- urutan pertama dipilih dari n objek,\n";
                cout << "- urutan kedua dipilih dari n- 1 objek,\n";
                cout << "- urutan ketiga dipilih dari n- 2 objek,\n";
                cout << "...\n";
                cout << "- urutan terakhir dipilih dari 1 objek yang tersisa.\n";
                cout << "\nMenurut kaidah perkalian, permutasi dari n objek adalah\n";
                cout << "\tn(n - 1) (n - 2) ... (2)(1) = n!\n\n";
                system("pause");
                system("cls");
                cout << "Untuk contoh dapat kita lakukan \n";
                cout << "Sebuah mobil mempunyai 4 tempat duduk. Berapa banyak cara 3\n";
                cout << "orang didudukkan jika diandaikan satu orang harus duduk di kursi\n";
                cout << "sopir?\n\n";
                cout << "Jawaban : \n\n";
                cout << "Kursi supir dapat diisi dengan salah satu dari 3 orang (atau 3 cara). Sekarang\n";
                cout << "tersisa tiga buah kursi lagi. Tiga kursi ini dapat diisi oleh dua orang lainnya. Maka\n";
                cout << "jumlah cara mendudukkan tiga orang adalah 3 x P(3, 2) = 3 x (3!/(1!) = 18.\n\n";
                system("pause");
                break;
            }
            case 2: {
                int pilih;
                do{
                    system("cls");
                    cout << "1. Contoh Soal 1\n";
                    cout << "2. Contoh Soal 2\n";
                    cout << "3. Contoh Soal 3\n";
                    cout << "4. Keluar\n";
                    cin >> pilih;
                    switch(pilih) {
                        case 1 : {
                            system("cls");
                            cout << "Contoh soal 1: \n";
                            cout << "Berapa banyak string yang dapat dibentuk dengan\n menggunakan huruf-huruf dari kata MISSISSIPPI?\n";
                            system("pause");
                            system("cls");
                            cout << "Penyelesaian\n";
                            cout << "S = {M,I,S,S,I,S,S,I,P,P,I}\n";
                            cout << "\t huruf M muncul 1 kali\n";
                            cout << "\t huruf I muncul 4 kali\n";
                            cout << "\t huruf S muncul 4 kali\n";
                            cout << "\t huruf P muncul 2 kali\n";
                            cout << "n = 1 + 4 + 4 + 2 = 11 buah = jumlah elemen himpunan S\n";
                            system("pause");
                            system("cls");
                            cout << "Ada dua cara yang dapat digu1nakan untuk menyelesaikan\n persoalan ini, keduanya memberikan hasil yang sama\n";
                            cout << "\nCara 1: Jumlah string =\n\n";
                            cout << "P(11; 1,4,4,2) =\n";
                            cout << "\t11!\n";
                            cout << "------------------  = 39916800 / 1152 = 34650\n";
                            cout << "(1! * 4! * 4! * 2!)\n\n";
                            system("pause");
                            system("cls");
                            cout << "Cara 2: Jumlah string =\n";
                            cout << "C(11, 1) * C(10, 4) * C(6, 4) * C(2, 2) =\n";
                            cout << "11! / (1! * 10!) * 10! / (4! * 6!) * 6! / (4! * 2!) * 2! / (2! * 0!) =\n";
                            cout << "11! / (1!) (4!) (4!) (2!) =34650\n";
                            system("pause");
                            break;
                        }
                        case 2 : {
                            system("cls");
                            cout << "Berapakah jumlah kemungkinan membentuk bilangan 3-angka\n dari 5 angka berikut: 1, 2, 3, 4 , 5, jika:";
                            cout << "\n\na. Angka tidak boleh diulang\n";
                            cout << "b. Angka boleh diulang\n";
                            cout << "Penyelesaian\n";
                            cout << "Dengan rumus permutasi P(5, 3) = 5!/(5 - 3)! = 60\n";
                            system("pause");
                            break;
                        }
                        case 3 : {
                            system("cls");
                            cout << "Lima putra dan tiga putri duduk berderet pada 8 kursi kosong sesuai\ndengan 8 lembar karcis bioskop yang mereka miliki.";
                            cout << "Berapa banyak carauntuk duduk yang diperoleh dengan urutan berbeda jika :\n\n";
                            cout << "a. Putra dan putri dapat duduk di sembarang kursi?\n";
                            cout << "b. Putra dan putri masing-masing mengelompok sehingga hanya sepasang\nputra dan putri yang dapat duduk berdampingan?\n";
                            system("pause");
                            system("cls");
                            cout << "Penyelesaian\n";
                            cout << "Terdapat 8 orang yang menempati 8 kursi dimana perbedaan urutan duduk\nmemberikan hasil yang berbeda.\n";
                            cout << "Ini adalah masalah permutasi 8 unsur dari 8unsur atau P(8, 8) diberikan oleh :\n\n";
                            cout << "P(8, 8) = 8! = 8 x 7 x 6 x 5 x 3 x 2 x 1 =40.320\n";
                            cout << "\n5 orang putra duduk pada 5 kursi tertentu dan pertukaran duduk hanya boleh\npada ke 5 kursi tersebut,\n";
                            cout << "sehingga banyaknya cara duduk putra adalah P(5,5).\n\n";
                            cout << "Demikian juga 3 putri duduk pada tiga kursi tertentu dan pertukaran duduk\ndiatara mereka hanya boleh pada ke 3 kursi ini\n";
                            cout << "3 kursi ini, sehingga banyaknya carauntuk duduk putri adalah P(3, 3).\n\n";
                            cout << "Dengan demikian, banyak cara duduk 5 putra dan 3 putri yang masing-masing \nmengelompok adalah P(5, 5) x P(3, 3)= 5! X 3! = 720\n";
                            system("pause");
                            break;
                        }
                    }
                }
                while(pilih != 4);
                break;
            }
            case 3: {
                int pilih;
                do{
                    system("cls");
                    cout << "1. Rumus permutasi\n";
                    cout << "2. Rumus permutasi kata\n";
                    cout << "3. Keluar\n";
                    cin >> pilih;
                    switch(pilih) {
                        case 1 : {
                            // Contoh soal 3
                            int n,r;
                            system("cls");
                            cout << "P(n,r) = \n";
                            cout << "       n\n";
                            cout << "----------------\n";
                            cout << "    (n - r)\n";
                            cout << "Masukkan n : ";
                            cin >> n;
                            cout << "Masukkan r : ";
                            cin >> r;
                            if (r > n ) {
                                cout << r << " harus kurang dari sama dengan " << n << endl;
                            } else {
                                int hasil = p(n,r);
                                cout << "Hasil: " << hasil << endl;
                            }
                            system("pause");
                            break;
                        }
                        case 2 : {
                            cout << "Masukkan kata: ";
                            cin >> kata;
                            int hasil = permutasiDenganPengulangan(kata);
                            system("pause");
                            break;
                        }
                    }
                }while(pilih != 3);
            }
            case 4: {
                cout << "Keluar dari program.\n";
                break;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
            }
        }
    } while (pilih != 4);

    return 0;
}