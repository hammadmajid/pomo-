build:
	mkdir target -p
	clang++ src/main.cpp -o target/timer -Wall

run: build
	./target/timer

clean:
	rm -rf target/
