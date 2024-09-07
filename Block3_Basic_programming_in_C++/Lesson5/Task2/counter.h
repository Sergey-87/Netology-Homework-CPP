#pragma once
class Counter
{
private:
    int a = 1;
public:
    Counter (int n)
    {
        this->a = n;
    }
    int getCounter();
    int counterPlus();
    int counterMinus();
};
