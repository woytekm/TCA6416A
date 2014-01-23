all:
	gcc i2c_lib.c -c
	gcc tca6416a.c -c
	ar rcs libtca6416a.a i2c_lib.o tca6416a.o
	
	gcc tca6416a-test.c -o tca6416a-test -L . -ltca6416a

clean:
	rm -f *.a *.o tca6416a-test
