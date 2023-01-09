
# cxx-core-tuple

Tuples primitives for bridging the gap between compile-time and run-time.

# Brief Tour


```c++
#include "core/tp/tuple.h"
```

# Installation

```bash
git clone git@github.com:cpp-core/mp
mkdir mp/build && cd mp/build
CC=clang-mp-14 CXX=clang++-mp-14 cmake -DCMAKE_INSTALL_PREFIX=$HOME/opt ..
make -j4 check  # Run the tests
make install    # Do the install
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
