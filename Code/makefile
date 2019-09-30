encode: encode.cpp
	g++ -o encode encode.cpp

decode: decode.cpp
	g++ -o decode decode.cpp

insertionTest: encode.cpp test7.txt
	g++ -o encode encode.cpp
	g++ -o decode decode.cpp
	./encode insertion < test7.txt > encoded.txt
	./decode insertion < encoded.txt > decoded.txt
	diff decoded.txt test7.txt

mergeTest: encode.cpp test7.txt
	g++ -o encode encode.cpp
	g++ -o decode decode.cpp
	./encode merge < test7.txt > encoded.txt
	./decode merge < encoded.txt > decoded.txt
	diff decoded.txt test7.txt

mixedTest: encode.cpp test7.txt
	g++ -o encode encode.cpp
	g++ -o decode decode.cpp
	./encode insertion < test7.txt > encoded.txt
	./decode merge < encoded.txt > decoded.txt
	diff decoded.txt test7.txt
	./encode merge < test7.txt > encoded.txt
	./decode insertion < encoded.txt > decoded.txt
	diff decoded.txt test7.txt

encodingTest: encode.cpp test7.txt
	g++ -o encode encode.cpp
	./encode insertion < test7.txt > insertionEncoded.txt
	./encode merge < test7.txt > mergeEncoded.txt
	diff insertionEncoded.txt mergeEncoded.txt

clean:
	$(RM) encode decode encoded.txt decoded.txt