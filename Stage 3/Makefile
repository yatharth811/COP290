FILE = main
LIBFILE = audio
COMPILEFLAGS =  -lopenblas -lpthread -lgfortran
PATHTOLIB = /mnt/c/Users/yatha/Desktop/Libs
LIB = /opt/OpenBLAS/lib
INC = /opt/OpenBLAS/include

all: 
	g++ $(LIBFILE).cpp -o $(LIBFILE).out -L $(LIB) -I $(INC) $(COMPILEFLAGS) -std=c++17 -c -Wall -Werror -fpic
	g++ -shared -o lib$(LIBFILE).so $(LIBFILE).out
	g++ -L$(PATHTOLIB) -Wl,-rpath=$(PATHTOLIB) -Wall -o yourcode.out $(FILE).cpp -laudio -lopenblas -lpthread -lgfortran

clean:
	rm -f *.out *.exe *.so *.o
