#include<stdio.h>
#include<stdlib.h>
#include "ARRAY_FUNCTIONS.h"

int main(){
    int choice, value, pos;
    char option;
    while(1){
        printf("\n1.Add at Beginining.\n2.Add at Position.\n3.Add at End\n4.Delete at Beginning.\n5.Delete at Position.\n6.Delete at End.\n7.Search a Value.\n8.Sort an Array.\n9.Display.\n10.IsEmpty.\n11.Exit.\n");
        printf("\nEnter a Choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value : ");
                scanf("%d", &value);
                addbeg(value);
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
                addend(value);
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
                printf("\nIs Your Array is Sorted ?(Y/N) : ");
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
            
            case 8:
                quickSort();
                break;

            case 9:
                display();
                break;

            case 10:
                printf("\n%d\n", isEmpty());
                break;

            case 11:
                exit(0);
                break;

            default:
            printf("\nEnter Correct Choice.");
        }
    }
}