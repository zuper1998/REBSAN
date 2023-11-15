//
// Created by narcano on 11/14/23.
//

#ifndef GRAPHTEST_H
#define GRAPHTEST_H
#include <gtest/gtest.h>

#include "../Algorithms/Graph/Node.h"
#include "../Algorithms/Graph/time_varying_graph.h"


#define NODE_AT(i) tvg_->getNode(names[i])


class GraphTest : public testing::Test {
protected:
    void SetUp() {
        tvg_ = new time_varying_graph();
        const std::vector<std::string> names = {"A","B","C","D"};

        for (const auto name : names) {
            tvg_->addNode(name);
        }

        NODE_AT(0).add_edge(visiblity_interval<edge_data>(0,3,std::make_pair(1.0,&NODE_AT(1))));
        NODE_AT(1).add_edge(visiblity_interval<edge_data>(1,4,std::make_pair(2.0,&NODE_AT(2))));
        NODE_AT(1).add_edge(visiblity_interval<edge_data>(4,9,std::make_pair(3.0,&NODE_AT(3))));
        NODE_AT(0).add_edge(visiblity_interval<edge_data>(1,2,std::make_pair(2.0,&NODE_AT(3))));
        NODE_AT(3).add_edge(visiblity_interval<edge_data>(0,4,std::make_pair(2.0,&NODE_AT(2))));




    }
    time_varying_graph * tvg_ = nullptr;


    void TearDown() {
        delete tvg_;
    }



};


#endif //GRAPHTEST_H
