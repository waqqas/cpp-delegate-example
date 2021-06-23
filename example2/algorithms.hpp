#pragma once

#include "book_delegate.hpp"

namespace app
{
    namespace algorithms
    {

        class algo1 : public feed_handler::book_delegate
        {
            void on_book_updated(void) override
            {
            }
        };
    }
}