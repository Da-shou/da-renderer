# Compile project using CMake
cmake --build . --target clean
cmake -S .
cmake --build .

# Run program if successfully compiled
if [ -f ./da_renderer ]; then
	./da_renderer
fi
