Karagiannis Eystathios 1115201800311

Compilation of exercise 2:
	Use Makefile .
Exercise 1 consists of 6 files:
	forum_main.cpp
	forum_functions.cpp
	Tree_functions.cpp
	forum_class.h
	Tree_class.h
	post_class.h
	Makefile(For the compilation)
	names.txt
	texts.txt

About forum_class.h:
	Includes the file Tree_class.h because it contains the classes(post,List,Tree).
	Includes the deffinitions of the classes (thread,forum).
	The functions of the classes are public.
	The information and the variables of the classes are private 
	because they should not be visible out of the classes' range.
	There are 2 global variables:
		GLOBAL_F_SIZE:Is the number of threads included in a forum.
		GLOBAL_T_SIZE:Is the number of posts included in a thread.

About Tree_class.h:
	Includes the file post_class.h because it contains the classes(post).
	Includes the deffinitions of the classes (List,Tree).
	The functions of the classes are public.
	The information and the variables of the classes are private 
	because they should not be visible out of the classes' range.

About post_class.h:
	Includes the deffinition of the class (post).
	The information and the variables of the class are private 
	because they should not be visible out of the class's range.

About Tree_functions.cpp:
	Includes the implementations of the classes' that were deffined in the file
	"Tree_class.h"
About forum_functions.cpp:
	Includes the implementations of the classes' functions that were deffined
	in the filea "forum_class.h" "post_class.h".
	The function createTXT(string Type) is returning a string the given "Type"
	(Name,Text),which string was read from the file "names.txt" or "texts.txt"
	depending on its "Type".  
	There are 5 global variables:
		GLOBAL_ID:which helps the constractor of the post to create a unicue id.
		Nms_Max_Range:which is assigned with the size of the "names.txt" file.
		Txt_Max_Range:which is assigned with the size of the "texts.txt" file.
		Txt_Max_Size and Txt_Min_Size:Help the function createTXT(string Type)
		to create and return a string with size in the range [Txt_Min_Size,Txt_Max_Range],
		in case the Type is "Text".

About names.txt and texts.txt:
	Those two .txt files contain the strings used as "Names" and "Texts" in the exercise.