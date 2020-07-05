#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "../common/Quote.cpp"
using namespace std;

class Client {
private:
	char name[50];
	char address1[100];
	char address2[100];
	char city[100];
	char state[2];
	char zipcode[9];
	string username[100];
	string password[100];
public:
	Client();
	Client(char n, char a1, char a2, char c, char s, char z);
	bool Registered(string user);
	string RegisterClient(char n[], char a1[], char a2[], char c[], char s[], char z[]);
	bool Login(string user, string pass);
	void QuoteHistory(Quote c);
	string getName();
	string getAdd1();
	string getAdd2();
	string getCity();
	string getState();
	string getZip();
	void setName(char n);
	void setAdd1(char a);
	void setAdd2(char a);
	void setCity(char c);
	void setState(char s);
	void setZip(char z);
};

#endif
#pragma once
