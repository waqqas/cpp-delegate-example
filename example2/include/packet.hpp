#pragma once

namespace feed_handler
{
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

    struct packet2
    {
        packet_type type;
    };

}