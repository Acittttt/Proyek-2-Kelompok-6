#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>
///* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int pilihan;
	do{
		title();
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
				menuLoginUser();
				break;
			}
		}
	}while(pilihan != 1 && pilihan != 2);

	return 0;
}
