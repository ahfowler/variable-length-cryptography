encode: encode.cpp
	g++ -o encode encode.cpp

decode: decode.cpp
	g++ -o decode decode.cpp

test: encode.cpp input.txt
	g++ -o encode encode.cpp
	g++ -o decode decode.cpp
	./encode merge < input.txt > encoded.txt
	./decode insertion < encoded.txt > decoded.txt
	diff decoded.txt input.txt

clean:
	$(RM) encode decode encoded.txt decoded.txt