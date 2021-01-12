#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool checkPalindrome(char str1[], int low, int high){
	if(low>=high){
		return true;
	}

	if(str1[low]==str1[high]){
		return checkPalindrome(str1 ,low+1, high-1);
	}

	return false;
}
int main(){
	char str1[20], str2[20];
	printf("Enter the string:\n");
	scanf("%s", str1);

	if(checkPalindrome(str1, 0, strlen(str1)-1)){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
}