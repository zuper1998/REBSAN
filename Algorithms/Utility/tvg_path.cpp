//
// Created by narcano on 11/18/23.
//

#include "tvg_path.h"

std::string tvg_path::export_path_to_graphviz(std::string from) const {
    std::stringstream ss;

    ss << "digraph {" << std::endl;
    for(auto edge : path) {
        ss << Node::edge_export_to_graphviz(edge,from) << std::endl;
        from = edge.getData().second->getName();
    }
    ss << "}" << std::endl;

    return ss.str();
}
