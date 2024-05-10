/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fordJhonsonSort.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:35:56 by craimond          #+#    #+#             */
/*   Updated: 2024/05/10 16:57:06 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fordJhonsonSort.hpp"

template <typename Iterator>
static void	merge(Iterator begin, Iterator mid, Iterator end);

template <typename Iterator>
static void	insertionSort(Iterator begin, Iterator end);

template <typename Iterator>
void	fordJhonsonSort(Iterator begin, Iterator end)
{
	size_t size = std::distance(begin, end);

	if (size < 2)
		return;
	if (size < K)
		insertionSort(begin, end);
	else
	{
		Iterator mid = std::next(begin, size / 2); //mid = begin + (size / 2)
		fordJhonsonSort(begin, mid);
		fordJhonsonSort(mid, end);
		merge(begin, mid, end);
	}
}

template <typename Iterator>
void merge(const Iterator begin, const Iterator mid, const Iterator end)
{
    typedef typename std::iterator_traits<Iterator>::value_type ValueType;
    std::vector<ValueType> temp(std::distance(begin, end));
    std::copy(begin, end, temp.begin());

    typename std::vector<ValueType>::iterator left = temp.begin();
    typename std::vector<ValueType>::iterator right = temp.begin() + std::distance(temp.begin(), mid - begin);
    typename std::vector<ValueType>::iterator left_end = right;
    typename std::vector<ValueType>::iterator right_end = temp.end();
    
    Iterator target = begin;

    while (left != left_end && right != right_end)
	{
        if (*left < *right)
            *target++ = *left++;
        else
            *target++ = *right++;
    }

    std::copy(left, left_end, target);
    std::copy(right, right_end, target);
}

template <typename Iterator>
void insertionSort(Iterator begin, Iterator end)
{
    if (begin == end)
		return;

    for (Iterator i = begin; i != end; ++i)
	{
        typename std::iterator_traits<Iterator>::value_type val = *i;
        Iterator j = i;
        while (j > begin && *(j - 1) > val)
		{
            *j = *(j - 1);
            --j;
        }
        *j = val;
    }
}