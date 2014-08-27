.PHONY: clean default martenoid.exe

CC = mgcc
CFLAGS = -Wall -I/home/alvaro/bin/marte/arch/drivers/svga
#CFLAGS = -Wall -I/home/alvaro/bin/marte/arch/drivers/svga
LDFLAGS = -lsvga -lm
GNATMAKE = mgnatmake
ADAFLAGS = -gnata -gnato -g

default: martenoid.exe

martenoid.exe: 
	$(CC) $(CFLAGS) main.c fonts.c $(LDFLAGS) -o $@;

clean:
	@exec echo -e "\n>> Cleaning... ";
	@find \( -name '*.[oa]' -or -name '*~*' -or -name '*.ali' -or -name '*.log' \
		-or -name '*.exe' -or -name 'mprogram' -or -name 'a.out' \) -print -delete
	@exec echo ">> End Cleaning"