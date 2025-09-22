# Compile project using CMake
cmake --build . --target clean
cmake -S .
cmake --build .

# Run program if successfully compiled
if [ -f ./build/da_renderer ]; then
	./build/da_renderer
fi
