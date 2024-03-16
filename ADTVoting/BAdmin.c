#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

//admin
char back[2];
FILE *FileA;
FILE *FileB;

int tampilanAdmin() {
    // Declare
    int HASILPILIHAN;

    // Algorithm
    printf("Menu Admin :\n1. Lihat hasil voting\n2. Lihat jumlah hasil voting\n0. Keluar\n\nPilih opsi yang anda inginkan :\n");
    scanf("%d", &HASILPILIHAN);
    return HASILPILIHAN;
}

void LihatHasilVoting(char *filename, int key) {
    // Declare
    int i = 1;
    char str[100];

    // Algorithm
    FILE *file = fopen(filename, "r");
    system("cls");
    if (file != NULL) {
        char line[20];
        printf("Hasil Voting Terdekripsi\n");
        while (fgets(line, sizeof(line), file) != NULL) {
            line[strcspn(line, "\n")] = 0;
            decrypt(line, key);
            sprintf(str, "%d", i);
            printf("Suara %d : %s\n", i, line);
            i++;
        }
        fclose(file);
    } else {
        printf("Gagal membuka File.\n");
    }

    printf("\nKembali ke menu admin? (Y/N) ");
    scanf("%s", back);

    if (strcmp(back, "y") == 0 || strcmp(back, "Y") == 0) {
        menuadmin();
    }
    else {
        exit(0);
    }
}


void LihatJumlahHasilVoting() {
    // Declare
    int calon1 = 0;
    int calon2 = 0;
    int keseluruhan = 0;

    float pCalon1, pCalon2;
    pCalon1 = pCalon2 = 0.0;

    // Algorithm
    FILE *FileB;
    FileB = fopen("jumlah_voting.txt", "r");
    system("cls");
    printf("Jumlah Hasil Voting\n");

    if (FileB == NULL) {
        printf("Gagal membuka File\n");
        return;
    }
    fscanf(FileB, "%d\n%d\n%d\n", &calon1, &calon2, &keseluruhan);
    pCalon1 = (float)calon1 / (float)keseluruhan * 100;
    pCalon2 = (float)calon2 / (float)keseluruhan * 100;
    printf("Jumlah pemilih untuk Calon 1: %d (%.2f%%)\n", calon1, pCalon1);
    printf("Jumlah pemilih untuk Calon 2: %d (%.2f%%)\n", calon2, pCalon2);
    printf("Jumlah keseluruhan pemilih: %d\n", keseluruhan);

    fclose(FileB);

    printf("\nKembali ke menu admin? (Y/N) ");
    scanf("%s", back);

    if (strcmp(back, "y") == 0 || strcmp(back, "Y") == 0) {
        menuadmin();
    }
    else {
        exit(0);
    }
}


void decrypt(char *data, int key) {
    int length = strlen(data);
    int i;
    for (i = 0; i < length; i++) {
        data[i] = data[i] ^ key;
    }
}

void copyB () {
    // Declare
    char tempPilihan[2];
    int jumlahCalon1 = 0;
    int jumlahCalon2 = 0;
    int jumlahKeseluruhan = 0;

    // Algorithm
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
    while (fscanf(FileA, "%s", tempPilihan) == 1) {
        if (strcmp(tempPilihan, ";") == 0) {
            jumlahCalon1++;
        } else if (strcmp(tempPilihan, "8") == 0) {
            jumlahCalon2++;
        }
        jumlahKeseluruhan++;
    }
    fprintf(FileB, "%d\n%d\n%d\n", jumlahCalon1, jumlahCalon2, jumlahKeseluruhan);

    fclose(FileA);
    fclose(FileB);

    exit(0);
}
