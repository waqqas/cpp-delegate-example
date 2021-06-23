#include <iostream>

#include "algorithms.hpp"

int main(int argc, char *argv[])
{
  app::algorithms::algo1::pointer algo = app::algorithms::algo1::make_pointer();

  feed_handler::book::pointer book1 = feed_handler::book::make_pointer();
  book1->book_delegate = algo;
  book1->event_delegate = algo;

  feed_handler::packet pkt1{feed_handler::packet_type::book_update};
  book1->process_packet(pkt1);

  feed_handler::packet pkt2{feed_handler::packet_type::event};
  book1->process_packet(pkt2);

  return 0;
}