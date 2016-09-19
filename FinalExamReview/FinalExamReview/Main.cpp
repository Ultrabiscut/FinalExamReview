#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;



int main()
{
	ifstream inFile; //declare file object
	double ftemps[31]; //hold tempatures
	double dSum = 0; //hold accum
	double dAverage; //do the average
	double Biggest = INT_MIN;
	double Smallest = INT_MAX;
	int BigLoc, SmallLoc;
	int temp;

	//open file
	inFile.open("temps.txt");

	//read from the file
	for (int x = 0; x < 31; x++)
	{
		inFile >> temp; //read a temp

		ftemps[x] = ((temp * 9.0) / 5.0) + 32; //convert to Fahrn.
	}
	//close the file
	inFile.close();

	//preform average, high, and low algorithms/routines
	for (int x = 0; x < 31; x++)
	{
		dSum = dSum + ftemps[x]; //accumulation
	}
	//find the average
	dAverage = dSum / 31;

	//high/low routine
	for (int x = 0; x < 31; x++)
	{
		//check for big
		if (ftemps[x] > Biggest)
		{
			Biggest = ftemps[x]; //array value is new biggest
			BigLoc = x; //keep track of index of biggest
		}
		//check for smallest
		if (ftemps[x] < Smallest)
		{
			Smallest = ftemps[x]; //array value is new smallest
			SmallLoc = x; //keep track of index of smallest
		}
	}


	//output
	cout << fixed << setprecision(1);
	cout << "Average: " << dAverage << endl;
	cout << "Hottest: " << Biggest << " on March " << BigLoc + 1 << endl;
	cout << "Coolest: " << Smallest << " on March " << SmallLoc + 1 << endl;

	return 0;
}