listtest: list.c
	gcc list.c -o listtest;

clean:
	rm *~;

run: listtest
	./listtest
