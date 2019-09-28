#include <string>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

void merge(vector<string *> array, int l, int m, int r)
{
    int i, j, k;
    int firstHalfSize = m - l + 1;
    int secondHalfSize = r - m;

    string *L[firstHalfSize];
    string *R[secondHalfSize];

    for (i = 0; i < firstHalfSize; i++)
        L[i] = array[l + i];
    for (j = 0; j < secondHalfSize; j++)
        R[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < firstHalfSize && j < secondHalfSize)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < firstHalfSize)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < secondHalfSize)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<string *> array, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}