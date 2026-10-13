#include "LibraryIO.h"
#include "ConsolIO.h"
#include <iostream>

using namespace std;

void LibraryIO::Input(Library& lib) {
    cout << "\n\t--- ¬в≥д даних про в≥деоф≥льм ---" << endl;

    cout << "\t¬вед≥ть заголовок ф≥льму: ";
    lib.setTitle(ConsolIO::GetText(cin));

    cout << "\t¬вед≥ть тему/жанр: ";
    lib.setTheme(ConsolIO::GetText(cin));

    cout << "\t¬вед≥ть актор≥в: ";
    lib.setActors(ConsolIO::GetText(cin));

    cout << "\t¬вед≥ть оц≥нку (0.0 - 10.0): ";
    lib.setRating(ConsolIO::GetValue(cin));

    cout << "\t¬вед≥ть тривал≥сть (хв): ";
    lib.setDuration(ConsolIO::GetValue(cin));

    cout << "\t¬вед≥ть швидк≥сть в≥дтворенн€ (напр., 1.0): ";
    lib.setSpeed(ConsolIO::GetValue(cin));

    cout << "\t¬вед≥ть назву файла: ";
    lib.setFileName(ConsolIO::GetText(cin));

    cout << "\t¬вед≥ть дату (ƒƒ.ћћ.––––): ";
    lib.setDate(ConsolIO::GetText(cin));
}

void LibraryIO::Output(const Library& lib) const {
    lib.show();
}