#pragma once
#include <sstream>
#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <ctime>

#define PADDING 3

enum {
	LEFT,
	RIGHT,
};

enum {
	EMPTY = -1,
};

class PmergeMe
{
	private:
		// title: global
		bool								half;
		int									straggler;
		clock_t								time_start;

		// title: vector members
		std::vector<int>					bvec;
		std::vector<std::pair<int, int> >	vec;
		std::vector<int>					mainChain_v;
		std::vector<int>					pend_v;
		std::vector<int>					jacobsequence_v;
		std::vector<int>					insertionOrder_v;

		// title: deque members
		std::deque<int>						bdeq;
		std::deque<std::pair<int, int> >	deq;
		std::deque<int>						mainChain_d;
		std::deque<int>						pend_d;
		std::deque<int>						jacobsequence_d;
		std::deque<int>						insertionOrder_d;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& P);
		PmergeMe& operator= (const PmergeMe& P);
		~PmergeMe();

		void	sortVector(char *av[]);
		void	sortDeque(char *av[]);

		size_t	recurrenceRelation(int n);

		// title: vector members
		void	sort_v(char *av[]);
		void	parseData_v(std::string& data);
		void	generateMainChainAndPend_v();
		void	generateJacobSequence_v(size_t size);
		void	generateInsertionOrder_v();
		void	insertPendElements_v();
		void	Display_v(std::string msg, std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void	DisplayTime_v(clock_t time_s);

		// title: deque members
		void	sort_d(char *av[]);
		void	parseData_d(std::string& data);
		void	generateMainChainAndPend_d();
		void	generateJacobSequence_d(size_t size);
		void	generateInsertionOrder_d();
		void	insertPendElements_d();
		void	Display_d(std::string msg, std::deque<int>::iterator begin, std::deque<int>::iterator end);
		void	DisplayTime_d(clock_t time_s);


		
		
};