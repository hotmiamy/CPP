#include "Base.hpp"

Base* generate() {
	std::srand(std::time(NULL));
    int randomValue = std::rand() % 3;
    if (randomValue == 0)
        return new A();
    else if (randomValue == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
	else
		std::cout << "Not derived class of Base" << std::endl;
}

void identify(Base& p) 
{
	try
	{
		A obj = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B obj = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C obj = dynamic_cast<C&>(p);
				std::cout << "C"<< std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << "Exception call: " << e.what() << '\n';
			}
		}
		
	}
}
