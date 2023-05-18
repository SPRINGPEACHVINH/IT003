#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main() {
    long n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    k%=n;
    vector <int> arr;
    for(int i=n-k; i<n; i++) {
        arr.push_back(a[i]);
    }
    for(int i=0; i<n-k; i++) {
        arr.push_back(a[i]);
    }
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
}