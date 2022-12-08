#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*start,*head,*temp;

void create_node()
{
    head=(struct node*)(malloc(sizeof(struct node)));
    int item;
    printf("enter the element");
    scanf("%d",&item);
    head->data = item;
    head->next = NULL;
    if(start == NULL)
    {
        start=head;
        head->prev=NULL;

    }
    else
    {
        temp = start;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head;
        head->prev = temp;
    }
}

void traverse()
{
    if(start == NULL)
    {
        printf("no linked list");
    }
    else
    {
        temp = start;
        while(temp != NULL)
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
    }
}

void insert_beginning()
{
    head=(struct node*)(malloc(sizeof(struct node)));
    int item;
    printf("enter the element");
    scanf("%d",&item);
    head->data = item;
    if(start == NULL)
    {
        start=head;
        head->prev=NULL;
    }
    else
    {
        head->next = start;
        head->prev = NULL;
        start = head;
    }
}

void insert_after_data()
{
    head=(struct node*)(malloc(sizeof(struct node)));
    int item;
    printf("enter the element");
    scanf("%d",&item);
    head->data = item;
    head->next = NULL;
    if(start == NULL)
    {
        start=head;
        head->prev=NULL;
    }
    else
    {
        int key;
        printf("enter the data to after insert");
        scanf("%d",&key);
        temp = start;
        while(temp->data != key)
        {
            temp = temp->next;
        }
        if(temp == NULL)
        {
            printf("key not found");
        }
        else
        {
            head->next = temp->next;
            head->prev = temp;
            temp->next = head;
        }
   }   
}

void main()
{
    int option;
    do
    {  
        printf("\nselect the option froavem below\n");
        printf("1.create a node\n2.traverse\n3.insert at beginning\n4.insert after a data\n0.exit\n");
        scanf("%d",&option);
        switch (option)
        {
            case 1:
                create_node();
                break;
            case 2:
                traverse();
                break;
            case 3:
                insert_beginning();
                break;
            case 4:
                insert_after_data();
                break;
            case 0:
                break;
        }
    }while(option != 0);
}
