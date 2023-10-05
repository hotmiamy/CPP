#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
//	Correct Animals song
	std::cout << "\e[0;32m******CORRECT ANIMAL SONG*********\e[0m" << std::endl << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;
	}
// Wrong Animals song
	{
	std::cout << std::endl << "\e[0;31m******WRONG ANIMAL SONG*********\e[0m" << std::endl << std::endl;

	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();

	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	meta->makeSound();

	delete i;
	delete meta;
	}
	return 0;
}