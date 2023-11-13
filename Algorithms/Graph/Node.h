//
// Created by andris on 2023.11.11..
//

#ifndef NODE_H
#define NODE_H
#include <array>
#include <list>
#include <ranges>
#include <utility>
#include <vector>

#include "../Utility/visiblity_interval.h"

class Node;

typedef std::pair<float,Node*> edge_data;

typedef std::list<visiblity_interval<edge_data>> edge_container;



class Node {
    edge_container edges;
    std::string name;
public:

    explicit Node(const std::string& _name) {
        name = _name;
    }
    explicit Node(const std::string& _name,edge_container _edges) {
        name = _name;
        edges = std::move(_edges);
    }

    const edge_container& getEdges() {
        return edges;
    }

    auto getEdgesBetween(float _start, float _end);

    void add_edge(const visiblity_interval<edge_data> & new_edge);

    friend std::ostream& operator <<(std::ostream& os,const Node& n);
    friend std::ostream& operator <<(std::ostream& os,const Node* n);

};





#endif //NODE_H
