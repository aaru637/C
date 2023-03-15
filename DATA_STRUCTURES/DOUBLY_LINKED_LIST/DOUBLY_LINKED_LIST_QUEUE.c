#include<stdio.h>
#include<stdlib.h>
#include "DOUBLY_LINKED_LIST_QUEUE_FUNCTIONS.h"

int main(){
    int choice, value, pos;
    char option;
    while(1){
        printf("\n1.Enqueue.\n2.Dequeue.\n3.Peek.\n4.Contains.\n5.IsEmpty.\n6.Search a Value.\n7.Sort a Queue.\n8.Display.\n9.Exit.\n");
        printf("\nEnter a Choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value : ");
                scanf("%d", &value);
                enQueue(value);
                break;

            case 2:
                printf("\n%d\n", deQueue());
                break;

            case 3:
                printf("\n%d\n", peek());
                break;
            
            case 4:
                printf("\nEnter the value to be check that contains or not : ");
                scanf("%d", &value);
                printf("%d", contains(value));
                break;

            case 5:
                printf("\n%d\n", isEmpty());
                break;

            case 6:
                printf("\nEnter the value to be Search : ");
                scanf("%d", &value);
                printf("%d", search(value));
                break;

            case 7:
                sort();
                break;

            case 8:
                display();
                break;

            case 9:
                exit(0);
                break;

            default:
            printf("\nEnter Correct Choice.");
            break;
        }
    }
}