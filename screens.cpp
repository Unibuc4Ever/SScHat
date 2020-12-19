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
        if (s.size() > 20)
            continue;
        s.push_back(c);
        mvwaddch(stdscr, x_act, y_act, c);
        y_act++;
        wrefresh(stdscr);
    }

    return s;
}

int UpdateTextbox(WINDOW* win, string& input, string& name, bool force_refresh)
{
    if (!input.empty() && input.back() == '\n') {
        input.pop_back();
        if (input == ":q")
            return -1;
        if (!input.empty()) {
            SendMessage(name + ": " + input);
            input.clear();
        }
    }
    
    int N, M;
    getmaxyx(win, N, M);
    assert(N == 3);

    string message = input;
    bool move_to_begin = 0;
    if (message.empty()) {
        move_to_begin = 1;
        message = "Type a message...";
        string s2 = ":q to quit";
        while (message.size() + s2.size() + 6 < M)
            message.push_back(' ');
        
        if (message.size() + s2.size() + 6 <= M)
            message += s2;
    }

    for (int i = 2; i < M - 2; i++) {
        mvwaddch(win, 1, i, ' ');
    }

    while (message.size() + 6 > M)
        message.pop_back();

    for (int i = 0; i < (int)message.size(); i++)
        mvwaddch(win, 1, i + 2, message[i]);
    if (move_to_begin)
        wmove(win, 1, 2);
    wrefresh(win);
    return 0;
}

void UpdateMessages(WINDOW* win, std::vector <std::string>& messages, bool force_refresh)
{
    static vector <string> last_messages;
    if (messages == last_messages && !force_refresh)
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