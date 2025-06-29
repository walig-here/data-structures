# ⚙️ Data structures v2

Personal project for in-depth learning and exploring the most important data structures in computer science. Why? Because practice makes perfect! Especially when practising the fundamentals 😉

Also it's a great way to find out how much I've improved in my coding skills over the years since the project's built upon my old university assignment from *Wrocław University of Science and Technology* where I implemented (in *C++*) and then measured time complexities of 3 basic data structures: **dynamic array**, **linked list**, **heap** and finally **binary search tree**.

- [⚙️ Data structures v2](#️-data-structures-v2)
  - [🎯 Goals](#-goals)
  - [🚀 Quickstart](#-quickstart)
  - [📇 Project structure](#-project-structure)
    - [*Data Structures Library*](#data-structures-library)
    - [Benchmarks](#benchmarks)
    - [*Benchmark analyzer*](#benchmark-analyzer)
    - [*Data Structures Analyzer*](#data-structures-analyzer)

## 🎯 Goals

- [ ] 👨🏻‍💻 Implement various data structures in low-level language (C++).

- [ ] ⏱️ Measure time & memory complexities of the implemented data structures & compare them to their equivalents from STL and higher-level languages: *Python*, *Java* and *TypeScript*.

- [ ] 📚 Dive into source code of these data structures in higher level languages to gain more in-depth understanding of those languages.

- [ ] 🖼️ App with visualizations for implemented data structures that would allow users to follow how they work step by step.

You can check the current progress in the [*Versions*](/docs/versions.md) document.

## 🚀 Quickstart

## 📇 Project structure

![project structure](/docs/img/project-structure.svg)

### *Data Structures Library*

Library written in *C++* that contains my implementations for various data structures (DS). It should allow to use those DS in 2 modes:

1. **Release:** Standard usage of the DSes for maximal performance.
2. **Debug:** Allows for step-by-step work of the DSes for easy visualization.

### Benchmarks

Applications with CLI (or simple Web for *TS*) interfaces that would allow to measure time and memory complexities of data structures. Included types of benchmarks:

* ***Library benchmark:*** Benchmarking for my *C++* implementations and *Standard Template Library* (STL). A *C++* application with CLI interface.
* ***Python benchmark:*** Benchmarking for *Python* implementations of the data structures (both builtin & third-party libs). A *Python* application with CLI interface.
* ***Java benchmark:*** Benchmarking for *Java* implementations of the data structures (both builtin & third party lib). A *Java* application with CLI interface. 
* ***TS benchmark:*** Benchmarking for *TypeScript* implementations of the data structures (both builtin & third party lib). Simple Web application.

All benchmarks generate output CSV files with results that follow the same schema.

### *Benchmark analyzer*

Python CLI application that analyzes targeted benchmark CSV files. It allows to:

* Compare implementations of data structures both numerically & graphically.
* Present time & memory complexities of DS operations both numerically and graphically.

It generates PDF reports as an output as well as SVG files for as graphical analysis output.

### *Data Structures Analyzer*

A *Python* desktop application with GUI that would allow to analyze inner-workings of the implemented data structures step-by-step. In other words this app runs implemented data structures in the *debug* mode. 
