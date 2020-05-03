#ifndef JOC_H
#define JOC_H


#include <string>

using namespace std;

#include "world.h"


class Joc
{
    World *w;
public :
    Joc();
    void run_round();
    void print_state();
    ~Joc()
    {
        delete w;
    }

};
#endif
