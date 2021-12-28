#if !defined(UTILS_HPP_)
#define UTILS_HPP_

class Utils: public TopologyDB
{

protected:
    virtual void create(json components_list) {}
    virtual json get(string id) { return nullptr; }

    /***** search for topology in topologyList with topology ID
     *
     * Args: topologyID(string)
     * return: 
     *      -topology index in topologyList
     *      -int(-1) if no matched topology
     */
    int search(string id) {
        int index = 0;
        for( json& topology : TopologyDB::topology_list) {
            if(topology["id"] == id) {
                cout<< "Topology in index: " << index<< "\n";
                return index;
            }
            index++;
        }
        return -1;
    }
};



#endif // UTILS_HPP_
