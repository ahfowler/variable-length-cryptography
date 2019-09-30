#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <sstream>
#include "mergesort.h"

using namespace std;

bool inNext(int next[], int value, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (next[i] == value)
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    // Store sorting method:
    string sortingMethod = argv[1];

    string indexString;
    while (getline(cin, indexString))
    {
        int index = stoi(indexString);

        // Step 2: Generate last string.
        string last, first;
        int count;
        char letter;
        string encodedLine;
        getline(cin, encodedLine);
        stringstream ss(encodedLine);
        // cout << encodedLine << endl;
        // cout << encodedLine.size() << endl;

        for (int i = 2; i < encodedLine.size(); i += 4)
        {
            ss >> count;
            ss.get();
            letter = ss.get();

            // cout << "Count: " << count << endl;
            // cout << "Letter: " << letter << endl;
            for (int j = 0; j < count; j++)
            {
                last.push_back(letter);
            }
        }

        // cout << "Exited with: " << count << endl;

        // Step 3: Sort the last string and store into the first string.
        if (sortingMethod == "insertion")
        {
            int i, j;
            string lastHolder;
            lastHolder.assign(last);
            string comparisionLetter;

            for (i = 1; i < last.size(); i++)
            {
                comparisionLetter = last[i];

                j = i - 1;

                while (j >= 0 && last[j] > comparisionLetter[0])
                {
                    last[j + 1] = last[j];
                    j = j - 1;
                }

                last[j + 1] = comparisionLetter[0];
            }

            first.assign(last);
            last.assign(lastHolder);
        }
        else if (sortingMethod == "merge")
        {
            // Sort last with merge.
        }
        else
        {
            return -1;
        }

        // Step 4: Generate the next array.
        int i, j;
        int k = 0;
        int next[last.size()];
        fill_n(next, last.size(), -1);
        char currentLetter;

        for (i = 0; i < first.size(); i++)
        {
            for (j = 0; j < last.size(); j++)
            {
                if (last[j] == first[i] && !inNext(next, j, first.size()))
                {
                    next[i] = j;
                    break;
                }
            }
        }

        // Step 5: Construct the original string.
        int x = next[index];
        string originalString;
        for (i = 0; i < first.size(); i++)
        {
            originalString.push_back(last[x]);
            x = next[x];
        }
        originalString.push_back('\n');
        cout << originalString;
    }
}
