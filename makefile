# makefile - zx-vexed

# builds a TZX format output file
#
# * "compiles" loader from Sinclair BASIC
# * cross-compiles C program into TAP (includes a loader I don't want)
# * splits cross-compiled TAP
# * builds TZX from component parts

cc = snap run z88dk.zcc
cc_opts = +zx -c -clib=sdcc_iy --opt-code-size -pragma-define:CRT_ORG_CODE=26000
ld = snap run z88dk.zcc
ld_opts = +zx -clib=sdcc_iy --opt-code-size -pragma-define:CRT_ORG_CODE=26000 -create-app

bas2tap = ../bas2tap/bas2tap
bas2tap_opts = -a10

tzxmerge = ../../Python/tzxtools/tzxmerge.py
tzxsplit = ../../Python/tzxtools/tzxsplit.py
split_opts = -1

objects = zx-vexed.o screen.o sysvars.o keyboard.o

# %.o: %.c %.h $(PRAGMA_FILE)
#	${cc} ${cc_opts} -o $@ $<

all: zx-vexed.tzx

zx-vexed.o: zx-vexed.c
	${cc} ${cc_opts} -o zx-vexed.o zx-vexed.c
screen.o: zxspectrum/screen.c zxspectrum/screen.h
	${cc} ${cc_opts} -o screen.o zxspectrum/screen.c
sysvars.o: zxspectrum/sysvars.c zxspectrum/sysvars.h
	${cc} ${cc_opts} -o sysvars.o zxspectrum/sysvars.c
keyboard.o: zxspectrum/keyboard.c zxspectrum/keyboard.h
	${cc} ${cc_opts} -o keyboard.o zxspectrum/keyboard.c

zx-vexed.tzx: loader.tap splash.tap zx-vexed.tap
	rm -f *.tzx
	${tzxsplit} ${split_opts} zx-vexed.tap
	${tzxmerge} loader.tap splash.tap zx-vexed-001.tzx -o $@
	rm -f *.bin zx-vexed Loader-001.tzx zx-vexed-001.tzx

zx-vexed.tap: ${objects}
	${ld} ${ld_opts} -o $(basename $@) -startup=31 ${objects}

loader.tap: loader.bas
	${bas2tap} ${bas2tap_opts} -s"$(basename $@)" $< $(basename $@).tap

clean:
	rm -f *.bin zx-vexed Loader-001.tzx zx-vexed-001.tzx ${objects}

unmake: clean
	rm zx-vexed.tzx zx-vexed.tap loader.tap
