#pragma once

#include "ireceiver.hpp"

#include <string>

namespace delegator
{
    class sender
    {
    private:
        const std::string _id;
        ireceiver &_delegate;

    public:
        sender(const std::string &id, ireceiver &delegate) : _id(id), _delegate(delegate) {}

        void do_work()
        {
            _delegate.do_actual_work(*this);
        }

        std::string id() const
        {
            return _id;
        }
    };
} // namespace delegator
