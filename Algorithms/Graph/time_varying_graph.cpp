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
