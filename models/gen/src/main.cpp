#include <itpp/itcomm.h>
#include <itpp/base/binfile.h>
#include <iostream>
#include <cstdlib>

#include <itpp_rw.h>

using namespace itpp;
using namespace std;

int main (int argc, char *argv[])
{
  RNG_randomize();

  int count = atoi(argv[3]);
  int n = atoi(argv[4]);
  int i;
  int sended = 0;
  bvec bits;
  string raw_to_write(argv[2]);
  vector<string> pipes_to_write = pipes_from_arg(raw_to_write);
  vector<bofstream*> write_streams = open_bofstreams(pipes_to_write);

  for(i = 0; i < count; i++) {
    bits = randb(n);
    (*write_streams[0]) << bits;
    (*write_streams[1]) << bits;
  }
  close_bofstreams(write_streams);
  return 0;
}
