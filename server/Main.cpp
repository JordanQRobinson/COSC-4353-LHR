//
// Created by Ryan Haney on 2020-07-05.
//

#include "Main.h"
using namespace std;

int main(int argc, char *argv[]){
    int mysocket = bindServerSocket(9999);
    int connectionsocket = acceptConnection(mysocket);
    string theirmessage = receiveMessage(connectionsocket);
    cout << theirmessage << endl;
    string response = "Goodbye World";
    sendMessage(connectionsocket, response);
    close(connectionsocket);
    close(mysocket);
    return 0;
}