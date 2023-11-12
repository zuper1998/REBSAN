//
// Created by andris on 2023.11.11..
//


#include <gtest/gtest.h>

#include "../Algorithms/Graph/Node.h"


TEST(NodeTest, BasicAssertions) {
    Node n1 = Node();
    Node n2 = Node(edge_container());

    visiblity_interval<edge_data> v_new (0, 3, edge_data(0.2,&n2));

    ASSERT_EQ(n1.getEdges().size(),0) << "Failed using default ctor for Node";
    ASSERT_EQ(n2.getEdges().size(),0) << "Failed using parameter ctor for Node";


    n1.add_edge(v_new);

    ASSERT_NE(n1.getEdges().size(),0) << "Edge not added";
    ASSERT_EQ(n1.getEdges()[0],visiblity_interval<edge_data>(0, 3, edge_data(0.2,&n2))) << "Error in adding edge";







}
