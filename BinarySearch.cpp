#include <bits/stdc++.h>
using namespace std;
bool search(int a[], int n, int x) {
    int l=0, r=n-1;
    while(l<=r) {
        int mid= (l+r)/2;
        if(a[mid]==x) return true;
        else if(a[mid]<x) l=mid+1;
        else r=mid-1;
    }
    return false;
}
int main() {
    int n,q;
    cin>>n>>q;
    int a[n], b[q];
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0; i<q; i++) {
        cin>>b[i];
    }
    for(int i=0; i<q; i++) {
        if(search(a,n,b[i])) {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}