#include "stdafx.h"

class Appliance4
{
private:
	int ID;
	Type ApplianceType;
	string Manufacturer;
	double Price;
	vector<string> Pictures;

public:
	Appliance4(int id, Type aType, string aManufacturer, double sellPrice) : ID(id), ApplianceType(aType), Manufacturer(aManufacturer), Price(sellPrice), Pictures(NULL) {}

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
};