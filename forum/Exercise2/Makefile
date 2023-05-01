run:forum_executable
	./forum_executable
forum_executable:forum_main.o forum_functions.o Tree_functions.o
	g++ forum_main.o forum_functions.o Tree_functions.o -o forum_executable
Tree_functions.o:Tree_functions.cpp Tree_class.h post_class.h
	g++ -c Tree_functions.cpp
forum_functions.o:forum_functions.cpp forum_class.h Tree_class.h post_class.h
	g++ -c forum_functions.cpp
forum_main.o:forum_main.cpp forum_class.h Tree_class.h post_class.h
	g++ -c forum_main.cpp
clean:
	rm -f forum_executable forum_main.o forum_functions.o Tree_functions.o
