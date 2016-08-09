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
  int m = atoi(argv[4]);
  int i;
  Hamming_Code hc(m);
  bvec bits;
  bvec decoded;

  bofstream out(argv[2]);
  bifstream in(argv[1]);

  for(i = 0; i < count; i++) {
    in >> bits;
    decoded = hc.decode(bits);
    out << decoded;
  }

  in.close();
  out.close();
  return 0;
}
