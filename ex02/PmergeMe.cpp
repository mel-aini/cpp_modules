#include "PmergeMe.hpp"

PmergeMe::PmergeMe(/* args */) : half(LEFT), straggler(EMPTY)
{

}

PmergeMe::PmergeMe(const PmergeMe& P) {
	*this = P;
}

PmergeMe& PmergeMe::operator= (const PmergeMe& P) {
	if (this != &P) {
		this->half = P.half;
		this->straggler = P.straggler;
		this->time_start = P.time_start;
		this->bvec = P.bvec;
		this->vec = P.vec;
		this->mainChain_v = P.mainChain_v;
		this->pend_v = P.pend_v;
		this->jacobsequence_v = P.jacobsequence_v;
		this->insertionOrder_v = P.insertionOrder_v;
		this->bdeq = P.bdeq;
		this->deq = P.deq;
		this->mainChain_d = P.mainChain_d;
		this->pend_d = P.pend_d;
		this->jacobsequence_d = P.jacobsequence_d;
		this->insertionOrder_d = P.insertionOrder_d;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void	PmergeMe::parseData_v(std::string& data)
{
	size_t	number;

	if (data.empty()) throw "Invalid input";

	std::stringstream ss(data);

	for (size_t i = 0; i < data.length(); i++)
		if (data[i] < '0' || data[i] > '9') throw "Invalid input";

	ss >> number;
	if (number > INT_MAX) throw "Too large number";

	if (half == LEFT) {
		straggler = number;
		half = RIGHT;
	}
	else if (half == RIGHT) {
		std::pair<int, int> p;
		p.first = static_cast<size_t>(straggler) < number ? number : straggler;
		p.second = static_cast<size_t>(straggler) < number ? straggler : number;
		this->vec.push_back(p);
		straggler = EMPTY;
		half = LEFT;
	}
	bvec.push_back(number);
}

void	PmergeMe::sort_v(char *av[])
{
	for (int i = 1; av[i]; i++) {
		std::string			str(av[i]);
		parseData_v(str);
	}
	if (bvec.size() < 2)
		throw "Should be more than two numbers";

	std::sort(vec.begin(), vec.end());
	generateMainChainAndPend_v();
	generateJacobSequence_v(pend_v.size() + PADDING);
	generateInsertionOrder_v();
	insertPendElements_v();
}

void	PmergeMe::generateInsertionOrder_v() {
	int Jacobindex = PADDING;
	int stop = 1;
	insertionOrder_v.push_back(jacobsequence_v[Jacobindex]);
	int toProcess = jacobsequence_v[Jacobindex];

	for (size_t i = Jacobindex; i < jacobsequence_v.size(); i++) {
		int tmp = toProcess - 1;
		if (tmp > stop) {
			insertionOrder_v.push_back(tmp);
			toProcess = tmp;
		} else {
			stop = jacobsequence_v[Jacobindex];
			Jacobindex++;
			toProcess = jacobsequence_v[Jacobindex];
			insertionOrder_v.push_back(toProcess);
		}
	}
}

void	PmergeMe::insertPendElements_v() {

	for (size_t i = 0; i < insertionOrder_v.size() > 0; i++) {
		size_t pos = insertionOrder_v[i];
		int start = 2;
		for (size_t j = 0; j < pend_v.size(); j++) {
			if (pos == start + j) {
				std::vector<int>::iterator it = std::lower_bound(mainChain_v.begin(), mainChain_v.end(), pend_v[j]);
				mainChain_v.insert(it, pend_v[j]);
				break;
			}
		}
	}

	if (straggler != EMPTY) {
		std::vector<int>::iterator it = std::lower_bound(mainChain_v.begin(), mainChain_v.end(), straggler);
		mainChain_v.insert(it, straggler);
	}
}

void	PmergeMe::generateMainChainAndPend_v() {
	std::vector<std::pair<int, int> >::iterator it = vec.begin();
	mainChain_v.push_back(it->second);
	mainChain_v.push_back(it->first);
	it++;

	for (; it != vec.end(); it++) {
		mainChain_v.push_back(it->first);
		pend_v.push_back(it->second);
	}
}

size_t	 PmergeMe::recurrenceRelation(int n) {
	if (n <= 1)
		return n;
	return recurrenceRelation(n - 1) + (2 * recurrenceRelation(n - 2));
}

void	PmergeMe::generateJacobSequence_v(size_t size) {
	if (size < 1)
		return;

	for (size_t i = 0; i < size; i++) {
		size_t tmp = recurrenceRelation(i);
		if (tmp > size)
			break ;
		jacobsequence_v.push_back(tmp);
	}
}

void	PmergeMe::Display_v(std::string msg, std::vector<int>::iterator it, std::vector<int>::iterator end) {
	std::cout << msg;
	for (; it != end; it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::DisplayTime_v(clock_t time_s)
{
	std::cout << "Time to process a range of " << bvec.size() << " elements with std::vector : " << time_s << "us" << std::endl;
}

void	PmergeMe::sortVector(char *av[])
{
	time_start = clock();

	sort_v(av);

	clock_t time_s = clock() - time_start;

	Display_v("Before: ", bvec.begin(), bvec.end());
	Display_v("After:  ", mainChain_v.begin(), mainChain_v.end());

	DisplayTime_v(time_s);
}

// title: deque methods

void	PmergeMe::sortDeque(char *av[])
{
	half = LEFT;
	straggler = EMPTY;
	time_start = clock();

	sort_d(av);

	clock_t time_s = clock() - time_start;

	DisplayTime_d(time_s);
}

void	PmergeMe::parseData_d(std::string& data)
{
	size_t	number;

	if (data.empty()) throw "Invalid input";

	std::stringstream ss(data);

	for (size_t i = 0; i < data.length(); i++)
		if (data[i] < '0' || data[i] > '9') throw "Invalid input";

	ss >> number;
	if (number > INT_MAX) throw "Too large number";

	if (half == LEFT) {
		straggler = number;
		half = RIGHT;
	}
	else if (half == RIGHT) {
		std::pair<int, int> p;
		p.first = static_cast<size_t>(straggler) < number ? number : straggler;
		p.second = static_cast<size_t>(straggler) < number ? straggler : number;
		this->deq.push_back(p);
		straggler = EMPTY;
		half = LEFT;
	}
	bdeq.push_back(number);
}

void	PmergeMe::sort_d(char *av[])
{
	for (int i = 1; av[i]; i++) {
		std::string			str(av[i]);
		parseData_d(str);
	}
	if (bdeq.size() < 2)
		throw "Should be more than two numbers";

	std::sort(deq.begin(), deq.end());
	generateMainChainAndPend_d();
	generateJacobSequence_d(pend_d.size() + PADDING);
	generateInsertionOrder_d();
	insertPendElements_d();
}

void	PmergeMe::generateJacobSequence_d(size_t size) {
	if (size < 1)
		return;

	for (size_t i = 0; i < size; i++) {
		size_t tmp = recurrenceRelation(i);
		if (tmp > size)
			break ;
		jacobsequence_d.push_back(tmp);
	}
}


void	PmergeMe::generateInsertionOrder_d() {
	int Jacobindex = PADDING;
	int stop = 1;
	insertionOrder_d.push_back(jacobsequence_d[Jacobindex]);
	int toProcess = jacobsequence_d[Jacobindex];

	for (size_t i = Jacobindex; i < jacobsequence_d.size(); i++) {
		int tmp = toProcess - 1;
		if (tmp > stop) {
			insertionOrder_d.push_back(tmp);
			toProcess = tmp;
		} else {
			stop = jacobsequence_d[Jacobindex];
			Jacobindex++;
			toProcess = jacobsequence_d[Jacobindex];
			insertionOrder_d.push_back(toProcess);
		}
	}
}

void	PmergeMe::insertPendElements_d()
{
	for (size_t i = 0; i < insertionOrder_d.size() > 0; i++) {
		size_t pos = insertionOrder_d[i];
		int start = 2;
		for (size_t j = 0; j < pend_d.size(); j++) {
			if (pos == start + j) {
				std::deque<int>::iterator it = std::lower_bound(mainChain_d.begin(), mainChain_d.end(), pend_d[j]);
				mainChain_d.insert(it, pend_d[j]);
				break;
			}
		}
	}

	if (straggler != EMPTY) {
		std::deque<int>::iterator it = std::lower_bound(mainChain_d.begin(), mainChain_d.end(), straggler);
		mainChain_d.insert(it, straggler);
	}
}

void	PmergeMe::generateMainChainAndPend_d() {
	std::deque<std::pair<int, int> >::iterator it = deq.begin();
	mainChain_d.push_back(it->second);
	mainChain_d.push_back(it->first);
	it++;

	for (; it != deq.end(); it++) {
		mainChain_d.push_back(it->first);
		pend_d.push_back(it->second);
	}
}

void	PmergeMe::Display_d(std::string msg, std::deque<int>::iterator it, std::deque<int>::iterator end) {
	std::cout << msg;
	for (; it != end; it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::DisplayTime_d(clock_t time_s) {
	
	std::cout << "Time to process a range of " << bdeq.size() << " elements with std::deque : " << time_s << "us" << std::endl;
}