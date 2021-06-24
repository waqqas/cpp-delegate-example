#include "algorithms.hpp"

#include <iostream>
#include <thread>
#include <cstdint>

int main(int argc, char *argv[])
{
  using current_algo = app::algorithms::algo1;

  current_algo::pointer algo = current_algo::make_pointer();

  feed_handler::book<current_algo>::pointer book1 = feed_handler::book<current_algo>::make_pointer();
  book1->bookDelegate = algo;
  book1->eventDelegate = algo;

  feed_handler::book<current_algo>::pointer book2 = feed_handler::book<current_algo>::make_pointer();
  book2->bookDelegate = algo;
  book2->eventDelegate = algo;

  std::thread t1{[&]()
                 {
                   for (uint32_t loop = 0; loop < 100; loop++)
                   {
                     feed_handler::packet<feed_handler::packet_type::book_update> pkt1;
                     book1->process_packet(pkt1);

                     feed_handler::packet<feed_handler::packet_type::event> pkt2;
                     book1->process_packet(pkt2);
                   }
                 }};

  std::thread t2{[&]()
                 {
                   for (uint32_t loop = 0; loop < 100; loop++)
                   {
                     feed_handler::packet<feed_handler::packet_type::book_update> pkt1;
                     book2->process_packet(pkt1);

                     feed_handler::packet<feed_handler::packet_type::event> pkt2;
                     book2->process_packet(pkt2);
                   }
                 }};
  t1.join();
  t2.join();

  algo->print_stats();

  return 0;
}