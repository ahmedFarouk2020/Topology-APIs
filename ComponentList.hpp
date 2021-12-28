#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

typedef json Componentlist;

/*
*** provide all methods and data to deal with Components
 *
 *  Methods: create, retrieve, getWithNetlist
 */
class ComponentList: public Utils {
private:
    // list of all components in a topology
    Componentlist components_list;

    
public:
    ComponentList() {}
    ComponentList(Componentlist components_list) {
        this->components_list = components_list;
    }

    /* Store a json object locally and treat it as components_list
     *
     * Args: 
     *      components_list(json)
     * 
     * return: void
     */
    void create(Componentlist components_list) {
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
    Componentlist retrieve(string id) {
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
    Componentlist getWithNetlist(string top_id,string id) {
        int topology_index = search(top_id); 

        if(topology_index < 0) {
            return nullptr;
        }
        
        for(json& comp: TopologyDB::topology_list[topology_index]["components"]) {
            if(comp["netlist"][id] != nullptr) {
                return comp;
            }
        }
    }

};




#endif