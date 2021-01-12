#include<stdio.h>

int bin_search(int low, int high, int ele, int arr[]){

	if(low>high){
		return -1;
	}
	int mid = (low+high)/2;

	if(arr[mid]==ele){
		return mid;
	}else if(ele<arr[mid]){
		return bin_search(low, mid-1 , ele ,arr);
	}else{
		return bin_search(mid+1, high, ele , arr);
	}

}

int main(){
	int n, ele;
	printf("Enter the number of elements in the array:\n");
	scanf("%d", &n);

	int arr[n];

	printf("Enter the elements in the array in sorted order only:\n");

	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	printf("Enter the item to be searched:\n");
	scanf("%d", &ele);

	int low=0;
	int high=n-1;

	int pos = bin_search(low, high, ele, arr);

	if(pos!=-1){
		printf("Found at %d\n", pos+1);
	}else{
		printf("Not found.\n");
	}
}