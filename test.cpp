#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char nama[300];
    int nilai;
    Node *next;

} *awal, *akhir;

Node *createNode(const char *nama,int score){
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->nilai=score);
    newNode->nilai = score;
    newNode->next=NULL;
    return newNode;
}

void pushTail(const char *nama,int nilai){
    Node *temp = createNode(nama,nilai);

    if(!awal){
        awal = akhir = temp;
    }else{
        akhir->next=temp;
        akhir = temp;
    }
}
void pushHead(const char *nama, int nilai){
    Node *temp = createNode(nama,nilai);

    if(!awal){
        awal=akhir=temp;
    }else{
        temp->next=awal;
        awal=temp;
    }
}

void printLinkedList(){
    Node *curr = awal;
    while(curr !=NULL){
        printf("%s ->",curr->nama);
        curr=curr->next;
    }
    printf("NULL\n");
}

int main(){
    int a,b,c,d;
    printf("Banyaknya List ke-1: ");scanf("%d",&b);
    printf("Masukan list ke 1 =\n");
    for(int i=0;i<b;i++){
        scanf("%d",&c);
        pushTail("Saiya",c);
    }

    printf("Banyaknya List ke-2 :"); scanf("%d",&a);
    printf("Masukan list ke 2 :\n");
    for(int i=0;i<a;i++){
        scanf("%d",&d);
        pushTail("Jean",d);
    }
    printLinkedList();

    printf("\n");
    return 0;
}
