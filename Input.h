#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <termios.h>
#include <unistd.h>

void setRawMode(bool enable);

int options(const char *choices[], int num_choices);

#endif // INPUT_H