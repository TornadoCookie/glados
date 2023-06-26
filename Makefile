LINUXCC=gcc
WIN32CC=x86_64-w64-mingw32-gcc

glados: prompt.c notes apply
	$(LINUXCC) $< -o $@

notes: notes.c
	$(LINUXCC) $^ -o $@

apply: apply.c
	$(LINUXCC) $^ -o $@

glados.exe: prompt.c notes.exe apply.exe
	$(WIN32CC) $< -o $@

notes.exe: notes.c
	$(WIN32CC) $^ -o $@

apply.exe: apply.c
	$(WIN32CC) $^ -o $@

linux: glados
windows: glados.exe

clean:
	rm -f apply glados notes
	rm -f apply.exe glados.exe notes.exe