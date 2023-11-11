//
// Created by andris on 2023.11.11..
//

#ifndef NODE_H
#define NODE_H
#include <array>
#include <vector>

#include "../Utility/visiblity_interval.h"

class Node;

typedef std::pair<float,Node*> edge_data;


class Node {
    std::vector<visiblity_interval<edge_data>> edges;
};



#endif //NODE_H
