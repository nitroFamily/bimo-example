#include <itpp/itcomm.h>
#include <itpp/base/binfile.h>
#include <iostream>
#include <cstdlib>
#include <vector>

#include <itpp_rw.h>

using namespace itpp;
using namespace std;

int main (int argc, char *argv[])
{
  int count = atoi(argv[3]);
  double p = strtod(argv[4], NULL);
  int i;
  BSC bsc(p);
  bvec bits;
  bvec after;

  bofstream out(argv[2]);
  bifstream in(argv[1]);

  for(i = 0; i < count; i++) {
    in >> bits;
    after = bsc(bits);
    out << after;
  }

  in.close();
  out.close();
  return 0;
}
