#include <iostream>
#include <string>
#include <stdlib.h>

class Karen
{
    public:

    void    complain(std::string level);

    private:

    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);
};