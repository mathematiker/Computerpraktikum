#ifndef MATRIX_HH
#define MATRIX_HH

// Curiously Recursive Template Patterns

#include <vector>
#include <iostream>
#include <iomanip>

/* TypeTraits. Ist aus technischen Gruenden leider noetig. */

template<class MatrixType>
struct MatrixTypeTraits
{
  typedef void EntryType;
};

/* Die Interface-Klasse, mit deren Hilfe man z.B. generische
 * IO-Operationen implementieren kann.
 */
template<class MatrixType>
class MatrixInterface
{
  typedef MatrixInterface SelfType;
  typedef MatrixType ImplementationType;
  typedef MatrixTypeTraits<ImplementationType> TraitsType;
 protected:
  MatrixInterface() {}
 public:
  typedef typename TraitsType::EntryType EntryType;

  // Zugriff mit Schreibberechtigung
  EntryType& operator()(int i, int j) {
    return asImp()(i, j);
  }

  // Zugriff ohne Schreibberechtigung
  const EntryType& operator()(int i, int j) const {
    return asImp()(i, j);
  }

  // Groesse aendern ohne umkopieren
  void resize(int new_size) {
    asImp().resize(new_size);
  }

  int size() const {
    return asImp().size();
  }
  
 private:
  MatrixType& asImp() {
    return *static_cast<ImplementationType *>(this);
  }
  const MatrixType& asImp() const {
    return *static_cast<const ImplementationType *>(this);
  }
};

/* Generische Input/Output Operatoren fuer alles, was dem MatrixInterface entspricht.
 */
template<class MatrixType>
std::istream& operator>>(std::istream &is, MatrixInterface<MatrixType> &obj)
{
  for (int i = 0; i < obj.size(); ++i) {
    for (int j = 0; j < obj.size(); ++j) {
      is >> obj(i, j);
    }
  }
  return is;
}
  
template<class MatrixType>
std::ostream& operator<<(std::ostream &os, const MatrixInterface<MatrixType> &obj)
{
  for (int i = 0; i < obj.size(); ++i) {
    for (int j = 0; j < obj.size(); ++j) {
      os << std::setw(5); // field-width
      os << obj(i, j) << " ";
    }
    os << std::endl;
  }
  return os;
}

/* Eine Implementierung des Interfaces, eine einfache vollbesetzte Matrix.
 */
template<class EntryType = double>
class Matrix
  : public MatrixInterface<Matrix<EntryType> >
{
  typedef std::vector<EntryType> DataType;

public:
  // constructor
  Matrix(int n_rows_ = 1) : n_rows(n_rows_), data(n_rows * n_rows) {}

  // Zugriff mit Schreibberechtigung
  EntryType& operator()(int i, int j) {
    return data[j + i * n_rows];
  }

  // Zugriff ohne Schreibberechtigung
  const EntryType& operator()(int i, int j) const {
    return data[j + i * n_rows];
  }

  // Groesse aendern ohne umkopieren
  void resize(int new_size) {
    // Evtl. Daten umkopieren???
    data.resize(new_size * new_size);
    n_rows = new_size;
  }

  int size() const {
    return n_rows;
  }

private:
  int n_rows;
  DataType data;
};

template<class Entry>
struct MatrixTypeTraits<Matrix<Entry> >
{
  typedef Entry EntryType;
};

/* Eine weieter Implementierung des Interfaces, eine Diagonalmatrix.
 */
template<class EntryType = double>
class DiagMatrix
  : public MatrixInterface<DiagMatrix<EntryType> >
{
  typedef std::vector<EntryType> DataType;

public:
  // constructor
  DiagMatrix(int n_rows_ = 1) : n_rows(n_rows_), data(n_rows) {}

  // Zugriff mit Schreibberechtigung
  EntryType& operator()(int i, int j) {
    if (i == j) {
      return data[i];
    } else {
      static EntryType result;

      result = 0;

      return result;
    }
  }

  // Zugriff ohne Schreibberechtigung
  const EntryType& operator()(int i, int j) const {
    //std::cout << "Hello" << std::endl; /* Debugging */
    if (i == j) {
      return data[i];
    } else {
      static EntryType result = 0;
      return result;
    }
  }

  // Groesse aendern ohne umkopieren
  void resize(int new_size) {
    // Evtl. Daten umkopieren???
    data.resize(new_size);
    n_rows = new_size;
  }

  int size() const {
    return n_rows;
  }

private:
  int n_rows;
  DataType data;
};

template<class Entry>
struct MatrixTypeTraits<DiagMatrix<Entry> >
{
  typedef Entry EntryType;
};

// Eine sehr einfache schwach besetzte Matrix mit hoechsten max_cols
// vielen Eintraegen pro Zeile. Fuer jede Zeile merkt man sich die
// Werte und die Spaltenindizes, an denen die Werte eingetragen sind.
template<class EntryType = double>
class SparseMatrix
  : public MatrixInterface<SparseMatrix<EntryType> >
{
  typedef std::vector<EntryType> DataType;
  typedef std::vector<int>       IndexType;

public:
  // constructor
  SparseMatrix(int n_rows_ = 1, int max_cols_ = 1)
    : n_rows(n_rows_), max_cols(max_cols_), data(n_rows*max_cols), colIdx(n_rows*max_cols, -1) {
  }

  // Zugriff mit Schreibberechtigung
  // Achtung: neue Eintraege werden nur mit der assign()-Methode angelegt.
  EntryType& operator()(int i, int j) {
    for (int k = 0; k < max_cols; k++) {
      if (colIdx[i*max_cols + k] == j) {
        return data[i*max_cols + k];
      }
    }

    static EntryType result;
        
    result = 0;
      
    return result;
  }

  // Zugriff ohne Schreibberechtigung
  const EntryType& operator()(int i, int j) const {
    for (int k = 0; k < max_cols; k++) {
      if (colIdx[i*max_cols + k] == j) {
        return data[i*max_cols + k];
      }
    }

    static EntryType result = 0;
      
    return result;
  }

  // Speichere neuen Eintrag VALUE an Stelle i, j, falls in der Zeile noch Platz ist.
  void assign(int i, int j, const EntryType& value) {
    // Freien Eintrag suchen
    for (int k = 0; k < max_cols; ++k) {
      if (colIdx[i * max_cols + k] == -1) {
        // Freie Eintraege werden durch den Index -1 markiert
        data[i * max_cols + k] = value; // Wert merken
        colIdx[i * max_cols + k] = j;   // Index merken
        break;
      }
    }
  }

  // Eintrag an der Stelle i, j freigeben, falls vorhanden
  void erase(int i, int j) {
    for (int k = 0; k < max_cols; k++) {
      if (colIdx[i*max_cols + k] == j) {
        colIdx[i*max_cols + k] = -1; // ist damit wieder "leer"
        break;
      }
    }
  }

  // Groesse aendern ohne umkopieren
  void resize(int new_size) {
    // Evtl. Daten umkopieren???
    data.resize(new_size*max_cols, -1);
    colIdx.resize(new_size*max_cols, -1);
    n_rows = new_size;
  }

  int size() const {
    return n_rows;
  }

private:
  int       n_rows;
  int       max_cols;
  DataType  data;
  IndexType colIdx;
};

template<class Entry>
struct MatrixTypeTraits<SparseMatrix<Entry> >
{
  typedef Entry EntryType;
};

#endif
