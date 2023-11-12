//
// Created by andris on 2023.11.11..
//

#include "Node.h"

auto Node::getEdgesBetween(const float _start,const float _end) {
    visiblity_interval<edge_data> v_finder(_start,_end);
    auto edge_iterator = edges  | std::views::filter([&](auto &vi) {
            return vi.during(v_finder);
    });

    return edge_iterator;

}

void Node::add_edge(const visiblity_interval<edge_data> &new_edge) {
    edges.push_back(new_edge);
}


