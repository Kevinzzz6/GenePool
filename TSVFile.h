//
//  TSVFile.h
//  GenePool
//
//  Created by Howard Stahl on 7/1/23.
//

#ifndef TSVFILE_H
#define TSVFILE_H

#include <map>
#include <string>
#include "DataCollectorCallback.h"

namespace cs32
{

/*
 A class provided to CS32 students to read a TSV file
 If hasHeaders, the first line of the file must be a line of field headers
 If combineQuotedFields, commas when found inside quotes are not treated as separators
 If no header is supplied, the data fields will be named field0, field1, field2, ...
 */
class TSVFile
{
public:
    TSVFile( DataCollectorCallback * callback, bool hasHeaders = false, bool combineQuotedFields = false );
    
    /* reads stated file, returns number of rows read */
    /* for each row of actual data found, it will invoke the DataCollecorCallback::tsvData( ... ) */
    int readFile( std::string filePath );
    
private:
    DataCollectorCallback * mCollector;
    bool mHasHeaders;
    bool mCombineQuotedFields;
    bool debug;
    
    // does s start with the prefix value?
    bool startsWith( const std::string& s, const std::string& value ) const;
    // does s end with suffix value?
    bool endsWith( const std::string& s, const std::string& value ) const;

};

}

#endif
