#pragma once

#include <cassert>
#include <cstddef>
#include <memory>
#include <boost/asio.hpp>

namespace feed_handler
{
    using namespace boost::asio;

    enum class packet_type
    {
        book_update,
        event
    };

    template <packet_type T>
    struct packet
    {
        packet_type type = T;
    };

    template <typename T>
    class book : public std::enable_shared_from_this<book<T>>
    {
    public:
        using pointer = std::shared_ptr<book<T>>;

        class book_delegate
        {
        private:
            io_context &_io;

        public:
            using pointer = std::shared_ptr<book_delegate>;

            book_delegate(io_context &io) : _io(io) {}

            void on_book_updated(book<T>::pointer book)
            {
                static_cast<T *>(this)->on_book_updated(book);
                // post(_io, [=]()
                //      { static_cast<T *>(this)->on_book_updated(book); });
            }
        };

        class event_delegate
        {
        private:
            io_context &_io;

        public:
            using pointer = std::shared_ptr<event_delegate>;

            event_delegate(io_context &io) : _io(io) {}

            void on_event_received(void)
            {
                static_cast<T *>(this)->on_event_received();
                // post(_io, [=]()
                //      { static_cast<T *>(this)->on_event_received(); });
            }
        };

        typename book_delegate::pointer bookDelegate;
        typename event_delegate::pointer eventDelegate;

        static pointer make_pointer()
        {
            return std::make_shared<book<T>>();
        }

        template <packet_type PT>
        void process_packet(const packet<PT> &pkt)
        {
            if constexpr (PT == packet_type::book_update)
            {
                if (bookDelegate != nullptr)
                {
                    bookDelegate->on_book_updated(std::enable_shared_from_this<book<T>>::shared_from_this());
                }
            }

            if constexpr (PT == packet_type::event)
            {
                if (eventDelegate != nullptr)
                {
                    eventDelegate->on_event_received();
                }
            }
        }
    };
}