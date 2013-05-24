// Module:  Log4CPLUS
// File:    hierarchy.h
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

#ifndef DCMTK__LOG4CPLUS_HIERARCHY_HEADER_
#define DCMTK__LOG4CPLUS_HIERARCHY_HEADER_

#include "dcmtk/oflog/config.h"
#include "dcmtk/oflog/logger.h"
#include "dcmtk/oflog/helpers/lloguser.h"
#include "dcmtk/oflog/helpers/pointer.h"
#include "dcmtk/oflog/helpers/threads.h"
//#include <map>
//#include <memory>
//#include <vector>


namespace dcmtk {
namespace log4cplus {
    // Forward Declarations
    class HierarchyLocker;

    /**
     * This class is specialized in retrieving loggers by name and
     * also maintaining the logger hierarchy.
     *
     * <em>The casual user should not have to deal with this class
     * directly.</em>  However, if you are in an environment where
     * multiple applications run in the same process, then read on.
     *
     * The structure of the logger hierarchy is maintained by the
     * {@link #getInstance} method. The hierarchy is such that children
     * link to their parent but parents do not have any pointers to their
     * children. Moreover, loggers can be instantiated in any order, in
     * particular descendant before ancestor.
     *
     * In case a descendant is created before a particular ancestor,
     * then it creates a provision node for the ancestor and adds itself
     * to the provision node. Other descendants of the same ancestor add
     * themselves to the previously created provision node.
     */
    class DCMTK_LOG4CPLUS_EXPORT Hierarchy : protected helpers::LogLogUser {
    public:
        // DISABLE_OFF should be set to a value lower than all possible
        // priorities.
        static const LogLevel DISABLE_OFF;
        static const LogLevel DISABLE_OVERRIDE;

      // Ctors
        /**
         * Create a new Logger hierarchy.
         */
        Hierarchy();

      // Dtor
        virtual ~Hierarchy();

      // Methods
        /**
         * This call will clear all logger definitions from the internal
         * hashtable. Invoking this method will irrevocably mess up the
         * logger hierarchy.
         *
         * You should <em>really</em> know what you are doing before
         * invoking this method.
         */
        virtual void clear();

        /**
         * Returns <code>true </code>if the named logger exists
         * (in the default hierarchy).
         *
         * @param name The name of the logger to search for.
         */
        virtual bool exists(const tstring& name);

        /**
         * Similar to {@link #disable(LogLevel)} except that the LogLevel
         * argument is given as a tstring.
         */
        virtual void disable(const tstring& loglevelStr);

        /**
         * Disable all logging requests of LogLevel <em>equal to or
         * below</em> the ll parameter <code>p</code>, for
         * <em>all</em> loggers in this hierarchy. Logging requests of
         * higher LogLevel then <code>p</code> remain unaffected.
         *
         * Nevertheless, if the {@link
         * BasicConfigurator#DISABLE_OVERRIDE_KEY} system property is set to
         * "true" or any value other than "false", then logging requests are
         * evaluated as usual, i.e. according to the <a
         * href="../../../../manual.html#selectionRule">Basic Selection Rule</a>.
         *
         * The "disable" family of methods are there for speed. They
         * allow printing methods such as debug, info, etc. to return
         * immediately after an integer comparison without walking the
         * logger hierarchy. In most modern computers an integer
         * comparison is measured in nanoseconds where as a logger walk is
         * measured in units of microseconds.
         */
        virtual void disable(LogLevel ll);

        /**
         * Disable all logging requests regardless of logger and LogLevel.
         * This method is equivalent to calling {@link #disable} with the
         * argument FATAL_LOG_LEVEL, the highest possible LogLevel.
         */
        virtual void disableAll();

        /**
         * Disable all Debug logging requests regardless of logger.
         * This method is equivalent to calling {@link #disable} with the
         * argument DEBUG_LOG_LEVEL.
         */
        virtual void disableDebug();

        /**
         * Disable all Info logging requests regardless of logger.
         * This method is equivalent to calling {@link #disable} with the
         * argument INFO_LOG_LEVEL.
         */
        virtual void disableInfo();

        /**
         * Undoes the effect of calling any of {@link #disable}, {@link
         * #disableAll}, {@link #disableDebug} and {@link #disableInfo}
         * methods. More precisely, invoking this method sets the Logger
         * class internal variable called <code>disable</code> to its
         * default "off" value.
         */
        virtual void enableAll();

        /**
         * Return a new logger instance named as the first parameter using
         * the default factory.
         *
         * If a logger of that name already exists, then it will be
         * returned.  Otherwise, a new logger will be instantiated and
         * then linked with its existing ancestors as well as children.
         *
         * @param name The name of the logger to retrieve.
         */
        virtual Logger getInstance(const tstring& name);

        /**
         * Return a new logger instance named as the first parameter using
         * <code>factory</code>.
         *
         * If a logger of that name already exists, then it will be
         * returned.  Otherwise, a new logger will be instantiated by the
         * <code>factory</code> parameter and linked with its existing
         * ancestors as well as children.
         *
         * @param name The name of the logger to retrieve.
         * @param factory The factory that will make the new logger instance.
         */
        virtual Logger getInstance(const tstring& name, spi::LoggerFactory& factory);

        /**
         * Returns all the currently defined loggers in this hierarchy.
         *
         * The root logger is <em>not</em> included in the returned list.
         */
        virtual LoggerList getCurrentLoggers();

        /**
         * Is the LogLevel specified by <code>level</code> enabled?
         */
        virtual bool isDisabled(int level);

        /**
         * Get the root of this hierarchy.
         */
        virtual Logger getRoot() const;

        /**
         * Reset all values contained in this hierarchy instance to their
         * default.  This removes all appenders from all loggers, sets
         * the LogLevel of all non-root loggers to <code>NOT_SET_LOG_LEVEL</code>,
         * sets their additivity flag to <code>true</code> and sets the LogLevel
         * of the root logger to DEBUG_LOG_LEVEL.  Moreover, message disabling
         * is set its default "off" value.
         *
         * Existing loggers are not removed. They are just reset.
         *
         * This method should be used sparingly and with care as it will
         * block all logging until it is completed.</p>
         */
        virtual void resetConfiguration();

        /**
         * Set the default LoggerFactory instance.
         */
        virtual void setLoggerFactory(OFauto_ptr<spi::LoggerFactory> factory);

        /**
         * Returns the default LoggerFactory instance.
         */
        virtual spi::LoggerFactory* getLoggerFactory() { return defaultFactory.get(); }

        /**
         * Shutting down a hierarchy will <em>safely</em> close and remove
         * all appenders in all loggers including the root logger.
         *
         * Some appenders such as SocketAppender need to be closed before the
         * application exits. Otherwise, pending logging events might be
         * lost.
         *
         * The <code>shutdown</code> method is careful to close nested
         * appenders before closing regular appenders. This is allows
         * configurations where a regular appender is attached to a logger
         * and again to a nested appender.
         */
        virtual void shutdown();

    private:
      // Types
        typedef OFList<Logger> ProvisionNode;
        typedef OFListIterator(Logger) ProvisionNodeIterator;
        typedef OFMap<tstring, ProvisionNode> ProvisionNodeMap;
        typedef OFMap<tstring, Logger> LoggerMap;

      // Methods
        /**
         * This is the implementation of the <code>getInstance()</code> method.
         * NOTE: This method does not lock the <code>hashtable_mutex</code>.
         */
        virtual Logger getInstanceImpl(const tstring& name,
                                       spi::LoggerFactory& factory);

        /**
         * This is the implementation of the <code>getCurrentLoggers()</code>.
         * NOTE: This method does not lock the <code>hashtable_mutex</code>.
         */
        virtual void initializeLoggerList(LoggerList& list) const;

        /**
         * This method loops through all the *potential* parents of
         * logger'. There 3 possible cases:
         *
         * 1) No entry for the potential parent of 'logger' exists
         *
         *    We create a ProvisionNode for this potential parent and insert
         *    'logger' in that provision node.
         *
         * 2) There is an entry of type Logger for the potential parent.
         *
         *    The entry is 'logger's nearest existing parent. We update logger's
         *    parent field with this entry. We also break from the loop
         *    because updating our parent's parent is our parent's
         *    responsibility.
         *
         * 3) There entry is of type ProvisionNode for this potential parent.
         *
         *    We add 'logger' to the list of children for this potential parent.
         */
        void updateParents(Logger logger);

        /**
         * We update the links for all the children that placed themselves
         * in the provision node 'pn'. The second argument 'logger' is a
         * reference for the newly created Logger, parent of all the
         * children in 'pn'
         *
         * We loop on all the children 'c' in 'pn':
         *
         *    If the child 'c' has been already linked to a child of
         *    'logger' then there is no need to update 'c'.
         *
         *   Otherwise, we set logger's parent field to c's parent and set
         *   c's parent field to logger.
         */
        void updateChildren(ProvisionNode& pn, Logger logger);

    // Data
       DCMTK_LOG4CPLUS_MUTEX_PTR_DECLARE hashtable_mutex;
       OFauto_ptr<spi::LoggerFactory> defaultFactory;
       ProvisionNodeMap provisionNodes;
       LoggerMap loggerPtrs;
       Logger root;

       int disableValue;

       bool emittedNoAppenderWarning;
       bool emittedNoResourceBundleWarning;

     // Disallow copying of instances of this class
       Hierarchy(const Hierarchy&);
       Hierarchy& operator=(const Hierarchy&);

    // Friends
       friend class spi::LoggerImpl;
       friend class HierarchyLocker;
    };

} // end namespace log4cplus
} // end namespace dcmtk

#endif // DCMTK__LOG4CPLUS_HIERARCHY_HEADER_

