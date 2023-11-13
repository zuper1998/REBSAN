//
// Created by andris on 2023.11.11..
//

#ifndef TIME_VARYING_GRAPH_H
#define TIME_VARYING_GRAPH_H
#include <forward_list>
#include <unordered_map>
#include <string>

#include "Node.h"

class time_varying_graph {
    std::unordered_map<std::string,Node> nodes;
public:
    const std::unordered_map<std::string,Node>& getNodes() {
        return nodes;
    }

    time_varying_graph() = default;

    Node& addNode(std::string);

    std::forward_list<visiblity_interval<edge_data>> path_from_to_during(Node*,Node*,float,float);
};



#endif //TIME_VARYING_GRAPH_H
