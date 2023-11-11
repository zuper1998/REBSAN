//
// Created by andris on 2023.11.11..
//

#ifndef ALLEN_ALGEBRA_H
#define ALLEN_ALGEBRA_H
#include <ostream>


class visiblity_interval {
private:
    float start;
    float end;
    float troughput;


public:
    visiblity_interval(const float _start,const float _end) : start(_start), end(_end), troughput(0) {}
    visiblity_interval(const float _start,const float _end,const float _troughput) : start(_start), end(_end), troughput(_troughput) {}

    [[nodiscard]] bool precede(const visiblity_interval  &other) const;
    [[nodiscard]] bool ipreceded(const visiblity_interval  &other) const;

    [[nodiscard]] bool equal(const visiblity_interval&other) const;

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

    friend std::ostream& operator<< (std::ostream& stream, const visiblity_interval& vi);
};



#endif //ALLEN_ALGEBRA_H
