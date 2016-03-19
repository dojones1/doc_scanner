# doc_scanner
File scanner project - to gather word count

I'm using this as an sandpit to create a build system for C/C++ coding which allows:
- parallel compilation and unit test execution (not directory based)
- Use of make macros to simplify definition of different build targets and types.
- Using unit tests in development to evaluate different unit test frameworks.

All build and unit test execution is triggered by the top level makefile

Build options:
make software    - compiles all target binaries
make alltests    - compiles all unit test binaries
make test     - compiles and runs all unit test binaries
make all         - compiles everything and runs all unit tests
make clean       - cleans all build binaries and intermediate objects

Additional flags:
_Q= 			enables verbose output during compilation
VALGRIND=Y		enables VALGRIND compilation and execution.
CCACHE=Y		enables CCACHE for faster compilation and linking.
