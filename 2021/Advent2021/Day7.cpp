#include "Day7.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
auto RunA_(auto infile)
{
	std::string line;
	std::vector<int> crabs;
	while (std::getline(infile, line, ','))
	{
		crabs.emplace_back(std::stoi(line));
	}
	std::ranges::sort(crabs);

	auto midIndex = crabs.size() / 2;
	auto fuel = std::accumulate(crabs.begin(), crabs.end(), 0, 
		[&](auto init, auto currCrab) {
			return init = init + ::abs(crabs[midIndex] - currCrab); 
		});
	return fuel;
}
auto RunB_(auto infile)
{
	std::string line;
	std::vector<int> crabs;
	auto totalSum = 0;
	while (std::getline(infile, line, ','))
	{
		auto currCrab = std::stoi(line);
		crabs.emplace_back(currCrab);
		totalSum += currCrab;
	}
	auto avg = ceil(double(totalSum) / double(crabs.size()));

	auto fuel = std::accumulate(crabs.begin(), crabs.end(), 0,
		[&](auto fuel, auto currCrab) 
		{
			int diff = ::abs(currCrab - avg);
			auto currFuel = (diff * (diff + 1)) / 2; // From : https://www.wolframalpha.com/input/?i=1%2B2%2B3%2B...%2Bn
			return fuel = fuel + currFuel;
		});
	return fuel;
}

void day7::Run()
{
	std::string example ("16,1,2,0,4,2,7,1,2,14");
	_ASSERT(RunA_(std::stringstream(example)) == 37);
	std::cout << "7A:" << RunA_(std::ifstream("7.txt")) << "\n";

	_ASSERT(RunB_(std::stringstream(example)) == 168);
	std::cout << "7B:" << RunB_(std::ifstream("7.txt")) << "\n";
}