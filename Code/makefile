encode: encode.cpp
	g++ -o encode encode.cpp

decode: decode.cpp
	g++ -o decode decode.cpp

test: encode.cpp input.txt
	g++ -o encode encode.cpp
	./encode merge < input.txt > encoded.txt

clean:
	$(RM) encode decode encoded.txt decoded.txt