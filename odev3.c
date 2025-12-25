#include <stdio.h>

/*
    Bu fonksiyon, verilen harfin ünlü olup olmadığını kontrol eder.
    Ünlü harfler: a, e, i, o, u
    Eğer ünlüyse 1, değilse 0 döndürür.
*/
int unluMu(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return 1;
    else
        return 0;
}

/*
    Bu fonksiyon, verilen sayının asal sayı olup olmadığını kontrol eder.
    Asal sayı: 1 ve kendisi dışında böleni olmayan sayılara asal sayı denir.
    Asal ise 1, değilse 0 döndürür.
*/
int asalMi(int sayi) {
    int i;

    /* 2'den küçük sayılar asal sayı değildir */
    if (sayi < 2)
        return 0;

    /* Sayının böleni var mı diye kontrol edilir */
    for (i = 2; i <= sayi / 2; i++) {
        if (sayi % i == 0)
            return 0;   /* Bölünüyorsa asal sayı değildir */
    }

    return 1;  /* Hiç bölünmediyse asal sayıdır */
}

int main() {

    /* Üç harfli ismin harfleri */
    char harf1, harf2, harf3;

    /* ASCII değerlerinin toplamı */
    int toplam;

    /* Geçerli isim sayısını tutar */
    int sayac = 0;

    /*
        harf1: 1. harf
        harf2: 2. harf
        harf3: 3. harf (harf1 ile aynı olacak)
    */
    for (harf1 = 'a'; harf1 <= 'z'; harf1++) {

        for (harf2 = 'a'; harf2 <= 'z'; harf2++) {

            /*
                aba veya bab kontrolü:
                harf1 ünlü ise harf2 ünsüz olmalı
                harf1 ünsüz ise harf2 ünlü olmalı
            */
            if (unluMu(harf1) != unluMu(harf2)) {

                /* 1. ve 3. harf aynı olmalı */
                harf3 = harf1;

                /* ASCII değerleri toplanır */
                toplam = harf1 + harf2 + harf3;

                /* ASCII toplamı asal mı? */
                if (asalMi(toplam)) {

                    /* Geçerli isim ekrana yazdırılır */
                    printf("%c%c%c\n", harf1, harf2, harf3);

                    /* Geçerli isim sayısı artırılır */
                    sayac++;
                }
            }
        }
    }

    /* Toplam geçerli isim sayısını ekrana yazdırır. */
    printf("\nToplam gecerli isim sayisi: %d\n", sayac);
    return 0;
}
