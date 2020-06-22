#include "Quote.h"

Quote::Quote() {
	gallons = 0;
	date = " ";
	price = 0;
	total = 0;

	for (int i = 0; i < 100; i++)
		address[i] = ' ';
}

Quote::Quote(float g, char a, string d, float p, float t) {
	gallons = g;
	date = d;
	price = p;
	total = t;

	for (int i = 0; i < 100; i++)
		address[i] = a;
}

float Quote::getGal() {
	return gallons;
}

string Quote::getAdd() {
	//for (int i = 0; i < 100; i++)
		//address[i] = a[i];
	return address;
}

string Quote::getDate() {
	return date;
}

float Quote::getPrice() {
	return price;
}

float Quote::getTotal() {
	return total;
}

void Quote::setGal(float g) {
	gallons = g;
}

void Quote::setAdd(char a) {
	for (int i = 0; i < 100; i++)
		address[i] = a;
}

void Quote::setDate(string d) {
	date = d;
}

void Quote::setPrice(float p) {
	price = p;
}

void Quote::getTotal(float t) {
	total = t;
}
