// Module:  Log4CPLUS
// File:    appenderattachable.h
// Created: 6/2001
// Author:  Tad E. Smith
//
//
// Copyright 2001-2009 Tad E. Smith
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/** @file */

#ifndef DCMTK__LOG4CPLUS_SPI_APPENDER_ATTACHABLE_HEADER_
#define DCMTK__LOG4CPLUS_SPI_APPENDER_ATTACHABLE_HEADER_

#include "dcmtk/oflog/config.h"
#include "dcmtk/oflog/appender.h"
#include "dcmtk/oflog/tstring.h"
#include "dcmtk/oflog/helpers/pointer.h"
//#include <vector>

namespace dcmtk {
namespace log4cplus {
    // Forward Declarations
    typedef helpers::SharedObjectPtr<Appender> SharedAppenderPtr;
    typedef OFList<SharedAppenderPtr> SharedAppenderPtrList;
    typedef OFListIterator(SharedAppenderPtr) SharedAppenderPtrListIterator;

    namespace spi {

        /**
         * This Interface is for attaching Appenders to objects.
         */
        class DCMTK_LOG4CPLUS_EXPORT AppenderAttachable {
        public:
          // Methods
            /**
             * Add an appender.
             */
            virtual void addAppender(SharedAppenderPtr newAppender) = 0;

            /**
             * Get all previously added appenders as an Enumeration.
             */
            virtual SharedAppenderPtrList getAllAppenders() = 0;

            /**
             * Get an appender by name.
             */
            virtual SharedAppenderPtr getAppender(const tstring& name) = 0;

            /**
             * Remove all previously added appenders.
             */
            virtual void removeAllAppenders() = 0;

            /**
             * Remove the appender passed as parameter from the list of appenders.
             */
            virtual void removeAppender(SharedAppenderPtr appender) = 0;

            /**
             * Remove the appender with the name passed as parameter from the
             * list of appenders.
             */
            virtual void removeAppender(const tstring& name) = 0;

          // Dtor
            virtual ~AppenderAttachable() = 0;
        };

    } // end namespace spi
} // end namespace log4cplus
} // end namespace dcmtk

#endif // DCMTK__LOG4CPLUS_SPI_APPENDER_ATTACHABLE_HEADER_

