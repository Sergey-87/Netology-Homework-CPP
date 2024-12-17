#include <iostream>
#include "decorator.h"
#include <memory>

int main()
{
    std::shared_ptr<Paragraph> paragraph_block = std::make_shared<Paragraph>(new Text);
    /*auto paragraph_block = new Paragraph(new Text());*/
    paragraph_block->render("Hello world");
    std::cout << std::endl;

    std::shared_ptr<Reversed> reverse_text_block = std::make_shared<Reversed>(new Text);
    /*auto reverse_text_block = new Reversed(new Text());*/
    reverse_text_block->render("Hello world");
    std::cout << std::endl;

    std::shared_ptr<Link> link_block = std::make_shared<Link>(new Text);
    /*auto link_block = new Link(new Text());*/
    link_block->render("netology.ru", "Hello world");
    std::cout << std::endl;

    return 0;
}