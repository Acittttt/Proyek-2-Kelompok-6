#include <stdio.h>
#include <string.h>

// Fungsi untuk mendekripsi string
void decryptString(char *str) {
    while (*str != '\0') {
        *str = *str - 3;  // Geser karakter sebanyak 3 langkah ke belakang
        str++;
    }
}

int main() {
    FILE *file;
    char line[256];  // Sebaiknya ukuran ini cukup besar untuk menampung satu baris data

    // Membuka file user.txt untuk dibaca
    file = fopen("user.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return 1;
    }

    printf("=== Data User ===\n");

    // Membaca file baris per baris
    while (fgets(line, sizeof(line), file) != NULL) {
        // Mencari posisi karakter ':' untuk memisahkan nama variabel dan data
        char *separator = strchr(line, ':');
        if (separator != NULL) {
            // Mendapatkan nama variabel
            char variableName[50];
            strncpy(variableName, line, separator - line);
            variableName[separator - line] = '\0';

            // Mendapatkan data setelah karakter ':'
            char *data = separator + 1;

            // Menghapus spasi di awal data jika ada
            while (*data == ' ') {
                data++;
            }

            // Mendekripsi data yang relevan
            if (strcmp(variableName, "Tempat/Tanggal Lahir") == 0 || strcmp(variableName, "Password") == 0 || strcmp(variableName, "Alamat") == 0) {
                decryptString(data);
                printf("\n");
            }

            // Menampilkan hasil dekripsi dengan format yang rapi
            printf("%-25s: %s", variableName, data);
        }
    }

    printf("=================\n");

    // Menutup file setelah selesai membaca
    fclose(file);

    return 0;
}
