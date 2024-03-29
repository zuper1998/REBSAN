//
// Created by andris on 2023.11.11..
//

#ifndef NODE_H
#define NODE_H
#include <array>
#include <list>
#include <ranges>
#include <utility>

#include "../Utility/SearchInterval.h"
#include "../Utility/visiblity_interval.h"




typedef std::list<visiblity_interval<edge_data>> edge_container;



class Node {
    edge_container edges;
    std::string name;
public:

    Node() = default;

    explicit Node(const std::string& _name) {
        name = _name;
    }
    explicit Node(const std::string& _name,edge_container _edges) {
        name = _name;
        edges = std::move(_edges);
    }

    const edge_container& getEdges() {
        return edges;
    }

    [[nodiscard]] const std::string& getName() const{
        return name;
    }

    Node(const Node&)=delete;
    Node( Node&&)=delete;

    static std::string edge_export_to_graphviz(const visiblity_interval<edge_data>& edge,const std::string &from);

    void export_to_graphviz(std::stringstream& ss) const;

    auto get_edges_between(const float _start, const float _end) {
        visiblity_interval<edge_data> v_finder(_start,_end);
        auto edge_iterator = edges  | std::views::filter([v_finder](auto &vi) {
                return vi.during(v_finder);
        });

        return edge_iterator;
    }


    auto get_edges_between(const search_interval &si) {
        auto [fst, snd]  = si.getExtendedIntervals();
        return get_edges_between(fst,snd);
    }


    void add_edge(const visiblity_interval<edge_data> & new_edge);


    bool operator==(const Node& other) const {
        return name == other.name;
    }


    friend std::ostream& operator <<(std::ostream& os,const edge_data& ed);
    friend std::ostream& operator <<(std::ostream& os,const Node& n);
    friend std::ostream& operator <<(std::ostream& os,const Node* n);

};





#endif //NODE_H
