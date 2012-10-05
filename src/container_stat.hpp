//============================================================================
// Name        : container_stat.hpp
// Author      : Cristiano Prato
// Version     :
// Copyright   : GPLv2
// Description : container_stat
//============================================================================

#ifndef CONTAINER_STAT_HPP_
#define CONTAINER_STAT_HPP_

#include <algorithm>
#include <functional>
#include <numeric>
#include <cmath>

using namespace std;

namespace crp
{

template<typename T, template<class T, class Allocator = allocator<T> > class C >
class container_stat
{

	typedef C<T> dataType;

public:
	container_stat(dataType data)
		: mData(data)
	{
		updateStats();
	}

	container_stat()
	{
		updateStats();
	}

	void updateStats()
	{
		if(mData.size() > 1)
		{
			mAvg = accumulate(mData.begin(), mData.end(), 0.0) / mData.size();

			dataType diffs(mData.size(), 0);
			transform(mData.begin(), mData.end(), diffs.begin(), [=](T i)
			{
				return pow(i - mAvg, 2);
			});

			mStdVar = accumulate(diffs.begin(), diffs.end(), 0.0) / (diffs.size() - 1);

			mStdDev = sqrt(mStdVar);
		}
		else
		{
			mAvg = 0;
			mStdVar = 0;
			mStdDev = 0;
		}
	}

	T getStdVar() { return mStdVar; }
	T getStdDev() { return mStdDev; }
	T getAvg() { return mAvg; }

	void setData(dataType data)
	{
		mData = data;
		updateStats();
	}

private:
	dataType mData;
	T mAvg;
	T mStdVar;
	T mStdDev;
};

}

#endif /* CONTAINER_STAT_HPP_ */
