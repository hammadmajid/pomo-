build:
	cmake -S . -B target
	make -C target

run: build
	./target/pomo++ $(filter-out $@,$(MAKECMDGOALS))

clean:
	rm -rf target/
