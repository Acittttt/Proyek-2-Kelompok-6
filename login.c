#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	
	// Enkripsi
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

// Function login
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

//procedure inputlogin
void inputlogin(){
	system("cls");
	char username[50], password[50];
	printf("Masukkan username: ");
	scanf("%s", username);
	printf("Masukkan password: ");
	scanf("%s", password);

	if (login(username, password)) {
		printf("Login berhasil");
		} else {
			printf("Login gagal. Username atau password salah.\n");
		}
}


int main(){
	
	int pilihan, pilih;
	printf("---------------------------------------\n");
	printf("\t\t E-Voting \n");
	printf("---------------------------------------\n");
	
	printf("Menu\n");
	printf("1.Admin\n");
	printf("2.User\n");
	printf("Masukkan pilihan anda : ");
	scanf("%d",&pilihan);
	system("cls");
	switch(pilihan){
		case 1 :{
			printf("admin");		
			break;
				}
		case 2 :{
			printf("Menu\n");
			printf("1.Register\n");
			printf("2.Login\n");
			printf("Masukkan pilihan anda : ");
			scanf("%d",&pilih);
			switch(pilih){
				case 1 :{
					register_user();
					break;
				}
				case 2 :{
					inputlogin();
					break;
				}
			}
			break;
		}
	}
}
