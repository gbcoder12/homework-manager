
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <sstream>

#include "Assignments.h"
#include "mycmds.h"

// PRIVATE

void Assignments::add_history(std::string& cmd) {
    this->prev_cmds.emplace_back(cmd);
    if(this->prev_cmds.size() == 5)
        this->prev_cmds.erase(this->prev_cmds.begin());
}


// PUBLIC

Assignments::Assignments(std::string file_name, std::string header_file_name) {
    this->hw_file = file_name;

    // store content of header file into a single string
    std::ifstream header_in (header_file_name);
    std::string line;
    while(std::getline(header_in, line))
    {
        this->header_string += line + "\n";
    }
    header_in.close();

    // move all data from homework file into program
    std::ifstream hw_in (file_name);
    while(std::getline(hw_in, line))
    {
        std::stringstream ss(line);
        std::string comp;
        std::vector<std::string> comps;
        while(std::getline(ss, comp, '#'))
            comps.push_back(comp);

        this->add(comps[0], comps[1], comps[2][0]);
    }
    hw_in.close();
}

void Assignments::execute(std::string& cmd, Assignments& as) {
    std::string curr_cmd;

    if(cmd == "add")
        curr_cmd = mycmds::add(as);

    else if(cmd == "remove")
        curr_cmd = mycmds::remove(as);

    else if(cmd == "showme")
        std::cout << as.to_str() << std::endl;

    else if(cmd == "quit") mycmds::quit(as, as.hw_file);

    else
    {
        std::cout << "Command not found." << std::endl;
        return;
    }

    as.add_history(curr_cmd);
}

std::string Assignments::prompt() {
    std::system("clear");

    // print header
    std::cout << this->header_string;

    // display homework
    std::cout << this->to_str() << std::endl;

    // print previous commands
    std::cout << "Previous Commands:" << std::endl;
    for(const std::string& p_cmd : this->prev_cmds)
        std::cout << "\t" << p_cmd << std::endl;

    // execute user input
    std::cout << std::endl << "\t> ";
    std::string input;
    std::cin >> input;
    std::cout << std::endl;

    return input;
}

std::map<std::string, std::vector<Homework>> Assignments::get_subjects() {
    return this->subjects;
}

std::string Assignments::to_str() {
    std::string str;
    for(int i = 0; i < 80; i++) str += '-';
    str += "\n\n";
    for(std::pair<std::string, std::vector<Homework>> pair : this->subjects)
    {
        str += "< " + pair.first + " > :\n";
        for(Homework hw : pair.second)
        {
            str += "\t( " + std::to_string(hw.get_UUID()) + " ) ( " + hw.get_due() + " ) " + hw.get_hw() + "\n";
        }
        str += "\n";
    }
    for(int i = 0; i < 80; i++) str += '-';
    return str;
}

void Assignments::add(std::string subj, std::string hw, const char due) {
    // add hw if subject exists
    for(std::pair<std::string, std::vector<Homework>> s : this->subjects)
    {
        if (s.first == subj)
        {
            this->subjects.at(s.first).emplace_back(Homework(hw, due));
            return;
        }
    }

    // add subject and hw if subject does not exist
    this->subjects.insert(
            std::pair<std::string, std::vector<Homework>>(
                    subj,
                    std::vector<Homework> { Homework(hw, due) } ));
}

bool Assignments::remove(short uuid) {
    auto subj = this->subjects.begin();
    while(subj != this->subjects.end())
    {
        (*subj).second = remove_hw((*subj).second, uuid);
        subj++;
    }
    return true;
}

std::vector<Homework> Assignments::remove_hw(std::vector<Homework>& hwlist, short uuid) {
    std::vector<Homework> to_rtn;
    for(Homework hw : hwlist) {
        if (hw.get_UUID() != uuid) to_rtn.emplace_back(hw);
        else
            std::cout << "Homework removed!";
    }
    return to_rtn;
}



