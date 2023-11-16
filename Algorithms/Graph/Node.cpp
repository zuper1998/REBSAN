//
// Created by andris on 2023.11.11..
//

#include "Node.h"

#include <sstream>
#include "Node.h"

std::string edge_export_to_graphviz(const visiblity_interval<edge_data>& edge,const std::string &from) {


    char* label_data = new char[200];
    sprintf(label_data,"%s -> %s [label=\"[%f, %f] - %f \"]",from.c_str(),edge.getData().second->getName().c_str(),edge.start,edge.end,edge.getData().first);

    // Clang version
    //std::string label_data = std::format("%s -> %s [label=\"[%f, %f] - %f \"]",from,data.second->getName(),start,end,data.first);


    return label_data;
}


std::string Node::export_to_graphviz() const {
    std::stringstream ss;
    for(visiblity_interval<edge_data> edge : edges) {
        ss << edge_export_to_graphviz(edge,name) << std::endl;
    }
    return ss.str();
}

void Node::add_edge(const visiblity_interval<edge_data> &new_edge) {
    edges.push_back(new_edge);
}


// Add operators for the edge_data type
bool operator!=(const edge_data& e1,const edge_data& e2) {
    return !(e1 == e2);
}

std::ostream& operator<<(std::ostream& os, const edge_data& ed) {
    os << " Tr: " << ed.first << " Target: " << *ed.second;

    return os;
}


std::ostream& operator<<(std::ostream& os, const Node& n) {
    os << n.name;

    return os;
}

std::ostream& operator<<(std::ostream& os, const Node *  n) {
    os << n->name;

    return os;
}
