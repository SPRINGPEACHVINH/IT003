#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class point
{
public:
    int x, y;
    point() {}
    void nhap()
    {
        cin >> x >> y;
    }
    void xuat()
    {
        cout << x << " " << y << endl;
    }
};
bool comparePoints(const point &a, const point &b)
{
    if (a.x != b.x)
        return a.x < b.x;
    else
        return a.y > b.y;
}
int main()
{
    int n;
    cin >> n;
    vector<point> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].nhap();
    }
    cout << "==================" << endl;
    sort(arr.begin(), arr.end(), comparePoints); //hàm sort tự hiểu để điền điểm vào hàm comparePoints 
    for (int i = 0; i < n; i++)
    {
        arr[i].xuat();
    }
    return 0;
}