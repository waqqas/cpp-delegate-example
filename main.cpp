#include <iostream>

#include "sender.hpp"
#include "receiver.hpp"

#include <string>

int main(int argc, char *argv[])
{
  delegator::sender s1{"sender 1"};
  user_defined::recevier r1;

  s1.delegate = &r1;

  s1.do_work();

  return 0;
}