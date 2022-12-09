#include <iostream>
#include "../headers/utility.h";

void readMap(std::string filePath, std::vector<std::vector<int>>& matrix) {
	std::string myText;
	std::ifstream myReadFile(filePath);
	while (std::getline(myReadFile, myText)) {
		// Output the text from the file
		std::vector<int> temp;
		std::string cell = "";
		for (int i = 0; i < myText.length(); i++) {
			if (myText[i] >= '0' && myText[i] <= '9') {
				cell += myText[i];
			} else if (myText[i] == ' ') {
				temp.push_back(std::stoi(cell));
				cell = "";
			}
		}
		if (cell != "") temp.push_back(std::stoi(cell));
		matrix.push_back(temp);
	}
}