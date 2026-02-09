#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    struct node *next;
    char data[10];
};

struct node *start = NULL;

struct node *createNode()
{
    struct node *k1;
    k1 = (struct node *)malloc(sizeof(struct node));
    printf("Enter a character:");
    scanf("%s", k1->data);
    k1->next = NULL;
    k1->prev = NULL;
    return k1;
}

void insertStart()
{
    struct node *h1;
    h1 = createNode();
}
void insertEnd()
{

}
void insertMiddle()
{

}
void deleteStart()
{

}
void deleteEnd()
{

}
void deleteMiddle()
{

}
void display()
{

}

int main() {
    int ch;
    while(1)
    {
        printf("\n ------MENU------");
        printf("\n 1. Insert from start");
        printf("\n 2. Insert from end");
        printf("\n 3. Insert from middle");
        printf("\n 4. Delete from start");
        printf("\n 5. Delete from end");
        printf("\n 6. Delete from middle");
        printf("\n 7. Display");
        printf("\n 8. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case(1):
                insertStart();
                break;
            case(2):
                insertEnd();
                break;
            case(3):
                insertMiddle();
                break;
            case(4):
                deleteStart();
                break;
            case(5):
                deleteEnd();
                break;
            case(6):
                deleteMiddle();
                break;
            case(7):
                display();
                break;
            case(8):
                printf("\n__*___*___*____Good Bye__*___*___*__*__\n");
                exit(0);
            default:
                printf("\n******Wrong Input.******");
                printf("\n~~~~~~Please enter a valid input.~~~~~~~\n");
        }
        
    }
    return 0;
}