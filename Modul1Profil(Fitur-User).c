#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lihatDataProfil();
int pilihCalonPresiden();
int pilihCalonWakilPresiden();

void clearScreen() {
    system("cls");
}

int main() {
    int pilihan;

    do {
        printf("Menu Utama:\n");
        printf("1. Lihat Data Profil\n");
        printf("2. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                clearScreen();
                lihatDataProfil();
                break;
            case 2:
                printf("Terima kasih, program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih lagi.\n");
        }
    } while (pilihan != 2);

    return 0;
}

void lihatDataProfil() {
    int pilihan;

    do {
        printf("\nData Profil:\n");
        printf("1. Calon Ketua Himpunan 1 \n");
        printf("2. Calon Ketua Himpunan 2 \n");
        printf("3. Kembali ke Menu Utama\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                clearScreen();
                pilihCalonPresiden();
                break;
            case 2:
                clearScreen();
                pilihCalonWakilPresiden();
                break;
            case 3:
                printf("Kembali ke Menu Utama.\n");
                clearScreen();
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih lagi.\n");
        }
    } while (pilihan != 3);
}

int pilihCalonPresiden() {
    printf("Nama : Muhammad Ihsan Maulana \n");
    printf("NIM  : 221809021 \n");
    printf("TTL  : Bandung, 12 Oktober 2004\n");
    printf("Visi & Misi : \n");
    printf("1. Membangun himpunan yang inklusif dan berwawasan ke depan.\n");
    printf("2. Menyelenggarakan berbagai kegiatan kreatif untuk meningkatkan semangat kebersamaan.\n");
    printf("3. Mengadakan pelatihan kepemimpinan guna mengasah potensi setiap anggota.\n");
    printf("4. Menjalin kerjasama dengan pihak eksternal untuk memperluas jaringan dan peluang karir.\n");

    int pilihan;
    printf("\n1. Kembali ke Menu Utama\n");
    printf("Pilih menu: ");
    scanf("%d", &pilihan);

    if (pilihan == 1) {
        clearScreen();
    }

    return pilihan;
}

int pilihCalonWakilPresiden() {
    printf("Nama : Wahyu Ertansa \n");
    printf("NIM  : 221809034 \n");
    printf("TTL  : Bandung, 25 Mei 2004\n");
    printf("Visi & Misi : \n");
    printf("1. Menyediakan wadah yang aman dan nyaman untuk seluruh anggota himpunan.\n");
    printf("2. Mengembangkan program kesejahteraan mahasiswa agar kebutuhan dasar terpenuhi\n");
    printf("3. Menyelenggarakan kegiatan sosial untuk memberikan dampak positif pada lingkungan sekitar.\n");
    printf("4. Meningkatkan transparansi dan akuntabilitas pengelolaan himpunan.\n");

    int pilihan;
    printf("\n1. Kembali ke Menu Utama\n");
    printf("Pilih menu: ");
    scanf("%d", &pilihan);

    if (pilihan == 1) {
        clearScreen();
    }

    return pilihan;
}

