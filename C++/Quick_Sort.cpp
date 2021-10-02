/*
Quick Sort
*/
#include<iostream>
#include <cstdlib>
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

int pivotPosition(int arr[], int st, int ed)
{
     srand(time(NULL));
    int random = st + rand() % (ed - st+1);
    swap(arr[random],arr[ed]);
    int pivElement = arr[ed];
    
    int pivIndex = st;
    for (int i = st; i < ed; i++)
    {
        if(arr[i] < pivElement)
        {
            swap(&arr[i], &arr[pivIndex]);
            pivIndex++;
        }
    }
    swap(&arr[pivIndex], &arr[ed]);
    return pivIndex;
}

void sortQuick(int arr[], int st, int ed)
{
    if (st < ed)
    {
        int pivIndex = pivotPosition(arr, st, ed);
        sortQuick(arr, st, pivIndex-1);
        sortQuick(arr, pivIndex+1, ed);
    }
}

void QuickSort(int size, int arr[])
{
    sortQuick(arr, 0, size-1);
}

main()
{
    int size = 10;
     int arr[size] = {10,8,5,9,1,7,6,3,4,2};
     cout << "Unsorted List:\n";
     display(size, arr);
     QuickSort(size, arr);
     cout << "Sorted List:\n";
     display(size, arr);
     return 0;
}
