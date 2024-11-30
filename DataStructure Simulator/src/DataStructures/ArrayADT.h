#ifndef ARRAYADT_H
#define ARRAYADT_H

struct CustomArray
{
    int Total_Size;
    int Used_Size;
    int* ptr;
}typedef Array;

void CreateArray(Array *a, int Tsize, int Usize);
void Set(Array* a);
void DeleteArray(Array* a);

//void operations
void Display(Array *a);
void Insert(Array* a, int element, int index);
void DeleteElement(Array* a, int index);
void LinearSearch(Array* a, int element);
void BinarySearch(Array* a, int element);
void BubbleSort(Array* a);
void SelectionSort(Array* a);
#endif