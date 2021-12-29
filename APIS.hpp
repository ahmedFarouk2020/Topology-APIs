#if !defined(APIS_HPP_)
#define APIS_HPP_

typedef string Result;

class APIS : protected Topology, ComponentList
{
private:

    string generateFilename(string& topology_ID) {
        return topology_ID + ".json";
    }

public:

    /******* Read json file and store the content in memory(topologyList)
     * Args: 
     *      filename(string)
     * return: 
     *      filename(Result): filename of the source file
     * OR
     *      null(string): invalid file name
     */
    Result readJSON(std::string filename) {

        // read content using ifstream object
        ifstream i_file(filename);

        if (!i_file)  // file not exist
        {
            return "null";
        }
        else   // file exists
        {
            // store the content as json object
            Topology::create(json::parse(i_file));

            // add the content(topology) to memory (TopologyList) 
            Topology::append();

            return filename;
        }

    }


    /******* write a topology from memory to a .json file
     * 
     * Args: 
     *      filename(string)
     * return: 
     *      filename(Result): filename of the saved file
     * OR
     *      null(string): invalid topology Id
     */
    Result writeJSON(string topology_ID) {

        // generate filename <topologyId>.json
        string filename = this->generateFilename(topology_ID);

        json topology = Topology::retrieve(topology_ID);

        if(topology == nullptr) // invalid topology ID
        {
            return "null";
        }
        else // topology ID exist
        {
            ofstream o_file(filename);
            o_file << std::setw(4) << topology << std::endl;
            return filename;
        }


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
       
        return Topology::erase(topologyId);
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

        return Topology::getAll();
    }

    /****** retrieve all components in a topology
     *
     * Args: topologyId(string)
     * 
     * return: 
     *      Componentlist(json)
     * OR
     *      nullptr
     * 
     */
    Componentlist queryDevices(string topologyId) {
        return ComponentList::retrieve(topologyId);
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
     * OR
     *      nullptr
     * 
     */
    json queryDevicesWithNetlistNode(string topologyId, string netlistNodeId) {
        return this->ComponentList::getWithNetlist(topologyId,netlistNodeId);
    }


};





#endif // APIS_HPP_
