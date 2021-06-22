#include "ireceiver.hpp"

#include <iostream>

namespace user_defined
{
    class recevier : public delegator::ireceiver
    {
        void do_actual_work(void) override
        {
            std::cout << "Doing actual work" << std::endl;
        }
    };
}