#ifndef NETWORKING_
#define NETWORKING_

#include <string>
#include <vector>

void InitializeNetworking();

void SendMessage(std::string message);

std::vector <std::string> GetLastMessages();

#endif // NETWORKING_