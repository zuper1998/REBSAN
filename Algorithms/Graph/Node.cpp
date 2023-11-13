//
// Created by andris on 2023.11.11..
//

#include "Node.h"


void Node::add_edge(const visiblity_interval<edge_data> &new_edge) {
    edges.push_back(new_edge);
}


// Add operators for the edge_data type
bool operator!=(const edge_data& e1,const edge_data& e2) {
    return !(e1 == e2);
}

std::ostream& operator<<(std::ostream& os, const edge_data& ed) {
    os << "Tr: " << ed.first << " Target: " << *ed.second;

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
