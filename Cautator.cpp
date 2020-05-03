#include <iostream>

using namespace std;

#include "Cautator.h"


void Cautator::set_position(const Position& new_position)
{
    position.row = new_position.row;
    position.column = new_position.column;
}

Cautator::Position Cautator::get_position()const
{
    return position;
}
