#include<stdio.h>

void checkPalindrome(char* string){

	char *ptr, *rev; 
  
    ptr = string;

  	
    while (*ptr != '\0') { 
        ++ptr; 
    } 

    --ptr;

    for (rev = string; ptr >= rev;) { 
        if (*ptr == *rev) { 
            --ptr; 
            rev++; 
        } 
        else
            break; 
    } 
  
    if (rev > ptr) 
        printf("String is Palindrome\n"); 
    else
        printf("String is not a Palindrome\n"); 

}

int main() {

	char str[60];

	printf("Enter the string:\n");
	// scanf("%s", str);
	fgets(str, 60, stdin);

	printf("%s", str);

	checkPalindrome(str);

	return 0;
}
