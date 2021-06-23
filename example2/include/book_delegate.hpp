#pragma once

#include <cassert>
#include <cstddef>

namespace feed_handler
{
    class book;

    using book_ptr = book *;

    class book_delegate
    {
    public:
        virtual void on_book_updated(book_ptr) = 0;
    };

    class event_delegate
    {
    public:
        virtual void on_event_received(void) = 0;
    };

    enum class packet_type
    {
        book_update,
        event
    };

    struct packet
    {
        packet_type type;
    };

    class book
    {
    public:
        book_delegate *book_delegate;
        event_delegate *event_delegate;

        void process_packet(const packet &pkt)
        {
            if (pkt.type == packet_type::book_update)
            {
                assert(book_delegate != nullptr);
                book_delegate->on_book_updated(this);
            }
            else if (pkt.type == packet_type::event)
            {
                assert(event_delegate != nullptr);
                event_delegate->on_event_received();
            }
        }
    };
}