#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int date;
	int month;
	int year;
} Dob;

typedef struct{
	int houseNo;
	int zip;
	char state[15];
} Address;

typedef struct{
	char name[10];
	Dob dob;
	Address add;
} Employee;

void readEmployee(int count, Employee* ptr){
	printf("Enter the name, DOB(dd/mm/yyyy), address (house number, zip and state) of employee %d:\n", count);
	scanf("%s", ptr->name);
	scanf("%d/%d/%d", &ptr->dob.date, &ptr->dob.month, &ptr->dob.year);
	scanf("%d", &ptr->add.houseNo);
	scanf("%d", &ptr->add.zip);
	scanf("%s", ptr->add.state);
}

void displayEmployee(int count, Employee* ptr){

	printf("For employee %d:\n", count);
	printf("Name: %s\n", ptr->name);
	printf("DOB: %d/%d/%d\n", ptr->dob.date, ptr->dob.month, ptr->dob.year);
	printf("Address: %d, %d, %s\n", ptr->add.houseNo, ptr->add.zip, ptr->add.state);
}

int main(){
	int n;
	Employee *ptr;

	printf("Enter the number of employees:\n");
	scanf("%d", &n);

	ptr = (Employee*)calloc(n, sizeof(Employee));

	for(int i=0; i<n; i++){
		readEmployee(i+1, ptr+i);
	}

	for(int i=0; i<n; i++){
		displayEmployee(i+1, ptr+i);
	}


}