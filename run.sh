# Make sur we are in workdir
workdir = ~/Repositories/Da-shou@github.com/da-renderer
cd workdir

# Compile project using CMake
cmake --build . --target clean
cmake --build .

# Run program if successfully compiled
if [ -f ./da_renderer ]; then
	./da_renderer
fi
