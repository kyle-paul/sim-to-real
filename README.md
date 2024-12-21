# Sim-to-real graphics environment explorer

## Getting Started
### Clone the Repository
First, you need to clone the repository and init all git submodules
```bash
git clone git@github.com:kyle-paul/sim-to-real.git
git submodule update --init --recursive
```

### Build Dependencies
Then, to build the dependencies, you can either manually set up by following the [Installation Guide](Installation.md) or run this command to automate the process
```bash
chmod +x build_dependencies.sh
./build_dependencies.sh
```

### Build the Project
Noew, build the project with CMake. My build environment is on Ubuntu 24.04, Linux.
```bash
cmake -B build
cmake --build build --parallel <your-cpu-threads>
./build/chess
```