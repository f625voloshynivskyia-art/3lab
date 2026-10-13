#ifndef PLAYER_H
#define PLAYER_H

#include "Library.h"
#include "LibraryIO.h"

class Player {
private:
    int count;
    Library* items;
    LibraryIO* ioWorker;

    bool ContainsIgnoreCase(const std::string& text, const std::string& pattern) const;

public:
    Player();
    ~Player();

    void FillLibrary();
    void LoadDemoData();
    void ShowAll() const;

    // Пошук фільмів за акторами, назвами, темами
    void ShowByActor() const;
    void ShowByTitle() const;
    void ShowByTheme() const;
};

#endif // PLAYER_H