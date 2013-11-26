prkt_SRC = prkt.cpp
matrix_HDR = MatrixKlassen/matrix.hh
vector_HDR=vector.hh
methods_SRC=methods.cpp
methods_HDR=methods.hh

PROGS = prkt

all: prkt

prkt: $(prkt_SRC) $(matrix_HDR) $(methods_SRC) $(methods_HDR)
	$(CXX) -o $@ $(prkt_SRC) $(methods_SRC)

clean:
	rm -f $(PROGS)

realclean: clean
	rm -f *~
