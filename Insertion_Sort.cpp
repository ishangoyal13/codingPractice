/*
Insertion Sort
:Finding the correct position of each element
*/
#include<iostream>
using namespace std;

void display(int size, int arr[])
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void InsertionSort(int size, int arr[])
{
    int min, j;
    for (int i = 1; i < size; i++)
    {
        min = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > min)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = min;
    }
}

main()
{
    int size = 10;
     int arr[size] = {10,8,5,9,1,7,6,3,4,2};
     cout << "Unsorted List:\n";
     display(size, arr);
     InsertionSort(size, arr);
     cout << "Sorted List:\n";
     display(size, arr);
     return 0;
}
