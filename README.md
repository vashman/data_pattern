Data Pattern
==========================================================================
status: Open Alpha Development

Data model aims to make database input / output simple and extensible. It
accoplish this by seperating the query language from the underlying data
model, while seperating data type's via the typesystems library.

Formatting
```c++
auto io = make_data_model(device, func);
io << format (T);
```

Type Saftey
```c++
io << T << U >> X;
T = read<T>(io);
write (T, io);
```

Extending
```c++
model & operator << (model&, T&){
// do stuff
return _mdl;
}
```

i18n
Error Handling
```c++

```

Performance
```c++

```


Documentation
==========================================================================
+ [Tutorial](doc/tutorial.md)
+ [Desgin Overview](doc/proposal.md)

Features
==========================================================================
+ add writer iterator
+ collection of model / locale builder
+ make Locale immutable
+ add concurrancy measures
+ add inilizer list ctor for model

License
==========================================================================
Source Copyright © 2013-2017 Sundeep S. Sangha and contributers.
Distributed under the Boost software license. See the
[License](./License_1_0.txt) file.
