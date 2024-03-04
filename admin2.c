#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include string.h for strlen function

// Array of Record
struct Data {
    char username[100];
    char pilihan[100];
};

// Function prototypes
int tampilanAdmin();
void LihatHasilVoting();
void LihatJumlahHasilVoting();
void copyB(int key);
void decrypt(char *data, int key);
void openFile();

FILE *FileA;

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
    int i = 0;

    // Algorithm
    FileA = fopen("hasil_voting.txt", "r");
    if (FileA == NULL) {
        printf("Gagal membuka hasil_voting.txt\n");
        return;
    }

    system("cls");
    printf("Hasil voting :\n\n");
    while (fscanf(FileA, "%s", HasilVote.pilihan) == 1) {
    	printf("JOHNDOE ");
        printf("%s\n", HasilVote.pilihan);
        i++;
    }

    fclose(FileA);
}

void copyB(int key) {
    // Declare
    struct Data HasilVote;
    int i = 0;
    FILE *FileB;

    // Algorithm
    FileA = fopen("hasil_voting.txt", "r");
    FileB = fopen("FileB.txt", "w");

    if (FileA == NULL || FileB == NULL) {
        printf("Gagal membuka file\n");
        return;
    }

    while (fscanf(FileA, "%s %s", HasilVote.username, HasilVote.pilihan) == 2) {
        // Dekripsi pilihan
        decrypt(HasilVote.pilihan, key);

        // Tulis data ke file FileB
        fprintf(FileB, "%s %s\n", HasilVote.username, HasilVote.pilihan);
        i++;
    }

    fclose(FileA);
    fclose(FileB);

    LihatJumlahHasilVoting(key);
}

void LihatJumlahHasilVoting(int key) {
    // Declare
    int jumlahHasilVoting = 0;
    FILE *FileB;
    struct Data HasilVote;

    // Algorithm
    FileB = fopen("FileB.txt", "r");

    if (FileB == NULL) {
        printf("Gagal membuka FileB.txt\n");
        return;
    }

    while (fscanf(FileB, "%s %s", HasilVote.username, HasilVote.pilihan) == 2) {
        jumlahHasilVoting++;
    }

    fclose(FileB);

    printf("Jumlah hasil voting: %d\n", jumlahHasilVoting);
}

void decrypt(char *data, int key) {
    int i;
    for (i = 0; i < strlen(data); i++) {
        data[i] -= key;
        if (data[i] < 'a') {
            data[i] += 26;
        }
    }
}

void openFile() {
    struct Data HasilVote;
    FILE *FileA;
    int key; // You need to define 'key' here

    // Algorithm
    FileA = fopen("hasil_voting.txt", "r");

    if (FileA == NULL) {
        printf("Gagal membuka FileA.txt\n");
        return;
    }

    fscanf(FileA, "%s %s", HasilVote.username, HasilVote.pilihan);
    fclose(FileA);

    // You need to decrypt the pilihan here if needed
}

void displayDecryptedDataFromFile(char *filename, int key) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        char line[20];  // Adjust buffer size if needed
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

