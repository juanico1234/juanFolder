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

void pushTail(){
    Node *temp = createNode(nama,nilai);

    if(!head){
        awal = akhir = temp;
    }else{
        akhir->next=temp;
        akhir = temp;
    }
}
void pushHead(){
    
}

