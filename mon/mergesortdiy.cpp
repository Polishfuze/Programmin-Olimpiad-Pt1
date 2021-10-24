#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void merge(int **Arr, int p, int m, int size)
{
    int n1 = m - p + 1;
    int n2 = size - m;

    int **L;
    int **M;
    L = (int **)calloc(n1, sizeof(int *));
    M = (int **)calloc(n2, sizeof(int *));

    for (int i = 0; i < n1; i++)
    {
        L[i] = (int *)calloc(2, sizeof(int));
        L[i][0] = Arr[p + i][0];
        L[i][1] = Arr[p + i][1];
    }
    for (int j = 0; j < n2; j++)
    {
        M[j] = (int *)calloc(2, sizeof(int));
        M[j][0] = Arr[m + 1 + j][0];
        M[j][1] = Arr[m + 1 + j][1];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i][0] <= M[j][0])
        {
            Arr[k][0] = L[i][0];
            Arr[k][1] = L[i][1];
            i++;
        }
        else
        {
            Arr[k][0] = M[j][0];
            Arr[k][1] = M[j][1];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        Arr[k][0] = L[i][0];
        Arr[k][1] = L[i][1];
        i++;
        k++;
    }

    while (j < n2)
    {
        Arr[k][0] = M[j][0];
        Arr[k][1] = M[j][1];
        j++;
        k++;
    }
    for (int i = 0; i < n1; i++)
    {
        free(L[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        free(M[i]);
    }
    free(L);
    free(M);
}

void mergesort(int **Arr, int p, int size)
{
    if (p < size)
    {
        int m = p + int((size - 1) / 2);
        mergesort(Arr, p, m);
        mergesort(Arr, m + 1, size);
        merge(Arr, p, m, size);
    }
}

void printArray(int **Arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << Arr[i][0] << " " << Arr[i][1] << "\n";
    cout << endl;
}

int main(void)
{
    int a;
    cin >> a;

    int **arr1 = (int **)calloc(a, sizeof(int *));

    for (int i = 0; i < a; i++)
    {
        int n1, n2;
        arr1[i] = (int *)calloc(2, sizeof(int));
        cin >> n1;
        cin >> n2;
        arr1[i][0] = n1;
        arr1[i][1] = n2;
    }

    cout << "Unsorted arr:\n";

    printArray(arr1, a);

    mergesort(arr1, 0, a - 1);

    cout << "Sorted arr:\n";

    printArray(arr1, a);

    for (int i = 0; i < a; i++)
    {
        free(arr1[i]);
    }

    free(arr1);
    return 0;
}
