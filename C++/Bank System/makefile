OBJ = main.o 
CXXFLAGS=-Wall

banksys.out: $(OBJ)
	g++ -o banksys.out $(OBJ)

-include dependencies

.PHONY: clean cleanall run
depend:
	g++ -MM *.cpp > dependencies
clean:
	rm -f *.o
cleanall:
	rm -f banksys *.o