#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include <string>
using namespace std;

#include "Cautator.h"

class World
{
private:
    Cautator ***matrix;
    vector<Cautator*>  agents;
    const int number_of_rows;
    const int number_of_columns;
public:


    World(const int rows, const int columns);

    virtual ~World();

    int get_number_of_rows() const;
    int get_number_of_cols() const;


    void add_agent(const Cautator* agent, const int row, const int column);

    void remove_agent(const Cautator* agent);


    vector<Cautator*> get_all_agents() const;

    bool possible_move(const int row, const int column);

    Cautator* get_agent(const int row, const int column) const;


    void move_agent(
        Cautator* const agent,
        const int new_row,
        const int new_column);
};

#endif
