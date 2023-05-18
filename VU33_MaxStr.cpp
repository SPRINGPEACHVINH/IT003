#include <bits/stdc++.h>
using namespace std;
void tong(string &key, int &sum, int count[])
{
    for (char c : key)
    {
        int digit = c - '0';
        count[digit]++;
        sum += c - '0';
    }
}
void erase(string key, int sum, int count[])
{
    if (sum % 3 == 1)
    {
        for (int i = 1; i <= 9; i += 3)
        {
            if (count[i] > 0)
            {
                count[i]--;
                sum -= i;
                break;
            }
        }
        if (sum % 3 == 1)
        {
            int dem = 0;
            for (int i = 2; i <= 8; i += 3)
            {
                while (count[i] > 0)
                {
                    count[i]--;
                    dem++;
                    sum -= i;
                    if (dem == 2)
                        break;
                }
                if (dem == 2)
                    break;
            }
        }
    }
    else if (sum % 3 == 2)
    {
        for (int i = 2; i <= 8; i += 3)
        {
            if (count[i] > 0)
            {
                count[i]--;
                sum -= i;
                break;
            }
        }
        if (sum % 3 == 2)
        {
            int dem = 0;
            for (int i = 1; i <= 7; i += 3)
            {
                while (count[i] > 0)
                {
                    count[i]--;
                    dem++;
                    sum -= i;
                    if (dem == 2)
                        break;
                }
                if (dem == 2)
                    break;
            }
        }
    }
    key.clear();
    for (int i = 9; i >= 0; i--)
    {
        key += string(count[i], '0' + i);
    }
    cout << key;
    return;
}
int main()
{
    string key;
    cin >> key;
    int sum = 0;
    int count[10] = {0};
    tong(key, sum, count);
    erase(key, sum, count);
}