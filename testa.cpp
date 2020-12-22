#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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


void printLinkedList(){
  Node *curr = awal;
  while(curr !=NULL){
  printf("%d ", curr-> num);
    curr= curr-> next;
  }
}


void sortLinkedList(){
  int temp;
  Node *curr;
  Node *ptr = awal;
  while(ptr!= NULL){
    curr = ptr-> next;
    while(curr!= NULL){
      if(ptr->num > curr->num){
        temp = ptr->num;
        ptr->num = curr->num;
        curr->num = temp;
      }
      curr = curr->next;
    }
    ptr = ptr->next;
  }
}


int main(){
  int a , b , c , d;

  printf("Banyak list 1 : "); scanf("%d" , &b);
  printf("Input array number 1 :\n");
  for(int i=0 ; i<b ; i++){
    scanf(" %d" , &c);
    pushTail(c);
  }
  printf("Banyak List 2 : "); scanf("%d" , &a);
  printf("Input array number 2 :\n");
  for(int i=0 ; i<a ; i++){
    scanf(" %d" , &d);
    pushTail(d);
  }
  sortLinkedList();
  printf("List Akhir :\n");
  printLinkedList();
  printf("\n");
  
  return 0;

}