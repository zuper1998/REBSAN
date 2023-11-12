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

// Add operators for the edge_data type
inline bool operator!=(const edge_data& e1,const edge_data& e2) {
    return !(e1 == e2);
}

inline std::ostream& operator<<(std::ostream& os, edge_data ed) {
    os << "Tr: " << ed.first << " Target: " << ed.second;

    return os;
}


class Node {
    edge_container edges;
public:
    Node() = default;
    explicit Node(edge_container _edges) {
        edges = std::move(_edges);
    }

    const edge_container& getEdges() {
        return edges;
    }

    void add_edge(const visiblity_interval<edge_data> & new_edge);


};



#endif //NODE_H
