#include <iostream>
#include <fstream>
#include "Assignments.h"

int main() {
    Assignments asgm("hw-src", "header");

    while(1)
    {
        std::string s = asgm.prompt();
        Assignments::execute(s, asgm);
    }

    return 0;
}