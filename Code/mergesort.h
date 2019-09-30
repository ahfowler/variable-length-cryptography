#include <string>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

void merge(vector<string *> array, int l, int m, int r)
{
    int i, j, k;
    int firstHalfSize = m - l + 1;
    int secondHalfSize = r - m;

    vector<string *> firstHalf;
    vector<string *> secondHalf;

    for (i = 0; i < firstHalfSize; i++)
        firstHalf.push_back(array[l + i]);
    for (j = 0; j < secondHalfSize; j++)
        secondHalf.push_back(array[m + 1 + j]);

    // firstHalf = A[l...m]
    cout << "firstHalf is ";
    for (i = 0; i < firstHalfSize; i++)
        cout << *firstHalf[i] << " ";
    cout << endl;
    // secondHalf = A[m+1...r]
    cout << "secondHalf is ";
    for (i = 0; i < secondHalfSize; i++)
        cout << *secondHalf[i] << " ";
    cout << endl;

    i = 0;
    j = 0;

    // while (i < firstHalfSize && j < secondHalfSize)
    // {
    //     if ((*firstHalf[i]) <= (*secondHalf[j]))
    //     {
    //         cout << (*firstHalf[i]) << " is less than " << (*secondHalf[j]) << " by " << (*firstHalf[i]).compare((*secondHalf[j])) << endl;
    //         array[k] = firstHalf[i];
    //         i++;
    //     }
    //     else
    //     {
    //         cout << (*firstHalf[i]) << " is greater than " << (*secondHalf[j]) << " by " << (*firstHalf[i]).compare((*secondHalf[j])) << endl;
    //         array[k] = secondHalf[j];
    //         j++;
    //     }
    //     k++;
    // }

    // while (i < firstHalfSize)
    // {
    //     array[k] = firstHalf[i];
    //     i++;
    //     k++;
    // }

    // while (j < secondHalfSize)
    // {
    //     array[k] = secondHalf[j];
    //     j++;
    //     k++;
    // }

    for (int k = l; k < r; k++)
    {
        if ((*firstHalf[i]) <= (*secondHalf[j]))
        {
            cout << (*firstHalf[i]) << " is less than " << (*secondHalf[j]) << " by " << (*firstHalf[i]).compare((*secondHalf[j])) << endl;
            array[k] = firstHalf[i];
            i++;
        }
        else
        {
            cout << (*firstHalf[i]) << " is greater than " << (*secondHalf[j]) << " by " << (*firstHalf[i]).compare((*secondHalf[j])) << endl;
            cout << "Inserting " << *secondHalf[j] << " at " << k << endl;
            array[k] = secondHalf[j];
            j++;
        }
    }

    firstHalf.clear();
    secondHalf.clear();
}

void mergeSort(vector<string *> array, int l, int r)
{
    if (l < r)
    {
        int m = floor((l + r) / 2);
        cout << "mid is " << floor((l + r) / 2) << endl;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        cout << "merging with " << l << " " << floor((l + r) / 2) << " " << r << endl;
        merge(array, l, m, r);
    }
}