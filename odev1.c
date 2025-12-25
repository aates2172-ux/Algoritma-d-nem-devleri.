#include <stdio.h>   
#include <stdlib.h>  
#include <time.h>    

#define AY_SAYISI 12 
/*/
    Bu program:
    1) 12 aylık rastgele ciro(kazanc) degerleri üretir.
    2) Yatay bar grafiği çizimlerini gösterir.
    3) Dikey bar grafiği çizimlerini gösterir.
/*/

int main() {

    int ciro[AY_SAYISI];   
    int i, j;              
    int maxCiro = 0;       

    srand(time(NULL));     // Rastgele sayi üretmek için bu ifadeyi kullanıyoruz.

    //12 aylık ciroyu olusturur.
    for (i = 0; i < AY_SAYISI; i++) {
        ciro[i] = (rand() % 10) + 1;   // 1 - 10 arasi
    }

    //12 aylık ciro içinde en büyük ciroyu(kazancı) bulur.
    for (i = 0; i < AY_SAYISI; i++) {
        if (ciro[i] > maxCiro) {
            maxCiro = ciro[i];
        }
    }

    
    printf("\n==================================\n");
    printf("\nYATAY BAR GRAFIK;\n");
    printf("\n==================================\n\n");
    

    for (i = 0; i < AY_SAYISI; i++) {

        printf("Ay %2d | ", i + 1);    // Ay numarasini belirtir.

        for (j = 0; j < ciro[i]; j++) {
            printf("*");               // Ciro degeri kadar yıldız koyulur.
        }

        printf(" (%dK)\n", ciro[i]);   
    }

    
    printf("\n==================================\n");
    printf("\nDIKEY BAR GRAFIK;\n\n");
    printf("\n==================================\n\n");

    for (i = maxCiro; i >= 1; i--) {

        for (j = 0; j < AY_SAYISI; j++) {

            if (ciro[j] >= i)
                printf(" * ");
            else
                printf("   ");
        }
        printf("\n");
    }

    // Grafik altindaki çizgiyi çizer.
    for (i = 0; i < AY_SAYISI; i++) {
        printf("---");
    }
    printf("\n");

    //Ay numaralarını alt satıra ekler.
    for (i = 0; i < AY_SAYISI; i++) {
        printf("%2d ", i + 1);
    }
    printf("\n");

    return 0;
}
