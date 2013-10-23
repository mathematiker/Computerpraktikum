matrix_SRC = main.cpp
matrix_HDR = matrix.hh
matrix_crtp_SRC = main-crtp.cpp
matrix_crtp_HDR = matrix-crtp.hh
PROGS = matrix matrix-crtp

all: matrix matrix-crtp

matrix: $(matrix_SRC) $(matrix_HDR)
	$(CXX) -o $@ $(matrix_SRC)

matrix-crtp: $(matrix_crtp_SRC) $(matrix_crtp_HDR)
	$(CXX) -o $@ $(matrix_crtp_SRC)

clean:
	rm -f $(PROGS)

realclean: clean
	rm -f *~
