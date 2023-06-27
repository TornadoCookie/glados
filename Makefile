LINUXCC=gcc
WIN32CC=x86_64-w64-mingw32-gcc
CFLAGS=-Wall -Werror

%:%.c
	$(LINUXCC) $^ -o $@ $(CFLAGS)

%.exe:%.c
	$(WIN32CC) $^ -o $@ $(CFLAGS)

linux: glados notes apply
windows: glados.exe notes.exe apply.exe

clean:
	rm -f apply glados notes
	rm -f apply.exe glados.exe notes.exe