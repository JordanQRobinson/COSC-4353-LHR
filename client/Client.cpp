#include "Client.h"
#include <iostream>
#include <fstream>

Client::Client() {
	for (int i = 0; i < 100; i++) {
		address1[i] = ' ';
		address2[i] = ' ';
		city[i] = ' ';
		state[i] = ' ';
	}

	for (int i = 0; i < 50; i++)
		name[i] = ' ';

	for (int i = 0; i < 9; i++)
		zipcode[i] = ' ';
}

Client::Client(char n, char a1, char a2, char c, char s, char z) {
	for (int i = 0; i < 100; i++) {
		address1[i] = a1;
		address2[i] = a2;
		city[i] = c;
		state[i] = s;
	}

	for (int i = 0; i < 50; i++)
		name[i] = n;

	for (int i = 0; i < 9; i++)
		zipcode[i] = z;
}

bool Client::Registered(string user) {
	bool flag = false;

	for (int i = 0; i < 100; i++) {
		if (user == username[i])
			return true;
	}

	return flag;
}

string Client::RegisterClient(char n[], char a1[], char a2[], char c[], char s[], char z[]) {
	string str;

	cin >> str;
	for (int i = 0; i < str.length(); ++i)
		n[i] = str.at(i);

	cin >> str;
	for (int i = 0; i < str.length(); ++i)
		a1[i] = str.at(i);

	cin >> str;
	for (int i = 0; i < str.length(); ++i)
		a2[i] = str.at(i);

	cin >> str;
	for (int i = 0; i < str.length(); ++i)
		c[i] = str.at(i);

	cin >> str;
	for (int i = 0; i < str.length(); ++i)
		s[i] = str.at(i);

	cin >> str;
	for (int i = 0; i < str.length(); ++i)
		z[i] = str.at(i);

}

bool Client::Login(string user, string pass) {
	bool login_complete = false;

	for (int i = 0; i < 100; i++) {
		if (user == username[i] && pass == password[i])
			return true;
	}

	return login_complete;
}

void Client::QuoteHistory(Quote c) {
	cout << "Fuel Quote:\n";
	cout << c.getGal() << endl;
	cout << c.getAdd() << endl;
	cout << c.getDate() << endl;
	cout << c.getPrice() << endl;
	cout << c.getTotal() << endl;
}

string Client::getName() {
	//for (int i = 0; i < 50; i++)
		//name[i] = n[i];
	return name;
}

string Client::getAdd1() {
	//for (int i = 0; i < 100; i++)
		//address1[i] = a[i];
	return address1;
}

string Client::getAdd2() {
	//for (int i = 0; i < 100; i++)
		//address2[i] = a[i];
	return address2;
}

string Client::getCity() {
	//for (int i = 0; i < 100; i++)
		//city[i] = c[i];
	return city;
}

string Client::getState() {
	//for (int i = 0; i < 100; i++)
		//state[i] = s[i];
	return state;
}

string Client::getZip() {
	//for (int i = 0; i < 100; i++)
		//zipcode[i] = z[i];
	return zipcode;
}

void Client::setName(char n) {
	for (int i = 0; i < 100; i++)
		name[i] = n;
}

void Client::setAdd1(char a) {
	for (int i = 0; i < 100; i++)
		address1[i] = a;
}

void Client::setAdd2(char a) {
	for (int i = 0; i < 100; i++)
		address2[i] = a;
}

void Client::setCity(char c) {
	for (int i = 0; i < 100; i++)
		city[i] = c;
}

void Client::setState(char s) {
	for (int i = 0; i < 100; i++)
		state[i] = s;
}

void Client::setZip(char z) {
	for (int i = 0; i < 100; i++)
		zipcode[i] = z;
}
