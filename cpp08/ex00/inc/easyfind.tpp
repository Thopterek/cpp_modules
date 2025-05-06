/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:42:10 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/05/05 10:57:53 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char	*NotFound::what() const throw() {
	return ("Error: value not found in container");
}

template<typename T>
int	easyfind(T container, int tb_found) {
	auto it = std::find(container.begin(), container.end(), tb_found);
	if (it == container.end())
		throw NotFound();
	return (*it);
}