#pragma once

#include "book_delegate.hpp"

namespace app
{
    namespace algorithms
    {

        class algo1 : public feed_handler::book::book_delegate, public feed_handler::book::event_delegate
        {
        public:
            using pointer = std::shared_ptr<algo1>;

            static pointer make_pointer()
            {
                return std::make_shared<algo1>();
            }

        private:
            void on_book_updated(feed_handler::book::pointer book) override
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