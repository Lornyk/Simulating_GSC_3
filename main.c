/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmohin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:33:51 by lmohin            #+#    #+#             */
/*   Updated: 2023/04/15 18:48:09 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//randomize points distributions

void shuffle(int *array, size_t n, int k)
{
	srand(k * 53453 * time(NULL));
	{
		size_t i;

		i = 0;
		while (i < n - 1)
		{
			size_t j = rand() % (n - i) + 1;
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
			i++;
		}
	}
}

//count number of times m appears in final array

int count_st(int *array, int m)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 1000000)
	{
		if (array[i] == m)
			j++;
		i++;
	}
	return (j);
}		

void ft_order(int *array, size_t n)
{
	size_t i;
	int	t;
	i = 0;
	while (i < n)
	{
		if (array[i + 1] > array[i])
		{
			t = array[i + 1];
			array[i + 1] = array[i];
			array[i] = t;
			ft_order(array, n);
		}
		else
			i++;
	}
}

int main(void)
{
	int	*results;
	int 	*points;
	int	i;
	int	*joueurs;
	int	j;
	int	k;

	k = 0;
	results = malloc(sizeof(unsigned long int) * 1000000);
	points = malloc(sizeof(unsigned long int) * 64);
	joueurs = malloc(sizeof(unsigned long int) * 100);
	while (k < 1000000)
	{
		points[0] = 10000;
		points[1] = 62;
		points[2] = 60;
		points[3] = 58;
		points[4] = 56;
		points[5] = 54;
		points[6] = 52;
		points[7] = 50;
		points[8] = 45;
		points[9] = 45;
		points[10] = 45;
		points[11] = 45;
		points[12] = 40;
		points[13] = 40;
		points[14] = 40;
		points[15] = 40;
		points[16] = 35;
		points[17] = 35;
		points[18] = 35;
		points[19] = 35;
		points[20] = 30;
		points[21] = 30;
		points[22] = 30;
		points[23] = 30;
		points[24] = 25;
		points[25] = 25;
		points[26] = 25;
		points[27] = 25;
		points[28] = 20;
		points[29] = 20;
		points[30] = 20;
		points[31] = 20;
//points table filled, filling players table		
		joueurs[0] = 0;
		joueurs[1] = 0;
		joueurs[2] = 90;
		joueurs[3] = 0;
		joueurs[4] = 80;
		joueurs[5] = 70;
		joueurs[6] = 69;
		joueurs[7] = 0;
		joueurs[8] = 52;
		joueurs[9] = 45;
		joueurs[10] = 45;
		joueurs[12] = 40;
		joueurs[13] = 0;
		joueurs[14] = 0;
		joueurs[15] = 0;
		joueurs[16] = 35;
		joueurs[17] = 35;
		joueurs[18] = 0;
		joueurs[19] = 0;
		joueurs[20] = 0;
		joueurs[21] = 0;
		joueurs[22] = 25;
		joueurs[23] = 20;
		joueurs[24] = 0;
		joueurs[25] = 0;
		joueurs[26] = 0;
		joueurs[27] = 0;
		joueurs[28] = 0;
		joueurs[29] = 0;
		joueurs[30] = 0;
		joueurs[31] = 0;
		i = 0;
		shuffle(points, 32, k);
		while (i < 32)
		{
			joueurs[i] = joueurs[i] + points[i]; //giving points randomly to each players
			i++;
		}
//adding players with gsc points, but not playing in the GSC_3
		joueurs[32] = 107;
		joueurs[33] = 65;
		joueurs[34] = 62;
		joueurs[35] = 60;
		joueurs[36] = 60;
		joueurs[37] = 58;
		joueurs[38] = 56;
		joueurs[39] = 81;
		joueurs[40] = 78;
		joueurs[41] = 90;
		joueurs[42] = 54;
		ft_order(joueurs, 42);
		i = 0;
		while (joueurs[i] > 500)
			i++;
		j = 1;
		while (j < 21)
		{
			i++;
			j++;
		}
		results[k] = joueurs[i];
		k++;
	}
	printf("Number of 45 : %d\n", count_st(results, 45));
	printf("Number of 50 : %d\n", count_st(results, 50));
	printf("Number of 52 : %d\n", count_st(results, 52));
	printf("Number of 54 : %d\n", count_st(results, 54));
	printf("Number of 55 : %d\n", count_st(results, 55));
	printf("Number of 56 : %d\n", count_st(results, 56));
	printf("Number of 58 : %d\n", count_st(results, 58));
	printf("Number of 60 : %d\n", count_st(results, 60));
	printf("Number of 62 : %d\n", count_st(results, 62));
	printf("Number of 64 : %d\n", count_st(results, 64));
	printf("Number of 65 : %d\n", count_st(results, 65));
	printf("Number of 70 : %d\n", count_st(results, 70));
	free(points);
	free(joueurs);
	free(results);
	return (0);	
}
