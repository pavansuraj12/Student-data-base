#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int roll;
    char name[100];
    char attan[20];
    struct node *next;
};
int cp=0,ca=0;
struct node *head=NULL;
struct node *create();
struct node *delete();
void display();
void search();
void attandance();
void display_attan();
int main(){
    int c;
    printf(".........................");
    printf("\nSTUDENT DATA BASE\n");
    printf(".........................");
    printf("\nWELCOME\n1.Enter student details\n2.Display Students\n3.Delete a student.\n4.Search students\n6.Enter attandance\n7.Display attandance\n8.Exit\n");
    while(1){
        printf("\nEnter Your Choice :");
        scanf("%d",&c);
        switch(c){
            case 1:
            head=create();
            break;
            case 2:
            display();
            break;
            case 3:
            head=delete();
            break;
            case 4:
            search();
            break;
            case 6:
            attandance();
            break;
            case 7:
            display_attan();
            break;
            case 8:
            printf("EXITED Successfully");
            exit (0);
            break;
            default:
            printf("Enter valid option");
            break;
        }
    }
}
struct node *create(){
    struct node *ptr,*newnode,*t,*t1;
    int r;
    if(head==NULL){
        head=(struct node*)malloc(sizeof(struct node));
        ptr=head;
        strcpy(ptr->attan,"Not entered");
    }
    else{
        t1=head;
        while(t1->next!=NULL){
            t1=t1->next;
        }
        newnode=(struct node*)malloc(sizeof(struct node));
        t1->next=newnode;
        ptr=newnode;
        strcpy(ptr->attan,"Not entered");
    }
    ptr->next=NULL;
    printf("\nEnter Roll number :");
    scanf("%d",&r);
    t=head;
    while(t!=NULL){
        if(t->roll==r){
            printf("Already Entered...\n");
            printf("\nEnter Another Roll no:");
            scanf("%d",&r);
            break;
        }
        t=t->next;
    }
    ptr->roll=r;
    printf("Name(Do not use spaces):");
    scanf("%s",ptr->name);
    printf("\nAdded Successfully\n");
    return (head);
}
void display(){
    struct node *ptr=head;
    if(ptr==NULL){
        printf("\nDatabase is Empty.\n");
        return;
    }
    printf("...................................\n");
    printf("Roll number               Name\n");
    printf("...................................\n");
    while(ptr!=NULL){
        printf("\n%d                     %s",ptr->roll,ptr->name);
        ptr=ptr->next;
    }
    printf("\n");
}
struct node *delete()
{
    int d;
    struct node *ptr=head,*temp;
    if(ptr==NULL){
        printf("\nDatabase is Empty.\n");
        return(head);
    }
    printf("\nEnter Roll no to Delete:");
    scanf("%d",&d);
    while(ptr!=NULL){
        if(ptr->roll==d)
        break;
        temp=ptr;
        ptr=ptr->next;
    }
    if(ptr==NULL){
    printf("\nRoll number Not Found\n");
    }
    else if(ptr==head){
        head=head->next;
        free(ptr);
        printf("\nDeleted Successfully...\n"); 
    }
    else{
        temp->next=ptr->next;
        free(ptr);
        printf("\nDeleted Successfully...\n"); 
    }
    return(head);
}
void search(){
    struct node *ptr=head;
    if(ptr==NULL){
        printf("\nDatabase is Empty.\n");
        return;
    }
    int s;
    printf("\nEnter roll number to be searched:");
    scanf("%d",&s);
    while(ptr!=NULL){
        if(ptr->roll==s){
            printf("\nFound roll number. %d\n\nDetails:\nRoll number : %d\nName : %s\n",s,ptr->roll,ptr->name);
            return;
        }
        ptr=ptr->next;
    }
    printf("\nNot found\n");
    return;
}
void attandance(){
    struct node *ptr=head;
    if(ptr==NULL){
        printf("\nDatabase is Empty.\n");
        return;
    }
    int a;
    char d[5];
    printf("\nEnter roll no to mark attandance:");
    scanf("%d",&a);
    while(ptr!=NULL){
        if(ptr->roll==a){
            printf("\nEnter A for Absent and P for present:");
            scanf("%1s",d);
            if(*d=='p'||*d=='P'){
            strcpy(ptr->attan,"Present");
            cp++;
            }
            else {
            strcpy(ptr->attan,"Absent");
            ca++;
            }
            printf("\nEntered attandance for roll no %d Successfully.\n",a);
            return;
        }
        ptr=ptr->next;
    }
     printf("\nNot found.Enter correct roll number.\n");
}
void display_attan(){
    struct node *ptr=head;
    if(ptr==NULL){
        printf("\nDatabase is Empty.\n");
        return;
    }
    printf("...............................\n");
    printf("Roll Number          Attandance details\n");
    printf("...............................\n");
    while(ptr!=NULL){
        printf("\n%d         %s",ptr->roll,ptr->attan);
        ptr=ptr->next;
    }
    printf("\nNo of students present : %d\nNo of students Absent : %d\n",cp,ca);
    return;
}
