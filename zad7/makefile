JANEK=mydb.o baza.o

mydb: $(JANEK)
	cc $(JANEK) -o $@ -Wall --pedantic -lm

%.o:%.c
	cc -c $^ -o $@

clean:
	rm -f mydb
	rm -f *.o

list_students: mydb
	./mydb baza.csv list students

list_courses: mydb
	./mydb baza.csv list courses

list_grades: mydb
	./mydb baza.csv list grades

add_student: mydb
	./mydb baza.csv add student $(filter-out $@,$(MAKECMDGOALS))

add_course: mydb
	./mydb baza.csv add course $(filter-out $@,$(MAKECMDGOALS))

add_grade: mydb
	./mydb baza.csv add grade $(filter-out $@,$(MAKECMDGOALS))

test-memory: mydb
	valgrind ./mydb baza.csv count_students
