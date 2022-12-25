#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    struct Node *left;
    int data;
    struct Node *right;
}*head = NULL;

struct Node *min_node(struct Node*);

void insert(struct Node **head,int value){
    struct Node *newnode, *temp;
    bool flag = true;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    temp = *head;
    newnode -> left = NULL;
    newnode -> data = value;
    newnode -> right = NULL;
    if(temp == NULL){
        *head = newnode;
        printf("Inserted Successfully \n\n");
    }
    else{
        while(flag){
            if(temp -> data < value){
                if(temp -> right == NULL){
                    temp -> right = newnode;
                    printf("Inserted Successfully on Right\n\n");
                    flag = false;
                }
                else
                    temp = temp -> right;
            }
            if(temp -> data > value){
                if(temp -> left == NULL){
                    temp -> left = newnode;
                    printf("Inserted Successfully on Left\n\n");
                    flag = false;
                }
                else
                    temp = temp -> left;
            }
        }
    }
}

struct Node *delete_node(struct Node *head, int value){
    /*struct Node *temp;
    temp = search(*head,value);
    if(temp != NULL){
        if((temp -> right)->right == NULL && (temp -> left)->left == NULL){
            if((temp -> right)->data = value){
                free(temp -> right);
                temp -> right = NULL;
            }
            else{
                free(temp -> left);
                temp -> left = NULL;
            }
        }
    }
    else{
        printf("Element Not Found");
    }*/
    if(head == NULL){
        return head;
    }
    if(value < head -> data){
        head -> left = delete_node(head -> left,value);
    }
    else if(value > head -> data)
        head -> right = delete_node(head -> right,value);
    else{
        if(head -> left == NULL){
            struct Node *temp = head -> right;
            free(head);
            printf("Node Deleted\n");
            return temp;
        }
        else if(head -> right == NULL){
            struct Node *temp = head->left;
            free(head);
            printf("Node Deleted\n");
            return temp;
        }
        struct Node *temp = min_node(head->right);
        head -> data = temp -> data;
        head -> right = delete_node(head -> right, temp -> data);
    }
    return head;
    
}

struct Node *min_node(struct Node *node){
    struct Node *curr = node;
    while(curr -> left != NULL){
        curr = curr -> left;
    }
    return curr;
}

void display(struct Node *head, int choice){
    if(choice == 1){
        if(head != NULL){
            display(head -> left, choice);
            printf("%d ",head -> data);
            display(head -> right, choice);
        }
    }
    else if(choice == 2){
        if(head != NULL){
            printf("%d ",head->data);
            display(head -> left, choice);
            display(head -> right, choice);
        }
    }
    else if(choice == 3){
        if(head != NULL){
            display(head -> left, choice);
            display(head -> right, choice);
            printf("%d ",head -> data);
        }
    }
    else{
        printf("Wrong Input\n");
    }
}

struct Node* search(struct Node *head,int value){
    struct Node *prev;
    prev = head;
    if(head != NULL){
        if(value == head -> data){
            printf("Element Found\n\n");
            return prev;
        }
        else if(value > head -> data)
            search(head -> right, value);
        else
            search (head -> left, value);
    }
    else{
        printf("Element Not Found\n\n");
        return NULL;
    }
}
int sum(struct Node *head){
    if(head != NULL){
        return (head->data+sum(head->left)+sum(head->right));
    }
    else{
        return 0;
    }
}

void display_BST(struct Node *head){
	struct Node *temp;
	static long long int queue[7];
	static int front=0,rear=-1;
	if(head == NULL) return;
	queue[++rear] = (long long int)head;
	while(front<=7){
		temp = (struct Node*)queue[front++];
		printf("%d ",temp->data);
		if(temp->right!=NULL) queue[++rear] = (long long int)temp->right;
		if(temp->left!=NULL) queue[++rear] = (long long int)temp->left;
	}
}

int main()
{
	insert(&head,1);
	insert(&head->right,2);
	insert(&head->left,3);
	insert(&head->right->right,4);
	insert(&head->right->left,5);
	insert(&head->left->right,6);
	insert(&head->left->left,7);
	display_BST(head);
    /*int choice,value,orderchoice;
    do{
        printf("1.Insert 2.Delete 3.Display 4.Search 5.Sum 6.Exit\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value:");
                scanf("%d",&value);
                insert(&head,value);
                break;
            case 2:
                printf("Enter the value:");
                scanf("%d",&value);
                delete_node(head,value);
                break;
            case 3:
                printf("1.Inorder 2.Preorder 3.Postorder\n");
                printf("Enter the order choice:");
                scanf("%d",&orderchoice);
                printf("Elements:");
                display(head,orderchoice);
                printf("\n\n");
                break;
            case 4:
                printf("Enter the value:");
                scanf("%d",&value);
                search(head,value);
                break;
            case 5:
                printf("Sum of all Nodes:%d\n",sum(head));
                break;
            case 6:
                printf("Exiting...");
        }
        
    }while(choice!=6);*/
    return 0;
}
