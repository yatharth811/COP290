FILE_NAME = yourcode

$(FILE_NAME).out: $(FILE_NAME).c
	g++ $(FILE_NAME).c -o $(FILE_NAME).out -I /mnt/c/users/yatha/desktop/tmp/openblas/mainfiles/include -L /mnt/c/users/yatha/desktop/tmp/openblas/mainfiles/lib -lopenblas -lpthread -lgfortran

clean:
	rm -f *.out *.exe