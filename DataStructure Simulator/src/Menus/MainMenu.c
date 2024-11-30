#include <stdio.h>

#include "Colors.h"
#include "ArrayMenu.h"
#include "LinkedListMenu.h"

void MainMenu() {
    int option = -1;
    printf("\nChoose A Data Structure:-");
    printf("\n1) Array");
    printf("\n2) Linked List");
    printf("\n3) Stack");
    printf("\n4) Queue");
    printf("\n5) Tree");
    printf("\n6) Graph");
    printf("\n\n0) Exit The Application");
    printf("\nEnter The Option Number: ");
    scanf_s("%d", &option);

    switch (option)
    {
    case 0:
        exit(0);
    case 1:
        ArrayMenu();
        break;
    case 2:
        LinkedListMenu();
        break;
    case 3:
        printf("\nYou Entered Stack.");
        break;
    case 4:
        printf("\nYou Entered Queue.");
        break;
    case 5:
        printf("\nYou Entered Tree.");
        break;
    case 6:
        printf("\nYou Entered Graph.");
        break;
    default:
        setRedColor();
        printf("\nError: Invalid Option\n");
        resetToBaseColor();
        MainMenu();
        break;
    }
}