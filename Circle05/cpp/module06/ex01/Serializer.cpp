#include "Serializer.hpp"

// OCF
Serializer::Serializer(void) {
}
Serializer::Serializer(const Serializer &ref) {
	(void)ref;
}
Serializer& Serializer::operator=(Serializer const &ref) {
	(void)ref;
	return (*this);
}
Serializer::~Serializer(void) {
}

// METHOD
uintptr_t	Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data		*Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}