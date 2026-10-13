#define _CRT_SECURE_NO_WARNINGS
#include "Library.h"
#include <iostream>
#include <cstdio>

Library::Library()
    : title("Невідомо"), theme("Загальна"), actors("Невідомо"),
    rating(0.0), duration(0.0), speed(1.0), fileName("none.mp4"), date("01.01.2024") {
}

Library::Library(const std::string& title, const std::string& theme, const std::string& actors,
    double rating, double duration, double speed,
    const std::string& fileName, const std::string& date)
    : title(title), theme(theme), actors(actors),
    rating(rating), duration(duration), speed(speed), fileName(fileName), date(date) {
}

Library::~Library() {
}

Library& Library::operator=(const Library& other) {
    if (this != &other) {
        title = other.title;
        theme = other.theme;
        actors = other.actors;
        rating = other.rating;
        duration = other.duration;
        speed = other.speed;
        fileName = other.fileName;
        date = other.date;
    }
    return *this;
}

// Геттери
std::string Library::getTitle() const { return title; }
std::string Library::getTheme() const { return theme; }
std::string Library::getActor() const { return actors; }
std::string Library::getActors() const { return actors; }
double Library::getRating() const { return rating; }
double Library::getDuration() const { return duration; }
double Library::getSpeed() const { return speed; }
std::string Library::getFileName() const { return fileName; }
std::string Library::getDate() const { return date; }

double Library::PlayTime() const {
    return (speed > 0.0) ? (duration / speed) : duration;
}

std::string Library::DurationText() const {
    int totalSec = static_cast<int>(duration * 60);
    int min = totalSec / 60;
    int sec = totalSec % 60;
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%02d:%02d", min, sec);
    return std::string(buffer);
}

// Сеттери
bool Library::setTitle(const std::string& newTitle) {
    if (newTitle.empty()) return false;
    title = newTitle;
    return true;
}

bool Library::setTheme(const std::string& newTheme) {
    if (newTheme.empty()) return false;
    theme = newTheme;
    return true;
}

bool Library::setActors(const std::string& newActors) {
    if (newActors.empty()) return false;
    actors = newActors;
    return true;
}

bool Library::setRating(double newRating) {
    if (newRating < 0.0 || newRating > 10.0) return false;
    rating = newRating;
    return true;
}

bool Library::setDuration(int newDuration) {
    if (newDuration < 0) return false;
    duration = static_cast<double>(newDuration);
    return true;
}

bool Library::setDuration(double newDuration) {
    if (newDuration < 0.0) return false;
    duration = newDuration;
    return true;
}

bool Library::setSpeed(double newSpeed) {
    if (newSpeed <= 0.0) return false;
    speed = newSpeed;
    return true;
}

bool Library::setFileName(const std::string& newFileName) {
    if (newFileName.empty()) return false;
    fileName = newFileName;
    return true;
}

bool Library::setDate(const std::string& newDate) {
    if (newDate.empty()) return false;
    date = newDate;
    return true;
}

void Library::show() const {
    std::cout << "\t---------------------------------------\n"
        << "\tЗаголовок: " << title << "\n"
        << "\tТема:      " << theme << "\n"
        << "\tАктори:    " << actors << "\n"
        << "\tОцінка:    " << rating << "/10\n"
        << "\tТривалість: " << duration << " хв (" << DurationText() << ")\n"
        << "\tШвидкість: " << speed << "x\n"
        << "\tНазва файлу: " << fileName << "\n"
        << "\tДата:      " << date << "\n"
        << "\t---------------------------------------\n";
}