#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	// Check for sorting method
	string sortingMethod;
	cin >> sortingMethod;
	cin.ignore();

	// For each line, we will do the following:

	// Step 1: Perform Cyclic Shifts
	string line;

	while (getline(cin, line))
	{
		vector<string> cyclicShifts;

		// Keep original string.
		string originalString = line;
		cout << "String: " << originalString << endl;

		// Generate all rotations one by one and print
		// Shift letters in line.
		int len = line.size();
		char temp[len];
		for (int i = 0; i < len; i++)
		{
			int j = i; // Current index in line
			int k = 0; // Current index in temp

			while (line[j] != '\0')
			{
				temp[k] = line[j];
				k++;
				j++;
			}

			j = 0;
			while (j < i)
			{
				temp[k] = line[j];
				j++;
				k++;
			}

			temp[k] = '\0';

			cyclicShifts.push_back(temp);
			
		}

		cout << "Current Order:\n";
		for (int j = 0; j < cyclicShifts.size(); j++)
		{
			cout << j << " " << cyclicShifts[j] << endl;
		}
		cout << endl;

		// Step 2: Sorting the cyclic shifts.
		if (sortingMethod == "insertion")
		{
			int i, j;
			string key;

			for (i = 1; i < cyclicShifts.size(); i++)
			{
				key = cyclicShifts[i];
				j = i - 1;

				while (j >= 0 && cyclicShifts[j] > key)
				{
					cyclicShifts[j + 1] = cyclicShifts[j];
					j = j - 1;
				}
				cyclicShifts[j + 1] = key;
			}

			cout << "Sorted Order:\n";
			for (int j = 0; j < cyclicShifts.size(); j++)
			{
				cout << j << " " << cyclicShifts[j] << endl;
			}
			cout << endl;
		}
		else if (sortingMethod == "merge")
		{
			// Merge Sort Algorithm
		}
		else
		{
			return -1;
		}

		// Step 3: Find index of original string and create string with ending characters.
		int index;
		int endIndex = line.size() - 1;
		string last;

		for (int k = 0; k < cyclicShifts.size(); k++)
		{
			if (cyclicShifts[k] == originalString)
			{
				index = k;
			}

			last.push_back(cyclicShifts[k][endIndex]);
		}

		// Step 4: Print index and find the clusters.
		cout << "Answer:\n";
		cout << index << endl;

		char compareChar, currentChar;
		int count = 1;
		int lastIndex = 0;

		while (lastIndex < last.size())
		{
			compareChar = last[lastIndex];
			currentChar = last[lastIndex + 1];
			if (compareChar == currentChar)
			{
				count += 1;
			}
			else
			{
				if ((lastIndex + 1) == last.size())
				{
					cout << count << " " << compareChar << endl;
				}
				else
				{
					cout << count << " " << compareChar << " ";
					count = 1;
				}
			}
			lastIndex++;
		}

		// Step 5: Clear for next line
		cyclicShifts.clear();
		last.clear();
		index = 0;
		len = 0;
	}
}