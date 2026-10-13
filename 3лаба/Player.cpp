#include "Player.h"
#include "ConsolIO.h"
#include <iostream>
#include <algorithm>

using namespace std;

Player::Player() : count(0), items(nullptr), ioWorker(new LibraryIO()) {
}

Player::~Player() {
    delete[] items;
    delete ioWorker;
}

bool Player::ContainsIgnoreCase(const string& text, const string& pattern) const {
    if (pattern.empty()) return true;
    string t = text;
    string p = pattern;
    transform(t.begin(), t.end(), t.begin(), ::tolower);
    transform(p.begin(), p.end(), p.begin(), ::tolower);
    return t.find(p) != string::npos;
}

void Player::FillLibrary() {
    cout << "Введіть кількість фільмів для додавання у бібліотеку: ";
    int n = ConsolIO::GetInt(cin);
    if (n <= 0) return;

    delete[] items;
    count = n;
    items = new Library[count];

    for (int i = 0; i < count; ++i) {
        cout << "\nФільм #" << (i + 1) << " з " << count << ":";
        ioWorker->Input(items[i]);
    }
}

void Player::LoadDemoData() {
    delete[] items;
    count = 3;
    items = new Library[count];

    items[0] = Library("Inception", "Sci-Fi", "Leonardo DiCaprio, Joseph Gordon-Levitt",
        8.8, 148.0, 1.0, "inception.mkv", "16.07.2010");
    items[1] = Library("The Dark Knight", "Action", "Christian Bale, Heath Ledger",
        9.0, 152.0, 1.0, "dark_knight.mp4", "18.07.2008");
    items[2] = Library("Interstellar", "Sci-Fi", "Matthew McConaughey, Anne Hathaway",
        8.7, 169.0, 1.0, "interstellar.avi", "07.11.2014");

    cout << "\n[Завантажено 3 демонстраційні фільми]\n";
}

void Player::ShowAll() const {
    if (count == 0 || items == nullptr) {
        cout << "\nБібліотека мультимедіа порожня!\n";
        return;
    }
    cout << "\n========== СПИСОК УСІХ ФІЛЬМІВ В БІБЛІОТЕЦІ ==========\n";
    for (int i = 0; i < count; ++i) {
        cout << "\nЗапис #" << (i + 1) << ":\n";
        ioWorker->Output(items[i]);
    }
}

void Player::ShowByActor() const {
    if (count == 0 || items == nullptr) {
        cout << "\nБібліотека порожня!\n";
        return;
    }
    cout << "\nПошук фільмів за актором. Введіть ім'я або прізвище актора: ";
    string value = ConsolIO::GetText(cin);

    cout << "\nФільми з актором \"" << value << "\":\n";
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (ContainsIgnoreCase(items[i].getActors(), value)) {
            ioWorker->Output(items[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Нічого не знайдено.\n";
    }
}

void Player::ShowByTitle() const {
    if (count == 0 || items == nullptr) {
        cout << "\nБібліотека порожня!\n";
        return;
    }
    cout << "\nПошук фільмів за назвою. Введіть назву (або її частину): ";
    string value = ConsolIO::GetText(cin);

    cout << "\nФільми з назвою \"" << value << "\":\n";
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (ContainsIgnoreCase(items[i].getTitle(), value)) {
            ioWorker->Output(items[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Нічого не знайдено.\n";
    }
}

void Player::ShowByTheme() const {
    if (count == 0 || items == nullptr) {
        cout << "\nБібліотека порожня!\n";
        return;
    }
    cout << "\nПошук фільмів за темою. Введіть тему (або її частину): ";
    string value = ConsolIO::GetText(cin);

    cout << "\nФільми на тему \"" << value << "\":\n";
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (ContainsIgnoreCase(items[i].getTheme(), value)) {
            ioWorker->Output(items[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Нічого не знайдено.\n";
    }
}