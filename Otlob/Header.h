#include<iostream>
#include<string>
#include <fstream>
#include <conio.h>
#include <map>
#include <list>
#include <vector>
#include <time.h>
#pragma warning(disable:4996)
using namespace std;

class Person
{
public:
	string ID;
	string UserName;
	string Email;
	string Password;
	string Birthday;
	string phone;
	virtual void login() = 0;
	
};


class Customer:public Person
{
public:
	void login();
	void OfferResturant();
	void gatagory();
	void customerRegister();
	//void CustomerLogin();
	void SelectResturant();
    void MakeOrder();
	void Payment();
	void Rate_Resturant();
	//void UnRegister_Customer();
	void ViewCataloge();
	float Vouchers(int , string);
	void deleteOrder();
	string user_temp, name2_temp;
	

};
 
class Admin : public Person
{
public:
	//void SignasManager();
	void login();
	void RemoveEmployee(string);
	void AddEmployee();
	void ViewBillsin_date();
	void ViewBillsin_Customer();
	//void Check_Quantity();
};

class Delivery_Boy
{
public:
	string Id;
	string userName;
	int No_of_Order;
	string Dlev_place;
public:
	Delivery_Boy()
	{
		Id = "";
		userName = "";
		No_of_Order = 0;
	}
	Delivery_Boy(string id,string name,int order,string place)
	{
		Id = id;
		userName = name;
		No_of_Order = order;
		Dlev_place = place;

	}
	/*
	Delivery_Boy()
	{
		
	}
	*/
	
	void RecivedOrder();
	bool DeliverOrder();
};
class item
{
public:
	int ID;
	string Name;
	float Price;
	
	
public:
	item(int d,string s, float p ){
		ID = d; Name = s; Price = p;
	}
	
};

class Menu
{
public:
	vector<item> items;
	vector<string> restura;
	vector<string> meals;
	
};

class Resturant
{

	string name;
	string Place;
	string TypeofFood;
	
	Menu m;
public :
	float Rate;
	Resturant();
};


