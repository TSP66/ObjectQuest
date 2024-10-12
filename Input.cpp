#include "Input.h"

static bool rawModeOn = false;

void setRawMode(bool enable) {
    static struct termios oldt, newt;
    if (enable) {
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        rawModeOn = true;
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        rawModeOn = false;
    }
}

void clearScreen() {
    std::cout << "\033[2J\033[H";  // ANSI escape code to clear the screen
}

int options(std::string *choices, int num_choices) {
    
    int selected = 0;

    if (!rawModeOn){
        setRawMode(true);  // Enable raw input mode
    }

    while (true) {
        for (int i = 0; i < num_choices; ++i) {
            std::cout << "  " << choices[i] << std::endl;
        }

        std::cout << "> ";

        char c = getchar();

        if (c == '\033') { // If first character is ESC
            getchar(); // skip the '[' character
            switch(getchar()) { // the third character is the actual key code
                case 'A':
                    selected = (selected - 1 + num_choices) % num_choices; // Up arrow
                    break;
                case 'B':
                    selected = (selected + 1) % num_choices; // Down arrow
                    break;
            }
        } else if (c == '\n') {
            break;
        }
    }
    setRawMode(false); 

    return selected;
} 