#include <iostream>
#include <time.h>
using namespace std;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void printarray(int a[], int start,int end)
{
    for (int i = start; i <=end; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int partition(int a[], int lb, int ub)
{
    int pivot = a[lb], start = lb, end = ub,t;
    while (start < end)
    {
        while (a[start] <= pivot)
            start++;
        while (a[end] > pivot)
            end--;
        if (start < end)
            swap(&a[start],&a[end]);
    }
    swap(&a[lb],&a[end]);
    return end;
}
void quicksort(int a[], int lb, int ub)
{
    if(lb<ub){
        int loc = partition(a, lb, ub);
        quicksort(a, lb, loc - 1);
        // printarray(a,lb,ub);
        quicksort(a, loc + 1, ub);
        // printarray(a,lb,ub);
    }
}
int main()
{
    clock_t begin=clock();
    int a[] = {9, 11, 5, 2, 1, 3, 0},i;
    printarray(a,0,6);
    quicksort(a, 0, 6);
    begin = clock()- begin;
    printarray(a, 0, 6);
    cout << "Processor time taken for sorting: "
        << (float)begin/CLOCKS_PER_SEC << " seconds" << endl;
    cout<< "Bytes consumed: " << sizeof(begin)+sizeof(a)+sizeof(i)*37;
}