//
// Created by andris on 2023.11.11..
//

#ifndef ALLEN_ALGEBRA_H
#define ALLEN_ALGEBRA_H
#include <ostream>
#include <sstream>


class Node;

typedef std::pair<float,Node*> edge_data;

template <typename TR_TYPE=float>
class visiblity_interval {
    TR_TYPE data;

public:
    float start;
    float end;
    visiblity_interval(const float _start,const float _end) : start(_start), end(_end) {}
    visiblity_interval(const float _start,const float _end,const TR_TYPE _data) : start(_start), end(_end), data(_data) {}


    [[nodiscard]] bool precede(const visiblity_interval  &other) const;
    [[nodiscard]] bool ipreceded(const visiblity_interval  &other) const;

    [[nodiscard]] bool equal(const visiblity_interval &other) const;

    [[nodiscard]] bool meets(const visiblity_interval  &other) const;
    [[nodiscard]] bool imeets(const visiblity_interval  &other) const;

    [[nodiscard]] bool overlaps(const visiblity_interval  &other) const;
    [[nodiscard]] bool ioverlaps(const visiblity_interval  &other) const;

    [[nodiscard]] bool starts(const visiblity_interval  &other) const;
    [[nodiscard]] bool istarts(const visiblity_interval  &other) const;

    [[nodiscard]] bool during(const visiblity_interval  &other) const;
    [[nodiscard]] bool iduring(const visiblity_interval  &other) const;

    [[nodiscard]] bool finishes(const visiblity_interval  &other) const;
    [[nodiscard]] bool ifinishes(const visiblity_interval  &other) const;






    const TR_TYPE& getData() const {
        return data;
    }

    friend bool operator==(const visiblity_interval&v1, const visiblity_interval&v2) {
        const bool data_match = v1.data == v2.data;
        const bool interval_match = v1.equal(v2);
        return data_match && interval_match;
    }

    friend std::ostream& operator<<(std::ostream&stream, const visiblity_interval<TR_TYPE>&vi){
        stream << vi.start << " --- " << vi.end;
        if (vi.data!=TR_TYPE()) {
            stream << vi.data;
        }
        return stream;
    }
};

// Definition needs to be here bc: https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
template <typename TR_TYPE>
bool visiblity_interval<TR_TYPE>::precede(const visiblity_interval& other) const {
    return end < other.start;
}

template <typename TR_TYPE>
bool visiblity_interval<TR_TYPE>::equal(const visiblity_interval&other) const {
    return start == other.start && end == other.end;

}

template <typename TR_TYPE>
bool visiblity_interval<TR_TYPE>::ipreceded(const visiblity_interval& other) const {
    return other.precede(*this);
}

template <typename TR_TYPE>
bool visiblity_interval<TR_TYPE>::meets(const visiblity_interval& other) const {
    return end == other.start;
}
template <typename TR_TYPE>
bool visiblity_interval<TR_TYPE>::imeets(const visiblity_interval& other) const {
    return other.meets(*this);
}

template <typename TR_TYPE>
bool visiblity_interval<TR_TYPE>::overlaps(const visiblity_interval& other) const {
    return other.start < end;
}

template <typename TR_TYPE>
bool visiblity_interval<TR_TYPE>::ioverlaps(const visiblity_interval& other) const {
    return other.overlaps(*this);
}

template <typename TR_TYPE>
bool visiblity_interval<TR_TYPE>::starts(const visiblity_interval& other) const {
    return start == other.start && end < other.end;
}

template <typename TR_TYPE>
bool visiblity_interval<TR_TYPE>::istarts(const visiblity_interval& other) const {
    return other.starts(*this);
}

template <typename TR_TYPE>
bool visiblity_interval<TR_TYPE>::during(const visiblity_interval& other) const {
    return other.start < start && end < other.end;
}

template <typename TR_TYPE>
bool visiblity_interval<TR_TYPE>::iduring(const visiblity_interval& other) const {
    return other.during(*this);
}

template <typename TR_TYPE>
bool visiblity_interval<TR_TYPE>::finishes(const visiblity_interval& other) const {
    return other.start < start && end == other.end;
}

template <typename TR_TYPE>
bool visiblity_interval<TR_TYPE>::ifinishes(const visiblity_interval& other) const {
    return other.finishes(*this);
}



template<typename TR_TYPE>
std::ostream& operator<<(std::ostream& stream, const visiblity_interval<TR_TYPE>& vi) {
    stream << vi.start << " --- " << vi.end;
    if (vi.data !=0 ) {
        stream << " : " << vi.data;
    }
    return stream;
}


#endif //ALLEN_ALGEBRA_H
