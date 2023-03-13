#include<stdio.h>
#include<stdlib.h>
#include "SINGLY_LINKED_LIST_FUNCTIONS.h"

int main(){
    int choice, value, pos;
    char option;
    while(1){
        printf("\n1.Add at Beginining.\n2.Add at Position.\n3.Add at End\n4.Delete at Beginning.\n5.Delete at Position.\n6.Delete at End.\n7.Search a Value.\n8.Contains a Value.\n9.Sort a List.\n10.Display.\n11.IsEmpty.\n12.Exit.\n");
        printf("\nEnter a Choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value : ");
                scanf("%d", &value);
                addBeg(value);
                break;

            case 2:
                printf("Enter the value : ");
                scanf("%d", &value);
                printf("Enter the Position : ");
                scanf("%d", &pos);
                addPos(value, pos);
                break;

            case 3:
                printf("Enter the value : ");
                scanf("%d", &value);
                addEnd(value);
                break;

            case 4:
                delBeg();
                break;

            case 5:
                printf("Enter the Position : ");
                scanf("%d", &pos);
                delPos(pos);
                break;

            case 6:
                delEnd();
                break;

            case 7:
                printf("\nEnter the value to be Search : ");
                scanf("%d", &value);
                printf("%d", search(value));
                break;
            
            case 8:
                printf("\nEnter the value to be check that contains or not : ");
                scanf("%d", &value);
                printf("%d", contains(value));
                break;

            case 9:
                sort();
                break;

            case 10:
                display();
                break;

            case 11:
                printf("\n%d\n", isEmpty());
                break;

            case 12:
                exit(0);
                break;

            default:
            printf("\nEnter Correct Choice.");
        }
    }
}