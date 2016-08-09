#include <itpp/itcomm.h>
#include <itpp/base/binfile.h>
#include <iostream>
#include <vector>
#include <cstdlib>

#include <itpp_rw.h>

using namespace itpp;
using namespace std;

int main (int argc, char *argv[])
{
  int count = atoi(argv[3]);
  int i;
  BERC berc;
  string raw_to_read(argv[1]);
  vector<string> pipes_to_read = pipes_from_arg(raw_to_read);
  vector<bifstream*> read_streams = open_bifstreams(pipes_to_read);

  bvec bits1;
  bvec bits2;

  for(i = 0; i < count; i++) {
    (*read_streams[0]) >> bits1;
    (*read_streams[1]) >> bits2;
    berc.count(bits1, bits2);
  }

  berc.report();
  close_bifstreams(read_streams);
  return 0;
}
