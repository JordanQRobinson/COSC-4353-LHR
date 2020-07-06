//
// Created by Ryan Haney on 2020-07-05.
//

#ifndef CSPROJECT_MESSENGER_H
#define CSPROJECT_MESSENGER_H

// During my Operating Systems Class, one of our objectives was to create a simple client/server app.
// This is some code copy-pasted from that.

// WARNING: This uses Unix sockets, so it won't work on Windows.
// It's possible to make it run on Windows by replacing sys/socket.h (and sys/types.h, maybe?) with winsock2.h and making a few relevent code changes.
// Might do that later on, but for now, I'll just use this.
#include <unistd.h> //required for the read function to work
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <math.h> //required since I use the ceiling math function.
#include "strings.h"
#include "Util.h"

void sendMessage(int sockfd, std::string message);
std::string receiveMessage(int sockfd);
int bindServerSocket(int portno);
int acceptConnection(int sockfd);
int connectToServer(std::string hostname, int portno);

#endif //CSPROJECT_MESSENGER_H
