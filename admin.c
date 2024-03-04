#include <stdio.h>
#include <stdlib.h>

// Array of Record
struct Data {
    char username[100];
    char pilihan[100];
};

// Procedure or Function
int tampilanAdmin();
void LihatHasilVoting(struct Data HasilVote);
FILE *FileA;

int main () {
    // Declare
    int hasilPilihan;
    hasilPilihan = 0;
    struct Data HasilVote;

    // Algorithm
    hasilPilihan = tampilanAdmin();
    switch(hasilPilihan) {
        case 1:
            LihatHasilVoting(HasilVote);
            break;
        case 2:
            // Tambah disini bang roy
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Mohon maaf, opsi anda tidak ada di pilihan.");
    }
    return 0;
}

int tampilanAdmin() {
    // Declare
    int HASILPILIHAN;

    // Algorithm
    printf("Opsi anda :\n\n1. Lihat hasil voting\n2. Lihat jumlah hasil voting\n0. Keluar\n\nPilih opsi yang anda inginkan :\n");
    scanf("%d", &HASILPILIHAN);
    return HASILPILIHAN;
}

void LihatHasilVoting (struct Data HasilVote) {
    // Declare
    int i;
    i = 0;
    FileA = fopen("hasil_voting.txt", "r");
    if (FileA == NULL) {
        system("cls");
        printf("Mohon maaf, user belum melakukan vote.");
        return;
    }

    // Algorithm
    system("cls");
    printf("Hasil voting :\n\n");
    while (!feof(FileA)) {
            fscanf(FileA, "%s\n", HasilVote.pilihan);
            printf("JOHNDOE ");
            printf("%s\n", HasilVote.pilihan);
    }

    fclose(FileA);
}
