#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

int main()
{

	// Define variables
	double erd, lso, rso, lfd, rfd, clf, crf, shd, nos, lnoc, rnoc;
	char redo;
	double llength, rlength;

	// Give variables some default values
	lso = 0;
	rso = 0;
	shd = 2.5;

	// Display bicycle asci art

	cout << string(5, '\n');


	// Start program
	cout << string(5, '\n');
	cout << "-----------------------------------------------------------------\n";
	cout << R"(-------------------------       __o     -------------------------)" << "\n";
	cout << R"(-------------------------     _ \<_     -------------------------)" << "\n";
	cout << R"(-------------------------    (_)/(_)    -------------------------)" << "\n";
	cout << "-----------------------------------------------------------------\n";
	cout << "---------------- Bicycle Spoke Length Calculator ----------------\n";
	cout << "---------------- version 1.0.0 ----------------------------------\n";
	cout << "---------------- Written by: Matt Barron ------------------------\n";
	cout << "-----------------------------------------------------------------\n";
	cout << endl;
	cout << string(5, '\n');

	// Loop so program can be re run without exiting
	do
	{

		// Input effective rim diameter
		erd = 0;

		cout << "Effective Rim Diameter: ";
		cin >> erd;
		cout << endl;


		// Validate erd
		while (erd == 0) {
			if (cin.fail() || isnan(erd)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl << "Input must be a postive numerical value\n";
				cout << "Effective Rim Diameter: ";
				cin >> erd;
				cout << endl;
			}
		}

		// Input left and right hub flange diameters
		lfd = 0;
		rfd = 0;

		cout << "Hub Flange Diameter\n";
		cout << "Left: ";
		cin >> lfd;

		// Validate lfd
		while (lfd == 0) {
			if (cin.fail() || isnan(lfd)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl << "Input must be a postive numerical value\n";
				cout << "Left: ";
				cin >> lfd;
				cout << endl;
			}
		}

		cout << "Right: ";
		cin >> rfd;

		// Validate rfd
		while (rfd == 0) {
			if (cin.fail() || isnan(rfd)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl << "Input must be a postive numerical value\n";
				cout << "Right: ";
				cin >> rfd;
				cout << endl;
			}
		}

		cout << endl;

		// Input left and right hub-center-to-flange measurements
		clf = 0;
		crf = 0;

		cout << "Hub Center to Flange Distance\n";

		cout << "Left: ";
		cin >> clf;

		// Validate clf
		while (clf == 0) {
			if (cin.fail() || isnan(clf)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl << "Input must be a postive numerical value\n";
				cout << "Left: ";
				cin >> clf;
				cout << endl;
			}
		}

		cout << "Right: ";
		cin >> crf;

		// Validate crf
		while (crf == 0) {
			if (cin.fail() || isnan(crf)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl << "Input must be a postive numerical value\n";
				cout << "Right: ";
				cin >> crf;
				cout << endl;
			}
		}

		cout << endl;

		// Input number of spokes
		cout << "Number of Spokes: ";
		cin >> nos;
		cout << endl;

		// Input number of spoke crosses
		cout << "Number of Spoke Crosses\n";
		cout << "Left: ";
		cin >> lnoc;

		cout << "Right: ";
		cin >> rnoc;
		cout << endl;

		// Input Hub Spoke Hole Diameter
		cout << "Hub Spoke Hole Diameter (default = 2.5mm): ";
		cin >> shd;
		cout << endl;

		// Caclulate left side spoke length
		llength = -(shd / 2) + 0.998 * sqrt((pow(erd, 2) / 4) + (pow(lfd, 2) / 4) - (erd * lfd / 2 * cos(4 * M_PI * lnoc / nos )) + pow((clf + lso), 2)) + 0.5;

		// Calculate right side spoke length
		rlength = -(shd / 2) + 0.998 * sqrt((pow(erd, 2) / 4) + (pow(rfd, 2) / 4) - (erd * rfd / 2 * cos(4 * M_PI * rnoc / nos )) + pow((crf + rso), 2)) + 0.5;


		// Print out results
		cout << "-------------------------------------------------------------\n";
		cout << "--- Results -------------------------------------------------\n";
		cout << "-------------------------------------------------------------\n";
		cout << endl;
		cout << "Left Spoke Length:  " << llength << endl;
		cout << "Right Spoke Length: " << rlength << endl;
		cout << endl;

		// Ask to run caclulator again before exiting
		cout << "Do you wish to caclulate spoke length for another wheel? (Y/n): ";
		cin >> redo;
		cout << endl << endl;

	} while (redo == 'y' || redo == 'Y');

	return 0;
}
