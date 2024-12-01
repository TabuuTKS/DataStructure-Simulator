#include <stdio.h>

#include "Colors.h"
#include "ArrayMenu.h"
#include "LinkedListMenu.h"
#include "StackMenu.h"
#include "QueueMenu.h"
#include "BinaryTreeMenu.h"

void MainMenu() {
    int option = -1;
    printf("\nChoose A Data Structure:-");
    printf("\n1) Array");
    printf("\n2) Linked List");
    printf("\n3) Stack");
    printf("\n4) Queue");
    printf("\n5) Binary Tree");
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
        StackMenu();
        break;
    case 4:
        QueueMenu();
        break;
    case 5:
        BinaryTreeMenu();
        break;
    default:
        setRedColor();
        printf("\nError: Invalid Option\n");
        resetToBaseColor();
        MainMenu();
        break;
    }
}