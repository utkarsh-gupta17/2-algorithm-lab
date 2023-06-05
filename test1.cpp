// C++ program to find groups of unknown
// Points using K nearest neighbour algorithm.
#include <bits/stdc++.h>
using namespace std;

struct Point
{
	int val;	 // Group of point
	double x, y;	 // Co-ordinate of point
	double distance; // Distance from test point
};

// Used to sort an array of points by increasing
// order of distance
bool comparison(Point a, Point b)
{
	return (a.distance < b.distance);
}

void insertionsort(Point a[],int n){
    int i,j;
    for(i=1 ; i<n ; i++){
        Point temp=a[i];
        j=i-1;
        while(j>=0 && a[j].distance>temp.distance){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

// This function finds classification of point p using
// k nearest neighbour algorithm. It assumes only two
// groups and returns 0 if p belongs to group 0, else
// 1 (belongs to group 1).
int classifyAPoint(Point arr[], int n, int k, Point p)
{
	// Fill distances of all points from p
    int ansarr[3];
    int centroidx0,centroidy0;
    int centroidx1,centroidy1;
	for (int i = 0; i < n; i++){
		arr[i].distance = sqrt((arr[i].x - p.x) * (arr[i].x - p.x) + (arr[i].y - p.y) * (arr[i].y - p.y));
        if(arr[i].val==0){
            centroidx0+=arr[i].x;
            centroidy0+=arr[i].y;
        }
        else{
            centroidx1+=arr[i].x;
            centroidy1+=arr[i].y; 
        }
    }
    centroidx0=centroidx0/2;
    centroidy0=centroidy0/2;
    centroidx1=centroidx1/2;
    centroidy1=centroidy1/2;
    int centdist0=sqrt((centroidx0 - p.x) * (centroidx0 - p.x) + (centroidy0 - p.y) * (centroidy0 - p.y));
    int centdist1=sqrt((centroidx1 - p.x) * (centroidx1 - p.x) + (centroidy1 - p.y) * (centroidy1 - p.y));
    int ans3=(centdist0 > centdist1 ? 1 : 0);

	// Sort the Points by distance from p
	// sort(arr, arr+n, comparison);
    insertionsort(arr,n);
    int ans1=arr[0].val;
    int maxdist0=INT_MIN;
    int maxdist1=INT_MIN;

	// Now consider the first k elements and only
	// two groups
	int freq1 = 0;	 // Frequency of group 0
	int freq2 = 0;	 // Frequency of group 1
	for (int i = 0; i < k; i++)
	{
		if (arr[i].val == 0){
            if(arr[i].distance>=maxdist0){
                maxdist0=arr[i].distance;
            }
			freq1++;
        }
		else if (arr[i].val == 1){
            if(arr[i].distance>=maxdist1){
                maxdist1=arr[i].distance;
            }
			freq2++;
        }
	}
    int ans2 = (maxdist0 > maxdist1 ? 1 : 0);
    int finalans;
    ansarr[0]=ans1;
    ansarr[1]=ans2;
    ansarr[2]=ans3;
    int frq0=0,frq1=0;
    for(int i=0 ; i<3 ; i++){
        if(ansarr[i]==0){
            frq0++;
        }
        else{
            frq1++;
        }
    }
	return (frq0 > frq1 ? 0 : 1);
}

// Driver code
int main()
{
	int n = 5; // Number of data points
	Point arr[n];

	arr[0].x = 100;
	arr[0].y = 25;
	arr[0].val = 0;

	arr[1].x = 20;
	arr[1].y = 90;
	arr[1].val = 1;

	arr[2].x = 95;
	arr[2].y = 15;
	arr[2].val = 0;

	arr[3].x = 25;
	arr[3].y = 110;
	arr[3].val = 1;

	/*Testing Point*/
	Point p;
    cout<<"enter the x coordinate for test point::";
    cin>>p.x;
    cout<<"enter the x coordinate for test point::";
    cin>>p.y;

	// Parameter to decide group of the testing point
	int k = 3;
    int result = classifyAPoint(arr, n, k, p);
    if(result==0){
        cout<<"The category classified to unknown point is Action.";
    }
    else{
        cout<<"The category classified to unknown point is Comedy. ";
    }
	// printf ("The value classified to unknown point"
	// 		" is %d.\n", classifyAPoint(arr, n, k, p));
	return 0;
}
