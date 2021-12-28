#if !defined(APIS_HPP_)
#define APIS_HPP_

typedef string Result;

class APIS
{
private:
    /* data */
    Topology topology;
    ComponentList component_list;
public:
    /******* Read json file and store the content in memory(topologyList)
     * Args: filename(string)
     * return: 
     *      filename(Result): file name of the source file
     */
    Result readJSON(std::string filename) {
        // read using ifstream object
        ifstream i_file(filename);

        // pass it to json object
        this->topology.create(json::parse(i_file));

        cout<< "reading........\n\n";

        this->topology.append();

        return filename;

    }


    /******* write a topology in json format from memory to a .json file
     * Args: filename(string)
     * return: 
     *      filename(Result): file name of the saved file
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
     *      Result(string): "deleted"
     * 
     */
    Result deleteTopology(string topologyId) {
       
        this->topology.erase(topologyId);

        cout<< "Deleting..." << "\n";

        return "deleted";
    }

    /****** retrieve all topologies in memory
     *
     * Args: void
     * 
     * return: 
     *      -topologyList
     * 
     */
    TopologyList queryTopologies(void) {

        return this->topology.getAll();
    }

    /****** retrieve all components a topology
     *
     * Args: topologyId(string)
     * 
     * return: 
     *      -Componentlist(nlohmann::json)
     * 
     */
    Componentlist queryDevices(string topologyId) {
        return this->component_list.get(topologyId);
    }

    /****** retrieve all components in a given topology connected in a 
     *      given netlist node id
     *
     * Args: 
     *      -topology Id(string)
     *      -netlistNode Id(string)
     * 
     * return: 
     *      -DeviceList(nlohmann::json)
     * 
     */
    json queryDevicesWithNetlistNode(string topologyId, string netlistNodeId) {
        return this->component_list.getWithNetlist(topologyId,netlistNodeId);
    }


};





#endif // APIS_HPP_
