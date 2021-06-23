#include <iostream>

#include "algorithms.hpp"

int main(int argc, char *argv[])
{
  using current_algo = app::algorithms::algo1;

  current_algo::pointer algo = current_algo::make_pointer();

  feed_handler::book<current_algo>::pointer book1 = feed_handler::book<current_algo>::make_pointer();
  book1->bookDelegate = algo;
  book1->eventDelegate = algo;

  feed_handler::packet<feed_handler::packet_type::book_update> pkt1;
  book1->process_packet(pkt1);

  feed_handler::packet<feed_handler::packet_type::event> pkt2;
  book1->process_packet(pkt2);

  return 0;
}