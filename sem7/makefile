# co_chcemy_zrobic:od_czego_to_zalezy
# (TAB)co_trzeba_uruchomic_aby_uzyskac_co

#p7_3:p7_3.c p7_3_liczydlo.c p7_3_dodaj.c includy/p7_3_liczydlo.h includy/p7_3_dodaj.h
#	cc p7_3.c p7_3_liczydlo.c p7_3_dodaj.c -o p7_3 -Wall --pedantic

DEPS=p7_3.o p7_3_liczydlo.o p7_3_dodaj.o

# p7_3: clean $(DEPS)
p7_3: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic

%.o:%.c
	cc -c $^ -o $@

#p7_3.o:p7_3.c
#	cc -c $^ -o $@

#p7_3_dodaj.o:p7_3_dodaj.c
#	cc -c $^ -o $@

#p7_3_liczydlo.o:p7_3_liczydlo.c
#	cc -c $^ -o $@

clean:
	rm -f p7_3
	rm -f *.o

test: p7_3
	./p7_3 1 2 3
