#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	// Check for sorting method:
	string sortingMethod;
	cin >> sortingMethod;
	if (sortingMethod == "insertion") {
		cout << "Insertion Sort\n";
	} else if (sortingMethod == "merge") {
		cout << "Merge Sort\n";
	} else {
		return -1;
	}
}