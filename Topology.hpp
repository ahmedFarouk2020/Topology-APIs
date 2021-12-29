#ifndef TOPOLOGY_HPP_
#define TOPOLOGY_HPP_

/*
*** provide all methods and data to deal with topologies
 *
 *  Methods: create, append, retrieve, erase, getAll
 */

class Topology: public Utils
{
private:
    json topology;
    

public:
    Topology(json topology = nullptr){
        this-> topology = topology;
    }

    /* Store a json object locally and treat it as topology
     *
     * Args: 
     *      topology(json)
     * 
     * return: void
     */
    void create(json topology) override {
        // store topology ID
        this-> topology = topology;

    }

    /* retrieve a topology from memory with Id
     *
     * Args: 
     *      topologyId(string)
     * 
     * return: 
     *      topology(json) -> retrieved topology
     * OR
     *      nullptr -> no matching data
     */ 
    json retrieve(string& topologyId) override {
        int index = this->search(topologyId);
        if(index >= 0)
            return TopologyDB::topology_list[index];
        else
            return nullptr;
    }

    /* push back a topology(stored in private data) to memory 
     *
     * Args: void
     * 
     * return: void
     */ 
    void append(void) {
        TopologyDB::topology_list.push_back(this->topology);
    }

    /* remove a topology from memory using topology Id
     *
     * Args: 
     *      topologyId(string)
     * 
     * return: topologyId
     */ 
    string erase(string topologyId) {
        int index = this->search(topologyId);
        if(index < 0) {
            return "null";
        }
        TopologyDB::topology_list.erase(TopologyDB::topology_list.begin()+index);
        return topologyId;
    }

    /* retrieve all topologies from memory
     *
     * Args: void
     * 
     * return: 
     *      topologyList(json::array)
     */ 
    TopologyList getAll(void) {
        return TopologyDB::topology_list;
    }


};


#endif