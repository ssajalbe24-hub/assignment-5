#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node *next; };

struct Node* create(int x){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = x; p->next = NULL; return p;
}

void insert_begin(struct Node** head,int x){
    struct Node* p = create(x);
    p->next = *head; *head = p;
}
void insert_end(struct Node** head,int x){
    struct Node* p = create(x);
    if(*head==NULL){ *head = p; return; }
    struct Node* t = *head;
    while(t->next) t = t->next;
    t->next = p;
}
void insert_before_after(struct Node** head,int val,int x,int mode){
    if(*head==NULL) return;
    if(mode==0){
        if((*head)->data==val){ insert_begin(head,x); return; }
        struct Node* t = *head;
        while(t->next && t->next->data!=val) t = t->next;
        if(t->next){
            struct Node* p = create(x);
            p->next = t->next; t->next = p;
        }
    } else {
        struct Node* t = *head;
        while(t && t->data!=val) t = t->next;
        if(t){
            struct Node* p = create(x);
            p->next = t->next; t->next = p;
        }
    }
}
int delete_begin(struct Node** head){
    if(*head==NULL) return -1;
    struct Node* t = *head; int v = t->data;
    *head = t->next; free(t); return v;
}
int delete_end(struct Node** head){
    if(*head==NULL) return -1;
    struct Node* t = *head;
    if(t->next==NULL){ int v = t->data; free(t); *head=NULL; return v; }
    while(t->next->next) t = t->next;
    int v = t->next->data; free(t->next); t->next = NULL; return v;
}
int delete_value(struct Node** head,int val){
    if(*head==NULL) return 0;
    struct Node* t = *head;
    if(t->data==val){ *head = t->next; free(t); return 1; }
    while(t->next && t->next->data!=val) t = t->next;
    if(t->next){ struct Node* r = t->next; t->next = r->next; free(r); return 1; }
    return 0;
}
int search_pos(struct Node* head,int val){
    int pos=1;
    while(head){
        if(head->data==val) return pos;
        head=head->next; pos++;
    }
    return -1;
}
void display(struct Node* head){
    if(head==NULL){ printf("Empty\n"); return; }
    while(head){ printf("%d ", head->data); head = head->next; }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    int ch,x,val,mode;
    while(scanf("%d",&ch)==1){
        if(ch==1){ scanf("%d",&x); insert_begin(&head,x); }
        else if(ch==2){ scanf("%d",&x); insert_end(&head,x); }
        else if(ch==3){ scanf("%d %d %d",&val,&x,&mode); insert_before_after(&head,val,x,mode); }
        else if(ch==4){ printf("%d\n", delete_begin(&head)); }
        else if(ch==5){ printf("%d\n", delete_end(&head)); }
        else if(ch==6){ scanf("%d",&val); printf("%d\n", delete_value(&head,val)); }
        else if(ch==7){ scanf("%d",&val); printf("%d\n", search_pos(head,val)); }
        else if(ch==8){ display(head); }
        else break;
    }
    return 0;
}
