#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    set<int> s;
    vector<int> v;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
        m[a[i]]++;
    }
    for (set<int>::iterator check = s.begin(); check != s.end(); check++)
    {
        v.push_back(*check);
        if (v.size() == k)
            break;
        m[*check]--;
    }
    if (v.size() < k)
    {
        for (set<int>::iterator check = s.begin(); check != s.end(); check++)
        {
            while (m[*check] >= 1)
            {
                v.push_back(*check);
                m[*check]--;
                if (v.size() == k)
                {
                    break;
                }
            }
            if (v.size() == k)
                break;
        }
    }
    sort(v.begin(), v.end());
    for (auto x : v)
    {
        cout << x << " ";
    }
}