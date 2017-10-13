all: build doczip 

build: collegemain.o college.o course.o 
	g++ collegemain.o college.o course.o -o build

collegemain.o: collegemain.cc course.h node.h college.h
	g++ -c collegemain.cc course.h node.h college.h

college.o: college.cc college.h
	g++ -c college.cc college.h

course.o: course.cc course.h
	g++ -c course.cc course.h

doczip:
	tar cvzf archieve_file.tar.gz makefile college.h.gch course.h.gch node.h.gch collegemain.o college.o course.o node.h tarray.h

myexe: course.o college.o node.h collegemain.cc
	g++ course.o college.o collegemain.cc -o myexe

doc: *.cc *.h
	doxygen

clean:
	rm -rf *.o a.out build college.h.gch course.h.gch node.h.gch html latex archieve_file.tar.gz