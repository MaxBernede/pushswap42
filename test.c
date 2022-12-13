void	smallsortb(int **stack, int top)
{
	if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] > (*stack)[top - 2]
	&& (*stack)[top - 1] < (*stack)[top - 2])
	{
		swapb(stack, top, 'b');
		rotb(stack, top, 'b');
	}
	else if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] < (*stack)[top - 2]
	&& (*stack)[top - 1] > (*stack)[top - 2])
		rotb(stack, top, 'b');
	else if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] < (*stack)[top - 2]
	&& (*stack)[top - 1] < (*stack)[top - 2])
	{
		swapb(stack, top, 'b');
		revrotb(stack, top, 'b');
	}
	else if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] > (*stack)[top - 2]
	&& (*stack)[top - 1] > (*stack)[top - 2])
		swapb(stack, top, 'b');
	else if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] < (*stack)[top - 2]
	&& (*stack)[top - 1] < (*stack)[top - 2])
		revrotb(stack, top, 'b');
}