#include<stdio.h>  
#include<stdlib.h>
struct node  
{  
    int data;  
    struct node *left, *right;  
};
       
struct node *create()  
{  
   struct node *newnode;  
   int data,choice;  
   newnode = (struct node *)malloc(sizeof(struct node));  
   printf("\nEnter the data(-1 for no data)");  
   scanf("%d", &data);  
   if(data==-1)  
    {  
    return 0;  
    }  
else  
{  
   
    newnode->data = data;  
    printf("Enter the left child of data %d", data);  
    newnode->left = create();  
    printf("Enter the right child of data %d", data);  
    newnode->right = create();  
    return newnode;  
}  
}  
void preorder(struct node *root)
{
if(root!=NULL)
{
printf("\n%d",root->data);
preorder(root->left);
preorder(root->right);
}
}
void inorder(struct node *root)
{
    if(root != NULL)
    {   
        inorder(root->left);
        printf("\n%d",root->data);
        inorder(root->right); 
    }
}
void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("\n%d",root->data);   
    }
}
void main()  
{  
         
    struct node *root = create();  
    printf("Elements displayed in preorder");
    preorder(root);
    printf("\nElements displayed in inorder");
    inorder(root);
    printf("\nElements displayed in postorder");
    postorder(root);
}