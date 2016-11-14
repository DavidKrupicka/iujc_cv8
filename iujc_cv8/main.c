#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <crtdbg.h>

typedef struct osoba{
	char jmeno[30];
	int vek;
	struct osoba *dalsi;
}tOsoba;

tOsoba * alokuj(){
	tOsoba *os;
	os = malloc(sizeof(tOsoba));
	strcpy(os->jmeno, "");
	os->vek = -1;
	os->dalsi = NULL;
}

void nacti(tOsoba *os, char *jm, int vek){
	strcpy(os->jmeno, jm);
	os->vek = vek;
}

void vypisVse(tOsoba * os){
	while ((os != NULL)){
		printf("jm:%s vek%d", os->jmeno, os->vek);
		os = os->dalsi;
	}
}

void dealokuj(tOsoba*t1){
	tOsoba *t2 = t1->dalsi;
	while (t2 != NULL){
		free(t1);
		t1 = t2;
		t2 = t1->dalsi;
	}
	free(t1);
}

int main(int argc, char *argv[]){
	tOsoba *os, *prvni = NULL, *akt; //akt = aktualni
	int pocet = 4, vek;
	char jm[10];
	
	for (size_t i = 0; i < pocet; i++)
	{
		os = alokuj();
		printf("zadej jm");
		scanf("%s", jm); //jm je ukazatel(pole), nepisu &

		printf("zadej vek");
		scanf("%d", &vek); //pisu &, je to jednoducha prom.

		nacti(os, jm, vek);

		if (prvni == NULL){
			prvni = os;
		}
		else
			akt->dalsi = os;
		akt = os;
	}

	vypisVse(prvni);
	dealokuj(prvni);
	//vypisVse(prvni);

	_CrtDumpMemoryLeaks();

	system("pause");

	return 0;
}
