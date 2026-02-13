all:
	gcc src/main.c src/social_network.c -o social_network

clean:
	rm -f social_network
