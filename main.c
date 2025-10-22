#include <stdio.h> // Standart giriþ/çýkýþ fonksiyonlarý için gerekli kütüphane (printf, scanf)

// Fonksiyon prototipleri: Programýn ilerleyen kýsýmlarýnda tanýmlanacak olan 
// fonksiyonlarý derleyiciye önceden bildiriyoruz.
void tanitimYap();
void sonuclariYorumla(float sharpeOrani);

int main() {
    // --- Deðiþken Tanýmlamalarý ---
    // float: Ondalýklý sayýlarý tutabilen bir veri tipidir. Finansal hesaplamalar için idealdir.
    float yatirimGetirisi, risksizFaizOrani, standartSapma;
    float sharpeOrani;

    // Fonksiyonu çaðýrarak programýn amacýný ekrana yazdýrýyoruz.
    tanitimYap();

    // --- Kullanýcýdan Veri Alma ---
    // Kullanýcýya ne girmesi gerektiðini bildiren bir mesaj gösteriyoruz.
    printf("Lutfen yatirimin getirisini yuzde olarak giriniz (ornegin, 15): ");
    // scanf fonksiyonu ile kullanýcýdan ondalýklý bir sayý (%f) alýp 
    // yatirimGetirisi deðiþkeninin bellek adresine (&) kaydediyoruz.
    scanf("%f", &yatirimGetirisi);

    printf("Lutfen risksiz faiz oranini yuzde olarak giriniz (ornegin, 5): ");
    scanf("%f", &risksizFaizOrani);

    printf("Lutfen portfoyun standart sapmasini yuzde olarak giriniz (ornegin, 12): ");
    scanf("%f", &standartSapma);
    
    // Girilen yüzdesel deðerleri ondalýklý sayýya çeviriyoruz (15 -> 0.15).
    // Çünkü matematiksel formülde gerçek deðerler kullanýlýr.
    yatirimGetirisi = yatirimGetirisi / 100.0;
    risksizFaizOrani = risksizFaizOrani / 100.0;
    standartSapma = standartSapma / 100.0;
    
    // --- Hesaplama ve Kontrol ---
    // Standart sapma, yani payda sýfýr olamaz. Matematikte bir sayýyý sýfýra bölmek tanýmsýzdýr.
    // Bu durum programýn çökmesine neden olur. Bu yüzden bir kontrol yapýyoruz.
    if (standartSapma == 0) {
        printf("\nHATA: Standart sapma (risk) sifir olamaz. Hesaplama yapilamiyor.\n");
        return 1; // Programý bir hata koduyla (genellikle 0'dan farklý) sonlandýr.
    }

    // Sharpe Oraný formülünü uyguluyoruz.
    sharpeOrani = (yatirimGetirisi - risksizFaizOrani) / standartSapma;

    // --- Sonuçlarý Ekrana Yazdýrma ---
    printf("\n--- HESAPLAMA SONUCLARI ---\n");
    // %.2f formatý, ondalýklý sayýyý virgülden sonra sadece 2 basamak gösterecek þekilde formatlar.
    printf("Hesaplanan Sharpe Orani Degeri: %.2f\n", sharpeOrani);
    
    // Hesaplanan orana göre yorum yapmak için fonksiyonumuzu çaðýrýyoruz.
    sonuclariYorumla(sharpeOrani);
    
    return 0; // Programýn baþarýyla tamamlandýðýný iþletim sistemine bildirir.
}

/**
 * @brief Programýn amacýný ve ne yaptýðýný açýklayan bir karþýlama mesajý yazdýrýr.
 */
void tanitimYap() {
    printf("-----------------------------------------------------------------\n");
    printf("Finansal Portfoy Performansi Degerlendirme: Sharpe Orani Hesaplayici\n");
    printf("-----------------------------------------------------------------\n");
    printf("Bu program, girdiginiz degerlere gore bir yatirimin risk-getiri\n");
    printf("performansini olcen Sharpe oranini hesaplar ve yorumlar.\n\n");
}

/**
 * @brief Verilen Sharpe Oraný deðerine göre standart bir finansal yorum yazdýrýr.
 * @param sharpeOrani Hesaplanan Sharpe Oraný deðeri.
 */
void sonuclariYorumla(float sharpeOrani) {
    printf("Genel Yorum: ");
    if (sharpeOrani < 0) {
        printf("Negatif. Portfoyun getirisi, risksiz faiz oraninin altinda kalmistir.\n");
    } else if (sharpeOrani >= 0 && sharpeOrani < 1) {
        printf("1'den kucuk. Alinan risk karsiliginda elde edilen ek getiri yetersizdir.\n");
    } else if (sharpeOrani >= 1 && sharpeOrani < 2) {
        printf("1 ile 2 arasinda. Iyi. Alinan riske degen, kabul edilebilir bir performans.\n");
    } else if (sharpeOrani >= 2 && sharpeOrani < 3) {
        printf("2 ile 3 arasinda. Cok Iyi. Uzerinde calisilmis, ustun bir risk-getiri performansi.\n");
    } else { // sharpeOrani >= 3
        printf("3'ten buyuk. Mukemmel. Olaganustu ve nadir gorulen bir basari.\n");
    }
    printf("-----------------------------------------------------------------\n");
}
