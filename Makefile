CC=sdcc

REL_FILES=out/main.rel out/bank2.rel

BANKS=-Wl-b_BANK2=0x8000

$(shell mkdir -p out/)

.PHONY: all
all: assets game.sms

game.sms: out/game.ihx
	ihx2sms out/game.ihx out/game.sms

out/game.ihx: $(REL_FILES) assets
	$(CC) -mz80 --no-std-crt0 --data-loc 0xC000 \
		-o out/game.ihx \
		$(BANKS) \
		--peep-file peep.def \
		crt0/crt0_sms.rel $(REL_FILES) lib/SMSlib.lib

out/main.rel: src/main.c
	$(CC) -mz80 -c --std-sdcc99 \
		--peep-file peep.def \
		src/main.c -o out/main.rel

.PHONY: assets
assets:
	assets2banks ./assets --compile
	mv bank*.h bank*.rel out/

.PHONY: clean
clean:
	rm -rf out/