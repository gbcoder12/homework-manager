
#ifndef HOMEWORK_MYCMDS_H
#define HOMEWORK_MYCMDS_H

#include <string>
#include "Assignments.h"

namespace mycmds {

    std::string add(Assignments& as), remove(Assignments& as);
    void quit(Assignments& as, std::string& out_file);

}


#endif //HOMEWORK_MYCMDS_H
