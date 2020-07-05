#ifndef QUOTE_H
#define QUOTE_H

#include <string>
using namespace std;

class Quote {
	private:
		float gallons;
		char address[100];
		string date;
		float price;
		float total;
	public:
		Quote();
		Quote(float g, char a, string d, float p, float t);
		float getGal();
		string getAdd();
		string getDate();
		float getPrice();
		float getTotal();
		void setGal(float g);
		void setAdd(char a);
		void setDate(string d);
		void setPrice(float p);
		void getTotal(float t);
};

#endif
#pragma once
