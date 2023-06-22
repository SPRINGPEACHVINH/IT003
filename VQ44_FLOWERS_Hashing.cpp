#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

vector<int> get_ans(const vector<int> &A, int K)
{
    map<int, int> Hash;
    vector<int> ans;
    int index = 1;
    for (int i = 0; i < n; i++)
    {
        auto it = Hash.find(a[i]);
        if (it != Hash.end())
        {
            int temp = it->first;
            temp++;
            Hash.erase(it);
            Hash.insert(make_pair(temp, A[i]));
        }
        else
            Hash.insert(make_pair(index, A[i]));
    }
    int num = Hash.size();
    if (k > num)
    {
        for (int i = 0; i < num; i++)
        {
            auto it = Hash.begin();
            ans.push_back(it->second);
            Hash.erase(it);
        }
        for (int i = k - num; i < k; i++)
        {
            ans.push_back(Hash.begin()->second);
        }
    }
    else if (k == num)
    {
        for (int i = 0; i < num; i++)
        {
            auto it = Hash.begin();
            ans.push_back(it->second);
            Hash.erase(it);
        }
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            auto it = Hash.begin();
            ans.push_back(it->second);
            Hash.erase(it);
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> ans = get_ans(a, k);

    for (const int &x : ans)
        cout << x << ' ';
    return 0;
}
