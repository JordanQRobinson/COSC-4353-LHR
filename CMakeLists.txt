cmake_minimum_required(VERSION 3.13)
project(csproject)
set(CMAKE_CXX_STANDARD 14)

#set(CMAKE_SYSTEM_NAME Linux)

add_executable(csproject_server server/Main.h server/Main.cpp server/Pricing.h server/Pricing.cpp server/Server.h server/Server.cpp common/Quote.h common/Quote.cpp common/Messenger.h common/Messenger.cpp common/Util.h)
add_executable(csproject_client client/Main.h client/Main.cpp client/Client.h client/Client.cpp common/Quote.h common/Quote.cpp common/Messenger.h common/Messenger.cpp common/Util.h)

#set(CMAKE_SYSTEM_NAME Windows)
#
#add_executable(csproject_server_windows server/Main.h server/Main.cpp)
#add_executable(csproject_client_windows client/Main.h client/Main.cpp)