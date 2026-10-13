#ifndef LIBRARYIO_H
#define LIBRARYIO_H

#include "Library.h"

class LibraryIO {
public:
    void Input(Library& lib);
    void Output(const Library& lib) const;
};

#endif // LIBRARYIO_H