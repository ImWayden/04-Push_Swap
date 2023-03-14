/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:17:08 by wayden            #+#    #+#             */
/*   Updated: 2023/03/14 09:48:27 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static int read_instruction(t_stack *a, t_stack *b,char *inst)
{
    if(ft_strncmp(inst, "rra\n",5) == 0)
        return (rev_rotate(a,1),1);
    else if(ft_strncmp(inst, "rrb\n",5) == 0)
        return (rev_rotate(a,1),1);
    else if(ft_strncmp(inst, "rrr\n",5) == 0)
        return (rev_rotate(a,1),rev_rotate(b,1),1);
    else if(ft_strncmp(inst, "ra\n",5) == 0)
        return ((rotate(a,1),1));
    else if(ft_strncmp(inst, "rb\n",5) == 0)
        return ((rotate(b,1),1));
    else if(ft_strncmp(inst, "rr\n",5) == 0)
        return (rotate(a,1),rotate(b,1),1);
    else if(ft_strncmp(inst, "sa\n",5) == 0)
        return (swap(a,1),1);
    else if(ft_strncmp(inst, "sb\n",5) == 0)
        return (swap(b,1),1);
    else if(ft_strncmp(inst, "pa\n",5) == 0)
        return (push(b,a,1),1);
    else if(ft_strncmp(inst, "pb\n",5) == 0)
        return ((push(a,b,1),1));
    else
        return (0);
}

static int launch_checker(t_stack *a, t_stack *b,int *error)
{
    char *line;
    int verif;

    line = get_next_line(0);
    if(line == NULL)
        return(free(line),0);
    while(line != NULL)
    {
        verif = read_instruction(a,b,line);
        if(!verif)
            return(free(line),0);
        free(line);         
        line = get_next_line(0);     
    }
    if(b->top > -1)
        return(2);
    check_stack(a,error);
    if(*error == 6)
        return(1);
    else 
        return(2);
}

void result_printer(int i)
{
    if(i == 0)
        write(2,"Error\n",6);
    if(i == 1)
        ft_printf("OK\n");
    if(i == 2)
        ft_printf("KO\n");
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
    if (error > 0 && error < 6)
        return(error_manager(&a,&b,error),0);
    while(++i < argc - 1)
        a.stack[i] = atoi_error(argv[argc-1-i],&error);
    check_stack(&a,&error);    
    if (error > 0 && error < 6)
        return(error_manager(&a,&b,error),0);
    result_printer(launch_checker(&a,&b,&error));
    return(free(a.stack),free(b.stack),0);
}