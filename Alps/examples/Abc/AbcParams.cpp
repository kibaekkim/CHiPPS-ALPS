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

#include "AlpsParameterBase.h"
#include "AbcParams.h"

using std::make_pair;

void 
AbcParams::createKeywordList() {

    // Create the list of keywords for parameter file reading
    //-------------------------------------------------------------------------
    // CharPar
    keys_.push_back(make_pair(std::string("Abc_cutDuringRampup"),
			      AlpsParameter(AlpsCharPar, 
					    cutDuringRampup)));
    
    //-------------------------------------------------------------------------
    // BoolArrayPar

    //-------------------------------------------------------------------------
    // IntPar
    keys_.push_back(make_pair(std::string("Abc_statusInterval"),
			      AlpsParameter(AlpsIntPar, 
					    statusInterval)));
    keys_.push_back(make_pair(std::string("Abc_logLevel"),
			      AlpsParameter(AlpsIntPar, 
					    logLevel)));

    //-------------------------------------------------------------------------
    // DoublePar
   
    //-------------------------------------------------------------------------
    // StringPar

}

//#############################################################################

void 
AbcParams::setDefaultEntries() {
    //-------------------------------------------------------------------------
    // CharPar
    setEntry(cutDuringRampup, false);
    
    //-------------------------------------------------------------------------
    // IntPar
    setEntry(statusInterval, 50);
    setEntry(logLevel, 1);
    
    //-------------------------------------------------------------------------
    // DoublePar
  
    //-------------------------------------------------------------------------
    // StringPar

}
