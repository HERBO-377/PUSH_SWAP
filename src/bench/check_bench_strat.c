#include "push_swap.h"

static t_bench	init_bench(t_flags f)
{
	t_bench	b;

	b.enabled = 0;
	b.strat = 0;
	b.disorder = 0;
	b.total = 0;
	b.sa = 0;
	b.sb = 0;
	b.ss = 0;
	b.pa = 0;
	b.pb = 0;
	b.ra = 0;
	b.rb = 0;
	b.rr = 0;
	b.rra = 0;
	b.rrb = 0;
	b.rrr = 0;
	if (f.bench)
		b.enabled = 1;
	return (b);
}

t_bench check_bench_strat(t_flags f)
{
	t_bench	b;

	b = init_bench(f);
	if (f.simple)
		b.strat = STRAT_SIMPLE;
	else if (f.medium)
		b.strat = STRAT_MEDIUM;
	else if (f.complex)
		b.strat = STRAT_COMPLEX;
	else if	(f.adaptive)
		b.strat = STRAT_ADAPTIVE;
	return (b);
}
