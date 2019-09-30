#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include "mergesort.h"
using namespace std;

int main(int argc, char *argv[])
{
	// Store sorting method:
	string sortingMethod = argv[1];

	string line;
	// For each line, we will do the following:
	while (getline(cin, line))
	{
		// Step 1: Perform Cyclic Shifts
		vector<string *> cyclicShifts; // Contains string pointers to each cyclic shift of the line.

		// Keep the original string for later:
		string originalString = line;
		// cout << "String: " << originalString << endl;

		int length = line.size();
		char shiftedLine[length];

		for (int i = 0; i < length; i++)
		{

			int j = i; // Index in line
			int k = 0; // Index in shiftedLine

			while (line[j] != '\0')
			{
				shiftedLine[k] = line[j];
				k++;
				j++;
			}

			j = 0;
			while (j < i)
			{
				shiftedLine[k] = line[j];
				j++;
				k++;
			}

			// Important: Remember to add termination character!
			shiftedLine[k] = '\0';

			// Push a new pointer to shiftedLine in cyclicShifts
			cyclicShifts.push_back(new string(shiftedLine));
		}

		// Step 2: Sorting the cyclic shifts.

		// Insertion Sorting Method
		if (sortingMethod == "insertion")
		{
			int i, j;
			string *comparisionLine;

			for (i = 1; i < cyclicShifts.size(); i++)
			{
				comparisionLine = cyclicShifts[i];

				j = i - 1;

				while (j >= 0 && *cyclicShifts[j] > *comparisionLine)
				{
					cyclicShifts[j + 1] = cyclicShifts[j];
					j = j - 1;
				}

				cyclicShifts[j + 1] = comparisionLine;
			}

			// cout << "Sorted Order:\n";
			// for (int j = 0; j < cyclicShifts.size(); j++)
			// {
			// 	cout << j << " " << *cyclicShifts[j] << endl;
			// }
			// cout << endl;
		}
		// Merge Sorting Algorithm
		else if (sortingMethod == "merge")
		{

			cout << "Current Order: \n";
			for (int j = 0; j < cyclicShifts.size(); j++)
			{
				cout << j << " " << *cyclicShifts[j] << endl;
			}
			cout << endl;

			mergeSort(cyclicShifts, 0, length - 1);

			cout << "Sorted Order:\n";
			for (int j = 0; j < cyclicShifts.size(); j++)
			{
				cout << j << " " << *cyclicShifts[j] << endl;
			}
			cout << endl;
		}
		else
		{
			return -1;
		}

		// Step 3: Find index of original string and create string with ending characters.
		int index;						// Index of original string.
		int endIndex = line.size() - 1; // Index of last letter of line.
		string last;					// String of the last letters of each cyclic shifted line.

		for (int k = 0; k < cyclicShifts.size(); k++)
		{
			// Finding the index of the original string.
			if (*cyclicShifts[k] == originalString)
			{
				index = k;
			}

			// Add the last character of the string to last.
			last.push_back((*cyclicShifts[k])[endIndex]);
		}

		// Step 4: Print index and find the clusters.
		// cout << "Answer:\n";
		cout << index << endl;

		char compareChar;  // The current character we are counting.
		char currentChar;  // The current character we are checking to see if it is a cluster with compareChar.
		int count = 0;	 // Size of cluster.
		int lastIndex = 0; // Index of the last string.

		while (lastIndex < last.size())
		{
			compareChar = last[lastIndex];
			currentChar = last[lastIndex + 1];

			// If the next character is part of the current cluster:
			if (compareChar == currentChar)
			{
				count += 1;
			}

			// Else, print out the cluser size and continue traversing through the string.
			else
			{
				if ((lastIndex + 1) == last.size())
				{
					count += 1;
					cout << count << " " << compareChar << endl;
				}
				else
				{
					count += 1;
					cout << count << " " << compareChar << " ";
					count = 0;
				}
			}
			lastIndex++;
		}

		// Special Case: It is just a blank line.
		if (count == 0)
		{
			cout << '\n';
		}

		// Step 5: Clear for next line
		cyclicShifts.clear();
		last.clear();
		index = 0;
		length = 0;
	}
}