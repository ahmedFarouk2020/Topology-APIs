#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_



/*
*** provide all methods and data to deal with Components
 *
 *  Methods: create, retrieve, getWithNetlistNode
 */
class ComponentList: public Utils {
private:
    // list of all components in a topology
    json components_list;

    
protected:
    ComponentList(json components_list = nullptr) {
        this->components_list = components_list;
    }

    /* Store a json object locally and treat it as components_list
     *
     * Args: 
     *      components_list(json)
     * 
     * return: void
     */
    void create(json components_list) override {
        this->components_list = components_list;
    }


    /* retrieve a components_list from memory with topology Id
     *
     * Args: 
     *      topologyId(string)
     * 
     * return: 
     *      Componentlist(json) -> retrieved Component list
     * OR
     *      nullptr -> no matching data
     */ 
    json retrieve(string& id) override {
        int topology_index = search(id);
        if(topology_index < 0) {
            return nullptr;
        }
        return TopologyDB::topology_list[topology_index]["components"];
    }
    

    /****** retrieve all components in a given topology connected to a 
     *      given netlist node (private method)
     *
     * Args: 
     *      -topology Id(string)
     *      -netlistNode Id(string)
     * 
     * return: 
     *      Componentlist(json)-> matched components
     * OR
     *      nullptr: no matched components
     * 
     */
    json getWithNetlistNode(const string& topology_id,const string& id) {
        int topology_index = search(topology_id); 

        // invalid topology ID
        if(topology_index < 0) {
            return nullptr;
        }
        else {
            // search for netlist node ID in the topology components
            for(json& comp: TopologyDB::topology_list[topology_index]["components"]) {

                // return netlist node ID if found
                if(comp["netlist"][id] != nullptr) {
                    return comp;
                }
            }
            return nullptr; // no netlist node ID found
        }
    }

};




#endif