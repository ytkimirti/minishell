all: sender receiver

sender: sender.c
	gcc sender.c -o sender -g

receiver: receiver.c
	gcc receiver.c -o receiver -g

clean:
	rm -rf sender receiver

re: clean all

.PHONY: all
