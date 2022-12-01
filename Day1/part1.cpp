#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	fstream file;
	file.open("input.txt");

	string temp;
	int currentElf = 0, max = 0;

	while (!file.eof()) {
		getline(file, temp);
		if (temp == "") {	//separating elves by blank line
			// finding max if counting for current Elf ended
			if (currentElf > max) {
				max = currentElf;
			}
			currentElf = 0;
		}
		else {
			currentElf += stoi(temp);		//adding food value
		}
	}

	cout << "Max calories: " << max << "\n";

	file.close();

	return 0;
}