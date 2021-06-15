#include <stdio.h>
#include <stdlib.h>
int opcount = 0;
void heapify(int h[], int l, int n)
{
    int i, k, v, heapify, j;
    for(i = (n/2); i>=l; i--)
    {
        k = i; v = h[k]; heapify = 0;
        while(heapify == 0 && 2*k <= n)
        {
            j = 2*k;
	        opcount++;
            if(j<n)
                if(h[j]<h[j+1])
                    j = j+1;
            if(v>=h[j])
                heapify = 1;
            else
            {
                h[k] = h[j];
                k = j;
            }
        }
        h[k] = v;
    }
    return;
}
void HeapSort(int h[], int n)
{
    int k = 0;
    for(int i = 1; i<=n; i++)
    {
        heapify(h, 1, n - k);
        int temp = h[1];
        h[1] = h[n-k];
        h[n-k] = temp;
        k++;
    }
}
int main()
{
    int h[20], n;
    printf("Enter the number of elments: \t");
    scanf("%d", &n);

    printf("Enter the elements : \t");

    for(int i = 1; i<=n; i++)
        scanf("%d", &h[i]);

    HeapSort(h, n);

    printf("The sorted array is: \t");

    for(int i = 1; i<=n; i++)
        printf("%d ", h[i]);
    printf("\n");
    printf("Opcount: %d\t", opcount);
    printf("\n");
}