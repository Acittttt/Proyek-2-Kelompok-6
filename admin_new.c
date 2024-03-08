#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include string.h for strlen function

// Array of Record
struct Data {
    char pilihan[2];
};

// Function prototypes
int tampilanAdmin();
void LihatHasilVoting();
void LihatJumlahHasilVoting();
void decrypt(char *data, int key);

FILE *FileA;
FILE *FileB;

int main() {
    // Declare
    int hasilPilihan;
    hasilPilihan = 0;
    int key;

    // Algorithm
    hasilPilihan = tampilanAdmin();
    switch (hasilPilihan) {
        case 1:
            LihatHasilVoting();
            break;
        case 2:
            displayDecryptedDataFromFile("hasil_voting.txt", 10);
            LihatJumlahHasilVoting();
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

void LihatHasilVoting() {
    // Declare
    struct Data HasilVote;
    int i = 1;
    char str[2];

    // Algorithm
    FileA = fopen("hasil_voting.txt", "r");
    if (FileA == NULL) {
        printf("Gagal membuka hasil_voting.txt\n");
        return;
    }

    system("cls");
    printf("Hasil voting :\n\n");
    while (!feof(FileA)) {
            fscanf(FileA, "%s\n", HasilVote.pilihan);
            sprintf(str, "%d", i);
            printf("Suara %d : ", i);
            printf("%s\n", HasilVote.pilihan);
            i++;
    }

    fclose(FileA);
}

void LihatJumlahHasilVoting() {
    struct Data HasilVote;

    int jumlahCalon1 = 0;
    int jumlahCalon2 = 0;
    int jumlahKeseluruhan = 0;

    FileA = fopen("hasil_voting.txt", "r");
    FileB = fopen("jumlah_voting.txt", "w");

    if (FileA == NULL) {
        printf("Gagal membuka File\n");
        return;
    }
    if (FileB == NULL) {
        printf("Gagal membuka File\n");
        return;
    }

    while (fscanf(FileA, "%s", HasilVote.pilihan) == 1) {
        if (strcmp(HasilVote.pilihan, ";") == 0) {
            jumlahCalon1++;
        } else if (strcmp(HasilVote.pilihan, "8") == 0) {
            jumlahCalon2++;
        }
        jumlahKeseluruhan++;
    }

    printf("\nJumlah pemilih untuk Calon 1: %d\n", jumlahCalon1);
    printf("Jumlah pemilih untuk Calon 2: %d\n", jumlahCalon2);
    printf("Jumlah keseluruhan pemilih: %d\n", jumlahKeseluruhan);
    fprintf(FileB, "%d\n%d\n%d\n", jumlahCalon1, jumlahCalon2, jumlahKeseluruhan);

    fclose(FileA);
    fclose(FileB);
}

void decrypt(char *data, int key) {
    int length = strlen(data);
    int i;
    for (i = 0; i < length; i++) {
        data[i] = data[i] ^ key;
    }
}

void displayDecryptedDataFromFile(char *filename, int key) {
    FILE *file = fopen(filename, "r");
    system("cls");
    if (file != NULL) {
        char line[20];  // Adjust buf2fer size if needed
        while (fgets(line, sizeof(line), file) != NULL) {
            line[strcspn(line, "\n")] = 0;  // Remove newline character if present
            decrypt(line, key);
            printf("Hasil Voting Terdekripsi: %s\n", line);
        }
        fclose(file);
    } else {
        printf("Gagal membaca file hasil voting.\n");
    }
}
