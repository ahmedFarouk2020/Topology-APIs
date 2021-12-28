#include <iostream>
#include <fstream>
#include "../topology_apis/nlohmann/json.hpp"
using namespace std;

using json = nlohmann::json;

#include "TopologyList.hpp"
#include "Utils.hpp"
#include "Topology.hpp"
#include "ComponentList.hpp"
#include "APIS.hpp"

int main() {


    APIS apis = APIS();
    //cout<< apis.readJSON("topology.json") << "\n\n";

    cout<< apis.writeJSON("top2")<< "\n\n";

    cout<< "Devices: \n" << apis.deleteTopology("top5");

    return 0;
}


// int main() {

//     json ob ;
//     ifstream i("topology.json");

//     i>> ob;

//     Topology topo = Topology(ob);
//     topo.append();

//     topo.create(json::parse(R"({"id":"top2"})"));
//     topo.append();


//     ComponentList comps = ComponentList();

//     cout << "Components: \n" <<comps.get("top1") <<"\n\n";
//     cout<< "Components with netlist:\n" <<comps.getWithNetlist("top1","t1")<<"\n\n";

//     cout<< "Data retrieved: \n" << topo.retrieve("top1");
//     cout<< "Topology in database: "<< topo.getAll() << "\n\n";
//     topo.erase("top1");
//     cout<< "Topology in database: "<< topo.getAll() << "\n\n";

//     cout<< "done";



//     return 0;
// }