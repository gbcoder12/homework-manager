#ifndef HOMEWORK_ASSIGNMENTS_H
#define HOMEWORK_ASSIGNMENTS_H


#include <string>
#include <vector>
#include <map>
#include "Homework.h"

class Assignments {

private:
    std::string header_string;
    std::string hw_file;
    std::vector<std::string> prev_cmds;

    // first is subject, second is the homework in that subject.
    std::map<std::string, std::vector<Homework>> subjects;

    void add_history(std::string& cmd);
    std::vector<Homework> remove_hw(std::vector<Homework>& hwlist, short uuid);

public:
    static void execute(std::string& cmd, Assignments& as);

    explicit Assignments(std::string file_name, std::string header_file_name);
    std::string prompt();
    std::map<std::string, std::vector<Homework>> get_subjects();
    std::string to_str();
    void add(std::string subj, std::string hw, char due);
    bool remove(short uuid);

};


#endif //HOMEWORK_ASSIGNMENTS_H
