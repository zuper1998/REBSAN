//
// Created by andris on 2023.11.16..
//

#ifndef LOAD_TVG_H
#define LOAD_TVG_H
#include <string>
#include <filesystem>
#include <fstream>
#include <string>

#include "../Graph/time_varying_graph.h"


namespace fs = std::filesystem;

class file_utility {
public:
    static time_varying_graph load_tvg_from_file(const std::string &file);

    static std::string load_from_file(const fs::path& path);
};


inline bool parse_line(const std::string& line, float& start, float& end, std::string& from_node,std::string& to_node,  float& data) {
    std::stringstream ss{line};
    std::string data_segment;

    int index = 0;
    while (getline(ss,data_segment,'|') ) {
        uint8_t delim = data_segment.find(": ");
        data_segment.erase(0,delim+2);
        std::string::iterator end_pos = std::remove(data_segment.begin(), data_segment.end(), ' ');
        data_segment.erase(end_pos, data_segment.end());

        switch (index) {
            case 0:
                start = std::stof(data_segment);
            break;
            case 1:
                end = std::stof(data_segment);
            break;
            case 2:
                from_node = data_segment;
            break;
            case 3:
                to_node = data_segment;
            break;
            case 4:
                data = std::stof(data_segment);
            break;
            default:
                std::cerr << "Error reading in " << data_segment << " index: "<<index;
                return false;
            break;
        }
        index++;
    }
    return true;
}




// Data needed: start, end, from, to, tr data (float)
inline time_varying_graph file_utility::load_tvg_from_file(const std::string& file) {
    const fs::path path{file};

    if(!fs::exists(path)) {
        std::cerr << "File not found returning!";
        return {};
    }

    std::ifstream f(path, std::ios::in | std::ios::binary);

    time_varying_graph ret{};

    std::string line;
    while( getline(f,line) ) {

        float start, end=0;
        std::string from_node,to_node;
        float data;

        if(parse_line(line,start,end,from_node,to_node,data)) {
            Node& from = ret.addNode(from_node);
            Node& to = ret.addNode(to_node);
            from.add_edge(visiblity_interval<edge_data>{start,end,std::make_pair(data,&to)});
        }
    }









    return ret;
}

inline std::string file_utility::load_from_file(const fs::path& path) {
    std::ifstream f(path, std::ios::in | std::ios::binary);
    const auto file_size = fs::file_size(path);

    std::string file_data(file_size,'\0');

    f.read(file_data.data(),file_size);

    return file_data;
}


#endif //LOAD_TVG_H
