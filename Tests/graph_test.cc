//
// Created by andris on 2023.11.11..
//


#include <gtest/gtest.h>

#include "NodeTest.h"
#include "../Algorithms/Graph/Node.h"

bool contains(edge_container ec, const visiblity_interval<edge_data> & target) {
    const auto it = std::ranges::find(ec, target);
    return it!=ec.end();
}

TEST(NodeT, CTOR_TEST) {
    Node n1 = Node("N1");
    Node n2 = Node("N2",edge_container());

    ASSERT_EQ(n1.getEdges().size(),0) << "Failed using default ctor for Node";
    ASSERT_EQ(n2.getEdges().size(),0) << "Failed using parameter ctor for Node";

}


TEST_F(NodeTest,AddingEdges) {

    ASSERT_NE(n1_->getEdges().size(),0) << "Edge not added";
    ASSERT_TRUE(contains(n1_->getEdges(),visiblity_interval<edge_data>(0, 3, edge_data(0.2,n2_))));

    ASSERT_TRUE(contains(n1_->getEdges(),visiblity_interval<edge_data>(0, 3, edge_data(0.2,n2_)))) << "Error in adding edge for " << n1_;
    ASSERT_TRUE(contains(n2_->getEdges(),visiblity_interval<edge_data>(1, 2, edge_data(0.2,n1_)))) << "Error in adding edge for " << n2_;
    ASSERT_TRUE(contains(n2_->getEdges(),visiblity_interval<edge_data>(6, 9, edge_data(0.2,n3_)))) << "Error in adding edge for " << n2_;

}



