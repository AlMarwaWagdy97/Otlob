#include<iostream>
#include<string>
#include <fstream>
#include <conio.h>
#include <vector>
#include"Header.h"
#include <windows.h>
#include <ctime>
#include <iomanip>
#include <time.h>
#pragma warning(disable:4996)
using namespace std;

int main()

{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

	
	Customer co;
	Admin ad;
	
	Person *p = &co;
	Person *p2 = &ad;
	SetConsoleTextAttribute(color, 14);
	cout << "Welcome\n";
	SetConsoleTextAttribute(color, 7);
	time_t Otime;
	const struct tm *nowlocal;
	time(&Otime);
	Otime = time(0);
	nowlocal = localtime(&Otime);
	cout << asctime(nowlocal);
	
	int shoose;
 	
		char choise;
		cout << "Enter your choice" << endl;
		cout << "Are you Customer / Admin 1:Admin ,2:Customer ";
		cin >> choise;
		if (choise == '1')
		{
			p2->login();
		}
		else if (choise == '2')
		{
			co.OfferResturant();
			co.gatagory();
			co.SelectResturant();
			co.MakeOrder();
			cout << "Do you want to do another opertion : ";
			string repl;
			cin >> repl;
			if (repl == "y")
			{
				string ree;
				cout << "1-delete order\n";
				cout << "2-make order \n";
				cin >> ree;
				if (ree == "1")
					co.deleteOrder();
				else if (ree == "2")
				{
					co.SelectResturant();
					co.MakeOrder();
				}
			}
			

		}
		else
		{
			cout << "Check your choise" << endl;
			
		}
			
	
	return 0;
}


