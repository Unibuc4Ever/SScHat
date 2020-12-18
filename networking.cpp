#include <bits/stdc++.h>

#include "networking.h"

using namespace std;

namespace {
    static vector <string> vec_messages;
}

void InitializeNetworking() { }

void SendMessage(std::string message)
{
    vec_messages.push_back(message);
}

std::vector <std::string> GetLastMessages()
{
    return vec_messages;
}
