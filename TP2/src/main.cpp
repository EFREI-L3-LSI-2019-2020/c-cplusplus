#include "include/book.hpp"
#include "include/input.hpp"
#include <vector>

/* Affichage menu */
void menu(std::vector<Book> books, int nb){
    bool exit = false;
    int res;

    while (!exit)
    {
        std::cout << "\n[ Menu ] " << std::endl;
        for (unsigned int i = 0; i < books.size(); i++)
        {
            std::cout << i + 1 << ". " << books[i].getTitle() << std::endl;
        }

        std::cout << nb + 1 << ". Quitter" << std::endl;

        Input::input<int>("Votre choix : ", res);

        if (res < nb + 1 && res != 0) //tant que l'user selectionnne un livre existant
        {
            std::cout << "[ Livre " << res << " ]" << std::endl;
            std::cout << books[res - 1];
        }
        else if (res == nb + 1) //Fermeture du programme 
            exit = true;
    }
}

int main()
{
    auto books = std::vector<Book>(); //Liste de livres

    int nb, date;
    float price;
    std::string title, author;

    std::cout << "[ Vos livres ]" << std::endl;
    Input::input<int>("Nombre de livres : ", nb);

    for (int i = 0; i < nb; i++) //Tant que l'user n'a pas sélectionner le nombre max de livre
    {
        std::cout << "[ Livre " << i + 1 << " ]" << std::endl;
        Input::input("Titre : ", title);
        Input::input("Auteur : ", author);
        Input::input<int>("Date : ", date);
        Input::input<float>("Prix : ", price);
        books.push_back(Book(title, author, date, price)); //Ajout dans la liste du livre
    }
 
    menu(books, nb);

    return 0;
}