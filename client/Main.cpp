//
// Created by Ryan Haney on 2020-07-05.
//

#include "Main.h"
using namespace std;

int main(int argc, char *argv[]){
    int connectionsocket = connectToServer("localhost", 9999);
    string mymessage = "Hello World";
    sendMessage(connectionsocket, mymessage);
    string theirmessage = receiveMessage(connectionsocket);
    cout << theirmessage << endl;
    return 0;
}