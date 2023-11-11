//
// Created by andris on 2023.11.11..
//

#ifndef NODE_H
#define NODE_H
#include <array>
#include <utility>
#include <vector>

#include "../Utility/visiblity_interval.h"

class Node;

typedef std::pair<float,Node*> edge_data;

typedef std::vector<visiblity_interval<edge_data>> edge_container;

class Node {
    edge_container edges;
public:
    Node();
    explicit Node(std::vector<visiblity_interval<edge_data>> _edges) {
        edges = std::move(_edges);
    }

    const edge_container& getEdges() {
        return edges;
    }
};



#endif //NODE_H
