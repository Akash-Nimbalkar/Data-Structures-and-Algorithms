#include <stdio.h>
#include <stdlib.h>

int count = 0;
struct node
{
    int data;
    struct node *next;
} *head, *temp,*tail;


void insert_begin()
{
    int val;
    printf("Enter Value to insert at begining: ");
    scanf("%d",&val);
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next=head;
    
    head = newnode;
}

void display(struct node *head)
{
    struct node *temp = head;
    // temp = head;
    // while(temp->next!=head)
    // {
    //     printf("%d ",temp->data);
    //     temp=temp->next;
    // }
    do
    {
        printf("%d" , temp->data);
        temp = temp->next;
    } while (temp != head);
    
}

void insert_mid()
{
    int val,pos,i=2;
    printf("\nEnter Position: ");
    scanf("%d",&pos);
    printf("\nEnter Value to insert at Mid: ");
    scanf("%d",&val);
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    temp = head;
    while(i<pos)
    {
        temp= temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;

}
void insert_end()
{
    int val;
    printf("Enter Value to insert at End: ");
    scanf("%d",&val);
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    // temp = head;
    // while(temp->next!=head)
    tail->next = newnode;
    newnode->next= head;
    tail  = newnode;

}
void delete_begin(){}
void delete_mid(){}
void delete_end(){}
int main()
{
    struct node *newnode = malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data); // printf("\n%d",newnode->data);
    count++;
    newnode->next = head;
    head = newnode;
    tail=newnode;
    
    int ch = 1, c;
    while (ch)
    {
        printf("\n1.Insert at begin\n2.Insert at Mid\n3.Insert at End\n4.Delete at begin\n5.Delete at Mid\n6.Delete at End\n7.EXIT\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insert_begin();
           // display(head);
            break;
        case 8: display(head);
        break;
        case 2:
            insert_mid();
            display(head);
            break;
        case 3:
            insert_end();
            display(head);
            break;
        case 4:
            delete_begin();
            display(head);
            break;
        case 5:
            delete_mid();
            display(head);
            break;
        case 6:
            delete_end();
            display(head);
            break;
        case 7:
            ch = 0;
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}