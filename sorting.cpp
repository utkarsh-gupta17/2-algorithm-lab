#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// void swap(int a,int b){
//     int t=a;
//     a=b;
//     b=t;
// }
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void selection_sort(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++){
            if (arr[j] < arr[min])
                min = j;
            }
        if(min!=i)
            swap(&arr[min], &arr[i]);
    }
}
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}
void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    print_array(arr, 10);
    selection_sort(arr, 10);
    print_array(arr, 10);
    return 0;
}