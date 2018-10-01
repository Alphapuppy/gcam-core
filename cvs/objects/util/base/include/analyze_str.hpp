#ifndef _ANALYZE_STR_H_
#define _ANALYZE_STR_H_
#if defined(_MSC_VER)
#pragma once
#endif

/*
 * LEGAL NOTICE
 * This computer software was prepared by Battelle Memorial Institute,
 * hereinafter the Contractor, under Contract No. DE-AC05-76RL0 1830
 * with the Department of Energy (DOE). NEITHER THE GOVERNMENT NOR THE
 * CONTRACTOR MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR ASSUMES ANY
 * LIABILITY FOR THE USE OF THIS SOFTWARE. This notice including this
 * sentence must appear on any copies of this computer software.
 *
 * EXPORT CONTROL
 * User agrees that the Software will not be shipped, transferred or
 * exported into any country or used in any manner prohibited by the
 * United States Export Administration Act or any other applicable
 * export laws, restrictions or regulations (collectively the "Export Laws").
 * Export of the Software may require some form of license or other
 * authority from the U.S. Government, and failure to obtain such
 * export control license may result in criminal liability under
 * U.S. laws. In addition, if the Software is identified as export controlled
 * items under the Export Laws, User represents and warrants that User
 * is not a citizen, or otherwise located within, an embargoed nation
 * (including without limitation Iran, Syria, Sudan, Cuba, and North Korea)
 *     and that User is not otherwise prohibited
 * under the Export Laws from receiving the Software.
 *
 * Copyright 2011 Battelle Memorial Institute.  All Rights Reserved.
 * Distributed as open-source under the terms of the Educational Community
 * License version 2.0 (ECL 2.0). http://www.opensource.org/licenses/ecl2.php
 *
 * For further details, see: http://www.globalchange.umd.edu/models/gcam/
 *
 */

/*!
 * \file analyze_tech_mem.hpp
 * \ingroup util
 * \brief AnalyzeStr class header file.
 * \author Pralit Patel
 */

#include <cassert>
#include <string>
#include <map>

#include "util/base/include/definitions.h"
#include "containers/include/imodel_feedback_calc.h"

/*!
 * \brief Use GCAMFusion to analyze memory usage
 *
 * \author Pralit Patel
 */
class AnalyzeStr : public IModelFeedbackCalc {
public:

    // INamed methods
    virtual const std::string& getName() const { static const std::string XML_NAME = "analyze_str"; return XML_NAME; }

    // IParsable methods
    virtual bool XMLParse( const xercesc::DOMNode* aNode ) { return false; }

    // IRoundTrippable methods
    virtual void toInputXML( std::ostream& aOut, Tabs* aTabs ) const { }
    
    // IModelFeedbackCalc methods
    virtual void calcFeedbacksBeforePeriod( Scenario* aScenario, const IClimateModel* aClimateModel, const int aPeriod );

    virtual void calcFeedbacksAfterPeriod( Scenario* aScenario, const IClimateModel* aClimateModel, const int aPeriod );
    
    // Templated callbacks for GCAMFusion
    template<typename DataType>
    void processData( DataType& aData );
    /*
    template<typename DataType>
    void pushFilterStep( const DataType& aData );
    template<typename DataType>
    void popFilterStep( const DataType& aData );
    */

private:

    size_t mNumStr;

    size_t mTotalSize;

    std::map<std::string, size_t> mStrCount;
};

#endif // _ANALYZE_STR_H_
