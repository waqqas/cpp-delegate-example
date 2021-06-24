#pragma once

#include "book_delegate.hpp"
#include <cstdint>
#include <iostream>

namespace app
{
    namespace algorithms
    {
        using namespace feed_handler;

        class algo1 : public book<algo1>::book_delegate, public book<algo1>::event_delegate
        {
        private:
            uint32_t _book_update_count = {0};
            uint32_t _event_count = {0};

        public:
            using pointer = std::shared_ptr<algo1>;

            static pointer make_pointer()
            {
                return std::make_shared<algo1>();
            }

            void on_book_updated(book<algo1>::pointer book)
            {
                _book_update_count++;
                // std::cout << "book update count: " << _book_update_count << std::endl;
            }

            void on_event_received()
            {
                _event_count++;
                // std::cout << "event count: " << _event_count << std::endl;
            }

            void print_stats()
            {
                std::cout << "book update count: " << _book_update_count << std::endl;
                std::cout << "event count: " << _event_count << std::endl;
            }
        };
    }
}