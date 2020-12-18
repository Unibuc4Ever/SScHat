#ifndef NETWORKING_
#define NETWORKING_

#include <string>
#include <vector>

void InitializeNetworking(std::string channel, bool recover_chat);

void TeminateNetworking();

void SendMessage(std::string message);

std::vector <std::string> GetLastMessages();

#endif // NETWORKING_