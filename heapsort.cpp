#include <iostream>
#include <time.h>
using namespace std;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (a[left] > a[largest] && left < n)
    {
        largest = left;
    }
    if (a[right] > a[largest] && right < n)
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}
void heapsort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        printarray(a,n);
        heapify(a, i, 0);
    }
}
int main()
{
    clock_t begin = clock();
    int a[] = {9,11,5,2,1,},i;
    printarray(a, 5);
    heapsort(a, 5);
    begin = clock() - begin;
    printarray(a, 5);
    cout << "Processor time taken for sorting: "
         << (float)begin / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "Bytes consumed: " << sizeof(begin) + sizeof(a) + sizeof(i) * 37;
}