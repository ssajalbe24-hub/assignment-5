#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node *next; };
struct Node* create(int x){ struct Node* p=malloc(sizeof(struct Node)); p->data=x; p->next=NULL; return p; }

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    struct Node *head=NULL,*t;
    for(int i=0;i<n;i++){
        int x; scanf("%d",&x);
        if(head==NULL){ head=create(x); t=head; }
        else{ t->next=create(x); t=t->next; }
    }
    struct Node *prev=NULL,*cur=head,*next=NULL;
    while(cur){ next=cur->next; cur->next=prev; prev=cur; cur=next; }
    head = prev;
    while(head){ printf("%d", head->data); if(head->next) printf("->"); head=head->next; }
    printf("\n");
    return 0;
}
