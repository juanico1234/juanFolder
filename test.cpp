#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char nama[300];
    int nilai;
    Node *next;

} *awal, *akhir;

Node *createnode(const char *nama,int score){
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->score=score);
    newNode->score = score;
    newNode->next=NULL;
    return newNode;
}

void pushTail(const char *nama,int nilai){
    Node *temp = createNode(nama,nilai);

    if(!head){
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

int main(){
    int a,b,c,d;
    printf("Banyaknya List ke-1: ");scanf("%d",&b);
    printf("Masukan list ke 1 =\n");
    for(int i=0;i<m;i++){
        scanf("%d",&c);
        pushTail(c);
    }

    printf("Banyaknya List ke-2 :"); scanf("%d",&n);
    printf("TYpo");
}
