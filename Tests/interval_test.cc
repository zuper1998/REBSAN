//
// Created by andris on 2023.11.11..
//

#include <gtest/gtest.h>

#include "../Algorithms/Utility/visiblity_interval.h"

//USE: https://google.github.io/googletest/primer.html


// Demonstrate some basic assertions.
TEST(TestIntervals, CtorAndStuff) {
    visiblity_interval const v1(0,2);
    visiblity_interval const v2(2,5);
    visiblity_interval const v3(1,6);
    visiblity_interval const v4(0,1);
    visiblity_interval const v5(3,6);

    visiblity_interval<int> const vx(1,2,10);
    visiblity_interval<int> const vy(1,2,2);


    ASSERT_TRUE(v4.precede(v2)) << "Failed with: " << v4 << " | " << v2;

    ASSERT_TRUE(v1.equal(visiblity_interval(0,2))) << "Failed with: " << v1;

    ASSERT_TRUE(v1.meets(v2)) << "Failed with: " << v1 << " | " << v2;

    ASSERT_TRUE(v3.overlaps(v2)) << "Failed with: " << v3 << " | " << v2;

    ASSERT_TRUE(v4.starts(v1)) << "Failed with: " << v4 << " | " << v1;

    ASSERT_TRUE(v2.during(v3)) << "Failed with: " << v2 << " | " << v3;

    ASSERT_TRUE(v5.finishes(v3)) << "Failed with: " << v5 << " | " << v3;

    ASSERT_TRUE(vx.equal(vy)) << "Failed with: " << vx << " | " << vy;


}
