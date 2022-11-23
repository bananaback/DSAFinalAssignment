#include <iostream>
#include "../headers/utility.h";

void readMap(std::string filePath, std::vector<std::vector<int>>& matrix) {
	std::string myText;
	std::ifstream myReadFile(filePath);
	if (!myReadFile.is_open()) std::cout << "Failed\n";
	while (std::getline(myReadFile, myText)) {
		// Output the text from the file
		//std::cout << myText << "\n";
		std::vector<int> temp;
		for (int i = 0; i < myText.length(); i++) {
			if (myText[i] >= '0' && myText[i] <= '9') {
				temp.push_back((int)myText[i] - 48);
			}
		}
		matrix.push_back(temp);
	}
}