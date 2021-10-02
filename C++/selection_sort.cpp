/*
Selection Sort
:Put minimum value at the beginning
*/
#include<iostream>
using namespace std;

void display(int size, int arr[])
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int size, int arr[])
{
    int min;
    for (int i = 0; i < size-1; i++)
    {
        min = i;
        for (int j = i+1; j < size; j++)
            if (arr[min] > arr[j])
                min = j;
        if(min != i)
            swap(&arr[i], &arr[min]);
    }
}

main()
{
    int size = 10;
     int arr[size] = {10,8,5,9,1,7,6,3,4,2};
     cout << "Unsorted List:\n";
     display(size, arr);
     SelectionSort(size, arr);
     cout << "Sorted List:\n";
     display(size, arr);
     return 0;
}
