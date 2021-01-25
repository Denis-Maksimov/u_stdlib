


LIBS= \
u_stdlib/libu_stdlib.a \
u_types/libu_types.a

.PHONY: all clean
all: libu_std.a

libu_std.a: $(LIBS)
	ar crs $@ $^

u_stdlib/libu_stdlib.a:
	${MAKE} -C u_stdlib

u_types/libu_types.a:
	${MAKE} -C u_types

clean:
	${MAKE} -C u_stdlib clean
	${MAKE} -C u_types clean
	rm -f libu_std.a

