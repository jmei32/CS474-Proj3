// CS474Proj3.cpp : Defines the entry point for the console application.
// Jim Mei
// CS 474
// Proj 3

//#include "stdafx.h"
#include "stdio.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

enum Type { LAUNDRY_MACHINE, DISH_WASHER, DRYER };

class Appliance
{
private:
	int ID;
	Type ApplianceType;
	string Manufacturer;
	double Price;
	vector<string> Pictures;

public:
	Appliance(int id, Type aType, string aManufacturer, double sellPrice) : ID(id), ApplianceType(aType), Manufacturer(aManufacturer), Price(sellPrice), Pictures(NULL) {}

	int getApplianceID() const {
		return ID;
	}

	Type getApplianceType() {
		return ApplianceType;
	}

	string getApplianceManufacturer() {
		return Manufacturer;
	}

	double getAppliancePrice() {
		return Price;
	}

	std::vector<string> getAppliancePictures() {
		return Pictures;
	}

	void addAppliancePicture(string newPic) {
		Pictures.push_back(newPic);
	}

	void setID(int id) {
		ID = id;
	}

	void setType(Type newType) {
		ApplianceType = newType;
	}

	void setManufacturer(string nManufactuerer) {
		Manufacturer = nManufactuerer;
	}

	void setPrice(double newPrice) {
		Price = newPrice;
	}

	void printInfo() {
		string rType;

		if (ApplianceType == 0)
			rType = "LAUNDRY_MACHINE";
		else if (ApplianceType == 1)
			rType = "DISH_WASHER";
		else
			rType = "DRYER";

		cout << "ID: " << ID << endl;
		cout << "Type: " << rType << endl;
		cout << "Manufacturer: " << Manufacturer << endl; 
		cout << "Price: " << Price << endl;
		cout << "Picture URL:" << endl;
		for (auto i : Pictures) {
			cout << i << endl;
		}
		cout << endl;
	}

	~Appliance() {}
};


class Counter {
private:
	int count;

public:
	void AddCount() {
		count++;
	}

	int DecCount() {
		return --count;
	}
};


class AppliancePtr {
private:
	Appliance* applicationData;	//pointer to appliance class
	Counter* count;
	int ID;
public:
	AppliancePtr(): count(0), ID(0) {
		count = new Counter();
		count->AddCount();
	}

	AppliancePtr(Appliance* aValue, int id) : applicationData(aValue), count(0), ID(id) {
		count = new Counter();
		count->AddCount();
	}

	AppliancePtr(int id) : count(0), ID(id) {
		count = new Counter();
		count->AddCount();
	}

	AppliancePtr(const AppliancePtr& ap) : applicationData(ap.applicationData), count(ap.count) {
		count->AddCount();
	}

	void addAppliance(Appliance* newApp) {
		applicationData = newApp;
	}


	~AppliancePtr() {
		//cout << "Delete 1" << endl;

		if (count->DecCount() == 0) {
			//cout << "Delete 3" << endl;
			delete applicationData;
			delete count;
		}
	}

	void setID(int id) {
		ID = id;
	}

	void populateData(string filename) {
		ifstream file(filename);

		string line, id, aType, maker, price, address;
		//int newID;
		Type cType;
		double cost;


		while (getline(file, line)) {

			stringstream ss(line);

			getline(ss, id, ',');
			getline(ss, aType, ',');
			getline(ss, maker, ',');
			getline(ss, price, ',');
			getline(ss, address);

			//newID = stoi(id);

			if (aType == "LAUNDRY_MACHINE")
				cType = LAUNDRY_MACHINE;
			else if (aType == "DISH_WASHER")
				cType = DISH_WASHER;
			else
				cType = DRYER;

			cost = stod(price);

			applicationData = new Appliance(ID, cType, maker, cost);
		}
	}

	Appliance& operator* () {
		return *applicationData;
	}

	Appliance* operator-> () {
		return applicationData;
	}
	
	AppliancePtr& operator = (const AppliancePtr& ap) {
		if (this != &ap) {
			//cout << "Delete 2" << endl;

			if (count->DecCount() == 0) {
				delete applicationData;
				delete count;
			}

			applicationData = ap.applicationData;
			count = ap.count;
			count->AddCount();
		}
		return *this;
	}
};





class SmartList {
private:
	struct Node {
		AppliancePtr app;
		int ID;
		Node* next;
	};

	Node* head;
	Node* cur;

public:

	SmartList(){
		head = NULL; 
		cur = NULL;
	}

	void addNode(AppliancePtr newApp, int id) {
		Node* newNode = new Node();
		newNode->app = newApp;
		newNode->ID = id;
		newNode->next = NULL;

		if (head == NULL) {
			head = newNode;
		}
		else {
			cur = head;

			while (cur->next != NULL) {
				cur = cur->next;
			}

			cur->next = newNode;
			//cout << "Successfully inserted: " << id << endl;
		}
	}

	int isEmpty() {
		if (head == NULL)
			return 1;
		else
			return 0;
	}

	/*
	void printList() {
		if (head == NULL)
			return;
		else {
			cur = head;

			while (cur != NULL) {
				cur->app->printInfo();

				cur = cur->next;
			}
		}
	}*/

	void printList()
	{
		cur = head;
		string filename;
		int counter = 0;

		while (cur != NULL) {
			switch (cur->ID)
			{
			case 0:
				filename = "appliance0.txt";
				break;
			case 1:
				filename = "appliance1.txt";
				break;
			case 2:
				filename = "appliance2.txt";
				break;
			case 3:
				filename = "appliance3.txt";
				break;
			case 4:
				filename = "appliance4.txt";
				break;
			case 5:
				filename = "appliance5.txt";
				break;
			case 6:
				filename = "appliance6.txt";
				break;
			case 7:
				filename = "appliance7.txt";
				break;
			case 8:
				filename = "appliance8.txt";
				break;
			case 9:
				filename = "appliance9.txt";
				break;
			default:
				break;
			}
			cur->app.setID(counter);
			cur->app.populateData(filename);

			cur->app->printInfo();

			counter++;
			cur = cur->next;
		}

		cout << head->app->getApplianceID() << endl;
	}
};


void printInstructions() {
	cout << "Please Enter a command:" << endl;
	cout << "	l: List" << endl;
	cout << "	0 - 9: Edit an appliance" << endl;
	cout << "	c: Create an new appliance" << endl;
	cout << "	p: Change the price of an appliance" << endl;
	cout << "	s: Save all changes" << endl;
	cout << "	q: Exit Program" << endl;
}


void addAppliancesToList(SmartList List) {
	int counter = 0;
	int typeRotate = 0;
	string maker = "GE";
	string tempPic = "Nunu";

	/**/
}


void printList(SmartList List) {
	if (List.isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else {
		List.printList();		
	}
}


int main()
{
	SmartList ApplianceList;

	AppliancePtr app0(0);
	AppliancePtr app1(1);
	AppliancePtr app2(2);
	AppliancePtr app3(3);
	AppliancePtr app4(4);
	AppliancePtr app5(5);
	AppliancePtr app6(6);
	AppliancePtr app7(7);
	AppliancePtr app8(8);
	AppliancePtr app9(9);

	ApplianceList.addNode(app0, 0);
	ApplianceList.addNode(app1, 1);
	ApplianceList.addNode(app2, 2);
	ApplianceList.addNode(app3, 3);
	ApplianceList.addNode(app4, 4);
	ApplianceList.addNode(app5, 5);
	ApplianceList.addNode(app6, 6);
	ApplianceList.addNode(app7, 7);
	ApplianceList.addNode(app8, 8);
	ApplianceList.addNode(app9, 9);

	int curCount = 0;

	printInstructions();
	addAppliancesToList(ApplianceList);
	string command;

	cin >> command;

	while (command != "q") {
		if (command == "l" || command == "L") {
			//cout << "To Implement 1" << endl;
			//List all appliances (ID, Type, etc), including list of file paths, appliances are 
			//stored back on disk and deleted as needed to keep 3 total appliances in memory
			printList(ApplianceList);
		}
		else if (command == "0" || command == "1" || command == "2" || command == "3" || command == "4" || command == "5" || 
			command == "6" || command == "7" || command == "8" || command == "9") {
			cout << "To Implement 2" << endl;
			//edit numbered appliace, 
		}
		else if (command == "c" || command == "C") {
			cout << "To Implement 3" << endl;
			//create an appliance. User prompted for various fields for appliance instance
		}
		else if (command == "p" || command == "P") {
			cout << "To Implement 4" << endl;
			//changes price of current appliance. Prompts a new number to be entered and becomes new price.
			//file is NOT saved. The new content of current appliance is displayed in the user;s screen.
			//New price will be saved when the appliance instance is stored to its file, assuming S
		}
		else if (command == "s" || command == "S") {
			cout << "To Implement 5" << endl;
			//saves all appliances in memory to corresponding file(s). The files are deleted (using remove()), then an ofstream
			//instance is opened on the named file, and the appliances information is saved to the new file, and the stream is closed
		}
		else {
			cout << "Invalid Command" << endl;
		}

		cin >> command;
	}

	cout << "Thank you!" << endl;

    return 0;
}

