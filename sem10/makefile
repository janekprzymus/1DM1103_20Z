all:
	cc baza.c main.c -o mydb -Wall --pedantic

test: all
	./mydb baza.csv list_students

test-od-konca: all
	./mydb baza.csv list_students_from_end

test-sortuj-malejaco: all
	./mydb baza.csv sort_descending

test-ile: all
	./mydb baza.csv count_students

test-memory: all
	valgrind ./mydb baza.csv count_students
