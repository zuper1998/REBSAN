//
// Created by andris on 2023.11.11..
//

#ifndef TIME_VARYING_GRAPH_H
#define TIME_VARYING_GRAPH_H
#include <forward_list>
#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <set>

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

    std::list<tvg_path> path_from_to_during(Node*,Node*,search_interval si,std::set<Node*>);

    std::list<tvg_path> path_from_to(Node*,Node*);

    std::string export_to_graphviz();

    void save_graph_to_file(std::filesystem::path);

    friend std::ostream& operator<<(std::ostream&os,const time_varying_graph& tvg);

    static tvg_path getBestPath(std::list<tvg_path>);

    static std::string export_path_to_graphviz(tvg_path path, std::string from);
};



#endif //TIME_VARYING_GRAPH_H
