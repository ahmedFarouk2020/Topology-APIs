# Design Document

## The design consists of five classes
- APIS: contains public functions(APIs) the user can use

- Topology: represent an essensial unit in design because we deals with topologies and perform all operations on them using this class `Topology`

- Component: enable us to manage components

- Utils: provide common methods that are used in both `Topology` and `Component`

- TopologyDB: represent all topologies in memory and it is inhereted by Utils

# UML Design
[<img src="../images/TopologyAPIs_UML.png" width="600" height="800" />](../images/TopologyAPIs_UML.png)
