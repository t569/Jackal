project('jackal', 'cpp')

# Automatically find all .cpp files in src/
sources = cpp.find_sources('src', 'cpp')

# Specify the include directory for the header file
incdir = include_directories('include')

# The final executable
jackal_exe = executable('jackal', 'main.cpp', include_directories: incdir)
