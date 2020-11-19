# co_chcemy_zrobic:od_czego_to_zalezy
# (TAB)co_trzeba_uruchomic_aby_uzyskac_co
JANEK=main.o studenci.o dziekanat.o

main: $(JANEK)
	cc $(JANEK) -o $@ -Wall --pedantic

%.o:%.c
	cc -c $^ -o $@

clean:
	rm -f main
	rm -f *.o

#By znalezc studenta z najlepsza srednia:
najlepszy_student: main
	./main studenci.txt best_stud

#By znalezc przedmiot z najwyzsza srednia ocen:
najlepszy_przedmiot: main
	./main studenci.txt best_przed

#By znalezc przedmiot z najnizsza srednia ocen:
najgorszy_przedmiot: main
	./main studenci.txt worst_przed
