#pragma once

#include "ireceiver.hpp"

#include <cstddef> // for nullptr
#include <cassert> // for assert()
#include <string>

namespace delegator
{
    class sender
    {
    private:
        std::string _id;

    public:
        ireceiver *delegate;

        sender(const std::string &id) : _id(id) {}

        void do_work()
        {
            assert(delegate != nullptr);
            delegate->do_actual_work(this);
        }

        std::string id()
        {
            return _id;
        }
    };
} // namespace delegator
