
OBJ=\
	./src/u_hash.o \
	./src/u_vector.o \


CFLAGS = -Wall -O2 -I./inc -I. 
CFLAGS += -I../u_stdlib 
# CFLAGS += -march=native -fomit-frame-pointer
# LDFLAGS =   

# libu_stdlib.a: $(OBJ)
	# ar crs $@ $^

libu_types.a: $(OBJ)
	ar crs $@ $^
# ./src/u_hash:./src/u_hash.o #libu_stdlib.a
# ./src/u_hash.o:
# ./src/u_vector.o:

# test: libu_stdlib.a
# 	gcc $(CFLAGS) u_test.c hex.c -L. -lu_stdlib


clean:
	rm -f $(OBJ) libu_types.a
