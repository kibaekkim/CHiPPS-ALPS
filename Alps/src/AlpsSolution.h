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

#ifndef AlpsSolution_h_
#define AlpsSolution_h_

#include <iosfwd>
#include <map>
#include <vector>

#include "AlpsKnowledge.h"

//#############################################################################

class AlpsSolution : public AlpsKnowledge { 

 private:
    /** Diable copy constructor and assignment. */
    AlpsSolution(const AlpsSolution&);
    AlpsSolution& operator=(const AlpsSolution&);
    
 public:
    
    /** Default constructor. */
    AlpsSolution() {}

    /** Destructor. */
    virtual ~AlpsSolution() {}
    
    /** Print out the solution.*/
    virtual void print(std::ostream& os) const{
	os << "WARNING: No solution print function is defined." << std::endl;
    }
};

#endif