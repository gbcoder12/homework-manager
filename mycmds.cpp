#include <cstdlib>
#include <iostream>
#include <fstream>
#include "mycmds.h"
#include "Assignments.h"

std::string mycmds::add(Assignments& as) {
    std::string curr_cmd = "add ";

    std::cout << "Subject: ";
    std::string input_s;
    std::cin >> input_s;
    curr_cmd += input_s + " ";

    std::cout << "Homework: ";
    std::string input_h;
    std::cin >> input_h;
    curr_cmd += input_h + " ";

    std::cout << "Due: ";
    std::string input_d;
    std::cin >> input_d;
    curr_cmd += input_d + " ";

    as.add(input_s, input_h, input_d[0]);

    return curr_cmd;
}

std::string mycmds::remove(Assignments& as) {
    std::string curr_cmd = "remove ";

    std::cout << "UUID of homework to remove: ";
    std::string input_uuid;
    std::cin >> input_uuid;
    curr_cmd += input_uuid;

    if(as.remove(static_cast<short>(std::stoi(input_uuid))))
        std::cout << "Homework successfully removed!" << std::endl;
    else
        std::cout << "Homework w/ UUID " + input_uuid + " not found." << std::endl;

    return curr_cmd;
}

void mycmds::quit(Assignments& as, std::string& out_file) {
    std::ofstream out (out_file);
    for(std::pair<std::string, std::vector<Homework>> pair : as.get_subjects())
    {
        for(Homework hw : pair.second)
            out << pair.first+"#"+hw.get_hw()+"#"+hw.get_due()+'\n';
    }
    out.close();
    std::exit(0);
}
