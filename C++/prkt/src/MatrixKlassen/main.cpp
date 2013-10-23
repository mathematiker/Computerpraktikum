#include <iostream>
#include "matrix.hh"

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
  Matrix<double> M(3);

  M(1,2) = 19.1;

  cout << "M(1,2) = " << M(1,2) << endl;

  M.resize(5);
  cout << "M(1,2) = " << M(1,2) << endl;

  cout << "Groesse ist nun: " << M.size() << "x" << M.size() << endl;

  BlockMatrix<Matrix<double> >  BM(2, 3);

  BM(1,2) = 19.1;

  cout << "BM(1,2) = " << BM(1,2) << endl;

  for (int i = 0; i < BM.numBlocks(); ++i) {
    for (int j = 0; j < BM.numBlocks(); ++j) {
      cout << "Block(" << i << "," << j << ").size() = " << BM.block(i, j).size() << endl;
    }
  }


  DiagMatrix<double>  DM(5);

  for (int i = 0; i < DM.size(); ++i) {
    DM(i,i) = 19.1 * i;
  }

  cout << "DM(1,1) = " << DM(1,1) << endl;
  cout << "DM(2,2) = " << DM(2,2) << endl;

  for (int i = 0; i < DM.size(); ++i) {
    cout << "DM(" << i << "," << i << ") = " << DM(i,i) << endl;
  }

  SparseMatrix<double> SM(15, 5);
  
  SM(1, 2) = 42;
  cout << "SM(1,2) = " << SM(1,2) << endl;

  SM.assign(1, 2, 19.1);
  cout << "SM(1,2) = " << SM(1,2) << endl;

  SM(1, 2) = 42;
  cout << "SM(1,2) = " << SM(1,2) << endl;

  SM.erase(1, 2);
  SM(1, 2) = 42;
  cout << "SM(1,2) = " << SM(1,2) << endl;

  return 0;
}
