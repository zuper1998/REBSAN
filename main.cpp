#include <iostream>

#include "Algorithms/Graph/time_varying_graph.h"
#include "Algorithms/Utility/file_utility.h"

int main() {
    std::cout << "Init tvg" <<std::endl;
    time_varying_graph tvg= file_utility::load_tvg_from_file("/home/narcano/IdeaProjects/OrekitSatGenForC/Test_QSAT_RETRO_LOWMID1.txt.sat");
    tvg.setDepth(6);

    std::cout << "Done init"<<std::endl;

    Node& start = tvg.getNode("Test_70_45");
    Node& destination = tvg.getNode("Test_20_30");

    const auto data = tvg.path_from_to(&start,&destination);
    for(const tvg_path& path : data) {
        for(auto edge : path.getPaths()) {
            std::cout<< edge << " || ";
        }

        std::cout<<std::endl;

    }



    std::cout << tvg.export_to_graphviz();

    tvg_path best = time_varying_graph::getBestPath(data);

    std::cout << time_varying_graph::export_path_to_graphviz(best,start.getName());

}
