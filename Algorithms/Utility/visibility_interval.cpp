//
// Created by andris on 2023.11.11..
//

#include "visiblity_interval.h"


bool visiblity_interval::precede(const visiblity_interval& other) const {
    return end < other.start;
}

bool visiblity_interval::ipreceded(const visiblity_interval& other) const {
    return other.precede(*this);
}

bool  visiblity_interval::equal(const visiblity_interval&other) const {
    return start == other.start && end == other.end;

}

bool visiblity_interval::meets(const visiblity_interval& other) const {
    return end == other.start;
}
bool visiblity_interval::imeets(const visiblity_interval& other) const {
    return other.meets(*this);
}

bool visiblity_interval::overlaps(const visiblity_interval& other) const {
    return other.start < end;
}

bool visiblity_interval::ioverlaps(const visiblity_interval& other) const {
    return other.overlaps(*this);
}

bool visiblity_interval::starts(const visiblity_interval& other) const {
    return start == other.start && end < other.end;
}

bool visiblity_interval::istarts(const visiblity_interval& other) const {
    return other.starts(*this);
}

bool visiblity_interval::during(const visiblity_interval& other) const {
    return other.start < start && end < other.end;
}

bool visiblity_interval::iduring(const visiblity_interval& other) const {
    return other.during(*this);
}

bool visiblity_interval::finishes(const visiblity_interval& other) const {
    return other.start < start && end == other.end;
}

bool visiblity_interval::ifinishes(const visiblity_interval& other) const {
    return other.finishes(*this);
}

std::ostream& operator<<(std::ostream& stream, const visiblity_interval& vi) {
    stream << vi.start << " --- " << vi.end;
    if (vi.troughput!=0) {
        stream << vi.troughput;
    }
    return stream;
}





