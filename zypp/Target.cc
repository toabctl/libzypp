/*---------------------------------------------------------------------\
|                          ____ _   __ __ ___                          |
|                         |__  / \ / / . \ . \                         |
|                           / / \ V /|  _/  _/                         |
|                          / /__ | | | | | |                           |
|                         /_____||_| |_| |_|                           |
|                                                                      |
\---------------------------------------------------------------------*/
/** \file zypp/Target.cc
 *
*/
#include <cassert>

#include <iostream>

#include "zypp/Target.h"
#include "zypp/target/TargetImpl.h"

using namespace std;

///////////////////////////////////////////////////////////////////
namespace zypp
{ /////////////////////////////////////////////////////////////////

  IMPL_PTR_TYPE(Target);

  ///////////////////////////////////////////////////////////////////
  //
  //	METHOD NAME : Target::Target
  //	METHOD TYPE : Ctor
  //
  Target::Target( const Pathname & root )
  : _pimpl( new Impl(root) )
  {
  }

  ///////////////////////////////////////////////////////////////////
  //
  //	METHOD NAME : Target::Target
  //	METHOD TYPE : Ctor
  //
  Target::Target( const Impl_Ptr & impl_r )
  : _pimpl( impl_r )
  {
    assert( impl_r );
  }

  Target_Ptr Target::_nullimpl;

  /** Null implementation */
  Target_Ptr Target::nullimpl()
  {
    if (! _nullimpl)
    {
      _nullimpl = new Target(target::TargetImpl::nullimpl());
    }
    return _nullimpl;
  }


  ///////////////////////////////////////////////////////////////////
  //
  //	Forward to TargetImpl:
  //
  ///////////////////////////////////////////////////////////////////

  const ResStore & Target::resolvables()
  { return _pimpl->resolvables(); }

  target::rpm::RpmDb & Target::rpmDb()
  { return _pimpl->rpm(); }

#ifndef STORAGE_DISABLED
      /** enables the storage target */
  bool Target::isStorageEnabled() const
  { return _pimpl->isStorageEnabled(); }

  void Target::enableStorage(const Pathname &root_r)
  { _pimpl->enableStorage(root_r); }
#endif

  int Target::commit(ResPool pool_r, int medianr, PoolItemList & errors_r
        , PoolItemList & remaining_r, PoolItemList & srcremaining_r)
  { return _pimpl->commit(pool_r, medianr, errors_r, remaining_r, srcremaining_r); }

  bool Target::providesFile (const std::string & name_str, const std::string & path_str) const
  { return _pimpl->providesFile (name_str, path_str); }

  ResObject::constPtr Target::whoOwnsFile (const std::string & path_str) const
  { return _pimpl->whoOwnsFile (path_str); }

  std::ostream & Target::dumpOn( std::ostream & str ) const
  { return _pimpl->dumpOn( str ); }


  /////////////////////////////////////////////////////////////////
} // namespace zypp
///////////////////////////////////////////////////////////////////
