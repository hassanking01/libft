#include "libft.h"
#include <stdio.h>
#include <stdlib.h>



int main()
{
    char * str = "tripouille";
    char ** tab= ft_split(str , '\0');
    int i =0;
	if (tab[1] == NULL)
	{
		i++;

	}
    
    return 0;
}