// Chapter 8 - Programming Challenge 12, Stats Class and Rainfall Statistics
// This program revises Programming Challenge 8 to create and use a Stats class
// that contains general statistical functions. It will use it to store monthly
// rainfall data and to report rainfall statistics. The Stats class is defined
// in this same file as the client program that uses it. You may wish to have
// students use a separate file for the Stats class. 
#include "stdafx.h"
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
		double count  = 0;
		double highestRain, lowestRain;
		int highIndex, lowIndex;
		int statCount, index = 0;



	 public:
		 //Since the function is called from a constant reference object,
		 //it can only get the total value that another function will calculate
		 double total() const {
			 return count;
		}

		 //Function that calculates the total
		 double setTotal() {
			 const int NUM_MONTHS = 12;
			 for (int i = 0; i < NUM_MONTHS; i++) {
				// cout << statArray[i] << endl;
				 //Add the total rain volumes stored in the array
					 count += statArray[i];	
					
			 }
			 //cout << "Total" << count << endl;

			 return count;
		}
		 
		 double average() const { return count/ 12; } //Returns the average rain level;

		 double lowest () const { return lowestRain; } //returns the lowest rain level
		 double highest() const { return highestRain; } //returns the highest rain level
		bool storeValue(double value); //Stores the value passed in the array

		//This function will find the lowest rain level
		double setLowest() {
			//Set the lowest rain level to the first element of the array by default;
			lowestRain = statArray[0];
			const int NUM_MONTHS = 12;
			for (int i = 0; i < NUM_MONTHS; i++) {
				//Loop through all the values in the array and compare with the default lowest in order to find the lowest				
					if (statArray[i] < lowestRain)
					{
						lowestRain = statArray[i];
						lowIndex = i;
					}
				
			}

			return lowestRain;
		}

		double setHighest() {

			highestRain = statArray[0];////Set the highest rain level to the first element of the array by default;
			const int NUM_MONTHS = 12;
			for (int i = 0; i < NUM_MONTHS; i++)
			{
				//Loop through all the values in the array and compare with the default highest in order to find the highest
					if (statArray[i] > highestRain)
					{
						highestRain = statArray[i];
						//Store the index of the highest value in the variable highIndex;
						highIndex = i;
					}




			}
			//We are looking for the highest number, so the function returns
			return highestRain;
		}

		int highestIndex() const { return highIndex; }//returns the index of the highest rain level in the array
		int lowestIndex() const { return lowIndex; } //returns the index of the lowest rain level in the array


};





bool Stats::storeValue(double value)
//Impementation of the storeValue function, which stores the value passed in the array
{

	if (statCount < 30 && static_cast<double>(value)) {
		statArray[index] = value; //stores the value in the array and increments the index;
		index++;
		statCount++;
		return true;
		
	}

	else //if the value cannot be store return false;
		return false;

	
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
	rainfall.setTotal(); //Calculate the total amount of rain
	rainfall.setHighest();//Find the highest rain level to include on the report
	rainfall.setLowest(); //Find the lowest rain level to include on the report
	rainReport(rainfall);//Generate the report. 

	return 0;
}

/***************************************************************
*                          storeData                          *
* Accepts inputs and sends them to the Stats object to store. *
***************************************************************/
void storeData( Stats &rainfall)
{
	double rain;

	for (int month = 0; month < NUM_MONTHS; month++)
	{	// Input and validate the monthly rain amount
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