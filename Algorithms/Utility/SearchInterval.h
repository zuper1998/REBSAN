//
// Created by narcano on 11/13/23.
//

#ifndef SEARCHINTERVAL_H
#define SEARCHINTERVAL_H
#include <algorithm>

#define MAX_LEN 3000.0;

class search_interval {
    float begin;
    float end;
    const float max_size = MAX_LEN;
public:
    search_interval(const float _begin, const float _end ) : begin(_begin), end(_end) {}
    void addInterval(const float nbegin, const float nend) {
        begin = std::min(begin,nbegin);
        end = std::max(end,nend);

        // This is to make sure
        if (end - begin>max_size) {
            begin = end = -1;
        }

    }



    std::pair<float,float> getExtendedIntervals() const {
        const float mid = (begin + end ) / 2;
        return std::make_pair(mid-max_size/2,mid+max_size/2);
    }


};






#endif //SEARCHINTERVAL_H
