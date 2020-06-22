#ifndef CLIENT_H
#define CLIENT_H

#include <string>
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
};

#endif
#pragma once
