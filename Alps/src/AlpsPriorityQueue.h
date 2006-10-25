/*===========================================================================*
 * This file is part of the Abstract Library for Parallel Search (ALPS).     *
 *                                                                           *
 * ALPS is distributed under the Common Public License as part of the        *
 * COIN-OR repository (http://www.coin-or.org).                              *
 *                                                                           *
 * Authors: Yan Xu, SAS Institute Inc.                                       *
 *          Ted Ralphs, Lehigh University                                    *
 *          Laszlo Ladanyi, IBM T.J. Watson Research Center                  *
 *          Matthew Saltzman, Clemson University                             *
 *                                                                           * 
 *                                                                           *
 * Copyright (C) 2001-2006, Lehigh University, Yan Xu, and Ted Ralphs.       *
 * Corporation, Lehigh University, Yan Xu, Ted Ralphs, Matthew Salzman and   *
 *===========================================================================*/

#ifndef AlpsPriorityQueue_h_
#define AlpsPriorityQueue_h_

#include <queue>
#include <vector>
#include "CoinHelperFunctions.hpp"
#include "AlpsCompareBase.h"

//#############################################################################

template<class T>
class AlpsPriorityQueue {
 private:
    AlpsPriorityQueue(const AlpsPriorityQueue&);
    AlpsPriorityQueue& operator=(const AlpsPriorityQueue&);

 private:
    std::vector<T> vec_;
    AlpsCompare<T> comparison_;	///> Sort function for heap ordering.

 public:
    AlpsPriorityQueue() {}
    AlpsPriorityQueue(AlpsCompareBase<T>& compare) { 
	setComparison(compare);
    }

    /** Return a const reference to the container. */
    const std::vector<T>& getContainer() const { return vec_; }

    /** Set comparison function and resort heap. */
    void setComparison(AlpsCompareBase<T>& compare) {
	comparison_.test_ = &compare;
	make_heap(vec_.begin(), vec_.end(), comparison_);
    }

    /** Return the top element of the heap. */
    T top() const { return vec_.front(); }

    /** Add a element to the heap. */
    void push(T x) {
	vec_.push_back(x);
	push_heap(vec_.begin(), vec_.end(), comparison_);
    }

    /** Remove the top element from the heap. */
    void pop() {
	pop_heap(vec_.begin(), vec_.end(), comparison_);
	vec_.pop_back();
    }

    /** Return true for an empty vector. */
    bool empty() const{
	return vec_.empty();
    }
    
    /** Return the size of the vector. */
    size_t size() const {
	return vec_.size();
    }

    /** Remove all elements from the vector. But not delete them. */
    void clear() { vec_.clear(); }
    
};

//#############################################################################

#if 0
template<class T, 
    class Container = std::vector<T>, 
    class Compare = std::less<typename Container::value_type> >
class AlpsPriorityQueue : public std::priority_queue<T, Container, Compare> {
  public:
  /** Return a const reference to the container. */
  const Container& getContainer() const { return c; }

  /** Remove all elements who's priority is worth than the specified cutoff. */
  // void cleanQueue(double cutoff){};
};

#endif

#endif  // FILE