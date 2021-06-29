#include <iostream>

#include "sender.hpp"
#include "receiver.hpp"

#include <string>

int main(int argc, char *argv[])
{
  user_defined::receiver r1;
  delegator::sender s1{"sender 1", r1};

  s1.do_work();

  return 0;
}