#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string temp = "";
	fstream Input;
	Input.open("input.txt", fstream::in | fstream::out | fstream::app);
	if (Input.is_open())
		while (getline(Input, temp))
		{

		}
	Input.close();

	vector <char> res;
	for (int i = 0; i < temp.size(); i++)
		res.push_back(temp[i]);


	int status = 1;
	while (status == 1)
	{
		status = 0;
		for (int i = 0; i < res.size() - 1; i++)
			if (res[i] == res[i + 1])
			{
				status = 1;
				res.erase(res.begin() + i + 1);
				res.erase(res.begin() + i);
				i++;
			}
	}

	fstream Output;
	Output.open("output.txt", fstream::in | fstream::out | fstream::app);
	if (Output.is_open())
		for (int i = 0; i < res.size(); i++)
			Output << res[i];


	Output.close();
}
