#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node *next; };
struct Node* create(int x){ struct Node* p=malloc(sizeof(struct Node)); p->data=x; p->next=NULL; return p; }

struct Node* build(int n){
    struct Node *head=NULL,*t;
    for(int i=0;i<n;i++){
        int x; scanf("%d",&x);
        if(head==NULL){ head=create(x); t=head; }
        else{ t->next=create(x); t=t->next; }
    }
    return head;
}

int count_occ(struct Node* head,int key){
    int c=0;
    while(head){ if(head->data==key) c++; head=head->next; }
    return c;
}

struct Node* delete_all(struct Node* head,int key){
    while(head && head->data==key){ struct Node* t=head; head=head->next; free(t); }
    if(head==NULL) return NULL;
    struct Node* cur=head;
    while(cur->next){
        if(cur->next->data==key){ struct Node* t=cur->next; cur->next=t->next; free(t); }
        else cur=cur->next;
    }
    return head;
}

void display(struct Node* head){
    if(head==NULL){ printf("Empty\n"); return; }
    while(head){ printf("%d", head->data); if(head->next) printf("->"); head=head->next; }
    printf("\n");
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    struct Node* head = build(n);
    int key; scanf("%d",&key);
    int c = count_occ(head,key);
    printf("Count: %d\n", c);
    head = delete_all(head,key);
    printf("Updated Linked List: ");
    display(head);
    return 0;
}
