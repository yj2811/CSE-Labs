#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char name[20];
	int rollNo;
	float cgpa;
} Student;

void readStudent(int count, Student *s){
	printf("Enter the name, roll number and CGPA of the %d student:\n", count);
	scanf("%s", s->name);
	scanf("%d", &s->rollNo);
	scanf("%f", &s->cgpa);
}

void displayStudent(int count, Student *s){

	printf("For student %d\n", count );
	printf("Name: %s\n", s->name);
	printf("Roll No.: %d\n", s->rollNo);
	printf("CGPA: %.2f\n", s->cgpa);

	printf("\n");
}


void sort(int count, Student *ptr){
	int i, j, min;

	for(i=0; i<count-1; i++){
		min = i;
		for(j=i+1; j<count; j++){
			if((ptr + j)->rollNo < (ptr + min)->rollNo){
				min = j;
			}
		}
		if(min != i){

			printf("Hello\n");
			Student temp = *(ptr + i);
			*(ptr + i) = *(ptr+min);
			*(ptr+min) = temp;
		}
	}
}

int main(){
	
	Student* ptr;
	int n;


	printf("Enter the number of records:\n");
	scanf("%d", &n);

	ptr = (Student*)calloc(n, sizeof(Student));

	for(int i=0; i<n; i++){
		readStudent(i+1, ptr+i);
	}

	for(int i=0; i<n; i++){
		displayStudent(i+1, ptr+i);
	}

	sort(n, ptr);

	for(int i=0; i<n; i++){
		displayStudent(i+1, ptr+i);
	}


}

