#include <iostream>
#include <fstream>
#include "../nlohmann/json.hpp"
using namespace std;

using json = nlohmann::json;

#include "../TopologyList.hpp"
#include "../Utils.hpp"
#include "../Topology.hpp"
#include "../ComponentList.hpp"
#include "../APIS.hpp"

int main() {


    APIS apis = APIS();


    cout<< "\nTesting \"readJSON\" API....\n\n";
    cout<< "testcase1: Read a non-existing file\n";
    cout<< "Expected output: "<< "null\n";
    cout<< "Actual output: " <<apis.readJSON("topogy.json") << "\n\n";
    cout<< "testcase2: Read an existing file\n";
    cout<< "Expected output(filename): "<< "topology.json\n";
    cout<< "Actual output(filename): " <<apis.readJSON("topology.json") << "\n\n";
    cout<< "-----------------------------------------\n\n";
    
    apis.readJSON("top2.json"); // read the second topology

    cout<< "Testing \"writeJSON\" API....\n\n";
    cout<< "testcase1: Write a non-existing topology\n";
    cout<< "Expected output: "<< "null\n";
    cout<< "Actual output: " <<apis.writeJSON("top3") << "\n\n";
    cout<< "testcase2: Write an existing topology\n";
    cout<< "Expected output: "<< "top1.json\n";
    cout<< "Actual output: " <<apis.writeJSON("top1") << "\n\n";
    cout<< "-----------------------------------------\n\n";



    cout<< "Testing \"queryDevices\" API....\n\n";
    cout<< "testcase1: Retrieve all devices in a valid topology\n";
    cout<< "Expected output: "<< "list of all device topology\n";
    cout<< "Actual output: " <<apis.queryDevices("top1") << "\n\n";
    cout<< "testcase2: Retrieve devices of a non-existing topology\n";
    cout<< "Expected output: "<< "null\n" ;
    cout<< "Actual output: " <<apis.queryDevices("top3") << "\n\n";
    cout<< "-----------------------------------------\n\n";



    cout<< "Testing \"queryDevicesWithNetlistNode\" API....\n\n";
    cout<< "testcase1: Retrieve all devices in a valid topology that connects to valid netlistnode ID\n";
    cout<< "Expected output: "<< "list of all devices connected to this netlistnode in a specified topology\n";
    cout<< "Actual output: " <<apis.queryDevicesWithNetlistNode("top1","drain") << "\n\n";
    cout<< "testcase2: Retrieve devices from a non-existing topology with valid netlistnode\n";
    cout<< "Expected output: "<< "null\n" ;
    cout<< "Actual output: " <<apis.queryDevicesWithNetlistNode("top3","drain") << "\n\n";
    cout<< "testcase3: non-existing topology with non-existing netlistnode\n";
    cout<< "Expected output: "<< "null\n" ;
    cout<< "Actual output: " <<apis.queryDevicesWithNetlistNode("top3","a2") << "\n\n";
    cout<< "testcase4: valid topology with non-existing netlistnode\n";
    cout<< "Expected output: "<< "null\n" ;
    cout<< "Actual output: " <<apis.queryDevicesWithNetlistNode("top1","a2") << "\n\n";
    cout<< "-----------------------------------------\n\n";



    cout<< "Testing \"queryTopologies\" API....\n\n";
    cout<< "testcase1: Retrieve all topologies from a non-empty \n";
    cout<< "Expected output: "<< "list of all topologies\n";
    cout<< "Actual output: " <<apis.queryTopologies() << "\n\n";

    // delete the stored topology
    apis.deleteTopology("top1");
    apis.deleteTopology("top2"); 

    cout<< "testcase2: Retrieve empty topologyList\n";
    cout<< "Expected output: "<< "empty list\n";
    cout<< "Actual output: " <<apis.queryTopologies() << "\n\n";
    cout<< "-----------------------------------------\n\n";



    cout<< "Testing \"deleteTopology\" API....\n\n";
    cout<< "testcase1: Delete a non-existing topology\n";
    cout<< "Expected output: "<< "null\n";
    cout<< "Actual output: " <<apis.deleteTopology("top3") << "\n\n";

    // read deleted topologies 
    apis.readJSON("topology.json");
    apis.readJSON("top2.json");

    cout<< "testcase2: Delete an existing topology\n";
    cout<< "Expected output: "<< "top1\n";
    cout<< "Actual output: " <<apis.deleteTopology("top1") << "\n\n";
    cout<< "-----------------------------------------\n\n";


    return 0;
}
