/*
Merge Sort
:Divide and Conquer
*/
#include<iostream>
using namespace std;

void display(int size, int arr[])
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void mergeList(int arr[], int st, int md, int ed)
{
    int result[ed-st+1];
    int i, j, k = 0;
    i = st;
    j = md + 1;
    while(i <= md && j <= ed)
    {
        if(arr[i] <= arr[j])
        {
            result[k] = arr[i];
            i++;
        }
        else
        {
            result[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i <= md)
    {
        result[k] = arr[i];
        k++;
        i++;
    }
    while(j <= ed)
    {
        result[k] = arr[j];
        k++;
        j++;
    }
    k = 0;
    for(i = st; i <= ed; i++)
    {
        arr[i] = result[k];
        k++;
    }
}

void sortMerge(int arr[], int st, int ed)
{
    if (st == ed)
        return;
    int mid  = (st+ed)/2;
    sortMerge(arr, st, mid);
    sortMerge(arr, mid+1, ed);
    mergeList(arr, st, mid, ed);

}

void MergeSort(int size, int arr[])
{
    sortMerge(arr, 0, size-1);
}

main()
{
    int size = 10;
     int arr[size] = {10,8,5,9,1,7,6,3,4,2};
     cout << "Unsorted List:\n";
     display(size, arr);
     MergeSort(size, arr);
     cout << "Sorted List:\n";
     display(size, arr);
     return 0;
}
