//
// Created by Ryan Haney on 2020-07-05.
//

#ifndef CSPROJECT_UTIL_H
#define CSPROJECT_UTIL_H

//The error function, modified to use strings.
inline void error(std::string msg)
{
    perror(msg.data());
    exit(1);
}

//A string trimming function, which removes whitespace at the beginning and end of the string.
inline std::string trim(std::string input){
    int beginning = input.find_first_not_of("\t \n");
    int end = input.find_last_not_of("\t \n");
    return input.substr(beginning, end-beginning+1);
}

#endif //CSPROJECT_UTIL_H
