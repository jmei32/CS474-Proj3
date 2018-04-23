#include "stdafx.h"

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

		return;
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

	~Appliance(){}
};

class AppliancePtr {
private:
	Appliance* applicationData;	//pointer to appliance class
public:
	AppliancePtr(Appliance* aValue) : applicationData(aValue) {}

	~AppliancePtr() {
		delete applicationData;
	}

	Appliance& operator* () {
		return *applicationData;
	}

	Appliance* operator-> () {
		return applicationData;
	}
};