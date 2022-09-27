#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>

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

void lab1() {
	ifstream inFile;
	ofstream outFile;
	inFile.open("text.txt");
	outFile.open("outText.txt");
	decode(inFile, outFile, 2);
}

//lab222222222222222222222222

vector<int> getVector(ifstream& inTextFile) {

	vector<int> vec;
	if (!inTextFile.is_open()) {
		return vec;
	}
	else {
		
		int size = 0;
		string str;
		getline(inTextFile, str);
		size = stoi(str);
		while (!inTextFile.eof()) {
			str = "";
			inTextFile >> str;
			vec.push_back(stoi(str));
		}
	}
	inTextFile.close();
	return vec;
}


vector<int> sum(vector<vector<int>>& result, const vector<int>& v, int index, vector<int> curComb)
{
	if (index < v.size())
	{
		curComb.push_back(v[index]);
		for (int i = index + 1; i < v.size(); ++i)
		{
			vector<int> res = sum(result, v, i, curComb);
			result.push_back(res);
		}
	}
	return curComb;
}

int sumVector(vector<int> vec) {
	int sum = 0;
	for (auto it = vec.begin(); it != vec.end(); it++) {
		sum += *it;
	}
	return sum;
}

void lab2() {
	ifstream inFile;
	ofstream outFile;
	inFile.open("input2.txt");
	outFile.open("output2.txt");
	
	int count = 0;
	vector<int> v = getVector(inFile);
	int n = v.size();
	v.resize(n);

	vector<vector<int>> combs;
	for (int i = 0; i < v.size(); ++i)
	{
		vector<int> vec;
		vector<int> res = sum(combs, v, i, vec);
		combs.push_back(res);
	}

	for (int i = 0; i < combs.size(); i++) {
		if (sumVector(combs[i]) % n == 0) {
			count++;
		}	
	}
	if (count == 0) {
		outFile << "NO" << endl;
	}
	else {
		outFile << "\n---------\nYES\n---------\n";
		outFile << endl << count << endl;

		for (int i = 0; i < combs.size(); i++) {
			if (sumVector(combs[i]) % n == 0) {
				for (int j = 0; j < combs[i].size(); j++) {
					outFile << combs[i][j] << "  ";
				}
				outFile << endl;
			}			
		}
	}
}

//lab33333333333333333333333333

void generateGrayCodes(int n, ofstream& outFile) {
	for (int k = (1 << n) - 1; k >= 0; k--) {
		int s = k ^ (k >> 1);
		for (int i = 0; i < n; i++) outFile << ((s >> i) & 1);
		outFile << endl;
	}
}
void lab3() {
	ofstream outFile;
	outFile.open("output3.txt");
	int n = 0;
	cout << "n = ";
	cin >> n;
	generateGrayCodes(n, outFile);

}

int main()
{
	lab3();
	
}
