#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string shiftLeftBy(string word, int shiftLength) {
	string shifted = "";
	for (int i = (shiftLength % size(word)); i < size(word); i++) {
		shifted += word[i];
	}
	for (int i = 0; i < (shiftLength % size(word)); i++) {
		shifted += word[i];
	}
	return shifted;
}

string shiftRightBy(string word, int shiftLength) {
	string shifted = "";
	for (int i = word.size() - (shiftLength % size(word)) ; i < size(word); i++) {
		shifted += word[i];
	}
	for (int i = 0; i < word.size() - (shiftLength % size(word)); i++) {
		shifted += word[i];
	}
	return shifted;
}

string shiftLineBy(string line, int shiftLength) {
	int wordsSize = 0;
	line += ' ';
	for (int i = 0; i < line.size() - 1; i++) {
		if (line[i] != ' ' && line[i + 1] == ' ') wordsSize++;
	}
	int wordIndex = 0;
	string* words = new string[wordsSize];
	for (int i = 0; i < line.size() - 1; i++) {
		if (line[i] != ' ') words[wordIndex] += line[i];
		if (line[i] != ' ' && line[i + 1] == ' ') {
			wordIndex++;
		}	
	 }

	string shifted = "";
	for (int i = 0; i < wordsSize; i++) {
		shifted += shiftRightBy(words[i], shiftLength) + ' ';
		cout << endl << shiftRightBy(words[i], shiftLength) << endl;
	}
	
	return shifted;
}

void decode(ifstream& inTextFile, ofstream& outTextFile, int shiftLength) {
	if (!inTextFile.is_open()) {
		return;
	}
	else {
		string text = "", line = "";
		while (!inTextFile.eof()) {
			getline(inTextFile, line);
			outTextFile << shiftLineBy(line, shiftLength) << endl;
			line = "";
		}
		cout << endl << text << endl;
	}
	inTextFile.close();
	outTextFile.close();
}

int main()
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("text.txt");
	outFile.open("outText.txt");
	decode(inFile, outFile, 2);
}
