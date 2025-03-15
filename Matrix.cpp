#include <cmath>
#include <fstream>
#include <istream>
using namespace std;

class Matrix {
 public:
  typedef double Element;

 private:
  int n = 0;  // nrows
  int m = 0;  // ncolumns

  Element** data = nullptr;
  bool valid = false;

  void Init(const int n_, const int m_);
  void Clear();

  friend Matrix& operator++(Matrix& matrix);
  friend Matrix& operator+=(Matrix& left, const Matrix& right);

  friend bool operator==(const Matrix& left,
                         const Matrix& right);
  friend Matrix& operator*=(Matrix& left, const float right);
  friend ostream& operator<<(ostream& os, const Matrix& mat);
  friend istream& operator>>(istream& is, const Matrix& mat);

 public:
  Matrix(const int n_, const int m_);
  Matrix(const Matrix& matrix);
  ~Matrix();

  inline bool GetValid() const {
    return valid;
  }

  inline Element Get(const int i, const int j) const {
    return data[i][j];
  }

  inline void Set(const int i, const int j, const Element value) {
    data[i][j] = value;
  }

  void Print() const;
  bool Sum(const Matrix& matrix);
  void Prod(const Element alpha);

  static Matrix Sum(const Matrix& m1, const Matrix& m2);
  
  void Matrix::Clear(){
  	if()
  }
};  // end Matrix

// Start of Matrix implementations.
Matrix::Matrix(const int n_, const int m_) {
  if (n_ <= 0 || m_ <= 0) {
    return;
  }

  Init(n_, m_);
}

Matrix::Matrix(const Matrix& matrix) {
  if (matrix.valid == false) {
    return;
  }

  Init(matrix.n, matrix.m);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      Set(i, j, matrix.Get(i, j));
    }
  }
}

Matrix::~Matrix() {
  if (data != nullptr) {
    for (int i = 0; i < n; ++i) {
      delete[] data[i];
    }
    delete[] data;
  }
}

void Matrix::Init(const int n_, const int m_) {
  n = n_;
  m = m_;

  data = new Element*[n];
  for (int i = 0; i < n; ++i) {
    data[i] = new Element[m]();
  }
  valid = true;
}

void Matrix::Print() const {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << Get(i, j) << " ";
    }
    cout << endl;
  }
}

bool Matrix::Sum(const Matrix& matrix) {
  if (n != matrix.n || m != matrix.m ||
      !valid || !matrix.valid) {
    return false;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      Set(i, j, Get(i, j) + matrix.Get(i, j));
    }
  }
  return true;
}

void Matrix::Prod(const Element alpha) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      Set(i, j, Get(i, j) * alpha);
    }
  }
}

/* static */
Matrix Matrix::Sum(const Matrix& m1, const Matrix& m2) {
  if (m1.n != m2.n || m1.m != m2.m ||
      !m1.valid || !m2.valid) {
    return Matrix(0, 0);
  }

  Matrix res(m1.n, m1.m);
  for (int i = 0; i < m1.n; ++i) {
    for (int j = 0; j < m1.m; ++j) {
      res.Set(i, j, m1.Get(i, j) + m2.Get(i, j));
    }
  }
  return res;
}

//OPERATORs
Matrix& operator++(Matrix& matrix) {
  for (int i = 0; i < matrix.n; i++) {
    for (int j = 0; j < matrix.m; j++) {
      // matrix.data[i][j]++;
      matrix.Set(i, j, matrix.Get(i, j) + 1.0);
      // matrix.data[i][j] = matrix.data[i][j] + 1.0;
    }
  }
  return matrix;
}

Matrix operator+(const Matrix& left, const Matrix& right) {
  const Matrix result = Matrix::Sum(left, right);
  return result;
}

Matrix& operator+=(Matrix& left, const Matrix& right) {
  if (left.n != right.n || left.m != right.m) {
    left.valid = false;
  } else {
    for (int i = 0; i < left.n; ++i) {
      for (int j = 0; j < left.m; ++j) {
        left.Set(i, j, left.Get(i, j) + right.Get(i, j));
      }
    }
  }
  return left;
}


bool operator==(const Matrix& left, const Matrix& right) {
  if (left.n != right.n || left.m != right.m) {
    return false;
  }
  for (int i = 0; i < left.n; ++i) {
    for (int j = 0; j < left.m; ++j) {
      if (abs(left.Get(i, j) - right.Get(i, j)) > 1e-5) {
        return false;
      }
    }
  }
  return true;
}

Matrix& operator*=(Matrix& left, const float right) {
  for (int i = 0; i < left.n; ++i) {
    for (int j = 0; j < left.m; ++j) {
      left.Set(i, j, left.Get(i, j) * right);
    }
  }
  return left;
}

ostream& operator<<(ostream& os, const Matrix& mat){
	os << mat.n << " " << mat.m << endl;
	for(int i = 0; i < mat.n; ++){
		for(int j = 0; j < mat.m; ++j){
			os << mat[i] << " " << mat[j];
		}
		os << endl;
	}
	return os;
}

istream& operator>>(istream& is, const Matrix& mat){
	int n = 0;
	int m = 0;
	is >> n >> m;
	if(n != mat.n || m != mat.m){
		mat.Clear();
		mat.Init(n, m);
	}
	for(int i = 0; i < mat.n; ++i){
		for(int j = 0; j < mat.m; ++j){
			is >> mat.data[i][j];
		}
	}
	return is;
}

int main() {
  Matrix m1(3, 3);
  m1.Set(1, 1, 5.0);
  std::cout << "Print m1\n";
  m1.Print();

  Matrix m2(m1);
  const Matrix m3 = Matrix::Sum(m1, m2);
  if (m3.GetValid()) {
    std::cout << "Print m3\n";
    m3.Print();
  }

  m2.Prod(2.1);
  std::cout << "Print 2.1 * m2\n";
  m2.Print();

  Matrix::Element el = m2.Get(0, 0);

  std::cout << "Print ++m2\n";
  ++m2;
  m2.Print();
  (++m2).Print();


  Matrix m4 = m1 + m2;
  std::cout << "Print m4 = m1 + m2\n";
  m4.Print();

  m4 += m2;
  std::cout << "Print m4 += m2\n";
  m4.Print();

  m4 *= 3.1;
  std::cout << "Print m4 *= 3.1\n";
  m4.Print();
  
  ofstream os("matrix.txt");
  if(os.good){
  	os << m2;
  } else{
  	cerr << "Non è possibile stampare il file.\n";
  }

  return 0;

}

//inline va messo nelle funzioni che non richiedono molta complessità, tipo le getters o le setters, nel momento in cui in una funzione sono presenti cicli o comunque algoritmi abbastanza complessi è meglio implementare la funzione stessa al di fuori della classe.