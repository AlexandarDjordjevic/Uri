# Uri

This is the library which implements [IETF RFC 3986](https://datatracker.ietf.org/doc/html/rfc3986), "Uniform Resource Identifier (URI): Generic Syntax".

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Unit tests](https://github.com/AlexandarDjordjevic/Uri/actions/workflows/Debug.yml/badge.svg)](https://github.com/AlexandarDjordjevic/Uri/actions/workflows/Debug.yml)

## Requirements

* GCC 9.4.0 x86_64-linux-gnu
* CMake minimum 3.8
* gtests 

### Configure

```bash
cmake -B build -DCMAKE_BUILD_TYPE=<Release, Debug>
```

#### Build

```bash
cmake --build build --config <Release, Debug>
```
