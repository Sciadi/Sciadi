OBJ = bstEsame.o carta.o bst.o
CXXFLAGS=-Wall

bstEsame.exe: $(OBJ)
	g++ -o bstEsame.exe $(OBJ)

-include dependencies

.PHONY: clean cleanall run
depend:
	g++ -MM *.cpp > dependencies
clean:
	rm -f *.o
cleanall:
	rm -f bstEsame *.o