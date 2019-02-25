#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

int main()
{

	// Define variables
	double erd, lso, rso, lfd, rfd, clf, crf, shd;
	int nos, lnoc, rnoc;
	char redo;
	double llength, rlength;

	// Define some colors to make our output more interesting
	string textInput = "\033[1;36m";
	string textOutput = "\033[1;32m";
	string textError = "\033[1;31m";
	string textNormal = "\033[0m";

	// Default strings
	string inputTypeErrorMsg = textError + "Input must be a postive numerical value\n" + textNormal;
	string leftInputText = textInput + "    Left: " + textNormal;
	string rightInputText = textInput + "    Right: " + textNormal;

	// Give variables some default values
	lso = 0;
	rso = 0;
	shd = 2.5;

	// Start program
	cout << string(5, '\n');
	cout << "-----------------------------------------------------------------\n";
	cout << R"(-------------------------       __o     -------------------------)" << "\n";
	cout << R"(-------------------------     _ \<_     -------------------------)" << "\n";
	cout << R"(-------------------------    (_)/(_)    -------------------------)" << "\n";
	cout << "-----------------------------------------------------------------\n";
	cout << "---------------- Bicycle Spoke Length Calculator ----------------\n";
	cout << "---------------- version 0.1.0 ----------------------------------\n";
	cout << "---------------- Written by: Matt Barron ------------------------\n";
	cout << "-----------------------------------------------------------------\n";
	cout << endl;

	// Print disclaimer
	cout << textError;
	cout << "          Use at own risk! Please take the time to ensure\n";
	cout << "        that all your hub and rim measurements are acurrate.\n";
	cout << "          All measurements must be in millimeters (mm).\n";
	cout << textNormal;

	cout << string(5, '\n');


	// Loop so program can be re run without exiting
	do
	{

		// Input effective rim diameter
		erd = 0;
		string erdInputText = textInput + "Effective Rim Diameter (ERD): " + textNormal;

		cout << erdInputText;
		cin >> erd;

		// Validate erd
		while (erd == 0) {
			if (cin.fail() || isnan(erd)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl << inputTypeErrorMsg;
				cout << erdInputText;
				cin >> erd;
			}
		}

		while (erd <= 100.00 || erd >= 699.99) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << textError << "ERD must be a value between 100 and 700\n" << textNormal;
			cout << erdInputText;
			cin >> erd;
		}

		cout << endl;

		// Input left and right hub flange diameters
		lfd = 0;
		rfd = 0;
		string hfdInputText = textInput + "Hub Flange Diameter\n" + textNormal;
		cout << hfdInputText << leftInputText;
		cin >> lfd;

		// Validate lfd
		while (lfd == 0) {
			if (cin.fail() || isnan(lfd)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl << inputTypeErrorMsg;
				cout << hfdInputText << leftInputText;
				cin >> lfd;
			}
		}

		cout << rightInputText;
		cin >> rfd;

		// Validate rfd
		while (rfd == 0) {
			if (cin.fail() || isnan(rfd)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl << inputTypeErrorMsg;
				cout << hfdInputText << rightInputText;
				cin >> rfd;
			}
		}

		cout << endl;

		// Input left and right hub-center-to-flange measurements
		clf = 0;
		crf = 0;
		string hcfInputText = textInput + "Hub Center to Flange Distance\n" + textNormal;

		cout << hcfInputText << leftInputText;
		cin >> clf;

		// Validate clf
		while (clf == 0) {
			if (cin.fail() || isnan(clf)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl << inputTypeErrorMsg;
				cout << hcfInputText << leftInputText;
				cin >> clf;
			}
		}

		cout << rightInputText;
		cin >> crf;

		// Validate crf
		while (crf == 0) {
			if (cin.fail() || isnan(crf)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl << inputTypeErrorMsg;
				cout << hcfInputText << rightInputText;
				cin >> crf;
			}
		}

		cout << endl;

		// Input number of spokes
		nos = 0;
		string nosInputText = textInput + "Number of Spokes: " + textNormal;
		cout << nosInputText;
		cin >> nos;
		cout << endl;

		// Validate nos
		while (nos == 0) {
			if (cin.fail() || isnan(nos)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl << inputTypeErrorMsg;
				cout << nosInputText;
				cin >> nos;
			}
		}
		while ((0 + nos) % 4 != 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << textError << "Number of spokes must be a multipe of 4 (eg. 28, 32, 36)\n" << textNormal;
			cout << nosInputText;
			cin >> nos;
		}

		cout << endl;

		// Input number of spoke crosses
		lnoc = 0;
		rnoc = 0;
		string nocInputText = textInput + "Number of Spoke Crosses\n" + textNormal;
		cout << nocInputText;
		cout << leftInputText;
		cin >> lnoc;

		// Validate lnoc
		while (lnoc == 0) {
			if (cin.fail() || isnan(lnoc)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl << inputTypeErrorMsg;
				cout << nocInputText << leftInputText;
				cin >> lnoc;
			}
		}

		cout << rightInputText;
		cin >> rnoc;

		// Validate rnoc
		while (rnoc == 0) {
			if (cin.fail() || isnan(rnoc)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl << inputTypeErrorMsg;
				cout << nocInputText << rightInputText;
				cin >> rnoc;
			}
		}
		cout << endl;


		// Caclulate left side spoke length
		llength = -(shd / 2) + 0.998 * sqrt((pow(erd, 2) / 4) + (pow(lfd, 2) / 4) - (erd * lfd / 2 * cos(4 * M_PI * lnoc / nos )) + pow((clf + lso), 2)) + 0.5;

		// Calculate right side spoke length
		rlength = -(shd / 2) + 0.998 * sqrt((pow(erd, 2) / 4) + (pow(rfd, 2) / 4) - (erd * rfd / 2 * cos(4 * M_PI * rnoc / nos )) + pow((crf + rso), 2)) + 0.5;


		// Print out results
		cout << "-----------------------------------------------------------------\n";
		cout << "-------------------------- Results ------------------------------\n";
		cout << "-----------------------------------------------------------------\n";
		cout << endl;
		cout << textOutput << "Left Spoke Length:  "  << textNormal << llength << endl;
		cout << textOutput << "Right Spoke Length: "  << textNormal << rlength << endl;
		cout << endl;

		// Ask to run caclulator again before exiting
		cout << "Do you wish to caclulate spoke length for another wheel? (Y/n): ";
		cin >> redo;
		cout << endl << endl;

	} while (redo == 'y' || redo == 'Y');

	return 0;
}
