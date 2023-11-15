//
// Created by andris on 2023.11.11..
//

#include "time_varying_graph.h"

#include <iostream>


Node& time_varying_graph::addNode(std::string name) {
    if (nodes.contains(name)) {
        std::cerr << "Double adding of node: " << name << std::endl;
    } else {
        nodes.emplace(name,name);
    }
    return nodes[name];
}
Node& time_varying_graph::getNode(std::string name) {
    if (nodes.contains(name)) {
        return nodes[name];
    }
    throw std::invalid_argument("Cant find name in map");
}


std::list<tvg_path> time_varying_graph::path_from_to_during(Node* start,Node* destination,search_interval si) {

    std::list<tvg_path> ret{};



    for (auto edge : start->get_edges_between(si)) {


        // Scope down the search interval
        search_interval n_si = si.addInterval(edge.start,edge.end);

        Node* next_node = edge.getData().second;
        std::cout<< start << " --> " << next_node << std::endl;
        // Test if new interval is too large (it returns -1)
        if (!n_si.isValid()) {
            continue;
        }

        if (*next_node==*destination) {
            // Add LAST edge
            ret.push_back({edge});
            continue;
        }
        // Recursion
        auto next_path = path_from_to_during(next_node,destination,n_si);

        // Once returned from recursion it means we either ran out of interval time or we have a target
        for (tvg_path path : next_path) {
            path.push_front(edge);
        }
        ret.splice(ret.end(),next_path);

    }



    return ret;
}