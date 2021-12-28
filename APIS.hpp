#if !defined(APIS_HPP_)
#define APIS_HPP_

typedef string Result;

class APIS
{
private:

    Topology topology;
    ComponentList component_list;

public:
    /******* Read json file and store the content in memory(topologyList)
     * Args: 
     *      filename(string)
     * return: 
     *      filename(Result): filename of the source file
     */
    Result readJSON(std::string filename) {

        // read content using ifstream object
        ifstream i_file(filename);

        // store the content as json object
        this->topology.create(json::parse(i_file));

        // add the content(topology) to memory (TopologyList) 
        this->topology.append();

        return filename;

    }


    /******* write a topology from memory to a .json file
     * 
     * Args: 
     *      filename(string)
     * return: 
     *      filename(Result): filename of the saved file
     */
    Result writeJSON(string topology_ID) {

        // generate filename <topologyId>.json
        string filename = topology_ID + ".json";

        ofstream o_file(filename);

        o_file << std::setw(4) << this->topology.retrieve(topology_ID) << std::endl;

        return filename;

    }

    /******* delete topology from topologyList(memory) with topology Id
     * Args: 
     *      topologyId(string)
     * 
     * return:
     *      Result(string): topology ID of deleted one
     * OR
     *      null(string): no matched data
     * 
     */
    Result deleteTopology(string topologyId) {
       
        return this->topology.erase(topologyId);
    }

    /****** retrieve all topologies in memory
     *
     * Args: void
     * 
     * return: 
     *      topologyList
     * 
     */
    TopologyList queryTopologies(void) {

        return this->topology.getAll();
    }

    /****** retrieve all components in a topology
     *
     * Args: topologyId(string)
     * 
     * return: 
     *      Componentlist(json)
     * 
     */
    Componentlist queryDevices(string topologyId) {
        return this->component_list.retrieve(topologyId);
    }


    /****** retrieve all components in a given topology connected to a 
     *      given netlist node
     *
     * Args: 
     *      -topology Id(string)
     *      -netlistNode Id(string)
     * 
     * return: 
     *      DeviceList(json)
     * 
     */
    json queryDevicesWithNetlistNode(string topologyId, string netlistNodeId) {
        return this->component_list.getWithNetlist(topologyId,netlistNodeId);
    }


};





#endif // APIS_HPP_
