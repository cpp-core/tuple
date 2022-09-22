
# cxx-core-tuple

Tuples primitives for bridging the gap between compile-time and run-time.

# Brief Tour


```c++
#include "core/tp/tuple.h"
```

# Installation

## cxx-depends

```bash
git clone git@github.com:melton1968/cxx-depends
mkdir cxx-depends/build && cd cxx-depends/build
CC=clang-mp-11 CXX=clang++-mp-11 cmake -DCMAKE_INSTALL_PREFIX=$HOME/opt -DCORE_TESTS=ON ..
make cxx_core_tuple-check  # Run the tests
make cxx_core_tuple        # Do the install
```

To build the documentation (requires doxygen and sphinx-build to be installed):

```bash
CC=clang-11 CXX=clang++11 cmake -DCORE_DOCS ..
make cxx_core_tuple_docs # root of html tree is docs/html/index.html
```

# Background

*cxx-core-tuple* is part of the *cxx-core** family of C++20 based
libraries. The *cxx-core* libraries have two primary goals:

- **Ergonomics**. In the spirit of the `CppCoreGuideLines`, cxx-core
  aspires to facilitate writing concise, idiomatic code not by force,
  but by providing a clear path that produces robust, easy to read
  code. Good code should be fun to write.
  
- **Components**. Modern language platforms provide broad support for
  first-class library components, while C++ has traditionally only
  provided a very minimal standard library. *cxx-core* aspires to
  provide support for a broad range of libraries that feel like part
  of the language.

# Appendix

```{toctree}
---
caption: API REFERENCE
---
api/intro
api/construct
api/query
api/operate
api/utility
```

```{toctree}
---
caption: FILE REFERENCE
maxdepth: 5
---
include/ <generated/include/dir>
src/ <generated/src/dir>
test/ <generated/test/dir>
```
