//
// Created by andris on 2023.11.11..
//

#include "time_varying_graph.h"




float calc_tvg_path_tr(const tvg_path& path) {

    auto get_min_data =[](visiblity_interval<edge_data> e1,visiblity_interval<edge_data> e2) {
        return e1.getData().first < e2.getData().first;
    };

    auto min = std::ranges::min_element(path.getPaths(),get_min_data);

    return (*min).getData().first;
}

Node& time_varying_graph::addNode(std::string name) {
    if (!nodes.contains(name)) {
        nodes.emplace(name,name);
    }
    return nodes[name];
}
Node& time_varying_graph::getNode(std::string name) {
    if (nodes.contains(name)) {
        return nodes[name];
    }
    throw std::invalid_argument("Cant find name in map");
}

std::list<tvg_path> time_varying_graph::path_from_to(Node* start,Node* dest) {

    std::list<tvg_path> ret{};



    for (auto edge : start->getEdges()) {
        Node* next_node = edge.getData().second;

        std::vector<bool> visited(nodes.size()+1,false);
        visited[getNodeIndex(start)] = true;
        visited[getNodeIndex(next_node)] = true;



        auto cur_path = path_from_to_during(next_node,dest,search_interval{edge.start,edge.end},visited);

        for (tvg_path& path : cur_path) {
            path.push_to_front(edge);
        }
        ret.splice(ret.end(),cur_path);

    }

    return  ret;
}


std::list<tvg_path> time_varying_graph::path_from_to_during(Node* start,Node* destination,search_interval si,
    std::vector<bool> visited) {


    std::list<tvg_path> ret{};
    if( REBSAN_MAX_DEPTH < std::ranges::count(visited,true) ) {
        return ret;
    };


    for (auto edge : start->get_edges_between(si)) {


        // Scope down the search interval
        search_interval n_si = si.addInterval(edge.start,edge.end);

        Node* next_node = edge.getData().second;

        if (!n_si.isValid() || visited[getNodeIndex(next_node)]) {
            continue;
        }

        if (*next_node==*destination) {
            // Add LAST edge
            ret.push_back(tvg_path{edge});
            continue;
        }


        std::vector<bool> new_map = visited;
        new_map[getNodeIndex(next_node)] = true;
        // Recursion
        auto next_path = path_from_to_during(next_node,destination,n_si, std::move( new_map));

        // Once returned from recursion it means we either ran out of interval time or we have a target
        for (tvg_path& path : next_path) {
            path.push_to_front(edge);
        }
        ret.splice(ret.end(),next_path);

    }



    return ret;
}


tvg_path time_varying_graph::getBestPath(std::list<tvg_path> paths) {

    if (paths.size()==0) {
        return {};
    }

    auto compate_tr = [](tvg_path p1,tvg_path p2) {return calc_tvg_path_tr(p1)<calc_tvg_path_tr(p2);};
    auto max = std::ranges::max_element(paths,compate_tr);

    return *max;

}

std::string time_varying_graph::export_path_to_graphviz(tvg_path path, std::string from) {
    std::stringstream ss;

    ss << "digraph {" << std::endl;
    for(auto edge : path.getPaths()) {
        ss << Node::edge_export_to_graphviz(edge,from) << std::endl;
        from = edge.getData().second->getName();
    }
    ss << "}" << std::endl;

    return ss.str();

}



std::string time_varying_graph::export_to_graphviz() {
    std::stringstream ss;

    ss << "digraph {" << std::endl;
    for(auto& data : nodes) {
        data.second.export_to_graphviz(ss);
    }
    ss << "}" << std::endl;

    return ss.str();
}


std::ostream& operator<<(std::ostream&os,const time_varying_graph& tvg) {
    for(auto &data:tvg.nodes) {
        os << data.second << std::endl;
    }

    return os;
}