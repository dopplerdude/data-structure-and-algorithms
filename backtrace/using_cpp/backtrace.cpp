#include <iostream>

#define BOOST_STACKTRACE_USE_ADDR2LINE
#include <boost/stacktrace.hpp>

/* Obtain a backtrace and print it to stdout. */
void print_trace (void)
{
      std::cout << boost::stacktrace::stacktrace() << std::endl;
}

/* A dummy function to make the backtrace more interesting. */
void
dummy_function (void)
{
  print_trace ();
}

int
main (void)
{
  dummy_function ();
  return 0;
}