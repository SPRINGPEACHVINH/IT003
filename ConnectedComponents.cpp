#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> components(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        components[a].push_back(b);
        components[b].push_back(a);
    }

    int s;
    cin >> s;
    s--;
    vector<bool> visited(n, false);

    vector<int> queue;

    queue.push_back(s);

    visited[s] = true;
    while (!queue.empty())
    {
        int current = queue[0];

        queue.erase(queue.begin());

        for (int i = 0; i < components[current].size(); i++)
        {
            int connected = components[current][i];

            if (!visited[connected])
            {
                visited[connected] = true;

                queue.push_back(connected);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            count++;
        }
    }

    cout << count << endl;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            cout << i + 1 << " ";
        }
    }

    return 0;
}