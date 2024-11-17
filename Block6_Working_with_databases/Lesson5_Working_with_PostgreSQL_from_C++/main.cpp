#include "DB.h"

int main(int argc, char** argv)
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    try
    {
        std::string connection_string = 
            "host=localhost "
            "port=5432 "
            "dbname = test "
            "user =  "
            "password = ";

        DB db(connection_string);
        db.createTables();

        db.addClient("Sergey", "Proskurin", "sergei_proskurin87@mail.ru", "+79046926194");
        db.show();

        try
        {
            db.addPhone("Sergey", "89046926194");
            db.show();
        }
        catch (const std::exception& ex)
        {
            std::cout << "Exception happened: " << ex.what() << std::endl;
        }

        try
        {
            db.updateClient("sergei_proskurin87@mail.ru", "Sergey", "Proskurin", "sergeiproskurin87@mail.ru");
            db.show();

        }
        catch (const std::exception& ex)
        {
            std::cout << "Exception happened: " << ex.what() << std::endl;
        }

       db.removePhone("sergeiproskurin87@mail.ru", "+79046926194");

       db.removeClient("sergeiproskurin87@mail.ru");

        std::vector<Client> foundClients = db.findClients("Sergey");
        for (const auto& [name, surname, email, phones] : foundClients)
        {
            std::cout << "Found client: " << name << " " << surname << " " << email << " " << std::endl;
        }
        db.show();
    }
    catch (const std::exception& ex)
    {
        std::cout << "Exception happened: " << ex.what() << std::endl;
    }

    return 0;
};