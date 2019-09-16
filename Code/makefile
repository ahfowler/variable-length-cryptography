encode: encode.cpp
	g++ -o encode encode.cpp

decode: decode.cpp
	g++ -o decode decode.cpp

test: encode.cpp chicken-sandwich-vox.txt haiku1.txt tale-of-two-cities.txt through-the-looking-glass.txt
	g++ -o encode encode.cpp
	./encode < chicken-sandwich-vox.txt > output1.txt
	./encode < haiku1.txt > output2.txt
	./encode < tale-of-two-cities.txt > output3.txt
	./encode < through-the-looking-glass.txt > output4.txt

clean:
	$(RM) encode decode output1.txt output2.txt output3.txt output4.txt