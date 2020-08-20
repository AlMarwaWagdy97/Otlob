#include<iostream>

#include"Header.h"
#include <fstream>
#include <ostream>
#include <vector>
#include <set>
#include <string>
#include <iterator>
#include <windows.h>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <algorithm>

using namespace std;



HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
string city_temp;
string replay;
string rest_temp;
//time_t Otime;
//struct tm nowlocal;
time_t Otime = time(0);
struct tm *nowlocal = localtime(&Otime);
//time_t Otime1 = time(0);
//struct tm nowlocal1 = *localtime(&Otime1);
int t_h;
int t_m;
int t_s;
Resturant::Resturant()
{
	Rate = 0;
	name = "";
	Place = "";
	TypeofFood ="";
}
void Customer::customerRegister()
{
	SetConsoleTextAttribute(color, 13);

	fstream usersFile("userData.txt", ios::in | ios::out | ios::app);
		if (!usersFile.is_open())
		{
			usersFile.open("userData.txt");
		}
		cout << "Please enter your username" << endl;
		cin >> UserName;
		cout << "Please enter your Phone" << endl;
		cin >> phone;
		cout << "Please enter your Birthday" << endl;
		cin >> Birthday;
		cout << "Please enter your  Email" << endl;
		cin >> Email;
		cout << "Please enter your Password" << endl;
		cin >> Password;
		
		usersFile << UserName << " " << phone << " " << Birthday << " " << Email << " " << Password<<endl ;

		usersFile.close();
}

void Customer::login()
{
	SetConsoleTextAttribute(color, 11);

	 try
    {
		ifstream infile("userData.txt");
		string username, pass;
		int count = 0;
		cout << "Enter your username \n";
		cin >> username;
		cout << "Enter your Password \n";
		cin >> pass;
		SetConsoleTextAttribute(color, 10);
	    if (infile.is_open())
	   {
		  while (!infile.eof())
		    { //بيقارن كل اسم وبسورد داخله بالى موجود جوة الفايل
			  infile >> UserName >> phone >> Birthday >> Email >> Password;
			  if (username == UserName&& pass == Password)
			  {
				user_temp = username;
				name2_temp = username;
				count++;
			  }

		   }
		if (count > 0)
			cout << "Welcome in our system\n";
		else
		{
			int n;
			cout << "Invalid username or password \n";
			cout << "1-To try again \n 2-Register \n";
			cin >> n;
			if (n == 1)
				login();
			else if (n == 2)
				customerRegister();
		}
			

	}
	}
	 catch (...)
	 {
		 cout << "The file does not exist \n ";

	 }
}


void Customer::SelectResturant()
{
	SetConsoleTextAttribute(color, 7);

	ifstream infile("Places.txt");
	ifstream in ("Resturant.txt");
	string govee, cityy,rest,ratee,food,delv,cityy2;
	// vector for governate in file places
	vector<string> gov;
	// vector for city in file places
	vector<string> city;
	// vector for city,resturant name,rate,type of food and delivery time  in file resturant
	vector<string> city2;
	vector<string> res;
	vector<string> rat;
	vector<string> foode;
	vector<string> delivery;

	// read from places file and put in vectors
	while (!infile.eof())
	{
		infile >> govee;
	  gov.push_back(govee);
	  infile >> cityy;
	  city.push_back(cityy);
	}
	// read from resturant file and put in vectors
	while (!in.eof())
	{
		in >> cityy2;
		city2.push_back(cityy2);
		in >> rest;
		res.push_back(rest);
		in >> ratee ;
		rat.push_back(ratee);
		in >> food;
		foode.push_back(food);
		in >> delv;
		delivery.push_back(delv);

	}
	cout << "Alex \n";
	cout << "Cairo \n";
	cout << "Giza \n";
	cout << "PortSaid \n";
	cout << "Tanta \n";
	cout << endl;
	cout << "Please enter your governate:";
		string cit;
		cin >> cit;
		cout << "/****************************************/" << endl;
		cout << cit << " cities is :\n";
		cout << "/****************************************/" << endl;
		for (int i = 0; i < city.size()-1; i++)
		{ // output city in each governate
			if (cit == gov[i])
				cout << city[i]<< endl;
		}
		cout << endl;
		cout << "Choose your city :";
		string c;
		cin >> c;
		city_temp = c;
		cout << endl;
		cout << "The resturants in " << c << " is: " << endl;
		cout << "/****************************************/" << endl;
		
			//system("Color F3");
			SetConsoleTextAttribute(color,3);

			for (int i = 0; i < res.size(); i++)
			{ //output resturant in each city
				if (c == city2[i])
					cout << res[i] << "  " << rat[i] << "  " << foode[i] << "  " << delivery[i] << "  " << endl;
			}
			cout << "* means that this Resturant has special offer\n";
}
bool Delivery_Boy::DeliverOrder()
{
	ifstream file("order.txt");
	if (!file.is_open())
	{
		file.open("order.txt");
	}
	string name, city;
	int hr, min, sec;
	float price;
	vector <string> namee;
	vector <string> cityy;
	vector <int> hour;
	vector <int> Minute;
	vector <int> second;
	vector <float> fprice;
	int count = 0;
	while (file.peek() != -1)
	{
		file >> name;
		namee.push_back(name);
		file >> price;
		fprice.push_back(price);
		file >> city;
		cityy.push_back(city);
		file >> hr;
		hour.push_back(hr);
		file >> min;
		Minute.push_back(min);
		file >> sec;
		second.push_back(sec);
	}
	
	for (int i = 0; i < namee.size(); i++)
	{
		if (city_temp == cityy[i] && t_h - hour[i]<1)
		{
			count++;
			
		}
		if (count>2)
		{
			cout << "Please order after one hour then\n";
			return true;
		}
	}
	return false;

}


void Admin::AddEmployee()
{

	string id, Boy_name, delv_Place;
	int delv_order = 0;

	//write in delivery boy file
	fstream delvFile("Deliveryboy.txt", ios::in | ios::out | ios::app);
	if (!delvFile.is_open())
	{

		delvFile.open("Deliveryboy.txt");

	}

	/*
	Delivery_Boy boy(id, Boy_name, n_order);
	Delv.push_back(boy);
	*/
	cout << "Enter employee ID \n";
	cin >> id;
	cout << "Enter employee name\n";
	cin >> Boy_name;
	cout << "Enter employee Delivery Place\n";
	cin >> delv_Place;
	delvFile << id << " " << Boy_name << " " << delv_order << delv_Place << endl;




}
void Admin::RemoveEmployee(string delv_id)
{
	vector<Delivery_Boy>Delv;
	string d_id, d_name, d_place;
	int d_order = 0;
	map<string, int>mp;

	ifstream infile("Deliveryboy.txt");
	if (infile.is_open())
	{ //read delivery boy file and put them in vectors
		while (!infile.eof())
		{
			infile >> d_id >> d_name >> d_order >> d_place;
			//take id console and compare it with delivery boy file 
			// if found continue and put others in vector 
			if (d_id == delv_id)
				continue;
			// 
			else
			{
				// عشان اخر واحد كان دايما بيقرر فدنيا عملت الكود ده
				mp[d_id]++;
				if (mp[d_id] == 1)
				{
					Delivery_Boy boy(d_id, d_name, d_order, d_place);
					Delv.push_back(boy);
				}
			}


		}

	}
	//int count = Delv.size() - 1;
	// write in file from vector
	ofstream outfile("Deliveryboy.txt");
	//outfile.open("Deliveryboy.txt");
	for (const auto &e : Delv)
	{
		outfile << e.Id << " " << e.userName << " " << e.No_of_Order << " " << e.Dlev_place << endl;
		//	outfile << e.Id << " " << e.userName << " " << e.No_of_Order << " " << e.Dlev_place << endl;

	}


}
void Admin::ViewBillsin_Customer()
{
	Menu m;
	string name, date, iteme, res_name, res_city;
	int id;
	float price, f_price;
	vector<string> c_name;
	vector<string>	c_date;
	vector<string>	c_res;
	vector<float>	final_price;
	ifstream inbill("bill.txt");
	//inbill.open("bill.txt");
	if (inbill.is_open()){
		while (inbill.peek()!=-1)
		{
			inbill >> name;
			c_name.push_back(name);
			inbill >> id >> iteme >> price;
			item it(id, iteme, price);
			m.items.push_back(it);
			inbill >> res_name;
			m.restura.push_back(res_name);
			inbill >> res_city;
			c_res.push_back(res_city);
			inbill >> date;
			c_date.push_back(date);
			inbill >> f_price;
			final_price.push_back(f_price);


		}
	}
	string res_temp, ciyy_temp, datee_temp;
	float finalprice_temp;
	string customer_name;
	cin >> customer_name;
	for (int i = 0; i < c_name.size(); i++)
	{
		if (c_name[i] == customer_name)
		{
			
			res_temp = m.restura[i];
			ciyy_temp = c_res[i];
			datee_temp = c_date[i];
			finalprice_temp = final_price[i];
			cout << res_temp << " " << ciyy_temp << " " << datee_temp << endl;
			cout << m.items[i].ID << " " << m.items[i].Name << " " << m.items[i].Price << endl;
			cout << "Final Price = " << finalprice_temp << endl;
		
		}
		
	}
	
	

}

void Admin::ViewBillsin_date()
{
	Menu m;
	string name, date, iteme, res_name, res_city;
	int id;
	float price, f_price;
	vector<string> c_name;
	vector<string>	c_date;
	vector<string>	c_res;
	vector<float>	final_price;
	ifstream inbill("bill.txt");
	//inbill.open("bill.txt");
	if (inbill.is_open()){
		while (inbill.peek() != -1)
		{
			inbill >> name;
			c_name.push_back(name);
			inbill >> id >> iteme >> price;
			item it(id, iteme, price);
			m.items.push_back(it);
			inbill >> res_name;
			m.restura.push_back(res_name);
			inbill >> res_city;
			c_res.push_back(res_city);
			inbill >> date;
			c_date.push_back(date);
			inbill >> f_price;
			final_price.push_back(f_price);


		}
	}
	
	string customer_date;
	cin >> customer_date;
	for (int i = 0; i < c_name.size(); i++)
	{
		if (c_date[i] == customer_date)
		{

			cout << c_name[i] << " " << m.items[i].ID << " " << m.items[i].Name << " " << m.items[i].Price << " " << m.restura[i]
				<< " " << c_res[i] << " " <<"Final Price is "<< final_price[i] << endl;

		}

	}

}

void Admin::login()
{
	try
	{

		ifstream infile("Admin.txt");
		string username, pass;
		int count = 0;
		cout << "Enter your username \n";
		cin >> username;
		cout << "Enter your Password \n";
		cin >> pass;
		if (infile.is_open())
		{

			while (!infile.eof())

			{
				infile >> UserName >> phone >> Birthday >> Email >> Password;
				if (username == UserName&& pass == Password)
				{

					count++;
				}

			}
			if (count > 0)
			{
				cout << "Welcome in our system\n";
				cout << " 1-Add employee\n";
				cout << " 2-Remove employee\n";
				cout << " 3-veiw bill of customer\n";
				cout << " 4-veiw bill of Date\n";
				int num;
				cout << "Choose a number : ";
				cin >> num;
				if (num == 1)
				{

					AddEmployee();
				}
				else if (num == 2)
				{
					cout << "Enter Id to remove: ";
					string id;
					cin >> id;
					RemoveEmployee(id);
				}
				else if (num == 3)
				{
					cout << "Enter customer name : ";
					ViewBillsin_Customer();
				}
				else if (num == 4)
				{
					cout << "Enter Delvier date: ";
					ViewBillsin_date();
				}

			}
				
			else
				cout << "Invalid username or password \n";

		}
	}
	catch (...)
	{
		cout << "The file does not exist \n ";

	}
}
float Customer::Vouchers(int nO, string dt)
{
	float dis = 0;
	bool brth = true;
	ifstream Birth("userData.txt");
	if (nO >= 5 || nO == 0)
		dis += 0.1;
	if (Birth.is_open())
	{
		while (Birth.peek() != -1)
		{
			Birth >> UserName >> phone >> Birthday >> Email >> Password;
			int cdil = 0;
			if (user_temp == UserName)
			for (int i = 0; i < dt.size(); ++i)
			{
				if (cdil == 2)
					break;
				if (Birthday[i] != dt[i])
				{
					brth = false;
					break;
				}
				if (Birthday[i] == '/')
					cdil++;

			}
			if (!brth)
				break;
			else dis += 0.1;

		}
	}
	return dis;
}


void Customer::MakeOrder()
{

	Menu m;
	//map<string, int>mp;
	vector<item>  order;
	vector<float> Order_price;
	string res, cat, foood;
	float pricee;
	int id;
	float Total_price = 0;
	vector<Delivery_Boy>Delv;
	string d_id, d_name, d_place;
	int d_order = 0;
	Delivery_Boy boyy;
	
	ifstream infile("Food.txt");
	//read from food file and put in vectors
	if (infile.is_open())
	{
		while (infile.peek() != -1)
		{
			infile >> res;
			m.restura.push_back(res);
			infile >> cat;
			m.meals.push_back(cat);
			infile >> id >> foood >> pricee;
			item it(id, foood, pricee);
			m.items.push_back(it);
		}

	}

	SetConsoleTextAttribute(color, 7);
	cout << "Enter Resturant name : ";
	string r;
	cin >> r;
	rest_temp = r;
	string s;
	// lw 2lresturan sa7 be3rd 2lmenue
	for (int i = 0; i < m.restura.size(); i++){
		if (r == m.restura[i]){
			s = m.meals[i];
			//system("Color F3");
			// bekteb categoreies (mainmeal,dessert) 2bel 2litemes
			
			SetConsoleTextAttribute(color, 5);
			cout << m.meals[i] << endl;

			for (int j = 0; j < m.restura.size(); j++)
			{
				if (s == m.meals[j] && r== m.restura[j]){
					SetConsoleTextAttribute(color, 7);
					cout << m.items[j].ID << " " << m.items[j].Name << " " << m.items[j].Price << endl;
					i++;
				}
			}
			i--;
		}
	}

	int Order_id, idd = 0;
	string  foode;
	float prrice = 0;
	//beya5od 2ldate mn 2luser 
	cout << "Enter the date for deliver :";
	string date;
	cin >> date;
	string date_temp = date;
	// bya5od id kol item l8ayatv lma yda5l -1
	do
	{
		cout << "Select your order ID and press -1 to braak : ";
		cin >> Order_id;
		//item o(idd, foode, prrice);
		// item it(id, foood, pricee);
		for (int i = 0; i < m.meals.size(); i++)
		{
			if (Order_id == m.items[i].ID && m.restura[i]==rest_temp)
			{
				order.push_back(item{ m.items[i].ID, m.items[i].Name, m.items[i].Price });
				Order_price.push_back(m.items[i].Price);
			}
		}	
	}
	// vector bsum items price
	while (Order_id != -1);
	
	for (int i = 0; i < Order_price.size(); i++)
	{
		Total_price += Order_price[i];
	}
	SetConsoleTextAttribute(color, 2);
	
	for (int i = 0; i < Order_price.size(); i++)
	{
		cout << order[i].ID << " " << order[i].Name << " " << order[i].Price<<endl;
	}
	cout << "The Total Price with shipping is : ";
	float p = Total_price + 10;
	cout << p << endl;
	SetConsoleTextAttribute(color, 7);
	// lw 3ayez ykamel 2lorder bta3h
	cout << "Done ? press y to confirm order ";
    cin >> replay;
	if (replay == "y" || replay == "Y")
	{
		if (boyy.DeliverOrder()==true)
			return;
		login();
		fstream bill("bill.txt", ios::in | ios::out | ios::app);
		if (!bill.is_open())
		{
			bill.open("bill.txt");
		}
		
		//cout << "jfjdfbjdbf == " << name2_temp << endl;
		fstream Orders("order.txt", ios::in | ios::out | ios::app);
		if (!Orders.is_open())
		{
			Orders.open("order.txt");
		}

		int n_orders = 1;

		string n;
		float tp;
		int no, o = 0;
		ifstream f_order("order.txt");
		ifstream Birth("userData.txt");
		if (f_order.is_open())
		{
			while (f_order.peek() != -1)
			{
				f_order >> n;
				if (n == user_temp)
				{
					o++;

				}
			}
		}
		
		//cout << nowlocal.tm_hour << " " << nowlocal.tm_min << " " << nowlocal.tm_sec << endl;
		float dis = Vouchers(o, date);
		cout << "You have discount: " << dis << endl;
		Orders << user_temp << " " << p*(1 - dis) << " " << city_temp << " " << nowlocal->tm_hour << " " << nowlocal->tm_min << " " << nowlocal->tm_sec << endl;
		for (int k = 0; k < order.size(); k++)
			bill << name2_temp << " " << order[k].ID << " " << order[k].Name << " " << order[k].Price << " " << r << " " << city_temp << " " << date << " " << p*0.9 << endl;
		ifstream dboy("Deliveryboy.txt");
		if (dboy.is_open())
		{
			while (dboy.peek() != -1)
			{
				dboy >> d_id >> d_name >> d_order >> d_place;

				if (d_place == city_temp)
				{
					d_order++;
					Delivery_Boy boy(d_id, d_name, d_order++, d_place);
					Delv.push_back(boy);
					ofstream outfile("Deliveryboy.txt");

					for (int i = 0; i < Delv.size(); i++)
					{
						outfile << Delv[i].Id << " " << Delv[i].userName << " " << Delv[i].No_of_Order << " " << Delv[i].Dlev_place << endl;
						if (Delv[i].Dlev_place == d_place)
						{
							cout << user_temp << " " << nowlocal->tm_mday << "/" << nowlocal->tm_mon + 1 << "/2018" << " " << nowlocal->tm_hour << ":" << nowlocal->tm_min << ":" << nowlocal->tm_sec << "\n" << "Delvier date " << date << endl;
							t_h = nowlocal->tm_hour;
							t_m = nowlocal->tm_min;
							t_s = nowlocal->tm_sec;
							cout << Delv[i].userName << '\t' << city_temp << endl;
						}
					}

					for (int j = 0; j < order.size(); j++)
					{
						cout << order[j].ID << "  " << order[j].Name << "  " << order[j].Price << endl;
					}
					cout << "/***********************************************/" << endl;
					//ooo << "The total after discount = " << p*0.9 << endl;
					cout << "The total after discount = " << p*0.9 << endl;
				}
				else
				{
					Delivery_Boy boy(d_id, d_name, d_order, d_place);
					Delv.push_back(boy);
					ofstream outfile("Deliveryboy.txt");
					for (int i = 0; i < Delv.size(); i++)
						outfile << Delv[i].Id << " " << Delv[i].userName << " " << Delv[i].No_of_Order << " " << Delv[i].Dlev_place << endl;
				}
			}
		}
		
		// write in file order if name repeated 5 time make discount
	/*	if (o >= 5){
			string x;
			Orders << user_temp << " " << p*0.90 <<" "<<city_temp <<" "<< nowlocal->tm_hour << " " << nowlocal->tm_min << " " << nowlocal->tm_sec << endl;
			for (int k = 0; k < order.size(); k++)
				bill << name2_temp << " " << order[k].ID << " " << order[k].Name << " " << order[k].Price << " " << r << " " << city_temp << " " << date << " " << p*0.9 << endl;
			ifstream dboy("Deliveryboy.txt");
			if (dboy.is_open())
			{
				while (dboy.peek() != -1)
				{
					dboy >> d_id >> d_name >> d_order >> d_place;

					if (d_place == city_temp)
					{
						d_order++;
						Delivery_Boy boy(d_id, d_name, d_order++, d_place);
						Delv.push_back(boy);
						ofstream outfile("Deliveryboy.txt");
						
						for (int i = 0; i < Delv.size(); i++)
						{
							outfile << Delv[i].Id << " " << Delv[i].userName << " " << Delv[i].No_of_Order << " " << Delv[i].Dlev_place <<endl;
							if (Delv[i].Dlev_place == d_place) 
							{
								cout << user_temp << " " << nowlocal->tm_mday << "/" << nowlocal->tm_mon + 1 << "/2018" << " " << nowlocal->tm_hour << ":" << nowlocal->tm_min << ":" << nowlocal->tm_sec << "\n" << "Delvier date " << date << endl;
								t_h = nowlocal->tm_hour;
								t_m = nowlocal->tm_min;
								t_s = nowlocal->tm_sec;
								cout << Delv[i].userName << '\t' << city_temp << endl;		
							}
						}
						
						for (int j = 0; j < order.size(); j++)
						{
							cout << order[j].ID << "  " << order[j].Name << "  " << order[j].Price << endl;
						}
						cout << "/***********************************************" << endl;
						//ooo << "The total after discount = " << p*0.9 << endl;
						cout << "The total after discount = " << p*0.9 << endl;
					}
					else
					{
						Delivery_Boy boy(d_id, d_name, d_order, d_place);
						Delv.push_back(boy);
						ofstream outfile("Deliveryboy.txt");
						for (int i = 0; i < Delv.size(); i++)
							outfile << Delv[i].Id << " " << Delv[i].userName << " " << Delv[i].No_of_Order << " " << Delv[i].Dlev_place << endl;
					}
				}
			}
		}

		// write in file order order and price and veiw bill
		else if (o < 5)
		{
			Orders << user_temp << " " << p<<" "<<city_temp<< " " << nowlocal->tm_hour << " " << nowlocal->tm_min << " " << nowlocal->tm_sec << endl;
			for (int k = 0; k < order.size(); k++)
				bill << name2_temp << " " << order[k].ID << " " << order[k].Name << " " << order[k].Price << " " << r << " " << city_temp << " " << date << " " << p <<  endl;
			//ifstream dboy("Deliveryboy.txt");
			ifstream dboy("Deliveryboy.txt");
			if (dboy.is_open())
			{
				while (dboy.peek() != -1)
				{
					dboy >> d_id >> d_name >> d_order >> d_place;

					if (d_place == city_temp)
					{
						d_order++;
						Delivery_Boy boy(d_id, d_name, d_order++, d_place);
						Delv.push_back(boy);
						ofstream outfile("Deliveryboy.txt");
						for (int i = 0; i < Delv.size(); i++)
						{
							outfile << Delv[i].Id << " " << Delv[i].userName << " " << Delv[i].No_of_Order << " " << Delv[i].Dlev_place << endl;
							if (Delv[i].Dlev_place == d_place) {
								cout << user_temp <<" "<<nowlocal->tm_mday<<"/"<< nowlocal->tm_mon+1<<"/2018"<<" "<< " " <<nowlocal->tm_hour<<":"<<nowlocal->tm_min<<":"<<nowlocal->tm_sec<<"\n"<<"Delvier date " << date << endl;
								t_h = nowlocal->tm_hour;
								t_m = nowlocal->tm_min;
								t_s = nowlocal->tm_sec;
								cout << Delv[i].userName << '\t' << city_temp << endl;
							}
						}

						for (int j = 0; j < order.size(); j++)
							cout << order[j].ID << "  " << order[j].Name << "  " << order[j].Price << endl;
						cout << "/***********************************************" << endl;
						cout << "The total = " << p << endl;
					}
					else
					{
						Delivery_Boy boy(d_id, d_name, d_order, d_place);
						Delv.push_back(boy);
						ofstream outfile("Deliveryboy.txt");
						for (int i = 0; i < Delv.size(); i++)

							outfile << Delv[i].Id << " " << Delv[i].userName << " " << Delv[i].No_of_Order << " " << Delv[i].Dlev_place << endl;
					}
				}
			}
		}




		// lw birthday bta3h make discount view bill

		else if (Birth.is_open())
		{
			while (Birth.peek() != -1)
			{
				Birth >> UserName >> phone >> Birthday >> Email >> Password;
				if (user_temp == UserName&&Birthday == date)
				{

					Orders << user_temp << " " << p*0.95<<" "<<city_temp  << " " << nowlocal->tm_hour << ":" << nowlocal->tm_min << ":" << nowlocal->tm_sec << endl;
					for (int k = 0; k < order.size(); k++)
						bill << name2_temp << " " << order[k].ID << " " << order[k].Name << " " << order[k].Price << " " << r << " " << city_temp << " " << date << " " << p*0.95 << endl;
					//ifstream dboy("Deliveryboy.txt");
					ifstream dboy("Deliveryboy.txt");
					if (dboy.is_open())
					{
						while (dboy.peek() != -1)
						{
							dboy >> d_id >> d_name >> d_order >> d_place;

							if (d_place == city_temp)
							{
								d_order++;
								Delivery_Boy boy(d_id, d_name, d_order++, d_place);
								Delv.push_back(boy);
								ofstream outfile("Deliveryboy.txt");
								for (int i = 0; i < Delv.size(); i++)
								{
									outfile << Delv[i].Id << " " << Delv[i].userName << " " << Delv[i].No_of_Order << " " << Delv[i].Dlev_place << endl;
									if (Delv[i].Dlev_place == d_place) {
										cout << user_temp << " " << nowlocal->tm_mday << "/" << nowlocal->tm_mon + 1 << "/2018" << " " << " " << nowlocal->tm_hour << ":" << nowlocal->tm_min << ":" << nowlocal->tm_sec << "\n" << "Delvier date " << date << endl;
										t_h = nowlocal->tm_hour;
										t_m = nowlocal->tm_min;
										t_s = nowlocal->tm_sec;
										cout << Delv[i].userName << '\t' << city_temp << endl;
									}
								}

								for (int j = 0; j < order.size(); j++)
									cout << order[j].ID << "  " << order[j].Name << "  " << order[j].Price << endl;
								cout << "/***********************************************" << endl;
								cout << "The total after discount = " << p*0.95 << endl;
							}
							else
							{
								Delivery_Boy boy(d_id, d_name, d_order, d_place);
								Delv.push_back(boy);
								ofstream outfile("Deliveryboy.txt");
								for (int i = 0; i < Delv.size(); i++)
									outfile << Delv[i].Id << " " << Delv[i].userName << " " << Delv[i].No_of_Order << " " << Delv[i].Dlev_place << endl;
							}
						}
					}
				}
			}
		}
	*/
		cout << endl;
		Customer co;
		co.Payment();
		SetConsoleTextAttribute(color, 5);
		cout << "Do you want to rate us ? ";
		string answer;
		cin >> answer;
		transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
		if (answer[0] == 'y'){
			co.Rate_Resturant();
		}

		cout << "Thank you :)" << endl;
	}
	else
		MakeOrder();
	
}

void Customer::deleteOrder()
{
	/*if (replay == "y" || replay == "Y")
	{*/
		time_t Otime2;
		struct tm nowlocal2;
		Otime2 = time(0);
		nowlocal2 = *localtime(&Otime2);
		/*
		cout << "h1 = " << t_h << endl;
		cout << "h2 = " << nowlocal2.tm_hour << endl;
		cout << "m1 = " << t_m<< endl;
		cout << "m2 = " << nowlocal2.tm_min << endl;
		*/
		if (nowlocal2.tm_hour-t_h == 0 && nowlocal2.tm_min-t_m < 10)
		{
			ifstream file("order.txt");
			if (!file.is_open())
			{
				file.open("order.txt");
			}
			string name, city;
			int hr, min, sec;
			float price;
			vector <string> namee;
			vector <string> cityy;
			vector <int> hour;
			vector <int> Minute;
			vector <int> second;
			vector <float> fprice;
			int count = 0;
			while (file.peek() != -1)
			{
				file >> name;
				namee.push_back(name);
				file >> price;
				fprice.push_back(price);
				file >> city;
				cityy.push_back(city);
				file >> hr;
				hour.push_back(hr);
				file >> min;
				Minute.push_back(min);
				file >> sec;
				second.push_back(sec);
			}
					ofstream out("order.txt");
			for (int i = 0; i < namee.size(); i++)
			{
				if (t_h == hour[i] && t_m == Minute[i] && t_s == second[i])
					continue;
				//else
				//{
					out << namee[i] << " " << fprice[i] << " " << cityy[i] << " " << hour[i] << " " << Minute[i] << " " << second[i] << endl;
				//}
			}

			cout << "Deleted" << endl;
		}
		else if (nowlocal2.tm_hour - t_h != 0 || nowlocal2.tm_min - t_m >= 10)
			cout << "too late" << endl;
	//}
}
void Customer::Rate_Resturant()
{
	Menu m;
	string govee, cityy, rest, ratee, food, delv, cityy2;
	// vector for city,resturant name,rate,type of food and delivery time  in file resturant
	ifstream in("Resturant.txt");
	vector<string> city2;
	vector<string> res;
	vector<string> rat;
	vector<string> foode;
	vector<string> delivery;
	//Read from file to find restaurant and change its rate
	//to change in the vector of the rate.
	if (in.is_open())
	{
		while (in.peek() != -1)
		{
			in >> cityy2;
			city2.push_back(cityy2);
			in >> rest;
			res.push_back(rest);
			in >> ratee;
			rat.push_back(ratee);
			in >> food;
			foode.push_back(food);
			in >> delv;
			delivery.push_back(delv);
		}
	}
	cout << "Enter your rate from 1 to 5:";
	float r;
	cin >> r;
	for (int i = 0; i < rat.size(); i++){
			string s = res[i];
			if (s[s.size() - 1] == '*'){
				s.erase(s.begin() + (s.size() - 1));
			}
		if (city2[i] == city_temp && s == rest_temp){
			float x = float(rat[i][5]) - '0';
			x += r;
			x /= 2;
			rat[i][5] = char(x) + '0';
			cout << city2[i] << res[i] << rat[i] << foode[i] << delivery[i] << endl;

		}
	}
	//put vector in file again 
	ofstream outfile("Resturant.txt");
	for (int i = 0; i<res.size(); i++){
		outfile << city2[i] << " " << res[i] << " " << rat[i] << " " << foode[i] << " " << delivery[i] << endl;
	}
	if (r < 2.5)
	{
		cout << "Do you want to report a compliment";
		string s2;
		cin >> s2;
		if (s2 == "yes" || s2 == "Yes")
		{
			cout << "Write your notices \n";
			string report;
			cin >> report;
			cout << "Sorry we will solved it soon   ";
		}
	}
	cout << endl;
}
void Customer::gatagory(){
	SetConsoleTextAttribute(color, 9);
	cout << "Do yo know the resturants f special gategoray ? ";
	string answer;
	cin >> answer;
	if (answer[0] == 'y'){
		set <string>gat;
		set <string>::iterator it;
		set <string>ress;
		set <string>::iterator itt;
		string govee, cityy, rest, ratee, food, delv, cityy2;
		ifstream in("Resturant.txt");
		vector<string> city2;
		vector<string> res;
		vector<string> rat;
		vector<string> foode;
		vector<string> delivery;
		while (!in.eof())
		{
			in >> cityy2 >> rest >> ratee >> food >> delv;
			city2.push_back(cityy2);
			res.push_back(rest);
			rat.push_back(ratee);
			foode.push_back(food);
			gat.insert(food);
			delivery.push_back(delv);
		}
		for (it = gat.begin(); it != gat.end(); it++)cout << *it << endl;
		cout << "please , select a special gatagory ! ";
		string s;
		cin >> s;
		for (int i = 0; i < res.size(); i++){
			if (s == foode[i]){
				ress.insert(res[i]);
			}
		}
		for (itt = ress.begin(); itt != ress.end(); itt++)cout << *itt << endl;
	}
	cout << endl;
}
void Customer::OfferResturant(){
	SetConsoleTextAttribute(color, 9);
	cout << "Do you want to know the offer resturant ? ";
	string s;
	cin >> s;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	if (s[0] == 'y'){
		set<string>ofres;
		set<string>::iterator it;
		string res, cit;
		ifstream infile("Resturant.txt");
		if (infile.is_open())
		{
			while (infile.peek() != -1)
			{
				infile >> cit >> res;
				if (res[res.size() - 1] == '*'){
					res.erase(res.begin() + (res.size() - 1));
					ofres.insert(res);
				}

			}
		}
		for (it = ofres.begin(); it != ofres.end(); it++)cout << *it << endl;
	}
	cout << endl;
}
void Customer::Payment(){
	SetConsoleTextAttribute(color, 9);
	cout << "Do you want to pay when you take order or creditCard ? 1:creditCard , 2:another" << endl;
	string answer;
	cin >> answer;
	if (answer == "1"){
		cout << "Please Enter yor CreditCard Number : " << endl;
		string pass;
		cin >> pass;
	}
	else {
		cout << "OK, Thank you ." << endl;
	}

}