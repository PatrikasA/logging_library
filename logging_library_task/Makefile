.PHONY: all logger log_reader programs_for_logging install uninstall


all: logger log_reader programs_for_logging

logger:
	$(MAKE) -C ./logger

log_reader:
	$(MAKE) -C ./log_reader

programs_for_logging:
	$(MAKE) -C ./programs_for_logging

install:
	$(MAKE) -C ./logger install
	$(MAKE) -C ./log_reader install
	$(MAKE) -C ./programs_for_logging install

uninstall:
	$(MAKE) -C ./logger uninstall
	$(MAKE) -C ./log_reader uninstall
	$(MAKE) -C ./programs_for_logging uninstall

clean:
	$(MAKE) -C ./logger clean
	$(MAKE) -C ./log_reader clean
	$(MAKE) -C ./programs_for_logging clean