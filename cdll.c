#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head;

void display();
void create();
void beginInsert();
void insert();
void lastInsert();
void deleteLast();
void deleteFirst();
void delete();


int main(){
    display();
    create();
    create();
    create();
    // display();
    // beginInsert();
    // lastInsert();
    // display();
    // insert();
    // insert();
    // deleteLast();
    // deleteFirst();
    delete();
    display();

    return 0;
}

void create(){
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter data value: ");
    scanf("%d",&(ptr->data));
    if(head == NULL){
        ptr->next=ptr;
        ptr->prev=ptr;
        head = ptr;
        printf("a new first node created\n");
    }
    else{
        struct node *temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
        ptr->next = head;
        head->prev = ptr;
        printf("a new node created\n");
    }
}

void display(){
    struct node *temp = head;
    if (temp == NULL){
        printf("no elements in list to display\n");
    }
    else{
        printf("the data in list is:\n");
        while (temp->next != head){
            printf("%d\t",temp->data);
            temp = temp->next;
        }
        printf("%d\n",temp->data);        
    }
}

void beginInsert(){
    create();
    head = head->prev;
    printf("node inserted at begin\n");
}

void lastInsert(){
    create();
    printf("node inserted at last\n");
}

void insert(){
    if (head == NULL){
        printf("there are no elements in list  adding elements\n");
        create();
        return;
    }
    struct node *ptr;
    int no;
    printf("enter the index of insertion: ");
    scanf("%d",&no);
    if(no<0){
        printf("enter a valid index number\n");
        return;
    }
    if (no == 0){
        beginInsert();
        return;
    }
    struct node *temp = head;
    for(int i = 0;i<no; i++){
        if(temp->next == head){
            if(no == i+1){
                lastInsert();
            }
            else{
                printf("the index is out of range, try 0 to %d\n",i+1);
            }
            return;
        }
        temp = temp->next;
    }
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter data value: ");
    scanf("%d",&(ptr->data));
    ptr->prev = temp->prev;
    ptr->next = temp;
    temp->prev = ptr;
    ptr->prev->next = ptr;
    printf("node inserted\n");
}

void deleteLast(){
    if(head == NULL){
        printf("there are no elements in list to delete\n");
        return;
    }
    if(head->prev == head){
        free(head);
        head = NULL;
        return;
    }
    struct node *ptr = head->prev;
    head->prev = ptr->prev;
    ptr->prev->next = head;
    free(ptr);
}

void deleteFirst(){
    if(head == NULL){
        printf("there are no elements in list to delete\n");
        return;
    }
    if(head->next == head){
        free(head);
        head = NULL;
        return;
    }
    struct node *ptr = head->next;
    ptr->prev = head->prev;
    head->prev->next = ptr;
    free(head);
    head = ptr;
}

void delete(){
    if(head == NULL){
        printf("there are no elements in list to delete\n");
        return;
    }
    if(head->next == head){
        free(head);
        head = NULL;
        return;
    }
    int no;
    printf("enter the index to delete: ");
    scanf("%d",&no);
    if(no<0){
        printf("enter a valid index number\n");
        return;
    }
    if(no == 0){
        deleteFirst();
        return;
    }
    struct node *temp = head;
    for(int i = 0;i<no;i++){
        // printf("%d\n",i);
        if(temp->next == head){
            printf("the index is out of range, try 0 to %d\n",i+1);
            return;
        }
        temp = temp->next;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);
}