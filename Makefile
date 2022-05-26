SRC = analyzer
.PHONY: clean

$(SRC): lex.yy.c $(SRC).tab.c
	gcc -o $@ $+

lex.yy.c: $(SRC).l $(SRC).tab.c
	flex -d $<

$(SRC).tab.c: $(SRC).y
	bison -d -Wcounterexamples -Wconflicts-sr $<

clean:
	rm -f lex.yy.c
	rm -f $(SRC).tab.c
	rm -f $(SRC).tab.h
	rm -f $(SRC)
