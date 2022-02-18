// Advent2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream> 
#include "Day7.h"
constexpr int MissingValue = -9999999;
#define EQ ==
#define NE !=
#define AND &&
#define OR ||
#define LT <
#define GT >
#define LE <=

static void Day1A_()
{
	std::ifstream infile("1.txt");

	int prev = MissingValue;
	int curr = MissingValue;
	int count = 0;
	while (infile >> curr)
	{
		if (prev NE MissingValue AND prev LT curr)
		{
			count++;
		}
		prev = curr;
	}

	std::cout << "1A:" << count << "\n";
}

#include <deque>
#include <numeric>
static void Day1B_()
{
	std::ifstream infile("1.txt");
	std::deque<int> values; 
	int count = 0;
	int curr;
	while (infile >> curr)
	{
		values.push_back(curr);
		if (values.size() EQ 4)
		{
			auto sum1 = std::accumulate(values.begin(), values.begin() + 3, 0);

			auto sum2 = std::accumulate(values.begin() + 1, values.end(), 0);
			if (sum1 LT sum2)
			{
				count++;
			}
			values.pop_front();
		}
	}

	std::cout << "1B:" << count << "\n";
}
enum class Direction
{
	Forward, Down, Up
};
static Direction AsDirection_(const std::string& s)
{
	if (s EQ "forward") return Direction::Forward;
	if (s EQ "down") return Direction::Down;
	if (s EQ "up") return Direction::Up;
	_ASSERT(false);
	return Direction::Forward;
}
static void Day2A_()
{
	std::ifstream infile("2.txt");
	std::string command;
	int curr;
	int x = 0;
	int y = 0;

	while (infile >> command >> curr)
	{
		switch (AsDirection_(command))
		{
			case Direction::Forward: x += curr; break;
			case Direction::Down: y += curr; break;
			case Direction::Up: y -= curr; break;
		}
	}

	std::cout << "2A:" << x*y << "\n";
}


static void Day2B_()
{
	std::ifstream infile("2.txt");
	std::string command;
	int curr;
	int aim = 0;
	int x = 0;
	int y = 0;

	while (infile >> command >> curr)
	{
		switch (AsDirection_(command))
		{
		case Direction::Forward: 
		{
			x += curr; 
			y += (aim * curr);
			break;
		}
		case Direction::Down: aim += curr; break;
		case Direction::Up: aim -= curr; break;
		}
	}
	std::cout << "2B:" << x * y << "\n";
}
#include <bitset>
#include <vector>
static void Day3A_()
{
	std::ifstream infile("3.txt");
	std::bitset<12> currBitset;
	std::vector<int> binaryCount(12);
	while (infile >> currBitset)
	{
		for (unsigned i = 0; i < currBitset.size(); ++i)
		{
			currBitset.test(i) ? binaryCount[i]++ : binaryCount[i]--;
		}
	}

	std::bitset<12> gamma;
	for (unsigned i = 0; i < binaryCount.size(); ++i)
	{
		gamma.set(i, binaryCount[i] GT 0);
	}
	auto epsilon = ~gamma;

	std::cout << "3A:" << gamma.to_ulong() * epsilon.to_ulong() << "\n";
}

using Bitset = std::bitset<12>;
bool MajoritySet_(int index, const std::vector<Bitset>& list)
{
	int count = 0;
	for (const auto& currBitset : list)
	{
		currBitset.test(index) ? count++ : count--;
	}
	return count GT 0;
}
static void Day3B_()
{
	std::vector<Bitset> secondList;
	std::ifstream infile("3.txt");
	std::bitset<12> currBitset;
	while (infile >> currBitset)
	{
		secondList.push_back(currBitset);
	}
	auto firstList = secondList;

	int index = 0;
	while (firstList.size() GT 1 AND index LT 12)
	{
		bool isSet = MajoritySet_(index, firstList);
		std::erase_if(firstList, [&](const Bitset& bit) {return bit.test(index) NE isSet; });
		index++;
	}
	_ASSERT(index LE 12); //invalid 

	index = 0;
	while (secondList.size() GT 1 AND index LT 12)
	{
		bool isSet = MajoritySet_(index, secondList);
		std::erase_if(secondList, [&](const Bitset& bit) {return bit.test(index) EQ isSet; });
		index++;
	}
	_ASSERT(index LE 12); //invalid


	std::cout << "3B:" << firstList.front().to_ulong() * secondList.front().to_ulong() << "\n";

}
int main()
{
	/*Day1A_();
	Day1B_();
	Day2A_();
	Day2B_();
	Day3A_();
	Day3B_();
	day7::Run();*/
	day8::Run();
}

