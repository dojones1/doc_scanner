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
make testrun     - compiles and runs all unit test binaries
make all         - compiles everything and runs all unit tests
make clean       - cleans all build binaries and intermediate objects

The build output by default is relatively quiet to enable a verbose mode add _Q= to the make command.
