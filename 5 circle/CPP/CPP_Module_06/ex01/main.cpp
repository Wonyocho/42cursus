#include "Serializer.hpp"

int	main()
{
	Data src;
	Data *deserialized;
	uintptr_t serialized;

	src.value = "hello world";
	std::cout << "src: " << src.value << std::endl;

	serialized = Serializer::serialize(&src);
	std::cout << "serialized: " << serialized << std::endl;

	deserialized = Serializer::deserialize(serialized);
	std::cout << "deserialized: " << deserialized->value << std::endl;

	return (0);
}