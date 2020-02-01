# To build: simply call ./build.sh
# To also run when build completed pass the flag `-r` or `--run`

# Make build folder
mkdir -p ./bin

# Compile
g++ -std=c++17 ./logtools/src/main.cpp -o ./bin/program.o

# Run if requested
if echo $* | grep -e "--run" -q
then
	./bin/program.o
fi
