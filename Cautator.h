#ifndef CAUTATOR_H
#define CAUTATOR_H


#include <string>
using namespace std;

//#include "World.h"

class World;

class Cautator
{
public:


    struct Position
    {
        int row;
        int column;

        Position(const int r, const int c)
        {
            row = r;
            column = c;
        }

        bool operator==(const Position &p)
        {
            if(p.row==row && p.column==column)
                return true;
            return false;
        }
    };



protected:

    void set_position(const Position& new_position);
    struct Position position;
public:


    Cautator(Position p) : position(p) {};

    virtual ~Cautator() {};


    Position get_position() const;


    virtual string get_agent_type() const =0;


    virtual Position choose_new_position(const World& world) const =0;


    friend class World;
};

#endif
