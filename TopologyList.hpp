#ifndef TOPOLOGY_DB_HPP_
#define TOPOLOGY_DB_HPP_

typedef json TopologyList;

class TopologyDB
{
protected:
    static TopologyList topology_list;

};


// initialize topology list to nullptr
TopologyList TopologyDB::topology_list = nullptr;

#endif