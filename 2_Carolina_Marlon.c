//Código criado por Marlon Philipe Tereziano de Oliveira e Carolina Casemiro Batiston
//Engenharia de Computação - IFSULDEMINAS - Campus Poços de Caldas - MG
//Agosto de 2019

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int geraAleatorio(int max){

    int aux;

    aux = rand() % max;

    return aux;
}


void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
  
    for (i = 0; i < n-1; i++) 
    { 
        
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
       
        swap(&arr[min_idx], &arr[i]); 
    } 
} 
  
void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
  
      
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
      
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
   
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
       
        int m = l+(r-l)/2; 
  
       
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

void swap2(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];   
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
        
        if (arr[j] <= pivot) 
        { 
            i++;    
            swap2(&arr[i], &arr[j]); 
        } 
    } 
    swap2(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
   
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 


int main(){

    //t=Selectionsort , t2= insertionSort , t3=bubbleSort , t4= MergeSort , t5= Quicksort 

    
    double t=0,t2=0,t3=0,t4=0,t5=0;
    int *VetorSelection, *VetorInsertion, *VetorBubble, *VetorMerge, *VetorQuick;
    int i, aux,j;
    int *chavehash = malloc(50000000*sizeof(int));

    
    for (i = 50000; i <= 1000000; i +=50000)
    {

        for (j = 0; j < 50000000; j++) //i vai até o numero max
        {
        chavehash[j] = 0;
        }
        //printf("hash OK\n");

        VetorSelection = (int*) malloc(i*sizeof(int));
        VetorInsertion = (int*) malloc(i*sizeof(int));
        VetorBubble = (int*) malloc(i*sizeof(int));
        VetorMerge = (int*) malloc(i*sizeof(int));
        VetorQuick = (int*) malloc(i*sizeof(int));

        //printf("alocacao OK\n");

        for (j = 0; j < i; j++)
        {
            do // sorteia chaves que nao existem
            {
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

        //printf("aleatorio OK\n");



       
            
            t=clock();

            selectionSort(VetorSelection,j);

            t=clock() - t;

            t=t/CLOCKS_PER_SEC;

            //printf("selection OK\n");

        
            
            t2=clock();

            insertionSort(VetorInsertion,j);

            t2=clock() - t2;

            t2=t2/CLOCKS_PER_SEC;

            //printf("insertion OK\n");

         

        
            
            t3=clock();

            bubbleSort(VetorBubble,j);

            t3=clock() - t3;

            t3=t3/CLOCKS_PER_SEC;

        

       
            
            t4=clock();

            mergeSort(VetorMerge,0,j);

            t4=clock() - t4;

            t4=t4/CLOCKS_PER_SEC;

       

       
            
            t5=clock();

            quickSort(VetorQuick,0,j);

            t5=clock() - t5;

            t5=t5/CLOCKS_PER_SEC;

    

    

       

        printf("%d,%lf,%lf,%lf,%lf,%lf\n", i, t,t2,t3,t4,t5);

    }
    


    
    free(VetorSelection);
    free(VetorInsertion);
    free(VetorBubble);
    free(VetorMerge);
    free(VetorQuick);
    free(chavehash);

    return 0;
}

