#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int n, t, d = 0;
    cin >> n;
    // cout << "Ok" << n << "\n";
    int *films;
    films = (int *)calloc(n * 2, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        cin >> d;
        if (d >= t)
        {
            films[2 * i] = t;
            films[2 * i + 1] = d;
            // cout << "OK: " << t << " " << d << "\n";
        }
    }
    // cout << "Read ok!\n";

    for (int i = 0; i < n * 2; i++)
    {
        cout << films[i] << "\n";
    }
}