

OBJ=\
	./src/u_mallocat.o  \
	./src/u_string.o	\
	./src/u_chain.o		\
	./src/u_vector.o	\
	./src/u_graph.o		


CFLAGS = -Wall -O2 -I./inc

libu_stdlib.a: $(OBJ)
	ar crs $@ $^


./src/u_mallocat.o:
./src/u_string.o:	
./src/u_chain.o	:	
./src/u_vector.o:	
./src/u_graph.o	:	

test: libu_stdlib.a
	gcc $(CFLAGS) u_test.c hex.c -L. -lu_stdlib


clean:
	rm -f $(OBJ) libu_stdlib.a
