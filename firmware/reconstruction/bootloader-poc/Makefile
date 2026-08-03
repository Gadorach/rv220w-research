.PHONY: all stage2 test clean
all: stage2 test
stage2:
	$(MAKE) -C stage2 all
test:
	python3 tests/run_all.py
clean:
	$(MAKE) -C stage2 clean
