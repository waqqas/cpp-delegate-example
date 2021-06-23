#pragma once

#include <cassert>
#include <cstddef>
#include <memory>

namespace feed_handler
{
    enum class packet_type
    {
        book_update,
        event
    };

    struct packet
    {
        packet_type type;
    };

    class book : public std::enable_shared_from_this<book>
    {
    public:
        using pointer = std::shared_ptr<book>;

        class book_delegate
        {
        public:
            virtual void on_book_updated(book::pointer) = 0;
        };

        class event_delegate
        {
        public:
            virtual void on_event_received(void) = 0;
        };

        book_delegate *book_delegate;
        event_delegate *event_delegate;

        static pointer make_pointer()
        {
            return std::make_shared<book>();
        }

        void process_packet(const packet &pkt)
        {
            if (pkt.type == packet_type::book_update)
            {
                if (book_delegate != nullptr)
                {
                    book_delegate->on_book_updated(shared_from_this());
                }
            }
            else if (pkt.type == packet_type::event)
            {
                if (event_delegate != nullptr)
                {
                    event_delegate->on_event_received();
                }
            }
        }
    };
}