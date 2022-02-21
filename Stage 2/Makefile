FILE_NAME = main

$(FILE_NAME).out: $(FILE_NAME).cpp
	g++ $(FILE_NAME).cpp -o $(FILE_NAME).out -I /mnt/c/users/yatha/desktop/tmp/openblas/mainfiles/include -L /mnt/c/users/yatha/desktop/tmp/openblas/mainfiles/lib -lopenblas -lpthread -lgfortran

clean:
	rm -f *.out *.exe