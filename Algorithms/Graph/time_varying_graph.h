//
// Created by andris on 2023.11.11..
//

#ifndef TIME_VARYING_GRAPH_H
#define TIME_VARYING_GRAPH_H
#include <forward_list>
#include <unordered_map>
#include <string>

#include "Node.h"


typedef std::list<visiblity_interval<edge_data>> tvg_path;


class time_varying_graph {
    std::unordered_map<std::string,Node> nodes;
public:
    const std::unordered_map<std::string,Node>& getNodes() {
        return nodes;
    }

    time_varying_graph() = default;

    Node& addNode(std::string);

    Node& getNode(std::string);

    std::list<tvg_path> path_from_to_during(Node*,Node*,search_interval si);
};



#endif //TIME_VARYING_GRAPH_H
