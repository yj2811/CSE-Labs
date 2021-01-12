#include<stdio.h>

void copy(char str1[], char str2[], int index){
	if(str1[index]== '\0'){
		return;
	}

	str2[index] = str1[index];
	copy(str1, str2, index+1);
}
int main(){
	char str1[20], str2[20];
	printf("Enter the string to be copied:\n");
	scanf("%s", str1);

	copy(str1, str2, 0);

	printf("String 1: %s\n", str1);
	printf("String 2: %s\n", str2);
}