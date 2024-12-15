#include <iostream>
#include "decorator.h"

int main()
{
    auto paragraph_block = new Paragraph(new Text());
    paragraph_block->render("Hello world");
    std::cout << std::endl;

    auto reverse_text_block = new Reversed(new Text());
    reverse_text_block->render("Hello world");
    std::cout << std::endl;

    auto link_block = new Link(new Text());
    link_block->render("netology.ru", "Hello world");
    std::cout << std::endl;

    return 0;
}