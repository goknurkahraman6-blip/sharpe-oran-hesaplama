#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int ogrenciYasi =0;// Ogrencinin yasi için tanimlandi
	
	printf("Lutfen Yasinizi Giriniz : \n");
	scanf("%d", &ogrenciYasi);
	
	printf("Girdiðiniz Yas :%d\n", ogrenciYasi);
	
	printf("int : %1d byte, %d ile %d arasi\n" , sizeof(int), INT_MIN,INT_MAX);
	
	char karakter= 'A';
	long buyuk_tamsayi= 123456789L;
	float ondalikli = 3.14159f;
	return 0;
}
