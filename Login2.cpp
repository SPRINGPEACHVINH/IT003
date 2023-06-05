#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<string> user;
    user.resize(q);
    map<string, string> database;

    for (int i = 1; i <= n; i++)
    {
        string username, password;
        cin >> username >> password;
        auto it = database.find(username);
        if (it != database.end())
        {
            it->second = it->second + " " + password;
        }
        else
        {
            database.insert(make_pair(username, password));
        }
    }

    for (int i = 0; i < user.size(); i++)
    {
        cin >> user[i];
    }

    for (int i = 0; i < user.size(); i++)
    {
        auto it = database.find(user[i]);
        if (it != database.end())
        {
            cout << it->second << "\n";
        }
        else
        {
            cout << "Chua Dang Ky!"
                 << "\n";
        }
    }
}