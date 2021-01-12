#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int date;
	int month;
	int year;
} DOB;

typedef struct{
	int reg_no;
	char name[10];
	char address[20];
} STU_INFO;

typedef struct{
	char college_name[20];
	char university_name[20];
} COLLEGE;

typedef struct{
	DOB* dob;
	STU_INFO* stu_info;
	COLLEGE* college;
} STUDENT;

void readSTUDENT(int count, STUDENT* s){
	printf("Enter the details of student %d in order:\n", count);
	scanf("%d/%d/%d", &s->dob->date, &s->dob->month, &s->dob->year);
	scanf("%d", &s->stu_info->reg_no);
	scanf("%s", s->stu_info->name);
	scanf("%s", s->stu_info->address);
	scanf("%s", s->college->college_name);
	scanf("%s", s->college->university_name);

}

void displaySTUDENT(int count, STUDENT* s){
	printf("The details are of student %d are:\n", count);
	printf("%d/%d/%d\n", s->dob->date, s->dob->month, s->dob->year);
	printf("%d\n", s->stu_info->reg_no);
	printf("%s\n", s->stu_info->name);
	printf("%s\n", s->stu_info->address);
	printf("%s\n", s->college->college_name);
	printf("%s\n", s->college->university_name);
}

int main(){
	int n;
	STUDENT* s;

	printf("Enter the number of students:");
	scanf("%d", &n);

	s = (STUDENT*)calloc(n, sizeof(STUDENT));

	for(int i=0; i<n; i++){
		readSTUDENT(i+1, s+i);
	}

	for(int i=0; i<n; i++){
		displaySTUDENT(i+1, s+i);
	}
	
}