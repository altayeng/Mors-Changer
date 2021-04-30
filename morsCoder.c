#include <stdio.h>
#include <time.h>

void dosya_olustur(){
    int sayi, i;

    FILE *dosya;
    dosya = fopen("hatalar.dat", "w");

    srand(time(NULL));

    for(i=0; i<5; i++)
	{
		//999'a kadar random sayý oluþturacak
        sayi = rand()+1;
        //dosya içine yazýyor, for döngüsü bitene kadar yapýyor bunu.
        fprintf(dosya, "%d\n", sayi);
    }

    fclose(dosya);
}

void sayidanMorsaCevir(char **str, int sayi){
    switch(sayi)
    {
        case 0:
            *str = "-----";
            break;
        case 1:
            *str = ".----";
            break;
        case 2:
            *str = "..---";
            break;
        case 3:
            *str = "...--";
            break;
        case 4:
            *str = "....-";
            break;
        case 5:
            *str = ".....";
            break;
        case 6:
            *str = "-....";
            break;
        case 7:
            *str = "--...";
            break;
        case 8:
            *str = "---..";
            break;
        case 9:
            *str = "----.";
            break;
    }
}

int main(){
	char *suanki_mors = "aaaa";
	
	
    FILE *yenidosya;
    yenidosya = fopen("mors.txt", "w");

	
	int suanki_sayi;
	int loop=0, index;
	int temp;
	dosya_olustur();
	FILE *dosya = fopen("hatalar.dat", "r");
	fscanf(dosya, "%d", &suanki_sayi);

	while(!feof(dosya)){

		for (temp = 1; temp <= suanki_sayi; temp *= 10) ++loop;
		printf("\n");
		for(index=0; index<loop; ++index){
			temp /= 10;
			sayidanMorsaCevir(&suanki_mors, suanki_sayi/temp);
			
			printf("%s \t", suanki_mors);
			
			fprintf(yenidosya, "%s \t", suanki_mors);
			suanki_sayi %= temp;

		}
		loop=0;
		fprintf(yenidosya, "\n");

		fscanf(dosya, "%d", &suanki_sayi);
	}
	fclose(dosya);
	return 0;
}
