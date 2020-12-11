.POSIX:
.PHONY: examples install

PREFIX = /usr/local
VERSION = 1.1.7

all: dasynq.pc examples

examples:
	cd -- '$@' && $(MAKE) -e -f build.make

dasynq.pc: dasynq.pc.in
	<'$?' sed 's|@PREFIX@|$(PREFIX)|' | >'$@' sed 's|@VERSION@|$(VERSION)|'

install: dasynq.pc
	mkdir -p '$(DESTDIR)$(PREFIX)/include' '$(DESTDIR)$(PREFIX)/lib/pkgconfig'
	cp -PRfp include/. '$(DESTDIR)$(PREFIX)/include'
	cp -- '$?' '$(DESTDIR)$(PREFIX)/lib/pkgconfig'
