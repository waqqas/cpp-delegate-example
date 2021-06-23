#pragma once

#include "book_delegate.hpp"

namespace app
{
    namespace algorithms
    {

        class algo1 : public feed_handler::book_delegate, public feed_handler::event_delegate
        {
            void on_book_updated(feed_handler::book_ptr book) override
            {
                std::cout << "book updated" << std::endl;
            }

            void on_event_received() override
            {
                std::cout << "event received" << std::endl;
            }
        };
    }
}