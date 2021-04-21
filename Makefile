build: mock.c
	@gcc mock.c -o mock -Xlinker --strip-all
	@printf "Successfully built mock\n"

clean:
	@printf "Cleaning...\n"
	@-rm mock 2> /dev/null || echo > /dev/null
