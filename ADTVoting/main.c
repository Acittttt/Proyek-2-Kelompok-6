#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int pilihan, pilih;
	printf("---------------------------------------\n");
	printf("          SELAMAT DATANG DI\n");
    printf("          SISTEM E-VOTING\n");
	printf("---------------------------------------\n");
	
	printf("Menu\n");
	printf("1.Admin\n");
	printf("2.User\n");
	printf("Masukkan pilihan anda : ");
	scanf("%d",&pilihan);
	system("cls");
	switch(pilihan){
		case 1 :{
			loginAdmin();
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
	return 0;
}
