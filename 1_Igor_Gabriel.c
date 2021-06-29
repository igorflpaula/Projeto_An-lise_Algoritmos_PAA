#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>

// Igor Francisco e Gabriel Paes

struct time{
	int size;
	double seconds;
};

int pesquisaBinaria (int *vet, int key, int Tam){

     int inf = 0;
     int sup = Tam-1;
     int mid;

     while (inf <= sup){
          mid=(inf+sup)/2;
          if(key==vet[mid])
               return mid;
          if(key<vet[mid])
               sup=mid-1;
          else
               inf=mid+1;
     }
     return -1;
}

int pesquisaSequencial(int *vet, int n, int sizeMax){

     int i;

     for(i=0;i<sizeMax;i++){
          if(vet[i]==n){
              return i;
          }
     }
     return -1;
}

bool existe(int *v, int size, int value){

	int i;

	for(i=0;i<size;i++){
		if(v[i]==value){
			return true;
		}
		return false;
	}
}

void geraRand(int *v, int size, int limit){

	srand(time (NULL));
	int i, aux;

	for(i=0; i<size;i++){
		aux=rand() % limit;
		while(existe(v,i,aux)){
			aux=rand() %limit;
		}
		v[i]=aux;
	}
}


void selectSort(int *item,int count){

    int i, prefeito, j, sizeMin, pos;

    for(i=0;i<count-1;i++){
        prefeito=item[i];
        sizeMin=item[i+1];
        pos=i+1;

        for(j=i+1;j<count;j++){
            if(item[j]<sizeMin){
                sizeMin=item[j];
                pos=j;
            }
        }
        if(sizeMin<prefeito){
            item[i]=item[pos];
            item[pos]=prefeito;
        }
    }
}

int main(){

	struct timeval start, stop;
	int i,j,k,size=1000000,aux, result, Nexiste,Nnaoexiste;
	double secB,secS,mediaBin=0, mediaSequen=0;
	struct time binario[5]; 
    struct time sequencial[5];
    int *vBinario, *vSequencial;

    FILE *fp;
    	fp=fopen("trabalho.txt","w+");

    for(i=0;i<5;i++){
    	aux=50000*(i+1);
    	mediaBin=0;
    	mediaSequen=0;
    	vBinario=malloc(aux*sizeof(int));
    	vSequencial=malloc(aux*sizeof(int));
    	geraRand(vBinario,aux,size);
    	geraRand(vSequencial,aux,size);
    	selectSort(vBinario,aux);

        for(k=0;k<50;k++){
        	Nexiste=vSequencial[rand() % aux];
        	gettimeofday(&start, NULL);
	        result=pesquisaSequencial(vSequencial, Nexiste, aux);
	        gettimeofday(&stop, NULL);
	        secS=(double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
	        mediaSequen=mediaSequen+secS;
	        
	        Nexiste=vBinario[rand() % aux];
        	gettimeofday(&start, NULL);
	        result=pesquisaBinaria (vBinario, Nexiste, aux);
	        gettimeofday(&stop, NULL);
	        secS=(double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
	        mediaBin=mediaBin+secB;
		}

		for (k=0;k<50;k++){
        	Nnaoexiste=(size+1);
        	gettimeofday(&start, NULL);
	        result=pesquisaSequencial(vSequencial, Nnaoexiste, aux);
	        gettimeofday(&stop, NULL);
	        secS=(double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
	        mediaSequen=mediaSequen+secS;
	        
	        Nexiste = (size+1);
        	gettimeofday(&start, NULL);
	        result=pesquisaBinaria (vBinario, Nnaoexiste, aux);
	        gettimeofday(&stop, NULL);
	        secS = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
	        mediaBin=mediaBin+secB;
		}

		sequencial[i].size = aux;
        sequencial[i].seconds = mediaSequen/100;
        binario[i].size = aux;
        binario[i].seconds = mediaBin/100;
		free(vBinario);
        free(vSequencial);
	}

	for(i=0;i<5;i++){
        aux = 50000*(i+1);
        printf("TAMANHO %d\n",aux);
        fprintf(fp,"TAMANHO %d\n",aux);
        printf("B = %.30lf\n",binario[i].seconds);
        fprintf(fp,"B = %.30lf\n",binario[i].seconds);
        printf("S = %.30lf\n",sequencial[i].seconds);
        fprintf(fp,"S = %.30lf\n",sequencial[i].seconds);
    }

    fclose(fp);
	
	return 0;
}