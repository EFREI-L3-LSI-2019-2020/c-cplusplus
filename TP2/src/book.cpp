#include "include/book.hpp"

//Constructeur
Book::Book(std::string title, std::string author,
		   unsigned int date, float price) : title(title), author(author),
											 date(date), price(price)
{
}
//Destructeur
Book::~Book()
{
}

//Override default print fonction
std::ostream &operator<<(std::ostream &out, Book b)
{
	out << "Titre --> " << b.title << "\n"
		<< "Auteur --> " << b.author << "\n";
	out << "Date de parution --> " << b.date << "\n"
		<< "Prix indicatif --> " << b.price;
	return out;
}