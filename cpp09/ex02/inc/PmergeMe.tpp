/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 09:04:35 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/05/08 09:06:11 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
void	PmergeMe::insert_data_vector(T &other) {
	vec.insert(vec.begin(), other.begin(), other.end());
}

template<typename T>
void	PmergeMe::insert_data_deque(T &other) {
	que.insert(que.begin(), other.begin(), other.end());
}