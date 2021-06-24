#include "algorithms.hpp"

#include <benchmark/benchmark.h>

static void algo_bm(benchmark::State &state)
{
    using current_algo = app::algorithms::algo1;
    using namespace boost::asio;

    io_context io;

    current_algo::pointer algo = std::make_shared<current_algo>(io);

    feed_handler::book<current_algo>::pointer book1 = feed_handler::book<current_algo>::make_pointer();
    book1->bookDelegate = algo;
    book1->eventDelegate = algo;

    feed_handler::packet<feed_handler::packet_type::book_update> pkt1;
    feed_handler::packet<feed_handler::packet_type::event> pkt2;

    for (auto _ : state)
    {
        book1->process_packet(pkt1);
        book1->process_packet(pkt2);
        // io.run();
    }

    algo->print_stats();
}

BENCHMARK(algo_bm);