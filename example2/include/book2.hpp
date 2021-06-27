#pragma once

#include "packet.hpp"

#include <cstddef>
#include <memory>
#include <boost/asio.hpp>

namespace feed_handler
{
    using namespace boost::asio;

    class book2 : public std::enable_shared_from_this<book2>
    {
    public:
        using pointer = std::shared_ptr<book2>;

        class book_delegate
        {
        public:
            using pointer = std::shared_ptr<book_delegate>;
            virtual void on_book_updated(book2::pointer) = 0;
            virtual ~book_delegate() = default;
        };

        class event_delegate
        {
        public:
            using pointer = std::shared_ptr<event_delegate>;
            virtual void on_event_received(void) = 0;
            virtual ~event_delegate() = default;
        };

        book_delegate::pointer bookDelegate;
        event_delegate::pointer eventDelegate;

        static pointer make_pointer()
        {
            return std::make_shared<book2>();
        }

        void process_packet(const packet2 &pkt)
        {
            if (pkt.type == packet_type::book_update)
            {
                if (bookDelegate != nullptr)
                    bookDelegate->on_book_updated(shared_from_this());
            }
            else if (pkt.type == packet_type::event)
            {
                if (eventDelegate != nullptr)
                    eventDelegate->on_event_received();
            }
        }
    };
}