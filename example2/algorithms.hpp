#pragma once

#include "book_delegate.hpp"

#include <boost/asio.hpp>
#include <cstdint>
#include <iostream>
// #include <mutex>

namespace app
{
    namespace algorithms
    {
        using namespace feed_handler;
        using namespace boost::asio;

        class algo1 : public book<algo1>::book_delegate, public book<algo1>::event_delegate
        {
        private:
            uint32_t _book_update_count = {0};
            uint32_t _event_count = {0};
            // std::mutex _mutex;

        public:
            using pointer = std::shared_ptr<algo1>;

            algo1(io_context &io) : book<algo1>::book_delegate(io), book<algo1>::event_delegate(io) {}

            void on_book_updated(book<algo1>::pointer book)
            {
                // std::lock_guard<std::mutex> lock(_mutex);
                _book_update_count++;
            }

            void on_event_received()
            {
                // std::lock_guard<std::mutex> lock(_mutex);
                _event_count++;
            }

            void print_stats()
            {
                std::cout << "book update count : " << _book_update_count << std::endl;
                std::cout << "event count       : " << _event_count << std::endl;
            }
        };
    }
}