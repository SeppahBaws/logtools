# To build: simply call ./build.sh
# To also run when build completed pass the flag `-r` or `--run`

# Make build folder
mkdir -p ./bin

# Compile
g++ -o ./bin/program.o main.cpp

# Run if requested
