#ifndef HOMEWORK_HOMEWORK_H
#define HOMEWORK_HOMEWORK_H


#include <string>

class Homework {

private:
    char due;
    std::string hw;
    short UUID;

public:
    static short uuid_count;

    Homework(std::string hw, char due);
    const char get_due();
    const std::string get_hw();
    const short get_UUID();

};


#endif //HOMEWORK_HOMEWORK_H
