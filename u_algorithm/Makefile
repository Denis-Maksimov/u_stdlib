

OBJ=\
	./src/fast.o \
	./src/u_sort.o 

CFLAGS = -Wall -O2 -I./inc 
LDFLAGS = -L. -lu_algorithm -lm


libu_algorithm.a: $(OBJ)
	ar crs $@ $^


./src/fast.o:
./src/u_sort.o:	


test: libu_algorithm.a



clean:
	rm -f $(OBJ) libu_algorithm.a test
