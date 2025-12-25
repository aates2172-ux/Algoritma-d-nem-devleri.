#include <stdio.h>

#define BOYUT 5

char labirent[BOYUT][BOYUT] = {
    {'1','1','0','1','1'},
    {'0','1','0','1','0'},
    {'1','1','1','1','0'},
    {'1','0','0','1','1'},
    {'1','1','1','0','1'}
};

/* Ziyaret edilen yerleri tutar */
int ziyaret[BOYUT][BOYUT] = {0};

/*
    Bu fonksiyon, (x,y) konumundan cikisa yol bulmaya calisir.
    Yol bulursa 1, bulamazsa 0 dondurur.
*/
int yolBul(int x, int y) {

    /* Sinir kontrolu */
    if (x < 0 || x >= BOYUT || y < 0 || y >= BOYUT)
        return 0;

    /* Engel veya daha once gidilmisse */
    if (labirent[x][y] == '0' || ziyaret[x][y] == 1)
        return 0;

    /* Cikis noktasina gelindiyse */
    if (x == 4 && y == 4) {
        labirent[x][y] = 'X';
        return 1;
    }

    /* Bu noktayi ziyaret ettik */
    ziyaret[x][y] = 1;
    labirent[x][y] = 'X';

    /* Asagi gitme */
    if (yolBul(x + 1, y))
        return 1;

    /* Yukari gitme */
    if (yolBul(x - 1, y))
        return 1;

    /* Saga gitme */
    if (yolBul(x, y + 1))
        return 1;

    /* Sola gitme */
    if (yolBul(x, y - 1))
        return 1;

    /* Yol bulunamadi, geri al */
    labirent[x][y] = '1';
    return 0;
}

/* Labirenti ekrana yazdirir. */
void labirentiYazdir() {
    int i, j;
    for (i = 0; i < BOYUT; i++) {
        for (j = 0; j < BOYUT; j++) {
            printf("%c ", labirent[i][j]);
        }
        printf("\n");
    }
}

int main() {

    /* Labirent gecerlilik kontrol kısmı */
    if (labirent[0][0] == '0' || labirent[4][4] == '0') {
        printf("Baslangic veya cikis kapali!\n");
        return 0;
    }

    /* Yol arama kısmı */
    if (yolBul(0, 0)) {
        printf("Cikisa giden yol bulundu:\n");
        labirentiYazdir();
    } else {
        printf("Cikisa giden yol bulunamadi!\n");
    }

    return 0;
}
