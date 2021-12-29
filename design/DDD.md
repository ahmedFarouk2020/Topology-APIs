# Detailed Design Document

## The design consists of five classes
- APIS: contains public functions the user can use

- Topology: represent an essensial unit in design because we deals with topologies and 	
perform all operations on them using this class `Topology`

- ComponentsList: deals with Components lists and unable us to manage components

- Utils: provide common methods that are used in both `Topology` and `ComponentsList` and provide some prototypes `virtual methods` to be implemented inside those classes

- TopologyDB: represent all topologies in memory and it is inhereted by Utils

# UML Design
[](./TopologyAPIs_UML.png)