#include <stdio.h>
/* 
   Üçgen sayı hesaplayan recursive (özyinelemeli) fonksiyon
   Üçgen sayı formülü: 1 + 2 + 3 + ... + n
*/
int ucgenSayi(int n) {
    if (n <= 0)
        return 0;
    return n + ucgenSayi(n - 1);
}

int main() {
    int N, n;       // Kullanıcıdan alınacak değerler
    int sayi = 1;   // Üçgen çiziminde kullanılacak artan sayı 

    printf("N degerini giriniz (ucgen sayilar): "); 
    scanf("%d", &N);

    printf("Ilk %d ucgen sayi:\n", N);
    for (int i = 1; i <= N; i++) {
        printf("%d ", ucgenSayi(i));   // özyinelemeli fonksiyon dongude
    }

    printf("\n\n");


     // Üçgen yüksekliği için n değerini al
    printf("Ucgen icin n degerini giriniz: ");
    scanf("%d", &n);

    // Geçersiz (pozitif olmayan) değer kontrolü
    if (n <= 0) {
        printf("Lutfen pozitif bir n giriniz.\n");
        return 1;
    }

    printf("\nEskenar ucgen:\n\n");

    /* Eskenar ucgen (dongulerle) */
    for (int i = 1; i <= n; i++) {

        /* Bosluklar (ortalamak icin) */
        for (int s = 0; s < n - i; s++) {
            printf("  ");
        }

        /* Sayilar */
        for (int j = 1; j <= i; j++) {
            printf("%2d ", sayi);
            sayi++;
        }

        printf("\n");
    }

    return 0;
}
