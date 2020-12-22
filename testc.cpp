#include <stdio.h>
#include <stdlib.h>

struct Node{
    int num;
    Node *next;
}*awal , *akhir , *curr, *mid;

Node *createNode(int num){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->num = num;
    newNode->next  = NULL;
    return newNode;
}

void pushHead(int num){
  Node *temp = createNode(num);

  if(!awal){
    awal=akhir=temp;
  } else{
    temp->next = awal;
    awal=temp;
  }
}

void popHead(int num){
  if(!awal){
    return;
  } else if(awal==akhir){
  awal=akhir=NULL;
  free(awal);
  } else{
    Node *temp = awal;
    awal = temp->next;
    temp->next=NULL;
    free(temp);
  }
}
void popTail(int num) {
  if(!awal) {
    return;
  } else if(awal==akhir) {
    awal = akhir = NULL;
    free(awal);
  } else {
    Node *temp = awal;
    while(temp->next != akhir) {
      temp = temp->next;
    }
    temp->next = NULL;
    free(akhir);
    akhir = temp;
  }
}

void printLinkedList(){
  int count=0;
  struct Node *mid=awal;
  
  while(awal!=NULL){
  	count++;
	if(count%2==0)
	mid=mid->next;
  	
  	awal=awal->next;
  }
  if(mid!=NULL)
  printf("Median = %d\n", mid->num);

  
  }

int main(){
  int data , a , b;
  printf("banyak list nomor : "); 
  scanf("%d" , &data);
  printf("Input string number: ");
  for(int i=0 ; i<data ; i++){
    scanf(" %d" , &a);
    pushHead(a);
  }
  printLinkedList();

printf("\n");
return 0;
}