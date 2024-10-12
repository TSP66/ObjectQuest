#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <string>
#include <vector>


#define INDENT "    "
#define SELECTOR "▶   "

void setRawMode(bool enable);

void clearScreen();

int optionSelector(std::vector <std::string>);
int optionSelector(std::vector <std::string> choices, std::string topMessage, bool topMessageOn);

#endif // INPUT_H