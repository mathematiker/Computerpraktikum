#include <iostream>
#include "matrix-crtp.hh"

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
  Matrix<double> M(3);

  M(1,2) = 19.1;

  cout << M << endl;

  DiagMatrix<double> DM(3);

  DM(1,2) = 19.1; // Schreibversuch wird ignoriert
  DM(0,0) = 1;
  DM(2,2) = 42;

  cout << DM << endl;

  SparseMatrix<double> SM(8, 3);
  
  SM(1, 2) = 42;
  cout << "SM = " << endl << SM << endl;

  SM.assign(1, 2, 19.1);
  cout << "SM = " << endl << SM << endl;

  SM(1, 2) = 42;
  cout << "SM = " << endl << SM << endl;

  SM.erase(1, 2);
  SM(1, 2) = 42;
  cout << "SM = " << endl << SM << endl;

  return 0;
}
