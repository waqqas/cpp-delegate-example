#pragma once

namespace delegator
{
    class ireceiver
    {
    public:
        virtual void do_actual_work(void) = 0;
    };
}