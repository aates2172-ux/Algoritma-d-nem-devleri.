#include <stdio.h>

int main() {

    char mesaj[100];     // Mesaj veya sifreli mesaj 
    int anahtar;         // Anahtar degeri 
    int secim;           // Kullanici secimi 
    int i;

    // Menü
    printf("1 - Mesaj Sifrele\n");
    printf("2 - Mesaj Coz\n");
    printf("Seciminizi giriniz: ");
    scanf("%d", &secim);

    // Enter karakterini temizlemek icin.
    getchar();

    if (secim == 1){
         
        //===================== SIFRELEME ===================== 

        printf("Mesaji giriniz : ");
        gets(mesaj);

        printf("Anahtar degerini giriniz: ");
        scanf("%d", &anahtar);

        // Anahtar 26'dan buyukse sadeleştir 
        anahtar = anahtar % 26;

        // Mesajdaki her harf icin 
        for (i = 0; mesaj[i] != '\0'; i++) {

            if (mesaj[i] >= 'a' && mesaj[i] <= 'z') {

                mesaj[i] = mesaj[i] + anahtar;

                // Alfabe sonunu astiysa basa donmek için bu islem uygulanir.
                if (mesaj[i] > 'z') {
                    mesaj[i] = mesaj[i] - 26;
                }
            }
            else if(mesaj[i] >= 'A' && mesaj[i] <= 'Z'){
            mesaj[i] =  mesaj[i] + anahtar;
            if(mesaj[i] > 'Z'){
                mesaj[i] = mesaj[i] - 26;
            }
        }
        }

        printf("Sifrelenmis mesaj: %s\n", mesaj);
    }

    else if (secim == 2) {
        /* ===================== SIFRE COZME ===================== */

        printf("Sifreli mesaji giriniz: ");
        gets(mesaj);

        /* Varsayilan anahtar degeri */
        //anahtar = 3;
        
        printf("Anahtar degerini giriniz: ");
        scanf("%d",&anahtar);
        anahtar=anahtar%26;
        /* Mesajdaki her harf icin donguye alir. */
        for (i = 0; mesaj[i] != '\0'; i++) {

            if (mesaj[i] >= 'a' && mesaj[i] <= 'z') {

                mesaj[i] = mesaj[i] - anahtar;

                /* Alfabenin altina dustuyse sona gitmesi için uygulanan koşul. */
                if (mesaj[i] < 'a') {
                    mesaj[i] = mesaj[i] + 26;
                }
            }
            else if(mesaj[i] >= 'A' && mesaj[i] <= 'Z'){
            mesaj[i] = mesaj[i] - anahtar;
            if(mesaj[i] < 'A'){
                mesaj[i] = mesaj[i] + 26;
            }
        }
        }

        printf("Cozulmus mesaj: %s\n", mesaj);
    }

    else {
        printf("Gecersiz secim yaptiniz!\n");
    }

    return 0;
}
