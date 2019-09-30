#include <string>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

vector<string *> merge(vector<string *> firstHalf, vector<string *> secondHalf)
{
    vector<string *> result;

    while (!firstHalf.empty() && !secondHalf.empty())
    {
        string *x = firstHalf[0];
        string *y = secondHalf[0];

        // cout << "Comparing " << *x << " and " << *y << endl;

        if (*x <= *y)
        {
            result.push_back(x);
            firstHalf.erase(firstHalf.begin());
        }
        else
        {
            result.push_back(y);
            secondHalf.erase(secondHalf.begin());
        }
    }

    while (!firstHalf.empty())
    {
        // cout << "Pushing " << *firstHalf[0] << endl;
        result.push_back(firstHalf[0]);
        firstHalf.erase(firstHalf.begin());
    }

    while (!secondHalf.empty())
    {
        // cout << "Pushing " << *secondHalf[0] << endl;
        result.push_back(secondHalf[0]);
        secondHalf.erase(secondHalf.begin());
    }

    // cout << "Current Result: \n";
    // for (int j = 0; j < result.size(); j++)
    // {
    //     cout << j << " " << *result[j] << endl;
    // }
    // cout << endl;

    return result;
}

vector<string *> mergeSort(vector<string *> array, int l, int r)
{
    if (l < r)
    {
        int m = floor((l + r) / 2);
        vector<string *> firstHalf = mergeSort(array, l, m);

        // cout << "Current FirstHalf: \n";
        // for (int j = 0; j < firstHalf.size(); j++)
        // {
        //     cout << j << " " << *firstHalf[j] << endl;
        // }
        // cout << endl;

        vector<string *> secondHalf = mergeSort(array, m + 1, r);

        // cout << "Current SecondHalf: \n";
        // for (int j = 0; j < secondHalf.size(); j++)
        // {
        //     cout << j << " " << *secondHalf[j] << endl;
        // }
        // cout << endl;

        return merge(firstHalf, secondHalf);
    }

    vector<string *> firstHalf;
    firstHalf.push_back(array[l]);
    return firstHalf;
}