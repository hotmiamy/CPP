#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{
		Dog tmp;
		{
			Dog tmp2(tmp);
		}
	}
	std::cout << GREEN << "******PDF TEST******" << RESET << std::endl << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;//should not create a leak
		delete i;
	}
	std::cout << GREEN << "******ARRAY OF ANIMALS TEST******" << RESET << std::endl << std::endl;
	{
		const Animal*	animals[4];

		for (int i = 0; i < 4; i++)
		{
			if (i <= ((4 / 2) - 1))
				animals[i] = new Cat();
			else
				animals[i] = new Dog();
			animals[i]->makeSound();
		}
		for (size_t i = 0; i < 4; i++)
			delete animals[i];
	}
	std::cout << GREEN << "******IDEIAS TEST******" << RESET << std::endl << std::endl;
	{
		const Cat*	willy = new Cat();
		const Cat*	milly = new Cat(*willy);
		Cat*	billy = new Cat();

		willy->setIdea(0, "Sleep all day");
		std::cout << willy->getIdea(0) << std::endl;
		milly->setIdea(0, "Play all day");
		std::cout << milly->getIdea(0) << std::endl;
		*billy = *willy;
		std::cout << billy->getIdea(0) << std::endl;

		delete	willy;
		delete	billy;
		delete	milly;
	}
	return 0;
}