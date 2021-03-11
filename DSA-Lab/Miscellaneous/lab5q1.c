#include <stdio.h> #include <stdlib.h>
#define MAX 5
void pqinsert(int); void pqmindelete(int); void create();
void check(int);
void pqdisplay();
int pri_que[MAX]; int front, rear;
void main() {
int n, ch;
printf("\n1 - Insert an element into queue"); printf("\n2 - Delete an element from queue"); printf("\n3 - Display queue elements"); printf("\n4 - Exit");
create();
while (1)
{
printf("\nEnter your choice : "); scanf("%d", &ch);
switch (ch)
{
case 1:
printf("\nEnter value to be inserted : "); scanf("%d",&n);
pqinsert(n);
break;
case 2: pqmindelete(n); break;
case 3: pqdisplay(); break;
case 4: exit(0);
default:
printf("\nChoice is incorrect, Enter a correct choice");
} }
}


void create() {
front = rear = -1; }
void pqinsert(int data) {
if (rear >= MAX - 1) {
printf("\nQueue overflow no more elements can be inserted");
return; }
if ((front == -1) && (rear == -1)) {
front++;
rear++; pri_que[rear] = data; return;
} else
check(data); rear++;
}
void check(int data) {
int i,j;
for (i = 0; i <= rear; i++) {
if (data <= pri_que[i]) {
for (j = rear + 1; j > i; j--) {
pri_que[j] = pri_que[j - 1]; }
pri_que[i] = data;
return; }
}
pri_que[i] = data; }
void pqmindelete(int data)
{
inti;
if ((front==-1) && (rear==-1)) {
printf("\nQueue is empty no elements to delete");
return; }
for (i = 0; i < rear; i++) {
pri_que[i] = pri_que[i + 1];

 

}
pri_que[i] = -99; rear--;
if (rear == -1)
front = -1; return;
}
void pqdisplay() {
if ((front == -1) && (rear == -1)) {
printf("\nQueue is empty");
return; }
for (; front <= rear; front++) {
printf(" %d ", pri_que[front]); }
front = 0; }