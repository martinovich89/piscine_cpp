#include <iostream>
#include <string>

class Fixed
{
	private:
	int n;

	public:
	Fixed &operator=(const Fixed &bp);
	void	set_nvalue(int nb);
	int		get_nvalue();
};

int		Fixed::get_nvalue()
{
	return (this->n);
}

void	Fixed::set_nvalue(int nb)
{
	this->n = nb;
}

Fixed	&Fixed::operator=(const Fixed &bp)
{
	this->n = bp.n;
	return (*this);
}

int main(void)
{
	Fixed f;

	f.set_nvalue(10);
	std::cout << f.get_nvalue() << std::endl;

	Fixed g = f;
	std::cout << g.get_nvalue() << std::endl;
}
