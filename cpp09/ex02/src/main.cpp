/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:22:33 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/05/16 13:26:03 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

static void	error_exit(std::string info) {
	std::cerr << "Error: " << info << std::endl;
	exit(EXIT_FAILURE);
}

static std::deque<int>	check_input(int ac, char **av) {
	if (ac == 1)
		error_exit("wrong number of arguments");
	std::string input;
	for (int i = 1; i < ac; i++) {
		input += av[i];
		input += " ";
	}
	std::regex	spaces_and_numbers(R"(^[\d\s]+$)");
	if (std::regex_match(input, spaces_and_numbers) == false)
		error_exit("only positive numbers and spaces allowed");
	std::deque<int>	result;
	auto it = input.begin();
	auto end = input.end();
	while (it != end) {
		/*
			finally a good use case
			for a lambda function
		*/
		it = std::find_if(it, end, [](char c) {return (!std::isspace(c));});
		if (it == end)
			break ;
		auto space = std::find_if(it, end, [](char c) {return (std::isspace(c));});
		std::string sub(it, space);
		try {
			result.push_back(std::stoi(sub));
		} catch (std::exception &e) {
			error_exit("conversion to integer failed");
		}
		it = space;
	}
	if (result.size() == 1 || result.empty() == true || is_sorted(result.begin(), result.end()) == true)
		error_exit("no sorting needed");
	std::cout << "Before sorting: " << input << std::endl;
	return (result);
}

static double	vector_time(PmergeMe &prep, std::deque<int> &input) {
	auto start = std::chrono::high_resolution_clock::now();
	prep.insert_data_vector(input);
	prep.sort_vector(1, 0);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time = end - start;
	prep.display_vector("sorting on vector: ");
	return (time.count() * 1000.0);
}

static double	deque_time(PmergeMe &prep, std::deque<int> &input) {
	auto start = std::chrono::high_resolution_clock::now();
	prep.insert_data_deque(input);
	prep.sort_deque(1, 0);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time = end - start;
	prep.display_deque("sorting on deque: ");
	return (time.count() * 1000.0);
}

/*
	calculation of time starts before inserting the data
	inside of the containers as to indicate the time used
	for the sorting and the data management part
*/
int	main(int ac, char **av) {
	std::deque<int>	input = check_input(ac, av);
	PmergeMe	prep(input.size());
	std::pair<double, double> result(vector_time(prep, input), deque_time(prep, input));
	std::cout << "time to process " << input.size() << " elements with vector: " << std::flush;
	std::cout << result.first << " ms" << std::endl;
	std::cout << "time to process " << input.size() << " elements with deque: " << std::flush;
	std::cout << result.second << " ms" << std::endl;
	return (EXIT_SUCCESS);
}