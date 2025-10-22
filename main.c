#include <stdio.h> // Standart giri�/��k�� fonksiyonlar� i�in gerekli k�t�phane (printf, scanf)

// Fonksiyon prototipleri: Program�n ilerleyen k�s�mlar�nda tan�mlanacak olan 
// fonksiyonlar� derleyiciye �nceden bildiriyoruz.
void tanitimYap();
void sonuclariYorumla(float sharpeOrani);

int main() {
    // --- De�i�ken Tan�mlamalar� ---
    // float: Ondal�kl� say�lar� tutabilen bir veri tipidir. Finansal hesaplamalar i�in idealdir.
    float yatirimGetirisi, risksizFaizOrani, standartSapma;
    float sharpeOrani;

    // Fonksiyonu �a��rarak program�n amac�n� ekrana yazd�r�yoruz.
    tanitimYap();

    // --- Kullan�c�dan Veri Alma ---
    // Kullan�c�ya ne girmesi gerekti�ini bildiren bir mesaj g�steriyoruz.
    printf("Lutfen yatirimin getirisini yuzde olarak giriniz (ornegin, 15): ");
    // scanf fonksiyonu ile kullan�c�dan ondal�kl� bir say� (%f) al�p 
    // yatirimGetirisi de�i�keninin bellek adresine (&) kaydediyoruz.
    scanf("%f", &yatirimGetirisi);

    printf("Lutfen risksiz faiz oranini yuzde olarak giriniz (ornegin, 5): ");
    scanf("%f", &risksizFaizOrani);

    printf("Lutfen portfoyun standart sapmasini yuzde olarak giriniz (ornegin, 12): ");
    scanf("%f", &standartSapma);
    
    // Girilen y�zdesel de�erleri ondal�kl� say�ya �eviriyoruz (15 -> 0.15).
    // ��nk� matematiksel form�lde ger�ek de�erler kullan�l�r.
    yatirimGetirisi = yatirimGetirisi / 100.0;
    risksizFaizOrani = risksizFaizOrani / 100.0;
    standartSapma = standartSapma / 100.0;
    
    // --- Hesaplama ve Kontrol ---
    // Standart sapma, yani payda s�f�r olamaz. Matematikte bir say�y� s�f�ra b�lmek tan�ms�zd�r.
    // Bu durum program�n ��kmesine neden olur. Bu y�zden bir kontrol yap�yoruz.
    if (standartSapma == 0) {
        printf("\nHATA: Standart sapma (risk) sifir olamaz. Hesaplama yapilamiyor.\n");
        return 1; // Program� bir hata koduyla (genellikle 0'dan farkl�) sonland�r.
    }

    // Sharpe Oran� form�l�n� uyguluyoruz.
    sharpeOrani = (yatirimGetirisi - risksizFaizOrani) / standartSapma;

    // --- Sonu�lar� Ekrana Yazd�rma ---
    printf("\n--- HESAPLAMA SONUCLARI ---\n");
    // %.2f format�, ondal�kl� say�y� virg�lden sonra sadece 2 basamak g�sterecek �ekilde formatlar.
    printf("Hesaplanan Sharpe Orani Degeri: %.2f\n", sharpeOrani);
    
    // Hesaplanan orana g�re yorum yapmak i�in fonksiyonumuzu �a��r�yoruz.
    sonuclariYorumla(sharpeOrani);
    
    return 0; // Program�n ba�ar�yla tamamland���n� i�letim sistemine bildirir.
}

/**
 * @brief Program�n amac�n� ve ne yapt���n� a��klayan bir kar��lama mesaj� yazd�r�r.
 */
void tanitimYap() {
    printf("-----------------------------------------------------------------\n");
    printf("Finansal Portfoy Performansi Degerlendirme: Sharpe Orani Hesaplayici\n");
    printf("-----------------------------------------------------------------\n");
    printf("Bu program, girdiginiz degerlere gore bir yatirimin risk-getiri\n");
    printf("performansini olcen Sharpe oranini hesaplar ve yorumlar.\n\n");
}

/**
 * @brief Verilen Sharpe Oran� de�erine g�re standart bir finansal yorum yazd�r�r.
 * @param sharpeOrani Hesaplanan Sharpe Oran� de�eri.
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
