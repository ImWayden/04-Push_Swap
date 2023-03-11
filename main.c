/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:09:44 by marvin            #+#    #+#             */
/*   Updated: 2023/02/13 23:09:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void error_manager(t_stack *a, t_stack *b, int error);

static int atoi_error(char *str,int *error)
{
    unsigned int res;
    int i;
    int signe;

    i = 0;
    signe = 1;
    res = 0;
    if(str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            signe*=-1;
        i++;    
    }    
    while (isdigit(str[i]))      
    {
        if (signe == 1 && (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10))) 
            return(*error = 3, 1);
        else if (signe == -1 && (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0'> -(INT_MIN % 10))))
            return(*error = 3, 1);
        res = res * 10 + str[i++] - 48;
    }
    if(str[i] != '\0')
        return(*error = 4,0);
    return(res*signe);
}

void check_stack(t_stack *a, int *error)
{
    int i;
    int j;
    int same;

    same = 0;
    i = 0;
    while(i < a->top)
    {
        j = i+1;
        if(a->stack[j] < a->stack[i])
            same++; 
        while(j <= a->top)
        {
            
            if(a->stack[j] == a->stack[i])
            {
                *error = 5;
                return;
            }
            j++;
        }
        i++;
    }
    if(same == a->top)
        *error = 6;
}

void init_stack(t_stack *a, t_stack *b,int size,int *error)
{
    int i;

    i = 0;
    a->stack = calloc(size+1, sizeof(int));
    if(a->stack == NULL)
    {
        *error=1;
        return;
    }
    b->stack = calloc(size, sizeof(int));
    if(b->stack == NULL)
    {
        *error=2;
        return;
    }
    a->top = size-1;
    b->top = -1;
    while(i < size)
    {
        a->stack[i] = 0;
        b->stack[i++] = 0;
    }
    a->letter = 'a';
    b->letter = 'b';
}

int main(int argc, char **argv)
{
    int  i;
    int error;
    t_stack a;
    t_stack b;

    if(argc < 2)
        return 0;
    error = 0;
    i = -1;
    init_stack(&a,&b,argc-1,&error);
    if (error > 0)
        return(error_manager(&a,&b,error),0);
    while(++i < argc - 1)
        a.stack[i] = atoi_error(argv[argc-1-i],&error);
    check_stack(&a,&error);    
    if (error > 0)
        return(error_manager(&a,&b,error),0);
    launch_sort(&a,&b);
    return(free(a.stack),free(b.stack),0);
}