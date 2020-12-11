all:
	cc baza.c main.c -o mydb -Wall --pedantic

clean:
	rm -f mydb

test: all
	./mydb baza.csv list students

test-przedmiotow: all
	./mydb baza.csv list courses

test-ocen: all
	./mydb baza.csv list grades

test-od-konca: all
	./mydb baza.csv list students_from_end

test-sortuj-stud-malejaco: all
	./mydb baza.csv sort students descending

test-sortuj-stud-rosnaco: all
	./mydb baza.csv sort students ascending

test-sortuj-po-kodzie: all
	./mydb baza.csv sort courses by_code

test-sortuj-po-nazwie: all
	./mydb baza.csv sort courses by_name

test-oceny-przedmiotu: all
	./mydb baza.csv list grades_by_course $(filter-out $@,$(MAKECMDGOALS))

test-oceny-studenta: all
	./mydb baza.csv list grades_by_student $(filter-out $@,$(MAKECMDGOALS))

dodaj_studenta: all
	./mydb baza.csv add student $(filter-out $@,$(MAKECMDGOALS))

dodaj_przedmiot: all
	./mydb baza.csv add course $(filter-out $@,$(MAKECMDGOALS))

dodaj_ocene: all
	./mydb baza.csv add grade $(filter-out $@,$(MAKECMDGOALS))

test-ile: all
	./mydb baza.csv count_students

test-memory: all
	valgrind ./mydb baza.csv count_students
