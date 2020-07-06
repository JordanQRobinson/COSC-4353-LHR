//
// Created by Ryan Haney on 2020-07-05.
//
#include "Messenger.h"
using namespace std;

//Function (on both client and server) that is used to send a message. First sends a number to the other side specifying the number of buffers-worth it's sending, then sends the data.
//Can handle messages up to about 127*255 or 32,385 characters in length, since the number of chunks is stored in a char (which I think is signed).
void sendMessage(int sockfd, string message){
    int n;
    char buffer[256];
    char chunks = ceil(message.size()/255.0);
    n = write(sockfd, &chunks, 1);
    if(n < 0){
        error("ERROR ON WRITE");
    }
    for(int i = 0; i < message.size(); i+=255){
        bzero(buffer, 256);
        strncpy(buffer, message.substr(i, 255).data(), 255);
        n = write(sockfd, buffer, 255);
        if(n < 0){
            error("ERROR ON WRITE");
        }
    }
}

//Function (on both client and server) that is used to send a message. First receives a number from the other side specifying the number of buffers-worth it's sending, then receives that data.
//Returns the final message as a string.
//Can handle messages up to about 127*255 or 32,385 characters in length, since the number of chunks is stored in a char (which I think is signed).
string receiveMessage(int sockfd){
    int n;
    char chunks;
    n = read(sockfd, &chunks, 1);
    if(n < 0){
        error("READ FAILED");
    }
    char buffer[256];
    string result;
    for(int i = 0; i < chunks; i++){
        bzero(buffer, 256); //zero out the buffer.
        n = read(sockfd, buffer, 255); //Tries to read message from buffer. Will block until there is a message to read.
        //BLOCK UNTIL GET MESSAGE HERE
        result.append(buffer);
        if(n < 0)
            error("READ FAILED"); //Error on read if this runs.
    }
    return result;
}

//Function that binds the server to a socket, runs when the server first starts after getting the port number.
//Returns the sockfd of the bound socket.
int bindServerSocket(int portno){
    int sockfd;
    sockaddr_in serv_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0); //First value is either AF_UNIX if shares filesystem, or AF_INET over internet. Second is either SOCK_DGRAM or SOCK_STREAM. Third is 0, which defaults to UDP for SOCK_DGRAM or TCP for SOCK_STREAM.
    bzero((char *) &serv_addr, sizeof(serv_addr)); //Sets all values in the serv_addr struct to 0.
    serv_addr.sin_family = AF_INET; //First field of sockaddr_in type: sin_family. ALWAYS set to AF_INET.
    serv_addr.sin_port = htons(portno); //Second field: sin_port. Port of the server, use htons to convert the number to network ordering.
    serv_addr.sin_addr.s_addr = INADDR_ANY; //Third field: sin_addr. Contains actual address, stored in subfield s_addr. Set to INADDR_ANY if the address is this machine's address.
    if(::bind(sockfd, (sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) { //Bind: binds a socket to an address. First is the socket file descriptor, second is the address to bind the socket to, third is the length of the address.
        error("Binding failed");
    }//if this runes, the binding failed
    listen(sockfd,5); //Allows the process to start listening for connection, with the max number of waiting connections usually being 5 here. Doesn't actually start blocking until the accept call later on.
    return sockfd;
}

//Function that Blocks until a connection is received, and then returns the sockfd of the new connection.
int acceptConnection(int sockfd){
    int newsockfd;
    sockaddr_in client_addr;
    int clilen = sizeof(client_addr);
    newsockfd=accept(sockfd, (sockaddr *) &client_addr, (socklen_t *) &clilen); //Accept: waits until the server can accept a connection from the client. Returns a new socketfd that is used for the client.
    //BLOCK UNTIL CONNECTED HERE
    if(newsockfd < 0){
        error("ACCEPT CALL FAILED");
    }//if this runs the accept call failed for some reason.
    return newsockfd;
}

//Function that connects to the server with the given (string) hostname and port number.
//Returns the created sockfd as an int.
int connectToServer(string hostname, int portno){
    int sockfd;
    sockaddr_in serv_addr;
    hostent *server; //Hostent: defines a host computer on the internet.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        exit(1); //error opening socket if this runs.
    }
    server = gethostbyname(hostname.data());
    if(server == NULL){
        cout << "No such host" << endl;
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr)); //sets all values of the server address to zero.
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length); //copies the address from server to the serv_addr.
    serv_addr.sin_port = htons(portno);
    if(connect(sockfd, (sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("CAN'T CONNECT TO SERVER");
    return sockfd;
}