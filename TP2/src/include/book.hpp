#ifndef __BOOK_H__
#define __BOOK_H__

#include <string>
#include <iostream>

class Book
{
private:
    std::string title;
    std::string author;
    unsigned int date;
    float price;

public:
    Book(std::string title, std::string author, unsigned int date, float price);
    ~Book();

    friend std::ostream &operator<<(std::ostream &out, Book b);

    std::string getTitle()
    {
        return this->title;
    }

    std::string getAuthor()
    {
        return this->author;
    }

    int getDate()
    {
        return this->date;
    }

    float getPrice()
    {
        return this->price;
    }
};

#endif