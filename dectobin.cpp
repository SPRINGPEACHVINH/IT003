#include <iostream>
using namespace std;
void dectobin(long long n, int s[], int &h)
{
    for (int i = 31; i >= 0; i--)
    {
        int k = n >> i;
        if (k & 1)
            s[i] = 1;
    }
    int i = 31;
    while (s[i] == 0)
    {
        h--;
        i--;
    }
    return;
}
int main()
{
    long long n;
    cin >> n;
    int h = 32;
    int s[h] = {0};
    dectobin(n, s, h);
    for(int i=h-1; i>=0; i--) {
        cout<<s[i];
    }
}