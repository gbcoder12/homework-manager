#include <utility>
#include "Homework.h"

short Homework::uuid_count = 0;

Homework::Homework(std::string hw, char due) : hw(std::move(hw)), due(due) {
    this->UUID = Homework::uuid_count++;
}

const char Homework::get_due() { return this->due; };

const std::string Homework::get_hw() { return this->hw; }

const short Homework::get_UUID() { return this->UUID; }
