CC=sdcc

REL_FILES=out/main.rel

$(shell mkdir -p out/)

game.sms: out/game.ihx
	ihx2sms out/game.ihx game.sms

out/game.ihx: $(REL_FILES)
	$(CC) -mz80 --no-std-crt0 --data-loc 0xC000 \
		-o out/game.ihx \
		crt0/crt0_sms.rel $(REL_FILES) lib/SMSlib.lib

out/main.rel: src/main.c
	$(CC) -mz80 -c --std-sdcc99 src/main.c -o out/main.rel

clean:
	rm -rf out/