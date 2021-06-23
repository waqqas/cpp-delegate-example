#pragma once

#include "book_delegate.hpp"

namespace app
{
    namespace algorithms
    {
        using namespace feed_handler;

        class algo1 : public book<algo1>::book_delegate, public book<algo1>::event_delegate
        {
        public:
            using pointer = std::shared_ptr<algo1>;

            static pointer make_pointer()
            {
                return std::make_shared<algo1>();
            }

            void on_book_updated(book<algo1>::pointer book)
            {
                std::cout << "book updated" << std::endl;
            }

            void on_event_received()
            {
                std::cout << "event received" << std::endl;
            }
        };
    }
}