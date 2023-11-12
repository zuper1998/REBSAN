//
// Created by andris on 2023.11.12..
//

#ifndef NODETEST_H
#define NODETEST_H
#include <gtest/gtest.h>

#include "../Algorithms/Graph/Node.h"


class NodeTest : public testing::Test {
protected:
    void SetUp() {
        n1_ = new Node("N1");
        n2_ = new Node("N2",edge_container());
        n3_ = new Node("N3",edge_container());


        visiblity_interval<edge_data> v1 (0, 3, edge_data(0.2,n2_));
        visiblity_interval<edge_data> v2 (1, 2, edge_data(0.2,n1_));
        visiblity_interval<edge_data> v3 (6, 9, edge_data(0.2,n3_));


        n1_->add_edge(v1);
        n2_->add_edge(v2);
        n2_->add_edge(v3);
    }
    Node* n1_= nullptr;
    Node* n2_= nullptr;
    Node* n3_= nullptr;


    void TearDown() {
        delete n1_;
        delete n2_;
        delete n3_;
    }



};




#endif //NODETEST_H
