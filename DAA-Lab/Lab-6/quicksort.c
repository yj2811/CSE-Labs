#include <stdio.h>
#include <stdlib.h>

int opcount=0;

void QuickSort(int arr[], int l, int h);
int Partition(int arr[], int a, int b);
void Swap(int *c, int *d);

void QuickSort(int arr[], int l, int h) {
    int j;

    if(l < h) {
        j = Partition(arr, l, h);
        QuickSort(arr, l, j);
        QuickSort(arr, j+1, h);
    }
}

int Partition(int arr[], int a, int b){
    int i, j;
    int pivot = arr[a];

    i = a;
    j = b;
    while(i<j){
        opcount++;
        do{
            i++;
            opcount++;
        }while(arr[i] <= pivot);

        do{
            j--;
            opcount++;
        }while(arr[j] > pivot);

        if(i<j){
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[a], &arr[j]);
    return j;
}

void Swap(int *c, int *d){

    int temp = *c;
    *c = *d;
    *d = temp;
}

int main(){
    int n, i, x, y;

    printf("Enter the length of the array:  ");
    scanf("%d", &n);
    
    int arr[n];

    printf("Enter the array elements:  ");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    x = 0;
    y = n;

    QuickSort(arr, x, y);

    printf("Sorted array elements:\n");

    for(i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }

    printf("\nOpcount: %d\t\n", opcount);

}
