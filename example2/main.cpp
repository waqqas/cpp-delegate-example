#include "algorithms.hpp"

#include <iostream>
#include <thread>
#include <cstdint>
#include <boost/asio.hpp>

int main(int argc, char *argv[])
{
  using current_algo = app::algorithms::algo1;
  using namespace boost::asio;

  io_context io;

  current_algo::pointer algo = std::make_shared<current_algo>(io);

  feed_handler::book<current_algo>::pointer book1 = feed_handler::book<current_algo>::make_pointer();
  book1->bookDelegate = algo;
  book1->eventDelegate = algo;

  feed_handler::book<current_algo>::pointer book2 = feed_handler::book<current_algo>::make_pointer();
  book2->bookDelegate = algo;
  book2->eventDelegate = algo;

  std::thread book1thread{
      [&]()
      {
        for (uint32_t loop = 0; loop < 1000; loop++)
        {
          feed_handler::packet<feed_handler::packet_type::book_update> pkt1;
          book1->process_packet(pkt1);

          feed_handler::packet<feed_handler::packet_type::event> pkt2;
          book1->process_packet(pkt2);
        }
      }};

  std::thread book2thread{
      [&]()
      {
        for (uint32_t loop = 0; loop < 1000; loop++)
        {
          feed_handler::packet<feed_handler::packet_type::book_update> pkt1;
          book2->process_packet(pkt1);

          feed_handler::packet<feed_handler::packet_type::event> pkt2;
          book2->process_packet(pkt2);
        }
      }};

  book1thread.join();
  book2thread.join();

  io.run();

  algo->print_stats();

  return 0;
}