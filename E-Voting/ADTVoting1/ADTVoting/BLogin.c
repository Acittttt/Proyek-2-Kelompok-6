#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

//login
//procedure enkrip caesar ciper
void enkripsi(char *kata, int kunci) {
    int i;
    for (i = 0; kata[i] != '\0'; i++) {
        if (kata[i] >= 'a' && kata[i] <= 'z') {
            kata[i] = 'a' + (kata[i] - 'a' + kunci) % 26;
        } else if (kata[i] >= 'A' && kata[i] <= 'Z') {
            kata[i] = 'A' + (kata[i] - 'A' + kunci) % 26;
        }
    }
}

//procedure deskrip
void deskripsi(char *kata, int kunci) {
    enkripsi(kata, 26 - kunci);
}


//procedure register
void register_user(){
	system("cls");
	title3();
	char username_user[50], password_user[50];
	printf("Masukkan username : ");
	scanf("%s", username_user);
	printf("Masukkan password : ");
	scanf("%s", password_user);

	//enkripsi
    enkripsi(username_user, 5);
    enkripsi(password_user, 5);

	FILE *fp = fopen("datauser.txt", "a");
	if (fp != NULL){
		fprintf(fp, "%s %s \n", username_user, password_user);
		printf("Akun berhasil didaftarkan!\n");

		char kembali;
		printf("kembali ke menu user ? (Y/N): ");
		scanf(" %s", &kembali);

		system("cls");
		if (kembali == 'y' || kembali == 'Y') {
			fclose(fp);
			menuLoginUser();
		}
		else {
			fclose(fp);
			exit(0);
		}

		}else{
		printf("Akun gagal didaftarkan!\n");
	}
	fclose(fp);
}

//procedur menuloginuser
void menuLoginUser(){
    int pilih;
    do {
    	title3();
        printf("Menu\n");
        printf("1.Register\n");
        printf("2.Login\n");
        printf("Masukkan pilihan anda : ");
        scanf("%d",&pilih);
        switch(pilih){
            case 1 :
                register_user();
                break;
            case 2 :
                inputlogin();
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih lagi.\n");
        }
    } while (pilih != 1 && pilih != 2);
}


//function login
int login(char *username, char *password){
	char username_fp[50], password_fp[50];
	FILE *fp = fopen("datauser.txt", "r");
	if (fp != NULL){
		while(fscanf(fp, "%s %s \n", username_fp, password_fp) != EOF){
			deskripsi(username_fp, 5);
			deskripsi(password_fp, 5);
			if (strcmp(username, username_fp) == 0 && strcmp(password, password_fp) == 0){
				fclose(fp);
				return 1;
			}
		}
		fclose(fp);
	}
	return 0;
}

//function login admin
int loginAdmin() {
	system("cls");
	title2();
	//akun admin
	char admin_username[] = "admin";
	char admin_password[] = "admin123";

    //procedure inputloginAdmin
	char username[50], password[50];
	printf("Masukkan username: ");
	scanf("%s", username);
	printf("Masukkan password: ");
	scanf("%s", password);


    //validasi akun admin
    if (strcmp(username, admin_username) == 0 && strcmp(password, admin_password) == 0) {
    	printf("Login berhasil \n");
    	menuadmin();
        return 1;
    } else {
    	printf("Login gagal. Username atau password salah.\n");
	}

    return 0;
}

//procedure menu admin
void menuadmin(){
	system("cls");
	// Declare
	int hasilPilihan;
	hasilPilihan = 0;
	int key;
    char back[2];

	// Algorithm
	hasilPilihan = tampilanAdmin();
	switch (hasilPilihan) {
		case 1:
		    LihatHasilVoting("hasil_voting.txt", 10);
		    break;
		case 2:
		    LihatJumlahHasilVoting();
		    break;
		case 0:
			exit(0);
		    break;
		default:
		    menuadmin();
    }
}

//procedure inputlogin
void inputlogin(){
	system("cls");
	title3();
	char username[50], password[50];
	printf("Masukkan username: ");
	scanf("%s", username);
	printf("Masukkan password: ");
	scanf("%s", password);

	if (login(username, password)) {
		printf("Login berhasil \n");

		system("cls");
		int pilihan;
	    do {
	        printf("Menu Utama:\n");
	        printf("1. Lihat Data Profil\n");
	        printf("2. Voting Calon \n");
	        printf("3. Keluar\n");
	        printf("Pilih menu: ");
	        scanf("%d", &pilihan);

	        switch (pilihan) {
	            case 1:
	                clearScreen();
	                lihatDataProfil();
	                break;
	            case 2:
	                clearScreen();
	                votingKahim();
	                copyB();
	                break;
	            case 3:
	                printf("Terima kasih, program selesai.\n");
	                break;
	            default:
	                printf("Pilihan tidak valid. Silakan pilih lagi.\n");
	        }
	    } while (pilihan != 3);
		} else {
			printf("Login gagal. Username atau password salah.\n");
		}
}

void title(){
	FILE *file = fopen("icon.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Gagal membuka file list_barang.txt.\n");
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
		printf(" %s", buffer);
    }
    printf("\n");

    fclose(file);
}
