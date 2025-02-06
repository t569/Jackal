# project setup
project('jackal', 'cpp',
  version: '0.1.0',
  default_options: ['cpp_std=c++17'])

# # Automatically find all .cpp files in src/
sources = files('main.cpp', 'src/jackal/core.cpp') #FIXME: make this more efficient

# Specify the include directory for the header file
inc_dir = include_directories('include')

# Build executable
executable('jackal',
  sources: sources,
  include_directories: inc_dir,
  install: true)