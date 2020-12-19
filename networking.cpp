#include <bits/stdc++.h>

#include "networking.h"
extern "C" {
#include "Telemetry/Client/telemetry.h"
}
using namespace std;

namespace {
    mutex vec_messages_is_busy;
    static vector <string> vec_messages;
    string broadcast_channel;

    void callback(const char *channel, const char *message) {
        string str_message(message);
        vec_messages_is_busy.lock();
        vec_messages.push_back(str_message);
        // if more than 200 elements, then take last 100
        if (vec_messages.size() > 200) {
            reverse(vec_messages.begin(), vec_messages.end());
            while (vec_messages.size() > 100)
                vec_messages.pop_back();
            reverse(vec_messages.begin(), vec_messages.end());
        }
        vec_messages_is_busy.unlock();
    }
}



void InitializeNetworking(string channel, bool recover_chat)
{
    broadcast_channel = channel;
    InitializeTelemetry();

    if (recover_chat) {
        int nr;
        char **channels, **messages;
        GetSyncHistory(channel.c_str(), 100, &nr, &channels, &messages);
        for (int i = nr - 1; i >= 0; i--) {
            string s(messages[i]);
            free(channels[i]);
            free(messages[i]);
            vec_messages.push_back(s);
        }
        free(channels);
        free(messages);
    }

    RegisterCallback(channel.c_str(), callback);
}

void TeminateNetworking()
{
    CloseTelemetry();
}

void SendMessage(std::string message)
{
    BroadcastTelemetry(broadcast_channel.c_str(), message.c_str());
}

std::vector <std::string> GetLastMessages()
{
    vector <string> ans;
    vec_messages_is_busy.lock();
    ans = vec_messages;
    vec_messages_is_busy.unlock();
    return ans;
}
