/*---------------------------------------------------------------------\
|                          ____ _   __ __ ___                          |
|                         |__  / \ / / . \ . \                         |
|                           / / \ V /|  _/  _/                         |
|                          / /__ | | | | | |                           |
|                         /_____||_| |_| |_|                           |
|                                                                      |
\---------------------------------------------------------------------*/
/** \file zypp/base/PtrTypes.h
 *  \ingroup ZYPP_BASE_SMART_PTR
 *  \see ZYPP_BASE_SMART_PTR
*/
#ifndef ZYPP_BASE_PTRTYPES_H
#define ZYPP_BASE_PTRTYPES_H

#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

///////////////////////////////////////////////////////////////////
namespace zypp
{ /////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////
  namespace base
  { /////////////////////////////////////////////////////////////////

    /** \defgroup ZYPP_BASE_SMART_PTR ZYPP_BASE_SMART_PTR
     *  Smart pointer types.
     *
     * Namespace zypp::base provides 3 smart pointer types \b using the
     * boostsmart pointer library.
     *
     * \li \c scoped_ptr Simple sole ownership of single objects. Noncopyable.
     *
     * \li \c shared_ptr Object ownership shared among multiple pointers
     *
     * \li \c weak_ptr Non-owning observers of an object owned by shared_ptr.
    */
    /*@{*/

    /** */
    using boost::scoped_ptr;

    /** */
    using boost::shared_ptr;

    /** */
    using boost::weak_ptr;

    /*@}*/

    /////////////////////////////////////////////////////////////////
  } // namespace base
  ///////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////
} // namespace zypp
///////////////////////////////////////////////////////////////////
#endif // ZYPP_BASE_PTRTYPES_H
