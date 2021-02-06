CC=sdcc
CFLAGS=-c -mz80 --std-sdcc99
LDFLAGS=-mz80 --no-std-crt0 --data-loc 0xC000
LIBS=crt0/crt0_sms.rel lib/SMSlib.lib

# All .c files in the src/ directory
SRC_FILES=$(wildcard src/*.c)

# Map src/%.c to out/%.rel
REL_FILES=$(SRC_FILES:src/%.c=out/%.rel)

BANKS=-Wl-b_BANK2=0x8000

$(shell mkdir -p out/)

.PHONE: debug
debug: CFLAGS += --debug
debug: LDFLAGS += -Wl-y
debug: all

.PHONY: all
all: assets
all: REL_FILES += $(wildcard out/bank*.rel) # Add new bankX.rel files
all: game.sms

game.sms: out/game.ihx
	ihx2sms out/game.ihx out/game.sms

out/game.ihx: $(REL_FILES) assets
	$(CC) $(LDFLAGS) \
		-o out/game.ihx \
		$(BANKS) \
		--peep-file peep.def \
		$(LIBS) $(REL_FILES)

out/%.rel: src/%.c
	$(CC) $(CFLAGS) \
		--peep-file peep.def \
		$< -o $@

.PHONY: assets
assets:
	assets2banks ./assets --compile
	mv bank*.h bank*.rel out/

.PHONY: clean
clean:
	rm -rf out/
