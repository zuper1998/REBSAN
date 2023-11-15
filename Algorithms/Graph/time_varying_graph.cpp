//
// Created by andris on 2023.11.11..
//

#include "time_varying_graph.h"



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

std::list<tvg_path> time_varying_graph::path_from_to(Node* start,Node* dest) {

    std::list<tvg_path> ret{};



    for (auto edge : start->getEdges()) {
        Node* next_node = edge.getData().second;

        auto cur_path = path_from_to_during(next_node,dest,search_interval{edge.start,edge.end},std::set<Node*>{start ,next_node});
        for (tvg_path& path : cur_path) {
            path.push_front(edge);
        }
        ret.splice(ret.end(),cur_path);

    }

    return  ret;
}


std::list<tvg_path> time_varying_graph::path_from_to_during(Node* start,Node* destination,search_interval si,
    std::set<Node*> visited) {

    std::list<tvg_path> ret{};



    for (auto edge : start->get_edges_between(si)) {


        // Scope down the search interval
        search_interval n_si = si.addInterval(edge.start,edge.end);

        Node* next_node = edge.getData().second;
        // Test if new interval is too large (it returns -1)
        if (!n_si.isValid() || visited.contains(next_node)) {
            continue;
        }

        if (*next_node==*destination) {
            // Add LAST edge
            ret.push_back({edge});
            continue;
        }


        std::set<Node*> new_map = visited;
        new_map.insert(next_node);
        // Recursion
        auto next_path = path_from_to_during(next_node,destination,n_si, new_map);

        // Once returned from recursion it means we either ran out of interval time or we have a target
        for (tvg_path& path : next_path) {
            path.push_front(edge);
        }
        ret.splice(ret.end(),next_path);

    }



    return ret;
}