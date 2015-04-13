// color your text in Windows console mode
// colors are 0=black 1=blue 2=green and so on to 15=white
// colorattribute = foreground + background * 16
// to get red text on yellow use 4 + 14*16 = 228
// light red on yellow would be 12 + 14*16 = 236
// a Dev-C++ tested console application by vegaseat 07nov2004

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std; // std::cout, std::cin

int main(int argc, char* argv[])
{
	HANDLE hConsole;
	int k;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	const auto OriginalColors = 7;

	if (argc <= 1) {
		// ** Echo empty line if we have no arguments
		cout << endl;
	}
	else if (argc == 2) {
		// ** No color specified.. Echo just the message as it is
		cout << argv[1];
	}
	else {
		// ** Assume we have a forground but no background character
		int color = stoi(argv[1]);

		SetConsoleTextAttribute(hConsole, color);

		// ** Echo all the test except the last one
		auto lcv = 2;
		for (lcv; lcv < argc - 1; lcv++)
			cout << argv[lcv] << ' '; // Add a space

		// ** Echo the last arg with an end of line
		cout << argv[lcv] << endl;

		// ** Shortcut to reset the color
		SetConsoleTextAttribute(hConsole, OriginalColors);		
	}

	return 0;
}
