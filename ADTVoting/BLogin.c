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
	}else{
		printf("Akun gagal didaftarkan!\n");
	}
	fclose(fp);
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
}

//procedure inputlogin
void inputlogin(){
	system("cls");
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
