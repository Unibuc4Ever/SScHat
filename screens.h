#ifndef SCREENS_
#define SCREENS_

#include <curses.h>
#include <string>
#include <vector>

std::string AskFullScreenQuestion(std::string question);

int UpdateTextbox(WINDOW* win, std::string& input, std::string& name, bool force_refresh);

void UpdateMessages(WINDOW* win, std::vector <std::string>& messages, bool force_refresh);

#endif // SCREENS_