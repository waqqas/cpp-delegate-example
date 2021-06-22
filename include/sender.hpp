#pragma once

#include "ireceiver.hpp"

#include <cstddef> // for nullptr
#include <cassert> // for assert()

namespace delegator
{
    class sender
    {
    public:
        ireceiver *delegate;

        void work()
        {
            assert(delegate != nullptr);
            delegate->do_actual_work();
        }
    };
} // namespace delegator
