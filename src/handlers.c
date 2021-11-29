/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:11:47 by abaker            #+#    #+#             */
/*   Updated: 2021/11/27 19:11:49 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct t_hooks {
	int				key;
	void			(*func)();
	struct t_hooks	*next;
}	t_hooks;

static t_hooks	**g_hooks(void)
{
	static t_hooks	*hooks = NULL;

	return (&hooks);
}

static void	addhook(int key, void (*func)())
{
	t_hooks	*new;
	t_hooks	*curr;

	new = malloc(sizeof(t_hooks));
	if (!new)
		return ;
	new->key = key;
	new->func = func;
	new->next = NULL;
	curr = *g_hooks();
	if (!curr)
		(*g_hooks()) = new;
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}

void	freehooks(void)
{
	t_hooks	*curr;
	t_hooks	*next;

	curr = *g_hooks();
	while (curr->next)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(curr);
}

int	keyhandler(int key)
{
	t_hooks	*hooks;

	hooks = *g_hooks();
	while (hooks)
	{
		if (key == hooks->key)
		{
			(hooks->func)(key);
			drawsettings();
			render2dmap();
			break ;
		}
		hooks = hooks->next;
	}
	return (0);
}

void	loadhooks(void)
{
	addhook(XK_ECSAPE, destroy);
	addhook(XK_Z, changemap);
	addhook(XK_X, changemap);
	addhook(XK_R, defaultsettings);
	addhook(XK_A, updateoffset);
	addhook(XK_S, updateoffset);
	addhook(XK_D, updateoffset);
	addhook(XK_W, updateoffset);
	addhook(XK_LEFT, updaterot);
	addhook(XK_RIGHT, updaterot);
	addhook(XK_UP, updaterot);
	addhook(XK_DOWN, updaterot);
	addhook(XK_MINUS, updatescale);
	addhook(XK_NUMMINUS, updatescale);
	addhook(XK_PLUS, updatescale);
	addhook(XK_NUMPLUS, updatescale);
	mlx_hook(g_mlx()->win, 2, 1L << 0, keyhandler, NULL);
	mlx_hook(g_mlx()->win, 17, 1L << 17, closewin, NULL);
}
