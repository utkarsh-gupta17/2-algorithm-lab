#include <iostream>
#include <time.h>
using namespace std;
void print_array(int *a,int n){
    for(int i=0 ; i<n ; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void insertion_sort(int *a,int n){
    for(int i=1 ; i<n ; i++){
        int temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
        cout<<"pass "<<i<<endl;
        print_array(a,10);
    }
}
int main()
{
    clock_t begin=clock();
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},i=0;
    print_array(arr, 10);
    insertion_sort(arr,10);
    begin = clock()- begin;
    print_array(arr, 10);
    cout << "Processor time taken for sorting: "
        << (float)begin/CLOCKS_PER_SEC << " seconds" << endl;
    cout<< "Bytes consumed: " << sizeof(begin)+sizeof(arr)+sizeof(i)*3;
    return 0;
}