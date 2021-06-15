#include <stdio.h>
#include <stdlib.h>

int opcount=0;

void mergeSort(int arr[], int, int);
void merge(int arr[], int, int, int);

int main(){
    int arr[100],size, i, j, lb, ub, mid;

    printf("Enter the size of the array:  ");
    scanf("%d", &size);

    printf("Enter the elements of the array:  ");
    for(i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }


    lb = 0;
    ub = size-1;

    mergeSort(arr, lb, ub);

    printf("The sorted array is:\n");
    for(i=0; i<size; i++){
       printf("%d\t", arr[i]);
    }

    printf("\nOpcount: %d\t\n", opcount);
}

void mergeSort(int arr[], int lb, int ub){
    int mid;
    if(lb<ub){
        mid = (lb + ub)/2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid+1, ub);
        merge(arr, lb, mid, ub);
    }

}

void merge(int arr[], int lb, int mid, int ub){
    int b[100];
    int i = lb;
    int j = mid+1;
    int k = lb;

    while(i<=mid && j<=ub){
        opcount++;
        if(arr[i]<=arr[j]){
            b[k] = arr[i];
            i++;
        }else{
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        opcount++;
        while(j<=ub){
            b[k] = arr[j];
            j++;
            k++;
        }
    }else{
        while(i<=mid){
            opcount++;
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    for(k=lb; k<=ub; k++){
        arr[k] = b[k];
    }
}