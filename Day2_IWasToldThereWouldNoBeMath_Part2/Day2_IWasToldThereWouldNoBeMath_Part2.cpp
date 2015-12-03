// Day2_IWasToldThereWouldNoBeMath_Part2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream file("WrapPaperList.txt");
	int total = 0;

	if (!file)
		cout << "Erreur ouverture fichier" << endl;
	else
	{
		string str_Line;

		while (getline(file, str_Line))
		{
			string str_l, str_w, str_h;
			int xPosition = 0;

			for (int i = 0; i < str_Line.size(); ++i)
			{
				if (str_Line[i] == 'x')
					++xPosition;
				else if (xPosition == 0)
					str_l += str_Line[i];
				else if (xPosition == 1)
					str_w += str_Line[i];
				else if (xPosition == 2)
					str_h += str_Line[i];
			}

			int il = stoi(str_l);
			int iw = stoi(str_w);
			int ih = stoi(str_h);

			int smallestPerimeter = 0;

			int perimeterSide1 = 2 * il + 2 * iw;
			smallestPerimeter = perimeterSide1;

			int perimeterSide2 = 2 * iw + 2 * ih;
			if (perimeterSide2 < smallestPerimeter)
				smallestPerimeter = perimeterSide2;

			int perimeterSide3 = 2 * ih + 2 * il;
			if (perimeterSide3 < smallestPerimeter)
				smallestPerimeter = perimeterSide3;

			total +=(il*iw*ih)  + smallestPerimeter;
		}
	}

	cout << "Total : " << total << endl;





	return 0;

}

