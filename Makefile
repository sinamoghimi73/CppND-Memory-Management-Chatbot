.PHONY: all
all: format test build

.PHONY: format
format:
	clang-format src/*.cpp src/*.h -i

.PHONY: build
build:
	mkdir -p build
	cd build && \
	cmake .. && \
	make

.PHONY: debug
debug:
	mkdir -p build
	cd build && \
	cmake -DCMAKE_BUILD_TYPE=debug .. && \
	make

.PHONY: clean
clean:
	rm -rf build

style:
	clang-format -style=google -dump-config > .clang-format
