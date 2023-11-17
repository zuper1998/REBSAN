//
// Created by andris on 2023.11.11..
//


#include <gtest/gtest.h>

#include "NodeTest.h"
#include "GraphTest.h"
#include "../Algorithms/Graph/Node.h"
#include "../Algorithms/Graph/time_varying_graph.h"
#include "../Algorithms/Utility/file_utility.h"

bool contains(edge_container ec, const visiblity_interval<edge_data> & target) {
    const auto it = std::ranges::find(ec, target);
    return it!=ec.end();
}

TEST(NodeTestNoF, CTOR_TEST) {
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



TEST_F(NodeTest,RangeFindTest) {

    int cnt = 0;
    auto edges = n2_->get_edges_between(0,11);
    for (auto e : edges ) {
        cnt ++;

    }
    ASSERT_EQ(2,cnt) << "Wrong number of edges printes: " << cnt;

}


TEST(TestGraph,CTORTest) {
    time_varying_graph tvg{};

    ASSERT_EQ(tvg.getNodes().size(),0);
}

TEST(TestGraph,BasicFuntions) {
    time_varying_graph tvg{};
    ASSERT_EQ(tvg.getNodes().size(),0);

    tvg.addNode("AAA");

    ASSERT_EQ(tvg.getNodes().size(),1) << "Failed adding node";

    Node &n =  tvg.addNode("AAA");

    ASSERT_NE(tvg.getNodes().size(),2) << "Node was added two times ";

    ASSERT_STREQ(n.getName().c_str(),"AAA");

    Node &n2 = tvg.getNode("AAA");

    ASSERT_EQ(n,n2);


}


TEST_F(GraphTest, PathGeneration) {
    Node& start = tvg_->getNode("A");
    Node& destination = tvg_->getNode("C");

    const auto data = tvg_->path_from_to(&start,&destination);


    ASSERT_EQ(data.size(),3);
}



TEST(BigGraphTest, PathGeneration) {
    time_varying_graph tvg= file_utility::load_tvg_from_file("/home/narcano/CLionProjects/REBSAN/TestInput/TEST_SAT.sat");

    Node& start = tvg.getNode("B");
    Node& destination = tvg.getNode("H");

    const auto data = tvg.path_from_to(&start,&destination);
    /*for(const tvg_path& path : data) {
        for(auto edge : path) {
            std::cout<< edge << " || ";
        }

        std::cout<<std::endl;

    }*/


    ASSERT_EQ(data.size(),18);

    //std::cout << tvg.export_to_graphviz();

    tvg_path best = time_varying_graph::getBestPath(data);

    //std::cout << time_varying_graph::export_path_to_graphviz(best,start.getName());


}





