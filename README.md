# Algorithms and Data Structures project
This repository comprises the first part of the [Algorithms and Data Structures]((https://sigarra.up.pt/feup/en/UCURR_GERAL.FICHA_UC_VIEW?pv_ocorrencia_id=436433)) course unit project. The goal was to create a solution for a specific problem applying the object-oriented paradigm in C++.

## Project description
The theme approached in the problem is 'Fleet management and vehicle rental'. Besides implementing a solution for the problem the software produced must have basic CRUD operations (create, read, update, delete), file store handling and allow multiple listings of the data stored.

## Wiki
A formal approach of the software engineering solution to the problem is documented in the GitHub Wiki section. The wiki contains the following contents:
* Requirements Engineering - use case description;
* Analysis Object Oriented - domain model;
* Design - use case sequence diagram and class diagram.

## Tools

### Code documentation
The code documentation is generated with [doxygen](http://www.doxygen.nl). Doxygen is a third-party documentation tool, thus, it is necessary a previous installation in order to be able to get the documentation.
A standard project doxygen configuration file is located in the 'docs' directory under the name 'doxyfile'. Currently, the documentation is only exported in HTML. After exporting the files are stored in the 'docs' directory.

Here is an example of how to export the documentation with the standard project doxygen configuration file:
```bash
cd docs
doxygen doxyfile
```

### Unit testing
The unit tests are perfomed by [Google Test](https://github.com/google/googletest), the Google's C++ test framework. Currently, the version used is v1.10.0.

### Building
Packaging and building done with [CMake](https://cmake.org/).

Here is an example of how to make a build of the project:
```bash
mkdir feup-aeda-proj1_build
cd feup-aeda-proj1_build
cmake ../feup-aeda-proj1
cmake --build .
```

## How to run

To be done.
