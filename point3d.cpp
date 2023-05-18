#include <bits/stdc++.h>
using namespace std;
class point3d
{
public:
    int x, y, z;
    void nhap()
    {
        cin >> x >> y >> z;
    }
    void xuat()
    {
        cout << x << " " << y << " " << z << '\n';
    }
};
bool comparePoints(const point3d &a, const point3d &b) 
{
    if (a.x != b.x)
        return a.x < b.x;
    else if (a.y != b.y)
        return a.y > b.y;
    else
        return a.z < b.z;
}
void sapxep(vector<point3d> &p, int n, int m)
{
    if (n >= m)
        return;
    point3d k = p[(n + m) / 2];
    int i = n, j = m;
    while (i <= j)
    {
        while (comparePoints(p[i], k))
            i++;
        while (comparePoints(k, p[j]))
            j--;
        if (i <= j)
        {
            swap(p[i], p[j]);
            i++;
            j--;
        }
    }
    sapxep(p, n, j);
    sapxep(p, i, m);
}
int main()
{
    int n;
    cin >> n;
    vector<point3d> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].nhap();
    }
    sapxep(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        arr[i].xuat();
    }
    return 0;
}