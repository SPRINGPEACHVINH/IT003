#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
    int m,n;
    cin>>n>>m;
    int a[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>a[i][j];
        }
    }
    int minOreLeft = INT_MAX;
    int minOreLeftX = -1;
    int minOreLeftY = -1;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < m - 2; j++)
        {
            int oreLeft = 0;
            for (int x = i; x < i + 3; x++)
            {
                for (int y = j; y < j + 3; y++)
                {
                    oreLeft += a[x][y];
                }
            }
            if (oreLeft < minOreLeft)
            {
                minOreLeft = oreLeft;
                minOreLeftX = i;
                minOreLeftY = j;
            }
        }
    }
    cout<<minOreLeft<<endl;
}