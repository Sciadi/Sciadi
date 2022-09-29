OBJ = esame.o liste.o tipo.o
CXXFLAGS=-Wall

compito.exe: $(OBJ)
	g++ -o esame.exe $(OBJ)

-include dependencies

.PHONY: clean cleanall run
depend:
	g++ -MM *.cpp > dependencies
clean:
	rm -f *.o
cleanall:
	rm -f compito *.o
