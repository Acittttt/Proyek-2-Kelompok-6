#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Fungsi untuk mengenkripsi string
void encryptString(char *str) {
    while (*str != '\0') {
        *str = *str + 3;  // Geser karakter sebanyak 3 langkah
        str++;
    }
}

// Fungsi untuk membuat teks acak
void generateRandomText(char *randomText, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    srand((unsigned int)time(NULL));

    int i = 0;
    while (i < length - 1) {  // Mengubah batas menjadi length - 1
        int index = rand() % (int)(sizeof(charset) - 1);
        randomText[i] = charset[index];
        i++;
    }

    randomText[length - 1] = '\0';  // Menambahkan null-terminator di akhir
}

int main() {
    FILE *file;
    char nama[50], ttl[20], alamat[100], username[20], password[20], randomText[20];

    // Input data dari pengguna
    printf("Masukkan Nama: ");
    fgets(nama, sizeof(nama), stdin);
    nama[strcspn(nama, "\n")] = '\0';  // Menghapus newline character

    printf("Masukkan Tempat/Tanggal Lahir (format: Tempat, DD-MM-YYYY): ");
    fgets(ttl, sizeof(ttl), stdin);
    ttl[strcspn(ttl, "\n")] = '\0';

    printf("Masukkan Alamat: ");
    fgets(alamat, sizeof(alamat), stdin);
    alamat[strcspn(alamat, "\n")] = '\0';

    printf("Masukkan Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Masukkan Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    // Enkripsi Tempat/Tanggal Lahir dan Password
    encryptString(ttl);
    encryptString(password);
    encryptString(alamat);

    // Menyimpan data ke dalam file user.txt
    file = fopen("user.txt", "a");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return 1;
    }

    // Menghasilkan teks acak untuk alamat
    generateRandomText(randomText, 10);

    // Menyimpan data ke dalam file user.txt
    fprintf(file, "Nama: %s\n", nama);
    fprintf(file, "Username: %s\n", username);
    fprintf(file, "Tempat/Tanggal Lahir: %s\n", ttl);
    fprintf(file, "Alamat: %s\n", alamat);
    fprintf(file, "Password: %s\n", password);
    fprintf(file, "------------------------\n");

    fclose(file);

    printf("Registrasi berhasil. Data telah disimpan di user.txt.\n");

    return 0;
}

