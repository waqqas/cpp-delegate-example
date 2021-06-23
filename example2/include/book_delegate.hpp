#pragma once

namespace feed_handler
{
    class book_delegate
    {
    public:
        virtual void on_book_updated(void) = 0;
    };

    class event_delegate
    {
    public:
        virtual void on_event(void) = 0;
    };
}