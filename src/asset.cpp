#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>


Asset::Asset(string name)
{
	inFile.open(name, ios::in);
	
	if(!inFile)
	{
		cerr << "\nThe file could not be opened.\n";
	}
	
	while(getline(inFile,line))
	{
		
		stringstream check1(line);
		data.clear();
		
		while(getline(check1, inter, ','))
		{
			data.push_back(inter);
			cout << inter << endl;
		}
		
		if(data[0] == name)
			break;
	}

	data.erase(data.begin()); // The first element of the vector before the erase is the symbol name
}
string Asset::getAssetName()
{
	return assetName;
}
double Asset::getDayData(int dayNumber)
{
	return stod(data[dayNumber]);
}