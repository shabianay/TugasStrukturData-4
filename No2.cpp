#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
#include<cstdlib>


struct data{
	char nrp [15];
	char nama [20];
	char alamat [20];
	float indeks;
	struct data *next;
}d;

struct data *ujung;

int awal (){
	struct data *tampung, *awal;
	int j=0; char jawab[2];
	while (1) {
		awal=(struct data*)malloc(sizeof(struct data));
		awal->next=NULL;
		fflush(stdin);
		printf("Masukan NRP	: ");gets (awal->nrp);
		printf("Masukan Nama	: ");gets (awal->nama);
		printf("Masukan Alamat	: ");gets (awal->alamat);
		printf("Masukan IP	: ");scanf("%f",&awal->indeks);
		if(j==0){
			ujung=awal;
			tampung=awal;
		} else {
			tampung->next=awal;
			tampung=awal;
		}
		fflush (stdin);
		printf("Ada Data Lagi (y/t): ");scanf("%s",&jawab);
		if((strcmp(jawab,"Y")==0)||(strcmp(jawab,"y")==0)) {
			j++;continue;
		} else if ((strcmp(jawab,"T")==0)||(strcmp(jawab,"t")==0))
			break;
	}
}

int tampil_list(){
	struct data *tampil;
	tampil=ujung;
	system("cls");
	printf("====================================\n");
	puts("NRP\tNAMA\tALAMAT\t\tIP");
	while(tampil!=NULL) {
		printf ("%s\t%s\t%s\t\t%.2f\n",tampil->nrp,tampil->nama,
		tampil->alamat,tampil->indeks);
		tampil=tampil->next;
	}
}

int main (){
	awal();
	tampil_list();
	getch();
	return 0;
}
