//
// Created by narcano on 11/13/23.
//

#ifndef SEARCHINTERVAL_H
#define SEARCHINTERVAL_H
#include <algorithm>


#define MAX_LEN 5.1;

class search_interval {
    float begin;
    float end;
    const float max_size = MAX_LEN;
public:
    search_interval() : begin(-1), end(-1) {}
    search_interval(const float _begin, const float _end ) : begin(_begin), end(_end) {}
    search_interval(search_interval&& other) noexcept {
        begin = other.begin;
        end = other.end;
    }
    search_interval(const search_interval& other) noexcept {
        begin = other.begin;
        end = other.end;
    }

    search_interval& operator=(const search_interval& other) {
        begin = other.begin;
        end = other.end;
        return *this;
    }



    [[nodiscard]] search_interval addInterval(const float nbegin, const float nend) const {
        search_interval n_interval{begin,end};

        n_interval.begin = std::min(begin,nbegin);
        n_interval.end = std::max(end,nend);

        // This is to make sure
        if (n_interval.end - n_interval.begin>n_interval.max_size) {
            n_interval.begin = n_interval.end = -1;
        }
        return n_interval;
    }

    [[nodiscard]] bool isValid() const {
        return (begin != -1) && (end != -1);
    }

    [[nodiscard]] std::pair<float,float> getExtendedIntervals() const {
        const float mid = (begin + end ) / 2;
        return std::make_pair(mid-max_size/2,mid+max_size/2);
    }


};






#endif //SEARCHINTERVAL_H
