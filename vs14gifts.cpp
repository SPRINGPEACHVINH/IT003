#include<iostream>
#include<algorithm>
using namespace std;
int max(long sum, long x) 
{   
    if (sum>=x) return sum;
    return x;
}
int main()
{   
    int n; 
    long a,cost=0;
    cin>>n>>a;
    int arr[n]; 
    for (int i=0; i<n; i++) 
    {
        cin>>arr[i];
    }
    sort(arr, arr+n); 
    int i=0, j=n-1; 
    while (i<j) {
        int sum=arr[i]+arr[j];
        if (sum<=a) 
        {   
            cost=max(cost,sum);
            i++;
        } 
        else j--;
    } 
    cout<<cost;
    return 0;
}