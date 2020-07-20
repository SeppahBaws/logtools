# To build: simply call ./build.sh
# To also run when build completed pass the flag `-r`

# Compile
make

# Run if requested
if echo $* | grep -e "-r" -q
then
	./bin/Debug-x86_64-linux/logtools
fi
