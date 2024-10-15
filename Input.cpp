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
    if (!rawModeOn){
        setRawMode(true);  // Enable raw input mode.
    }
    std::cout << "\033[2J\033[H";  // ANSI escape code to clear the screen.
}

int optionSelector(std::vector <std::string> choices){

    return optionSelector(choices, std::string(""), false);

}

int optionSelector(std::vector <std::string> choices, std::string topMessage, bool topMessageOn) {

    #ifndef TESTING

    clearScreen();

    int selected = 0;
    const int numChoices = choices.size();

    if (!rawModeOn){
        setRawMode(true);  // Enable raw input mode.
    }

    while (true) {

        if (topMessageOn){
            std::cout << topMessage << std::endl;
        }

        for (int i = 0; i < numChoices; ++i) {
            if (i == selected) {
                std::cout << SELECTOR << choices[i] << std::endl; // Highlight current choice.
            } else {
                std::cout << INDENT << choices[i] << std::endl;
            }
        }

        char c = getchar();

        if (c == '\033') { // If first character is ESC.
            getchar(); // skip the '[' character.
            switch(getchar()) { // the third character is the actual key code.
                case 'A':
                    selected = (selected - 1 + numChoices) % numChoices; // Up arrow.
                    break;
                case 'B':
                    selected = (selected + 1) % numChoices; // Down arrow.
                    break;
            }
        } else if (c == '\n') {
            break;
        }
        clearScreen();

    }

    clearScreen();

    
    return selected;

    #else

    return 0;

    #endif
}
