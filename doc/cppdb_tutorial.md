CPPDB Tutoiral
==========================================================================
Table of Contents
==========================================================================
1. Adding Storage Types
  1. Durining Object Construction
  2. After Object Construction
2. Adding Operations
  1. Creating an Operation
  2. Adding Operation
3. Calling Operation

1 Adding Storage Types
==========================================================================

1 Durining Object Construction
--------------------------------------------------------------------------
With a c++11 cimplier with vardiac templates. Types with contaniers can be
added durning construction of the class. By providing the template
arguments in alternating order of (type, container), where type is the
type to be added and container is the container for that type.

[example: addtype.cpp](../example/cppdb/addtype.cpp)

```c++
cppdb instance<int, std::vector<int>, char, std::vector<char> >();
```

2 After Object Construction
--------------------------------------------------------------------------
[example: addtype.cpp](../example/cppdb/addtype.cpp)

```c++
instance.add_type<float, std::vector<float> >();
```

2 Adding Operations
==========================================================================
1 Creating an Operation
--------------------------------------------------------------------------
2 Adding Operation
--------------------------------------------------------------------------
3 Calling Operation
==========================================================================
