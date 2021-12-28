#if !defined(UTILS_HPP_)
#define UTILS_HPP_


/*
*** Provide common methods to be used within modules
 */

class Utils: protected TopologyDB
{

protected:
    Utils(){} // protected constructor

    /*
    *** Virtual methods (interfaces) for `ComponentsList` and `Topology` classes
    */
    virtual void create(json components_list) {}
    virtual json retrieve(string id) { return nullptr; }



    /***** Search for topology in topologyList with topology ID
     *
     * Args: topologyID(string)
     * return: 
     *      -topology index inside topologyList
     * OR
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
