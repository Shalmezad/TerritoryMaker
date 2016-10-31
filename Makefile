build:
	make prep
	g++ main.cpp src/territoryMap.cpp -o bin/TerritoryMaker 
prep:
	mkdir -p bin
clean:
	rm -rf bin
run:
	bin/TerritoryMaker
