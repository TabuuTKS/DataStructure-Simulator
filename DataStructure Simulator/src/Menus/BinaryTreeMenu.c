#include <stdio.h>
#include <conio.h>

#include  "Colors.h"
#include "MainMenu.h"
#include "../DataStructures/BinaryTree.h"
#include "../DataStructures/testDS.h"

void checkTreeDeleted() {
    int option2 = 0;
    setYellowColor();
    printf("\nWant to Go Back, Do You Want to Store The Privious Data?: ");
    printf("\n1) Yes");
    printf("\n2) No");
    printf("\nEnter The Option Number: ");
    scanf_s("%d", &option2);
    if (option2 == 1)
    {
        setRedColor();
        printf("Binary Tree Not Deleted");
        resetToBaseColor();
    }
    else {
        setGreenColor();
        DeleteBinaryTree(&testTree);
        printf("Binary Tree Deleted");
        isTreeCreated = false;
        resetToBaseColor();
    }
}

void TreeInsertMenu() {
    int element;
    printf("\nEnter The Element You Want to insert: ");
    scanf_s("%d", &element);
    InsertBinaryTreeNode(&testTree, element);
}

void TreeDeleteMenu() {
    int element;
    printf("\nEnter The Element You Want to Delete: ");
    scanf_s("%d", &element);
    DeleteBinaryTreeNode(&testTree, element);
}

void BinaryTreeMenu() {
    if (isTreeCreated == false)
    {
        setYellowColor();
        printf("\nNo Binary Tree Exists..We Have To Create One");
        testTree = *CreateBinaryTree();
        setGreenColor();
        printf("\nBinary Tree Created");
        resetToBaseColor();
        isTreeCreated = true;
    }
    else {
        setGreenColor();
        printf("\nBinary Tree Alredy Created");
        resetToBaseColor();
    }
    int option = -1;
    printf("\nSelect an Operation to be performed on Your Binary Tree:\n");
    printf("\n1) Insert");
    printf("\n2) Delete");
    printf("\n3) Display");

    printf("\n\n0) Go Back");
    printf("\nEnter The Option Number: ");
    scanf_s("%d", &option);

    switch (option)
    {
    case 0:
        checkTreeDeleted();
        MainMenu();
    case 1:
        TreeInsertMenu();
        _getch();
        BinaryTreeMenu();
        break;
    case 2:
        TreeDeleteMenu();
        _getch();
        BinaryTreeMenu();
        break;
    case 3:
        DisplayBinaryTree(&testTree);
        _getch();
        BinaryTreeMenu();
        break;
    default:
        setRedColor();
        printf("\nError: Invalid Option\n");
        resetToBaseColor();
        BinaryTreeMenu();
        break;
    }
}