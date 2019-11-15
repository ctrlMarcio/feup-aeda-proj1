# Algorithms and Data Structures project

[![Build Status](https://travis-ci.org/luist18/feup-aeda-proj1.svg?branch=master)](https://travis-ci.org/luist18/feup-aeda-proj1)
[![codecov](https://codecov.io/gh/luist18/feup-aeda-proj1/branch/master/graph/badge.svg)](https://codecov.io/gh/luist18/feup-aeda-proj1)
[![CodeFactor](https://www.codefactor.io/repository/github/luist18/feup-aeda-proj1/badge)](https://www.codefactor.io/repository/github/luist18/feup-aeda-proj1)
![Documentation Status](https://img.shields.io/website?down_color=red&down_message=failed&label=docs&up_message=passing&url=https%3A%2F%2Fluist18.github.io%2Ffeup-aeda-proj1%2F)
![GitHub](https://img.shields.io/github/license/luist18/feup-aeda-proj1?color=blue)
![GitHub language count](https://img.shields.io/github/languages/count/luist18/feup-aeda-proj1)
![GitHub last commit](https://img.shields.io/github/last-commit/luist18/feup-aeda-proj1)

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
cd doc
doxygen Doxyfile
```

### Unit testing
The unit tests are perfomed by [Google Test](https://github.com/google/googletest), the Google's C++ test framework. Currently, the version used is v1.10.0.

### Building
Packaging and building done with [CMake](https://cmake.org/).

Here is an example of how to make a build of the project:
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## How to run

To be done.
