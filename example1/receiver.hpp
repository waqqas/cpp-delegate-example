#include "ireceiver.hpp"
#include "sender.hpp"

#include <iostream>

namespace user_defined
{
    class recevier : public delegator::ireceiver
    {
        void do_actual_work(const delegator::sender &sender) override
        {
            std::cout << "Doing actual work for sender: " << sender.id() << std::endl;
        }
    };
}