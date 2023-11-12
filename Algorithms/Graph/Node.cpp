//
// Created by andris on 2023.11.11..
//

#include "Node.h"

void Node::add_edge(const visiblity_interval<edge_data> &new_edge) {
    edges.push_back(new_edge);
}
