
#include"push_swap.h"

t_moves get_instructions(t_stack *a, t_stack *b, int index_a, int index_b) 
{
    t_moves move;
    move.nb_ra = a->top - index_a;
    move.nb_rb = b->top - index_b;
    move.nb_rra = index_a + 1;
    move.nb_rrb = index_b + 1;
    move.nb_rr = ft_min(2,move.nb_ra,move.nb_rb);
    move.nb_rrr = ft_min(2, move.nb_rra,move.nb_rrb);
    move.ra_rb = -ft_min(2,-move.nb_ra, -move.nb_rb) - move.nb_rr;
    move.rra_rrb = -ft_min(2,-move.nb_rra, -move.nb_rrb) - move.nb_rrr;
    move.ra_rrb = move.nb_ra + move.nb_rrb;
    move.rra_rb = move.nb_rra + move.nb_rb;
    move.mincost = ft_min(4,move.ra_rb,move.rra_rrb,move.ra_rrb,move.rra_rb);
    return move;
}

void print_moves(t_moves moves) {
    printf("nb_ra: %d\n", moves.nb_ra);
    printf("nb_rb: %d\n", moves.nb_rb);
    printf("nb_rra: %d\n", moves.nb_rra);
    printf("nb_rrb: %d\n", moves.nb_rrb);
    printf("nb_rr: %d\n", moves.nb_rr);
    printf("nb_rrr: %d\n", moves.nb_rrr);
    printf("ra_rb: %d\n", moves.ra_rb);
    printf("rra_rrb: %d\n", moves.rra_rrb);
    printf("ra_rrb: %d\n", moves.ra_rrb);
    printf("rra_rb: %d\n", moves.rra_rb);
    printf("mincost: %d\n", moves.mincost);
}

int main()
{
    t_stack a;
    t_stack b;

    a.top = 12;
    b.top = 6;
    t_moves moves = get_instructions(&a, &b, 7, 1);
    print_moves(moves);


}