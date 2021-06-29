#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Igor Francisco e Gabriel Paes

int geraAleatorio(int max){

    int aux;
    aux = rand() % max;
    return aux;
}

void swap(int *xp, int *yp){ 

    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n){ 

    int i, j, min_idx; 
  
    for(i=0; i<n-1; i++){ 
        min_idx = i; 
        for(j=i+1; j<n; j++) 
          if(arr[j]<arr[min_idx]) 
            min_idx=j;   
       
        swap(&arr[min_idx], &arr[i]); 
    } 
} 
  
void insertionSort(int arr[], int n){ 
    int i, key, j; 
    for (i=1; i<n; i++){ 
        key=arr[i]; 
        j=i-1;  
      
        while (j>=0 && arr[j]>key){ 
            arr[j+1]=arr[j]; 
            j=j-1; 
        } 
        arr[j+1] = key; 
    } 
} 

void bubbleSort(int arr[], int n){ 
   int i, j; 
   for(i=0; i<n-1; i++)
       for(j=0; j<n-i-1; j++)  
           if(arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
}

void merge(int arr[], int l, int m, int r) { 
    int i, j, k; 
    int n1=m-l+1; 
    int n2=r-m; 
  
    int L[n1], R[n2]; 
  
    for(i=0; i<n1; i++) 
        L[i]=arr[l+i]; 
    for(j=0; j<n2; j++) 
        R[j]=arr[m+1+j]; 
  
    i=0; 
    j=0; 
    k=l; 

    while(i<n1 && j<n2){ 
        if(L[i]<=R[j]){ 
            arr[k]=L[i]; 
            i++; 
        } 
        else{ 
            arr[k]=R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while(i<n1){ 
        arr[k]=L[i]; 
        i++; 
        k++; 
    } 

    while(j<n2){ 
        arr[k]=R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(int arr[], int l, int r){ 
    if(l<r){ 
       
        int m=l+(r-l)/2;  
       
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

void swap2(int* a, int* b){ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high){ 
    int pivot = arr[high];   
    int i = (low-1);  
  
    for(int j = low; j <= high-1; j++){ 
        
        if(arr[j]<=pivot){ 
            i++;    
            swap2(&arr[i], &arr[j]); 
        } 
    } 
    swap2(&arr[i + 1], &arr[high]); 
    return (i+1); 
} 
  

void quickSort(int arr[], int low, int high){ 
    if (low<high){ 
   
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi-1); 
        quickSort(arr, pi + 1, high); 
    } 
} 


int main(){

    //Alg -> Algoritmo
    //Alg1=Selectionsort , Alg2= insertionSort , Alg3=bubbleSort , Alg4= MergeSort , Alg5= Quicksort 

    double Alg1=0, Alg2=0, Alg3=0, Alg4=0, Alg5=0;
    int *VetorSelection, *VetorInsertion, *VetorBubble, *VetorMerge, *VetorQuick;
    int i, aux,j;
    int *chavehash = malloc(50000000*sizeof(int));

    
    for(i=50000; i<=1000000; i+=50000){

        for(j=0; j<50000000; j++){ //i vai até o numero max
        chavehash[j] = 0;
        }

        VetorSelection = (int*) malloc(i*sizeof(int));
        VetorInsertion = (int*) malloc(i*sizeof(int));
        VetorBubble = (int*) malloc(i*sizeof(int));
        VetorMerge = (int*) malloc(i*sizeof(int));
        VetorQuick = (int*) malloc(i*sizeof(int));

        for(j=0; j<i; j++){
            do{ // sorteia chaves que nao existem
            aux = geraAleatorio(49999999);
            } while (chavehash[aux] == 1 );

            VetorSelection[j] = aux;
            VetorInsertion[j] = aux;
            VetorBubble[j] = aux;
            VetorMerge[j] = aux;
            VetorQuick[j] = aux;

            //já que usou o número, muda a posição da hash para 1
            chavehash[aux] = 1;
        
        }     
            
            Alg1=clock();

            selectionSort(VetorSelection,j);

            Alg1=clock() - Alg1;

            Alg1=Alg1/CLOCKS_PER_SEC;        
            
            Alg2=clock();

            insertionSort(VetorInsertion,j);

            Alg2=clock() - Alg2;

            Alg2=Alg2/CLOCKS_PER_SEC;  

            Alg3=clock();

            bubbleSort(VetorBubble,j);

            Alg3=clock() - Alg3;

            Alg3=Alg3/CLOCKS_PER_SEC;

            Alg4=clock();

            mergeSort(VetorMerge,0,j);

            Alg4=clock() - Alg4;

            Alg4=Alg4/CLOCKS_PER_SEC;

            Alg5=clock();

            quickSort(VetorQuick,0,j);

            Alg5=clock() - Alg5;

            Alg5=Alg5/CLOCKS_PER_SEC;

        printf("%d,%lf,%lf,%lf,%lf,%lf\n", i, Alg1, Alg2, Alg3, Alg4, Alg5);

    }
    
    free(VetorSelection);
    free(VetorInsertion);
    free(VetorBubble);
    free(VetorMerge);
    free(VetorQuick);
    free(chavehash);

    return 0;
}