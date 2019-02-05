//
// Created by fahr on 05.02.19.
//

#ifndef CXX_DOCKER_MAIN_WORLD_HXX
#define CXX_DOCKER_MAIN_WORLD_HXX

namespace sample {
    struct HW {
        template <class OS>
                friend OS& operator << (OS& os, const HW&) {
                    os << "Hy, 3gapoBa!";
                    return os;
                }
    };
}

#endif //CXX_DOCKER_MAIN_WORLD_HXX
