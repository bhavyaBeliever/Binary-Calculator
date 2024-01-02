//https://leetcode.com/problems/min-stack/
#include<stdlib.h>
typedef struct node{
    int n;
    int minTillEnd;
    struct node* next;
}node;
typedef struct {
    node* head;
} MinStack;


MinStack* minStackCreate() {
    MinStack* s=(MinStack* )malloc(sizeof(MinStack));
    s->head=NULL;
    return s;
}

void minStackPush(MinStack* obj, int val) {
    if(!obj->head) {
        obj->head=(node* )malloc(sizeof(node));
        obj->head->n=val;
        obj->head->minTillEnd=val;
        obj->head->next=NULL;
        return;
    }
    node* p=(node* )malloc(sizeof(node));
    p->n=val;
    if(val < obj->head->minTillEnd) p->minTillEnd=val; 
    else p->minTillEnd=obj->head->minTillEnd;
    p->next=obj->head;
    obj->head=p;
    return;
}
void minStackPop(MinStack* obj) {
    if(!obj->head) return;
    node* p=obj->head;
    obj->head=obj->head->next;
    free(p);
    p=NULL;
    return;
}

int minStackTop(MinStack* obj) {
    return obj->head->n;    
}

int minStackGetMin(MinStack* obj) {
    return obj->head->minTillEnd;
}

void minStackFree(MinStack* obj) {
    node* p=obj->head,*q;
    while(p){
        q=p->next;
        free(p);
        p=q;
    }
    obj->head=NULL;
    return;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/