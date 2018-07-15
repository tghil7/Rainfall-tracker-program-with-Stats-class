// Chapter 8 - Programming Challenge 12, Stats Class and Rainfall Statistics
// This program revises Programming Challenge 8 to create and use a Stats class
// that contains general statistical functions. It will use it to store monthly
// rainfall data and to report rainfall statistics. The Stats class is defined
// in this same file as the client program that uses it. You may wish to have
// students use a separate file for the Stats class. 
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// **************  Place class declarations and implementation here ******************
class Stats
{
	private:
		//Declaration member variables
		double statArray[30];
		double count;


	 public:
		double total();
		double average();
		int lowest();
		int highest();
		bool storeValue();
};

double Stats::total() {

	for (int i = 0; i < sizeof(statArray); i++) {
		//Add the total rain volumes stored in the array
		while (statArray[i])
		{
			count += statArray[i];
		}
	}
   
	return count;
}

double Stats::average() {
	//Since the number of months = 12 as the user enters the monthly
	//rainfall data, the average with the total rainfall divided by 12
	return count / 12;
}

int Stats::lowest()
{
	int min = statArray[0];
	for (int i = 0; i < sizeof(statArray); i++) {
		//Add the total rain volumes stored in the array
		while (statArray[i])
		{
			if (statArray[i] < min)
			{
				min = statArray[i];
			}
		}
	}
   
		return min;

}

int Stats::highest()
{
		int max = statArray[0];
		for (int i = 0; i < sizeof(statArray); i++)
		{
			//Add the total rain volumes stored in the array
			while (statArray[i])
			{
				if (statArray[i] > max)
				{
					max = statArray[i];
				}
			}

			

		}

		return max;
}


//*************************** user program *****************************

// Function prototype
void storeData(Stats &);
void rainReport(const Stats &);

const int NUM_MONTHS = 12;         // The number of months of data 
								   // being input and analyzed

const string monthName[] = { "January",   "February",  "March",     "April",
"May",       "June",      "July",      "August",
"September", "October",   "November ", "December " };
int main()
{
	Stats rainfall;              // Create an instance of the Stats class
								 // to store and manage the rainfall data
	storeData(rainfall);
	rainReport(rainfall);

	return 0;
}

/***************************************************************
*                          storeData                          *
* Accepts inputs and sends them to the Stats object to store. *
***************************************************************/
void storeData(Stats &rainfall)
{
	double rain;

	for (int month = 0; month < NUM_MONTHS; month++)
	{	// Input and validate the montly rain amount
		cout << "Enter the rainfall (in inches) for " << monthName[month] << ": ";
		cin >> rain;

		while (rain < 0)
		{
			cout << "Rainfall must be 0 or more. Please re-enter: ";
			cin >> rain;
		}

		// Send it to the Stats object to store
		rainfall.storeValue(rain);
	}
}

/*************************************************************
*                        	rainReport                       *
* Displays a report of rainfall statistics.                 *
*************************************************************/
void rainReport(const Stats &rainfall)
{
	// Print a report heading
	cout << "\n    2015 Rain Report for NeverSnows County \n";

	// Display the total rainfall
	cout << fixed << showpoint << setprecision(2) << endl;
	cout << "Total rainfall: ";
	cout << rainfall.total() << " inches \n";

	// Display the average rainfall
	cout << "Average monthly rainfall: ";
	cout << rainfall.average() << " inches \n";

	// Display the smallest & largest amounts of monthly rain
	string lowMonth = monthName[rainfall.lowestIndex()];
	string highMonth = monthName[rainfall.highestIndex()];

	cout << "The least rain fell in " << lowMonth << " with "
		<< rainfall.lowest() << " inches. \n";
	cout << "The most rain fell in " << highMonth << " with "
		<< rainfall.highest() << " inches. \n";
}

/* SAMPLE RUN RESULTS

Enter the rainfall (in inches) for January: .78
Enter the rainfall (in inches) for February: .50
Enter the rainfall (in inches) for March: 2.6
Enter the rainfall (in inches) for April: 4.8
Enter the rainfall (in inches) for May: 4.5
Enter the rainfall (in inches) for June: 3.2
Enter the rainfall (in inches) for July: 1.1
Enter the rainfall (in inches) for August: .75
Enter the rainfall (in inches) for September: 1.7
Enter the rainfall (in inches) for October: 1.4
Enter the rainfall (in inches) for November: 2.1
Enter the rainfall (in inches) for December: .83

2015 Rain Report for NeverSnows County

Total rainfall: 24.26 inches
Average monthly rainfall: 2.02 inches
The least rain fell in February with 0.50 inches.
The most rain fell in April with 4.80 inches.
*/