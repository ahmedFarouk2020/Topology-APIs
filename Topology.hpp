#ifndef TOPOLOGY_HPP_
#define TOPOLOGY_HPP_



class Topology: public Utils
{
private:
    /* data */
    json topology;

    
    int search(string id) {
        int index = 0;
        for( json& topology : TopologyDB::topology_list) {
            if(topology["id"] == id) {
                cout<< "\n" <<"Topology in index: " << index<< "\n";
                return index;
            }
            index++;
        }
        return -1;
    }

    

public:
    Topology(){}
    Topology(json topology){
        this-> topology = topology;
    }


    void create(json topology){
        // store topology ID
        this-> topology = topology;

    }


    json retrieve(string topologyId) {
        int index = this->search(topologyId);
        if(index >= 0)
            return TopologyDB::topology_list[index];
        else
            return nullptr;
    }

    void append(void) {
        TopologyDB::topology_list.push_back(this->topology);
    }
    void erase(string topologyId) {
        int index = this->search(topologyId);
        TopologyDB::topology_list.erase(TopologyDB::topology_list.begin()+index);
    }

    TopologyList getAll(void) {
        return TopologyDB::topology_list;
    }


};


#endif