// color your text in Windows console mode
// colors are 0=black 1=blue 2=green and so on to 15=white
// colorattribute = foreground + background * 16
// to get red text on yellow use 4 + 14*16 = 228
// light red on yellow would be 12 + 14*16 = 236
// a Dev-C++ tested console application by vegaseat 07nov2004

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <wincon.h>
#include <windows.h> // WinApi header

using namespace std; // std::cout, std::cin

int main(int argc, char* argv[])
{
	HANDLE hConsole;
	int k;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);		

	if (argc <= 1) {
		// ** Echo empty line if we have no arguments
		cout << endl;
	}
	else if (argc == 2) {
		// ** Echo just the message as it is
		cout << argv[0];
	}
	else if (argc == 3) {		
		// ** Assume we have a forground but no background character
		int color = stoi(argv[1]);

		SetConsoleTextAttribute(hConsole, color);
				
		cout << argv[2];
	}
	else {
		// ** Assume we have a forground but no background character
		int color = stoi(argv[1]);
		
		// ** Combine all remaining characters		
		//stringstream ss;
		//for (auto lcv = 2; lcv < argc; lcv++) {
		//	ss << " " << argv[lcv];
		//}

		SetConsoleTextAttribute(hConsole, color);
		
		//system("color 0" + foregroundColor);
		//cout << ss.str();

		for (auto lcv = 2; lcv < argc; lcv++) {
			cout << " " << argv[lcv];
		}
	}

	return 0;
}
