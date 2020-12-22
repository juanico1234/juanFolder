#include <stdio.h>
#include <stdlib.h>

struct Node{
    int num;
    Node *next;
}*awal , *akhir , *curr;


Node *createNode(int num){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->num = num;
    newNode->next  = NULL;
    return newNode;
}


void pushTail(int num){
    Node *temp = createNode(num);
    if(!awal){
        awal = akhir = temp;
    }
    else{
        akhir->next = temp;
        akhir = temp;
    }
}


void sortDLinkedList(){ // Descending
  int temp;
  Node *curr;
  Node *ptr = awal;
  while(ptr!= NULL){
    curr = ptr-> next;
    while(curr!= NULL){
      if(ptr->num < curr->num){
        temp = ptr->num;
        ptr->num = curr->num;
        curr->num = temp;
      }
      curr = curr->next;
    }
    ptr = ptr->next;
  }
}


void printLinkedList(){
  
  Node *curr = awal;
  while(curr !=NULL){
  printf("%d ", curr-> num);
    curr= curr-> next;
  }
}


int main(){
  int idx , a , b;

  printf("How many Integer : "); scanf("%d" , &idx);
  printf("Input number :\n");
  for(int i=0 ; i<idx ; i++){
    scanf(" %d" , &a);
    pushTail(a);
  }

  printf("Sorting :   "); 
   sortDLinkedList();
  printLinkedList();

printf("\n");
return 0;
}