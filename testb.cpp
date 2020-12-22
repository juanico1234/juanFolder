#include <stdio.h>
#include <stdlib.h>
  
struct node {
  int data;
  struct node *next;
} *awal;
 
void Unders(){
    awal = NULL;
}

void input(int num) {
    struct node* createNode = (struct node*) malloc(sizeof(struct node));
    createNode->data  = num;
    createNode->next = awal;
    awal = createNode;
    printf("%d -> ", num);
    
}

void Looping(struct node *awal) {
    struct node *o, *p;
    o = p = awal;
   
    while(o && p && p->next) {
        o = o->next;
        p  = p->next->next;
        if (o == p) {
           printf("\nLinked List contains a Cycle\n");
           return;
        }
    }
    printf("\nNo Cycle in Linked List\n");
}

void printLinkedList(struct node *ptr) {
  while (ptr != NULL) {
     printf("%d", ptr->data);
     ptr = ptr->next;
     if(ptr != NULL){
         printf("-->");
     }
  }
}
  
int main() {
    int a,b,c,d,e;
    printf("Input sorted number : ");
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    Unders();
    input(a);  
    input(b); 
    input(c); 
    input(d);
    input(e);
     printf("NULL");
    awal->next->next->next->next->next = awal->next;
 
    Looping(awal);
    return 0;
}