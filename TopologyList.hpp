#ifndef TOPOLOGY_DB_HPP_
#define TOPOLOGY_DB_HPP_

typedef json TopologyList;


/*
***  Acts as a database of all topologies (in memory)
 */
class TopologyDB
{
protected:
    TopologyDB(){} // protected constructor

    // represent all topologies in memory
    static TopologyList topology_list;

};


// initialize topology list to nullptr
TopologyList TopologyDB::topology_list = nullptr;

#endif