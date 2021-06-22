#include <iostream>

#include "sender.hpp"
#include "receiver.hpp"

int main(int argc, char *argv[])
{
  delegator::sender s1;
  user_defined::recevier r1;

  s1.delegate = &r1;

  s1.work();

  return 0;
}