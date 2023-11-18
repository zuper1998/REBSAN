//
// Created by narcano on 11/18/23.
//

#ifndef TVG_PATH_H
#define TVG_PATH_H
#include <list>

#include "visiblity_interval.h"
#include "../Graph/Node.h"

class tvg_path {
    std::list<visiblity_interval<edge_data>> path;

public:
    tvg_path() =default;
    explicit tvg_path(const visiblity_interval<edge_data>& vi) {
        path={vi};
    }

    void push_to_front(const visiblity_interval<edge_data>& vi) {
        path.push_front(vi);
    }




    const std::list<visiblity_interval<edge_data>>& getPaths()const{return path;};

    [[nodiscard]] std::string export_path_to_graphviz(std::string from)const;
};



#endif //TVG_PATH_H
