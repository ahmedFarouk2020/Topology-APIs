#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

typedef json Componentlist;


class ComponentList: public Utils {
    private:
        // list of all components in a topology
        Componentlist components_list;

        
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
    public:
        ComponentList() {}
        ComponentList(Componentlist components_list) {
            this->components_list = components_list;
        }


        void create(Componentlist components_list) {
            this->components_list = components_list;
        }



        Componentlist get(string id) {
            int topology_index = search(id); 
            return TopologyDB::topology_list[topology_index]["components"];
        }
        
        Componentlist getWithNetlist(string top_id,string id) {
            int topology_index = search(top_id); 

            for(json& comp: TopologyDB::topology_list[topology_index]["components"]) {
                if(comp["netlist"][id] != nullptr) {
                    return comp;
                }
            }
            return nullptr;
        }

};




#endif