export BUILD="build"

# Compile project using CMake
cmake -S . -B "$BUILD"
cmake --build "$BUILD" --target clean
cmake --build "$BUILD"

# Move compile_commands to root so clangd sees it.
if [ -f "./$BUILD/compile_commands.json" ]; then
	mv $BUILD/compile_commands.json .
fi

# Run program if successfully compiled
if [ -f "./$BUILD/da_renderer" ]; then
	"./$BUILD/da_renderer"
fi
