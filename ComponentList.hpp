#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

typedef json ComponentList;

/*
*** provide all methods and data to deal with Components
 *
 *  Methods: retrieve, getWithNetlistNode
 */
class Component: public Utils {

protected:
    Component() {}

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
    ComponentList retrieve(string& id) override {
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
    json getWithNetlistNode(const string& topology_id,const string& netlistNodeId) {
        int topology_index = search(topology_id); 

        // invalid topology ID
        if(topology_index < 0) {
            return nullptr;
        }
        else {
            // search for netlist node ID in the topology components
            for(json& comp: TopologyDB::topology_list[topology_index]["components"]) {

                // return the component when netlist node ID is found
                if(comp["netlist"][netlistNodeId] != nullptr) {
                    return comp;
                }
            }
            return nullptr; // no netlist node ID found
        }
    }

};




#endif