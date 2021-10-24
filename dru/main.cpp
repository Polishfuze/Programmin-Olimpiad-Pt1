#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int amm, length;
    cin >> amm;
    cin >> length;
    char **arr;
    arr = (char **)malloc(amm * sizeof(char *));
    for (int i = 0; i < amm; ++i)
    {
        arr[i] = (char *)malloc(length * sizeof(char));
        cin >> arr[i];
    }
    cout << arr[0] << arr[2];
    return 0;
}
