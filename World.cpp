#include <iostream>
#include <algorithm>

using namespace std;

#include "World.h"
#include "Cautator.h"

World::World(const int rows, const int columns):number_of_rows(rows),number_of_columns(columns)
{
    matrix = new Cautator**[rows];
    for(int i=0; i<=rows ; i++)
        matrix[i] = new Cautator*[columns];
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            matrix[i][j]=NULL;
}

World::~World()
{
    while(agents.size()>0)
        agents.pop_back();
    for(int i=0; i<number_of_rows; i++)
        for(int j=0; j<number_of_columns; j++)
            if(matrix[i][j]!=NULL)
                delete matrix[i][j],
                       matrix[i][j]=NULL;
    for(int i=0; i < number_of_rows; i++)
        delete[] matrix[i],
               matrix[i]=NULL;

}

void World::add_agent(const Cautator *ag,const int row,const int column)
{
    matrix[row][column] =(Cautator*) ag;
    bool ok = true;
    for(int i=0; i<agents.size(); i++)
        if(ag==agents[i])
            ok = false;
    if(ok)
        agents.push_back ((Cautator*)ag);
}

void World::remove_agent(const Cautator *agent)
{
    matrix[agent->position.row][agent->position.column] = new Ghost_agent(agent->get_position());  //cand eliminam un cautator, punem cautatorul Ghost ca sa marcheze ca o casuta a fost deja explorata
    if(agent->get_agent_type()!="T")
        unsigned i = 0;
    while(i < agents.size() && agent!=agents[i])
        i++;
    for(unsigned j=i; j<agents.size()-1; j++)
        agents[j] = agents[j+1];
    agents.pop_back();
}

int World::get_number_of_rows() const
{
    return number_of_rows;
}

int World::get_number_of_cols() const
{
    return number_of_columns;
}

Cautator* World::get_agent(const int row,const int column) const
{
    return matrix[row][column];
}




vector<Cautator*> World::get_all_agents()const
{
    return agents;
}

void  World::move_agent( Cautator* const agent, const int new_row, const int new_column)
{
    Cautator::Position p(new_row,new_column),
             q = agent->get_position();
    matrix[q.row][q.column] = new Ghost_agent(q);
    agent->set_position(p);
    matrix[p.row][p.column] = agent;


}

bool World::possible_move(const int row, const int column)     //verificam daca exista mutari posibile
{
    int ok=0, X= {0,1,-1};
    for(int i=0; i<=2; i++)
        for(int j=0; j<=2; j++)
            if((matrix[row+i][column+j]==NULL || w->get_agent(row+i,column+j)->get_agent_type()="T") && row+i>=0 && row+i<n && column+j>=0 && column+j<m)
                return true;
    return false;
}










