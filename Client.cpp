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
