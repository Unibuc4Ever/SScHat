#include <bits/stdc++.h>
#include <curses.h>

#include "screens.h"
#include "networking.h"
using namespace std;

mutex user_input_busy;
string user_input;
bool waiting_to_close;

void GetInput()
{
    timeout(100);
    while (!waiting_to_close) {
        int x = getch();
        if (x == ERR)
            continue;
        user_input_busy.lock();
        if (x == KEY_BACKSPACE && user_input.size() > 0)
            user_input.pop_back();
        else if (x <= 255)
            user_input.push_back(x);
        user_input_busy.unlock();
    }
}

int main()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    refresh();

    string name = AskFullScreenQuestion("What is your name?");
    string channel = AskFullScreenQuestion("In which channel do you want to talk?");
    string recover_chat = AskFullScreenQuestion("Should we get previous messages (Y/N)?");

    InitializeNetworking(channel, (recover_chat[0] == 'Y' || recover_chat[0] == 'y'));

    int N, M;
    getmaxyx(stdscr, N, M);

    clear();
    refresh();

    WINDOW* messages_win = newwin(N - 3, M, 0, 0);
    WINDOW* editor_win = newwin(3, M, N - 3, 0);
    box(editor_win, 0, 0);

    thread user_input_thread(GetInput);

    while (1) {
        this_thread::sleep_for(chrono::milliseconds(10));
        
        user_input_busy.lock();
        int output = UpdateTextbox(editor_win, user_input, name);
        user_input_busy.unlock();

        vector <string> messages = GetLastMessages();
        UpdateMessages(messages_win, messages);
    
        if (output == -1) {
            // quit
            break;
        }
    }

    TeminateNetworking();
    endwin();

    waiting_to_close = 1;
    user_input_thread.join();

    return 0;
}