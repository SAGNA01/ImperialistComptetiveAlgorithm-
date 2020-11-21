#include "Solution.h"

Solution::Solution(const Problem& pbm) : _pbm{pbm}
{

}

Solution::Solution(const Solution& sol) : _pbm{sol._pbm}
{

}

Solution::~Solution()
{

}
