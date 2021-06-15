#include <stdio.h>
#include <stdlib.h>
int opcount = 0;
void topDown(int arr[], int currIndex)
{
    int parent = (currIndex - 1)/2;
    while(parent >= 0)
    {
         opcount++;
        if(arr[parent]<arr[currIndex])
        {
            int temp = arr[parent];
            arr[parent] = arr[currIndex];
            arr[currIndex] = temp;

            currIndex = parent;
            parent = (currIndex - 1)/2;
        }
        else
            return;
    }
}

int main()
{
    int h[20], n;
    printf("Enter no. of elements:\t");
    scanf("%d", &n);

    printf("Enter Elements:\t");
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &h[i]);
        topDown(h, i);

        for(int k = 0; k<=i; k++)
            printf("%d ", h[k]);

        printf("\n");
    }


    printf("Heapified array:\t");
    for(int i = 0; i<n; i++)
        printf("%d ", h[i]);

    printf("\n");

    printf("Opcount: %d\t",opcount);
    printf("\n");
    
}
