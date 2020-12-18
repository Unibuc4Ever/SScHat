#include <bits/stdc++.h>

#include "screens.h"
#include "networking.h"

using namespace std;

string AskFullScreenQuestion(string question)
{
    clear();
    int N, M;
    getmaxyx(stdscr, N, M);
    int x_act = 5, y_act = 5;
    for (auto c : question) {
        mvwaddch(stdscr, x_act, y_act, c);
        y_act++;
    }
    wrefresh(stdscr);

    x_act = 7, y_act = 5;
    wmove(stdscr, x_act, y_act);
    string s;
    while (1) {
        int c = getch();
        if (c == '\n')
            break;
        if (c == KEY_BACKSPACE) {
            if (s.empty())
                continue;
            s.pop_back();
            y_act--;
            mvwaddch(stdscr, x_act, y_act, ' ');
            wmove(stdscr, x_act, y_act);
            continue;
        }
        s.push_back(c);
        mvwaddch(stdscr, x_act, y_act, c);
        y_act++;
        wrefresh(stdscr);
    }

    return s;
}

void UpdateTextbox(WINDOW* win, string& input, string& name)
{
    if (input.back() == '\n') {
        input.pop_back();
        if (!input.empty()) {
            SendMessage(name + ": " + input);
            input.clear();
        }
    }
    string message = input;
    if (message.empty())
        message = "Type a message...";
    
    int N, M;
    getmaxyx(win, N, M);

    assert(N == 3);
    for (int i = 2; i < M - 2; i++) {
        mvwaddch(win, 1, i, ' ');
    }

    while (message.size() + 6 > M)
        message.pop_back();

    for (int i = 0; i < (int)message.size(); i++)
        mvwaddch(win, 1, i + 2, message[i]);
    wrefresh(win);
}

void UpdateMessages(WINDOW* win, std::vector <std::string>& messages)
{
    static vector <string> last_messages;
    if (messages == last_messages)
        return;
    last_messages = messages;
    wclear(win);

    int N, M;
    getmaxyx(win, N, M);

    for (int i = max(0, (int)messages.size() - N), lin = 0;
            i < (int)messages.size(); i++, lin++) {
        string s = messages[i];
        for (int j = 0; j < (int)s.size(); j++) {
            if (j >= M)
                break;
            mvwaddch(win, lin, j, s[j]);
        }
    }

    wrefresh(win);
}