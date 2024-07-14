build:
	cmake -S . -B target
	make -C target

run: build
	./target/timer

clean:
	rm -rf target/
