#include "algorithms.hpp"

#include <benchmark/benchmark.h>
#include <thread>
#include <memory>

static void algo1_bm(benchmark::State &state)
{
    using current_algo = app::algorithms::algo1;
    using namespace boost::asio;

    io_context io;

    current_algo::pointer algo = std::make_shared<current_algo>(io);

    feed_handler::book<current_algo>::pointer book1 = feed_handler::book<current_algo>::make_pointer();
    book1->bookDelegate = algo;
    book1->eventDelegate = algo;

    auto work = std::make_shared<boost::asio::io_context::work>(io);

    std::thread th(
        [&]()
        {
            feed_handler::packet<feed_handler::packet_type::book_update> pkt1;
            for (auto _ : state)
            {
                book1->process_packet(pkt1);
            }
            work.reset();
        });

    io.run();

    th.join();

    algo->print_stats();
}

static void algo2_bm(benchmark::State &state)
{
    using current_algo = app::algorithms::algo2;

    current_algo::pointer algo = std::make_shared<current_algo>();

    feed_handler::book2::pointer book = feed_handler::book2::make_pointer();
    book->bookDelegate = algo;
    book->eventDelegate = algo;

    std::thread th(
        [&]()
        {
            feed_handler::packet2 pkt1{feed_handler::packet_type::book_update};
            for (auto _ : state)
            {
                book->process_packet(pkt1);
            }
        });

    th.join();

    algo->print_stats();
}

BENCHMARK(algo1_bm);
BENCHMARK(algo2_bm);