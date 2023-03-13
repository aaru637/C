#include<stdio.h>
#include<stdlib.h>
#include "ARRAY_QUEUE_FUNCTIONS.h"

int main(){
    int choice, value, pos;
    char option;
    while(1){
        printf("\n1.EnQueue.\n2.DeQueue.\n3.Peek.\n4.IsEmpty.\n5.Search a Value.\n6.Sort a Queue.\n7.Display.\n8.Exit.\n");
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
                printf("\n%d\n", isEmpty());
                break;

            case 5:
                printf("\nIs Your Queue is Sorted ?(Y/N) : ");
                scanf(" %c", &option);
                printf("\nEnter the value to be Search : ");
                scanf("%d", &value);
                switch(option){
                case 'y':
                case 'Y':
                    printf("%d ", Binarysearch(value));
                    break;
                case 'n':
                case 'N':
                    printf("%d ", LinearSearch(value));
                    break;
                default:
                    printf("\nEnter only (y/n) or (Y/N) only.");
                }
                break;
            
            case 6:
                quickSort();
                break;

            case 7:
            display();
            break;

            case 8:
            exit(0);
            break;

            default:
            printf("\nEnter Correct Choice.");
        }
    }
}