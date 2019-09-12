encode: encode.cpp
	g++ -o encode encode.cpp

decode: decode.cpp
	g++ -o decode decode.cpp

test: encode.cpp input.txt solution.txt
	./encode < input.txt > output.txt
	diff output.txt solution.txt

clean:
	$(RM) encode decode