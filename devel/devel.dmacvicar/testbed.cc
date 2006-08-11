#include <zypp/base/Logger.h>
#include <zypp/ZYpp.h>
#include <zypp/ZYppFactory.h>

#include "zypp/Product.h"
#include "zypp/Package.h"

#include "zypp/SourceFactory.h"
#include "testsuite/src/utils/TestUtils.h"

using namespace zypp::detail;

using namespace std;
using namespace zypp;
using namespace zypp::source;
//using namespace DbXml;

#define TestKind Selection

int main()
{
  try
  {
    ZYpp::Ptr z = getZYpp();
    //z->initializeTarget("/");
    
    //SourceManager_Ptr manager = SourceManager::sourceManager();
    
    Source_Ref source = SourceFactory().createFrom( Url("dir:/space/rpms/duncan/vim/i386"), "/", "bleh", Pathname() );
    ResStore store = source.resolvables();
    //zypp::testsuite::utils::dump(store, true, true);
    
    for (ResStore::const_iterator it = store.begin(); it != store.end(); ++it)
    {
      zypp::Package::Ptr res = asKind<zypp::Package>( *it );
      MIL << res->name() << " " << res->edition() << " " << res->location() << std::endl;
    }
        
  }
  catch ( const Exception &e )
  {
    MIL << "Sorry, bye" << endl;
  }
}



