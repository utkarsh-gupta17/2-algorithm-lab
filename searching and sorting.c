//searching and sorting programs
#include <stdio.h>
void linearsearch(int a[],int val){
    for(int i=0 ; i<n ; i++){
        if(a[i]==val){
            printf("%d found at %d position\n",val,i);
            return;
        }
    }
    printf("element not found\n");
}
void binarysearch(int a[],int val){
    int i=0,j=n-1,mid=(i+j)/2;
    while(i<j && a[mid]!=val){
        if(val<a[mid])
         j=mid-1;
        else
         i=mid+1;
        mid=(i+j)/2;
    }
    if(a[mid]==val)
     printf("%d found at %d position\n",val,mid);
    else
     printf("element not found\n");
}
void bubblesort(int a[]){
    for(int i=0 ; i<n-1 ; i++){
        int flag=0;
        for(int j=0 ; j<n-1-i ; j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                flag=1;
            }
        }
        if(flag==0)
         break;
    }
}
void insertionsort(int a[]){
    for(int i=1 ; i<n ; i++){
        int temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
void selectionsort(int a[]){
    for(int i=0 ; i<n-1 ; i++){
        int min=i;
        for(int j=i+1 ; j<=n ; j++){
            if(a[j]<a[min])
             min=j;
        }
        if(min!=i)
         swap(a[min],a[i]);
    }
}
void quicksortwhole(){
    void quicksort(int a[],int lb,int ub){
        int loc=partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }
    int partition(int a[],int lb,int ub){
        int pivot=a[lb],start=lb,end=ub;
        while(start<end){
            while(a[start]<=pivot)
             start++;
            while(a[end]>pivot)
             end--;
            if(start<end)
             swap(a[start],a[end]);
        }
        swap(a[end],a[lb]);
        return end;
    }
}
void mergesortwhole(){
    void mergesort(int a[],int l,int r){
        int mid=(l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
    void merge(int arr[],int p,int q,int r){
        int n1=q-p-1;
        int n2=r-q;
        for(int i=0 ; i<n1 ; i++)
         l[i]=arr[p+i];
        for(int j=0 ; j<n2 ; j++)
         m[j]=arr[q+1+j];
        int i,j,k; i=0,j=0,k=p;
        while(i<n1 && j<n2){
            if(l[i]<m[j]){
                arr[k]=l[i];
                i++; k++;
            }
            else{
                arr[k]=m[j];
                k++; j++;
            }
        }
        while(i<n1){
            arr[k]=l[i];
            k++; i++;
        }
        while(j<n2){
            arr[k]=m[j];
            k++; j++;
        }
    }
}
void shellsort(){
    for(int gap=n/2 ; gap>=1 ; gap=gap/2){
        for(int i=gap ; j<n ; j++){
            for(int i=j-gap ; i>=0 ; i=i-gap){
                if(a[i+gap]>a[i])
                 break;
                else
                 swap(a[i+gap],a[i]);
            }
        }
    }
}
void radixsortwhole(){
    void radixsort(int a[],int n){
        int max=getmax(a);
        for(int place=1 ; max/place>=0 ; place*=10)
         countingsort(a,n,place);
    }
    void countingsort(int a[],int size,int place){
        int output[size],count[10];
        for(int i=0 ; i<size ; i++)
         count[(a[i]/place)%10]++;
        for(int i=1 ; i<10 ; i++)
         count[i]+=count[i-1];
        for(int i=size-1 ; i>=0 ; i--){
            output[count[(a[i]/place)%10]-1]=a[i];
            count[(a[i]/place)%10]--;
        }
        for(int i=0 ; i<size ; i++)
         a[i]=output[i];
    }
}
int main()
{
    printf("Hello World");

    return 0;
}
