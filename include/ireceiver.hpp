#pragma once

namespace delegator
{
    class sender;

    class ireceiver
    {
    public:
        virtual void do_actual_work(const sender &) = 0;
    };
}