Karagiannis Eystathios 1115201800311

Compilation of exercise 1:
	Use Makefile .
Exercise 1 consists of 6 files:
	forum_main.cpp
	forum_functions.cpp
	forum_class.h
	Makefile(For the compilation)
	names.txt
	texts.txt

About forum_main.cpp:
	function print_Random_Post_of_Forum(forum& Currforum,int mult):
		Is printing "mult" random posts from the forum "Currforum".

About forum_class.h:
	Includes the deffinitions of the classes (post,thread,forum).
	The functions of the classes are public.
	The information and the variables of the classes are private 
	because they should not be visible out of the classes' range.
	There are 2 global variables:
		GLOBAL_F_SIZE:Is the number of threads included in a forum.
		GLOBAL_T_SIZE:Is the number of posts included in a thread.

About forum_functions.cpp:
	Includes the implementations of the classes' functions that were deffined
	in the file "forum_class.h".
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