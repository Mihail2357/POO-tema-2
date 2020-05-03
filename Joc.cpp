#include <iostream>
#include <fstream>
using namespace std;

#include "Cautator.h"
#include "Joc.h"
#include "Ghost_agent.h"
#include "World.h"
#include "Random_agent.h"
#include "Diagonal_agent.h"
#include "Eye_agent.h"
#include "Plus_agent.h"
#include "Treasure_agent.h"


Joc::Joc()
{

    ifstream F("1.txt");
    int x,y;
    F >> x >> y;
    w = new World(x,y);
    int X[2]= {0,x-1} ,Y[2]= {0,y-1}; //coordonate pentru cele 4 colturi
    for(int i=0; i<=1; i++)    //plasam cautatorii in cele 4 colturi
        for(int j=0; j<=1; j++)
        {
            Cautator::Position p(0,0);
            char c;
            F >> c;
            p.row=X[i];
            p.column=Y[j];
            Cautator *a;
            if(c=='E')
                a = new Eye_agent(p);
            else if(c='D')
                a = new Diagonal_agent(p);
            else if(c='P')
                a=new Plus_agent(p);
            else if(c='R')
                a=new Random_agent(p);
            w->add_agent(a,p.row,p.column);
        }
    for(int i=1; i<=3; i++)        //generam 3 comori
    {

        Cautator *b;
        int m,n;
        while(w->get_agent(m,n))
        {
            m=rand()%x;
            n=rand()%y;
        }
        Cautator::Position p(m,n);
    }

}

ostream &operator <<(ostream &out,World &wm)
{
    out <<endl <<" ";
    for(int i=0; i<2*wm.get_number_of_cols(); i++)
        out << (unsigned char)196;
    out << endl;
    for(int i=0; i<wm.get_number_of_rows(); i++)
    {
        out <<(unsigned char)179;
        for(int j=0; j<wm.get_number_of_cols(); j++)
            if(wm.get_agent(i,j)!=NULL)
                out << wm.get_agent(i,j)->get_agent_type()<<" ";
            else
                cout<<" "<<" ";
        out << (unsigned char)179;
        out << endl;
    }
    out <<" ";
    for(int i=0; i<2*wm.get_number_of_cols(); i++)
        out << (unsigned char)196;
    return out;
}

void Joc::run_round()
{
    Cautator::Position p(0,0);

    unsigned i = 0;
    vector<Cautator*> b;
    b = w->get_all_agents();
    while( i<b.size())
    {
        Cautator *a;
        Cautator::Position q(0,0);
        a = b[i];
        q = a->get_position();
        if(!w->possible_move(q.row,q.column))  //daca nu mai exista mutari, il scoatem de pe harta
        {
            w->remove_agent(a);
            delete a;
            b=w->get_all_agents();

        }
        else
        {
            p = a->choose_new_position(*w);    // daca exista mutari, il punem sa aleaga
            if(!w->get_agent(p.row,p.column))  //daca e liber, il mutam
            {
                w->move_agent(a,p.row,p.column);
                i++;
            }
            else if(w->get_agent(p.row,p.column)->get_agent_type()=="T")  // daca in locul ales e comoara, il scoatem si pe el si comoara
            {
                w->remove_agent(a);
                delete a;
                b=w->get_all_agents();
                w->remove_agent(w->get_agent(p.row,p.column));
            }



        }
    }
    cout<<endl<<*w;
}

void Joc::print_state()
{
    cout << *w;
}
