#ifndef HEADER_H
#define HEADER_H

// Array of Record
struct Data {
    char pilihan[2];
};


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

void LihatHasilVoting();

void LihatJumlahHasilVoting();

void decrypt(char *data, int key);

void displayDecryptedDataFromFile(char *filename, int key);
#endif
