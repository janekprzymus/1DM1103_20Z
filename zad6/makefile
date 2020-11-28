# co_chcemy_zrobic:od_czego_to_zalezy
# (TAB)co_trzeba_uruchomic_aby_uzyskac_co
JANEK=mymatlab.o przetwarzanko.o dzialania.o

mymatlab: $(JANEK)
	cc $(JANEK) -o $@ -Wall --pedantic -lm

%.o:%.c
	cc -c $^ -o $@

clean:
	rm -f mymatlab
	rm -f *.o
	rm -f b.txt

sum: mymatlab
	./mymatlab sum $(filter-out $@,$(MAKECMDGOALS))

subtract: mymatlab
	./mymatlab subtract $(filter-out $@,$(MAKECMDGOALS))

prod: mymatlab
	./mymatlab prod $(filter-out $@,$(MAKECMDGOALS))

multiply: mymatlab
	./mymatlab multiply $(filter-out $@,$(MAKECMDGOALS))

norm: mymatlab
	./mymatlab norm $(filter-out $@,$(MAKECMDGOALS))