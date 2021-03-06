#pragma once

#include "book.hpp"
#include "book2.hpp"

#include <boost/asio.hpp>
#include <cstdint>
#include <iostream>

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

        public:
            using pointer = std::shared_ptr<algo1>;

            algo1(io_context &io) : book<algo1>::book_delegate(io), book<algo1>::event_delegate(io) {}

            void on_book_updated(book<algo1>::pointer book)
            {
                _book_update_count++;
            }

            void on_event_received()
            {
                _event_count++;
            }

            void print_stats()
            {
                std::cout << "book update count : " << _book_update_count << std::endl;
                std::cout << "event count       : " << _event_count << std::endl;
            }
        };

        class algo2 : public book2::book_delegate, public book2::event_delegate
        {
        private:
            uint32_t _book_update_count = {0};
            uint32_t _event_count = {0};

        public:
            using pointer = std::shared_ptr<algo2>;

            void on_book_updated(book2::pointer book) override
            {
                _book_update_count++;
            }

            void on_event_received() override
            {
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