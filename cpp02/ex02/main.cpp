#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
Fixed const c(139138.2323f);
Fixed const d = c;
Fixed const e(1.57f);

if (d != c)
	std::cerr << "KO" << std::endl;

a = c / Fixed(150.2367f);
std::cout << a << std::endl;
a = e * Fixed(-123.321f);
std::cout << a << std::endl;
return 0;
}