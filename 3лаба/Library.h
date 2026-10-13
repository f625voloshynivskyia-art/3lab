#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>

class Library {
private:
    std::string title;      // Заголовок (назва)
    std::string theme;      // Тема (жанр)
    std::string actors;     // Актори
    double rating;          // Оцінка
    double duration;        // Тривалість (у хвилинах)
    double speed;           // Швидкість відтворення
    std::string fileName;   // Назва файлу
    std::string date;       // Дата

public:
    Library();
    Library(const std::string& title, const std::string& theme, const std::string& actors,
        double rating, double duration, double speed,
        const std::string& fileName, const std::string& date);
    ~Library();

    Library& operator=(const Library& other);

    // Геттери
    std::string getTitle() const;
    std::string getTheme() const;
    std::string getActor() const;
    std::string getActors() const;
    double getRating() const;
    double getDuration() const;
    double getSpeed() const;
    std::string getFileName() const;
    std::string getDate() const;
    double PlayTime() const;
    std::string DurationText() const;

    // Сеттери
    bool setTitle(const std::string& title);
    bool setTheme(const std::string& theme);
    bool setActors(const std::string& actors);
    bool setRating(double rating);
    bool setDuration(int duration);
    bool setDuration(double duration);
    bool setSpeed(double speed);
    bool setFileName(const std::string& fileName);
    bool setDate(const std::string& date);

    // Метод відображення
    void show() const;
};

#endif // LIBRARY_H