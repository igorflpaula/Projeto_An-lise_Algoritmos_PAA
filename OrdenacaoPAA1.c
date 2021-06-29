#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

// Igor Francisco e Gabriel Paes

struct time{
    int size;
    double seconds;
};

void bubbleSort(int *item, int numElemento){

    int n, i,aux;
    for(n=1; n<=numElemento; n++){
        for(i=0;i<numElemento-1;i++){
            if(item[i]>item[i+1]){
                aux = item[i];
                item[i] = item[i+1];
                item[i+1] = aux;
            }
        }
    }
}

void insertSort(int *item, int count){

    int i, j, prefeito;

    for(i=1; i<=count-1; i++){
        prefeito=item[i];
        j=i-1;

        while(j>=0&&item[j]>prefeito){
            item[j+1] = item[j];
            j=j-1;
        }
        item[j+1]=prefeito;
    }
}

void selectSort(int *item,int count){

    int i, prefeito, j, min, pos;

    for(i=0; i<count-1; i++){
        prefeito=item[i];
        min=item[i+1];
        pos=i+1;

        for(j=i+1;j<count;j++){
            if(item[j]<min){
                min=item[j];
                pos=j;
            }
        }

        if(min<prefeito){
            item[i]=item[pos];
            item[pos]=prefeito;
        }
    }
}

void merge(int *A,int *L,int leftCount,int *R,int rightCount){

	int i,j,k;
	
	i=0; j=0; k=0;

	while(i<leftCount && j< rightCount){
		if(L[i]<R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

void mergeSort(int *A,int n){

	int mid, i, *L, *R;
	if(n<2) return; 

	mid = n/2; 

	L = (int*)malloc(mid*sizeof(int));
	R = (int*)malloc((n- mid)*sizeof(int));

	for(i = 0;i<mid;i++) L[i] = A[i];
	for(i = mid;i<n;i++) R[i-mid] = A[i];

	mergeSort(L,mid); 
	mergeSort(R,n-mid); 
	merge(A,L,mid,R,n-mid); 
        free(L);
        free(R);
}

void quickSort(int *a, int left, int right){

    int i, j, x, y;
     
    i=left;
    j=right;
    x=a[(left + right)/2];
     
    while(i<=j){
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i<=j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j>left){
        quickSort(a, left, j);
    }

    if(i<right){
        quickSort(a, i, right);
    }
}

int main(){

    struct timeval start, stop;
    int aux;
    int i, j, k; 

    struct time merge[20];
    struct time quick[20];
    struct time insert[20];
    struct time select[20];
    struct time bubble[20];     

    int *vMerge;
    int *vQuick;
    int *vInsert;
    int *vSelect;
    int *vBubble;
    
    FILE *fp;
    	fp=fopen("ordenacao.txt","w+");
 
    for(i=0;i<20;i++){
        aux = 50000*(i+1);
        
        vBubble = malloc(aux*sizeof(int));  //bubble 
        vInsert = malloc(aux*sizeof(int)); //insert     
        vSelect = malloc(aux*sizeof(int)); //selection     
        vMerge = malloc(aux*sizeof(int)); //merge
        vQuick = malloc(aux*sizeof(int)); //quick
        
        for(j=(aux-1);j>=0;j--){
            vBubble[j] = j;
            vInsert[j] = vBubble[j];
            vSelect[j] = vBubble[j];
            vMerge[j] = vBubble[j];
            vQuick[j] = vBubble[j];
        }

	        gettimeofday(&start, NULL);
	        
	        bubbleSort(vBubble,aux);
	
	        gettimeofday(&stop, NULL);

	        bubble[i].size = aux;
	        bubble[i].seconds = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);

	        gettimeofday(&start, NULL);
	        
	        insertSort(vInsert,aux);
	
	        gettimeofday(&stop, NULL);
	
	        insert[i].size = aux;
	        insert[i].seconds = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);

	        gettimeofday(&start, NULL);
	        
	        selectSort(vSelect,aux);
	
	        gettimeofday(&stop, NULL);
	
	        select[i].size = aux;
	        select[i].seconds = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
	
	        gettimeofday(&start, NULL);
	        
	        mergeSort(vMerge,aux);
	
	        gettimeofday(&stop, NULL);
	
	        merge[i].size = aux;
	        merge[i].seconds = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
	
	        gettimeofday(&start, NULL);
	        
	        quickSort(vQuick, 0 ,(aux-1));
	
	        gettimeofday(&stop, NULL);
	
	        quick[i].size = aux;
	        quick[i].seconds = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
	
	        free(vBubble);
	        free(vInsert);
	        free(vSelect);
	        free(vMerge);
	        free(vQuick);
	    
    }

    for(i=0;i<20;i++){
        aux = 50000*(i+1);
        printf("size %d\n",aux);
        fprintf(fp,"size %d\n",aux);
        printf("bubble = %.20lf\n",bubble[i].seconds);
        fprintf(fp,"bubble = %.20lf\n",bubble[i].seconds);
        printf("insert = %.20lf\n",insert[i].seconds);
        fprintf(fp,"insert = %.20lf\n",insert[i].seconds);
        printf("select = %.20lf\n",select[i].seconds);
        fprintf(fp,"select = %.20lf\n",select[i].seconds);
        printf("merge = %.20lf\n",merge[i].seconds);
        fprintf(fp,"merge = %.20lf\n",merge[i].seconds);
        printf("quick = %.20lf\n\n",quick[i].seconds);
        fprintf(fp,"quick = %.20lf\n\n",quick[i].seconds);
    }

    fclose(fp);
    return 0;
}
