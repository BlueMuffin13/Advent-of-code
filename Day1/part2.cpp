#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	fstream file;
	file.open("input.txt");

	string temp;
	int currentElf = 0;
	vector<int> elves;

	while (!file.eof()) {
		getline(file, temp);
		if (temp == "") {	//separating elves by blank line
			elves.push_back(currentElf);	//saving current Elf's calorie value
			currentElf = 0;
		}
		else {
			currentElf += stoi(temp);		//adding food value
		}
	}

	sort(elves.begin(), elves.end(), greater<int>());	//sorting in descending order

	int maxThree = elves[0] + elves[1] + elves[2];		//adding three biggest values

	cout << "Three elves max calories: " << maxThree << "\n";

	file.close();

	return 0;
}