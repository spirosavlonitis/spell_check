default:
	gcc *.c -o spell_check

run: default
	./spell_check
