#define true 1
#define false 0

typedef int bool

bool isPremier(int nb){
    int foo = nb;
    int div = 0;
    
    while (nb > 0){
        if ( nb % foo == 0)
            div++;
        nb--;
    }
    if (div != 2)
        return false;
    else
        return true;
}