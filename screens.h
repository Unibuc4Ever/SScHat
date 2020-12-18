#ifndef SCREENS_
#define SCREENS_

#include <curses.h>
#include <string>
#include <vector>

std::string AskFullScreenQuestion(std::string question);

void UpdateTextbox(WINDOW* win, std::string& input, std::string& name);

void UpdateMessages(WINDOW* win, std::vector <std::string>& messages);

#endif // SCREENS_