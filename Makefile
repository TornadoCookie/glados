LINUXCC=gcc
WIN32CC=x86_64-w64-mingw32-gcc
CFLAGS=-Wall -Werror

glados: prompt.c notes apply
	$(LINUXCC) $< -o $@ $(CFLAGS)

notes: notes.c
	$(LINUXCC) $^ -o $@ $(CFLAGS)

apply: apply.c
	$(LINUXCC) $^ -o $@ $(CFLAGS)

glados.exe: prompt.c notes.exe apply.exe
	$(WIN32CC) $< -o $@ $(CFLAGS)

notes.exe: notes.c
	$(WIN32CC) $^ -o $@ $(CFLAGS)

apply.exe: apply.c
	$(WIN32CC) $^ -o $@ $(CFLAGS)

linux: glados
windows: glados.exe

clean:
	rm -f apply glados notes
	rm -f apply.exe glados.exe notes.exe