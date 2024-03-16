#ifndef HEADER_H
#define HEADER_H

//login
//procedure enkrip caesar ciper
void enkripsi(char *kata, int kunci);

//procedure deskrip
void deskripsi(char *kata, int kunci);

//procedure register
void register_user();

//function login
int login(char *username, char *password);

//function login admin
int loginAdmin();

//procedur menuloginuser
void menuLoginUser();

//procedure menu admin
void menuadmin();

//procedure inputlogin
void inputlogin();

/* ---------------------USER------------------------*/
void clearScreen();

void hapusIsiFile(const char *namaFile);

void lihatDataProfil();

int pilihCalonPresiden();

int pilihCalonWakilPresiden();

void votingKahim();

void encrypt(char *data, int key);

void saveEncryptedDataToFile(char *filename, int data, int key) ;

void menuuser();

/* ---------------------ADMIN------------------------*/

int tampilanAdmin();

void LihatHasilVoting(char *filename, int key);

void LihatJumlahHasilVoting();

void decrypt(char *data, int key);

void copyB ();

void kembaliMenu ();
#endif
