
#include <iostream>
#include <fstream>
#include <list>
#include <string>

#include "zypp/base/Logger.h"
#include "zypp/base/Exception.h"
#include "zypp/PublicKey.h"
#include "zypp/TmpPath.h"
#include "zypp/Date.h"

#include <boost/test/auto_unit_test.hpp>

using boost::unit_test::test_suite;
using boost::unit_test::test_case;

using namespace std;
using namespace zypp;

/*
-----BEGIN PGP PUBLIC KEY BLOCK-----
Version: GnuPG v1.4.2 (GNU/Linux)

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
=pJli
-----END PGP PUBLIC KEY BLOCK-----
*/

/**
 * Array version of the above key
 */
char susekey[]=
{
        0x2d,0x2d,0x2d,0x2d,0x2d,0x42,0x45,0x47,0x49,0x4e,0x20,0x50,0x47,
        0x50,0x20,0x50,0x55,0x42,0x4c,0x49,0x43,0x20,0x4b,0x45,0x59,0x20,
        0x42,0x4c,0x4f,0x43,0x4b,0x2d,0x2d,0x2d,0x2d,0x2d,0x0a,0x56,0x65,
        0x72,0x73,0x69,0x6f,0x6e,0x3a,0x20,0x47,0x6e,0x75,0x50,0x47,0x20,
        0x76,0x31,0x2e,0x34,0x2e,0x32,0x20,0x28,0x47,0x4e,0x55,0x2f,0x4c,
        0x69,0x6e,0x75,0x78,0x29,0x0a,0x0a,0x6d,0x51,0x47,0x69,0x42,0x44,
        0x6e,0x75,0x39,0x49,0x45,0x52,0x42,0x41,0x43,0x54,0x38,0x59,0x33,
        0x35,0x2b,0x32,0x76,0x76,0x34,0x4d,0x47,0x56,0x4b,0x69,0x4c,0x45,
        0x4d,0x4f,0x6c,0x39,0x47,0x64,0x53,0x54,0x36,0x4d,0x43,0x6b,0x59,
        0x53,0x33,0x79,0x45,0x4b,0x65,0x75,0x65,0x4e,0x57,0x63,0x2b,0x7a,
        0x2f,0x30,0x4b,0x76,0x66,0x66,0x0a,0x34,0x4a,0x63,0x74,0x42,0x73,
        0x67,0x73,0x34,0x37,0x74,0x6a,0x6d,0x69,0x49,0x39,0x73,0x6c,0x30,
        0x65,0x48,0x6a,0x6d,0x33,0x67,0x54,0x52,0x38,0x72,0x49,0x74,0x58,
        0x4d,0x4e,0x36,0x73,0x4a,0x45,0x55,0x48,0x57,0x7a,0x44,0x50,0x2b,
        0x59,0x30,0x50,0x46,0x50,0x62,0x6f,0x4d,0x76,0x4b,0x78,0x30,0x46,
        0x58,0x6c,0x2f,0x41,0x30,0x64,0x0a,0x4d,0x2b,0x48,0x46,0x72,0x72,
        0x75,0x43,0x67,0x42,0x6c,0x57,0x74,0x36,0x46,0x41,0x2b,0x6f,0x6b,
        0x52,0x79,0x53,0x51,0x69,0x6c,0x69,0x75,0x49,0x35,0x70,0x68,0x77,
        0x71,0x6b,0x58,0x65,0x66,0x6c,0x39,0x41,0x68,0x6b,0x77,0x52,0x38,
        0x78,0x6f,0x63,0x51,0x53,0x56,0x43,0x46,0x78,0x63,0x77,0x76,0x77,
        0x43,0x67,0x6c,0x56,0x63,0x4f,0x0a,0x51,0x6c,0x69,0x48,0x75,0x38,
        0x6a,0x77,0x52,0x51,0x48,0x78,0x6c,0x52,0x45,0x30,0x74,0x6b,0x77,
        0x51,0x51,0x49,0x30,0x44,0x2b,0x77,0x66,0x51,0x77,0x4b,0x64,0x76,
        0x68,0x44,0x70,0x6c,0x78,0x48,0x4a,0x35,0x6e,0x66,0x37,0x55,0x38,
        0x63,0x2f,0x79,0x45,0x2f,0x76,0x64,0x76,0x70,0x4e,0x36,0x6c,0x46,
        0x30,0x74,0x6d,0x46,0x72,0x4b,0x0a,0x58,0x42,0x55,0x58,0x2b,0x4b,
        0x37,0x75,0x34,0x69,0x66,0x72,0x5a,0x6c,0x51,0x76,0x6a,0x2f,0x38,
        0x31,0x4d,0x34,0x49,0x4e,0x6a,0x74,0x58,0x72,0x65,0x71,0x44,0x69,
        0x4a,0x74,0x72,0x39,0x39,0x52,0x73,0x36,0x78,0x61,0x30,0x53,0x63,
        0x5a,0x71,0x49,0x54,0x75,0x5a,0x43,0x34,0x43,0x57,0x78,0x4a,0x61,
        0x39,0x47,0x79,0x6e,0x42,0x45,0x0a,0x44,0x33,0x2b,0x44,0x32,0x74,
        0x31,0x56,0x2f,0x66,0x38,0x6c,0x30,0x73,0x6d,0x73,0x75,0x59,0x6f,
        0x46,0x4f,0x46,0x37,0x49,0x62,0x34,0x39,0x49,0x6b,0x54,0x64,0x62,
        0x74,0x77,0x41,0x54,0x68,0x6c,0x5a,0x70,0x38,0x62,0x45,0x68,0x45,
        0x4c,0x42,0x65,0x47,0x61,0x50,0x64,0x4e,0x43,0x63,0x6d,0x66,0x5a,
        0x36,0x36,0x72,0x4b,0x55,0x64,0x0a,0x47,0x35,0x73,0x52,0x41,0x2f,
        0x39,0x6f,0x76,0x6e,0x63,0x31,0x6b,0x72,0x53,0x51,0x46,0x32,0x2b,
        0x73,0x71,0x42,0x39,0x2f,0x6f,0x37,0x77,0x35,0x2f,0x71,0x32,0x71,
        0x69,0x79,0x7a,0x77,0x4f,0x53,0x54,0x6e,0x6b,0x6a,0x74,0x42,0x55,
        0x56,0x4b,0x6e,0x34,0x7a,0x4c,0x55,0x4f,0x66,0x36,0x61,0x65,0x42,
        0x41,0x6f,0x56,0x36,0x4e,0x4d,0x0a,0x43,0x43,0x33,0x4b,0x6a,0x39,
        0x61,0x5a,0x48,0x66,0x41,0x2b,0x4e,0x44,0x30,0x65,0x68,0x50,0x61,
        0x56,0x47,0x4a,0x67,0x6a,0x61,0x56,0x4e,0x46,0x68,0x50,0x69,0x34,
        0x78,0x30,0x65,0x37,0x42,0x55,0x4c,0x64,0x76,0x67,0x4f,0x6f,0x41,
        0x71,0x61,0x6a,0x4c,0x66,0x76,0x6b,0x55,0x52,0x48,0x41,0x65,0x53,
        0x73,0x78,0x58,0x49,0x6f,0x45,0x0a,0x6d,0x79,0x57,0x2f,0x78,0x43,
        0x31,0x73,0x42,0x62,0x44,0x6b,0x44,0x55,0x49,0x42,0x53,0x78,0x35,
        0x6f,0x65,0x6a,0x37,0x33,0x58,0x43,0x5a,0x67,0x6e,0x6a,0x2f,0x69,
        0x6e,0x70,0x68,0x52,0x71,0x47,0x70,0x73,0x62,0x2b,0x31,0x6e,0x4b,
        0x46,0x76,0x46,0x2b,0x72,0x51,0x6f,0x55,0x33,0x56,0x54,0x52,0x53,
        0x42,0x51,0x59,0x57,0x4e,0x72,0x0a,0x59,0x57,0x64,0x6c,0x49,0x46,
        0x4e,0x70,0x5a,0x32,0x35,0x70,0x62,0x6d,0x63,0x67,0x53,0x32,0x56,
        0x35,0x49,0x44,0x78,0x69,0x64,0x57,0x6c,0x73,0x5a,0x45,0x42,0x7a,
        0x64,0x58,0x4e,0x6c,0x4c,0x6d,0x52,0x6c,0x50,0x6f,0x68,0x69,0x42,
        0x42,0x4d,0x52,0x41,0x67,0x41,0x69,0x42,0x51,0x4a,0x41,0x32,0x41,
        0x59,0x2b,0x41,0x68,0x73,0x44,0x0a,0x42,0x51,0x6b,0x4f,0x62,0x64,
        0x2b,0x39,0x42,0x41,0x73,0x48,0x41,0x77,0x49,0x44,0x46,0x51,0x49,
        0x44,0x41,0x78,0x59,0x43,0x41,0x51,0x49,0x65,0x41,0x51,0x49,0x58,
        0x67,0x41,0x41,0x4b,0x43,0x52,0x43,0x6f,0x54,0x74,0x72,0x6f,0x6e,
        0x49,0x41,0x4b,0x79,0x70,0x43,0x66,0x41,0x4a,0x39,0x52,0x75,0x5a,
        0x36,0x5a,0x53,0x56,0x37,0x51,0x0a,0x57,0x34,0x70,0x54,0x67,0x54,
        0x49,0x78,0x51,0x2b,0x41,0x42,0x50,0x70,0x30,0x73,0x49,0x77,0x43,
        0x66,0x66,0x47,0x39,0x62,0x43,0x4e,0x6e,0x72,0x45,0x54,0x50,0x6c,
        0x67,0x4f,0x6e,0x2b,0x64,0x47,0x45,0x6b,0x41,0x57,0x65,0x67,0x4b,
        0x4c,0x2b,0x49,0x52,0x67,0x51,0x51,0x45,0x51,0x49,0x41,0x42,0x67,
        0x55,0x43,0x4f,0x6e,0x42,0x65,0x0a,0x55,0x67,0x41,0x4b,0x43,0x52,
        0x43,0x65,0x51,0x4f,0x4d,0x51,0x41,0x41,0x71,0x72,0x70,0x4e,0x7a,
        0x4f,0x41,0x4b,0x43,0x4c,0x35,0x31,0x32,0x46,0x5a,0x76,0x76,0x34,
        0x56,0x5a,0x78,0x39,0x34,0x54,0x70,0x62,0x41,0x39,0x6c,0x78,0x79,
        0x6f,0x41,0x65,0x6a,0x41,0x43,0x65,0x4f,0x4f,0x31,0x48,0x49,0x62,
        0x41,0x63,0x74,0x41,0x65,0x76,0x0a,0x6b,0x35,0x4d,0x55,0x42,0x68,
        0x4e,0x65,0x4c,0x5a,0x61,0x2f,0x71,0x4d,0x32,0x4a,0x41,0x52,0x55,
        0x44,0x42,0x52,0x41,0x36,0x63,0x47,0x42,0x76,0x64,0x37,0x4c,0x6d,
        0x41,0x44,0x30,0x6c,0x30,0x39,0x6b,0x42,0x41,0x54,0x57,0x6e,0x42,
        0x2f,0x39,0x41,0x6e,0x35,0x76,0x66,0x69,0x55,0x55,0x45,0x31,0x56,
        0x51,0x6e,0x74,0x2b,0x54,0x2f,0x0a,0x45,0x59,0x6b,0x6c,0x45,0x53,
        0x33,0x74,0x58,0x58,0x61,0x4a,0x4a,0x70,0x39,0x70,0x48,0x4d,0x61,
        0x34,0x66,0x7a,0x46,0x61,0x38,0x6a,0x50,0x56,0x74,0x76,0x35,0x55,
        0x42,0x48,0x47,0x65,0x65,0x33,0x58,0x6f,0x55,0x4e,0x44,0x56,0x77,
        0x4d,0x32,0x4f,0x67,0x53,0x45,0x49,0x53,0x5a,0x78,0x62,0x7a,0x64,
        0x58,0x47,0x6e,0x71,0x49,0x6c,0x0a,0x63,0x54,0x30,0x38,0x54,0x7a,
        0x42,0x55,0x44,0x39,0x69,0x35,0x37,0x39,0x75,0x69,0x66,0x6b,0x6c,
        0x4c,0x73,0x6e,0x72,0x33,0x35,0x53,0x4a,0x44,0x5a,0x36,0x72,0x61,
        0x6d,0x35,0x31,0x2f,0x43,0x57,0x4f,0x6e,0x6e,0x61,0x56,0x68,0x55,
        0x7a,0x6e,0x65,0x4f,0x41,0x39,0x67,0x54,0x50,0x53,0x72,0x2b,0x2f,
        0x66,0x54,0x33,0x57,0x65,0x56,0x0a,0x6e,0x77,0x4a,0x69,0x51,0x43,
        0x51,0x33,0x30,0x6b,0x4e,0x4c,0x57,0x56,0x58,0x57,0x41,0x54,0x4d,
        0x6e,0x73,0x6e,0x54,0x34,0x38,0x36,0x65,0x41,0x4f,0x6c,0x54,0x36,
        0x55,0x4e,0x42,0x50,0x59,0x51,0x4c,0x70,0x55,0x70,0x72,0x46,0x35,
        0x59,0x72,0x79,0x6b,0x32,0x33,0x70,0x51,0x55,0x50,0x41,0x67,0x4a,
        0x45,0x4e,0x44,0x45,0x71,0x65,0x0a,0x55,0x36,0x69,0x49,0x4f,0x39,
        0x4f,0x74,0x31,0x5a,0x50,0x74,0x42,0x30,0x6c,0x6e,0x69,0x77,0x2b,
        0x2f,0x78,0x43,0x69,0x31,0x33,0x44,0x33,0x36,0x30,0x6f,0x31,0x74,
        0x5a,0x44,0x59,0x4f,0x70,0x30,0x68,0x48,0x48,0x4a,0x4e,0x33,0x44,
        0x33,0x45,0x4e,0x38,0x43,0x31,0x79,0x50,0x71,0x5a,0x64,0x35,0x43,
        0x76,0x76,0x7a,0x6e,0x59,0x76,0x0a,0x42,0x36,0x62,0x57,0x42,0x49,
        0x70,0x57,0x63,0x52,0x67,0x64,0x6e,0x32,0x44,0x55,0x56,0x4d,0x6d,
        0x70,0x55,0x36,0x36,0x31,0x6a,0x77,0x71,0x47,0x6c,0x52,0x7a,0x31,
        0x46,0x38,0x34,0x4a,0x47,0x2f,0x78,0x65,0x34,0x6a,0x47,0x75,0x7a,
        0x67,0x70,0x4a,0x74,0x39,0x49,0x58,0x53,0x7a,0x79,0x6f,0x68,0x45,
        0x4a,0x42,0x36,0x58,0x47,0x35,0x0a,0x2b,0x44,0x30,0x42,0x75,0x51,
        0x49,0x4e,0x42,0x44,0x6e,0x75,0x39,0x4a,0x49,0x51,0x43,0x41,0x43,
        0x45,0x6b,0x64,0x42,0x4e,0x36,0x4d,0x78,0x66,0x35,0x57,0x76,0x71,
        0x44,0x57,0x6b,0x63,0x4d,0x52,0x79,0x36,0x77,0x6e,0x72,0x64,0x39,
        0x44,0x59,0x4a,0x38,0x55,0x55,0x54,0x6d,0x49,0x54,0x32,0x69,0x51,
        0x66,0x30,0x37,0x74,0x52,0x55,0x0a,0x4b,0x4a,0x4a,0x39,0x76,0x30,
        0x4a,0x58,0x66,0x78,0x32,0x5a,0x34,0x64,0x30,0x38,0x49,0x51,0x53,
        0x4d,0x4e,0x52,0x61,0x71,0x34,0x56,0x67,0x53,0x65,0x2b,0x50,0x64,
        0x59,0x67,0x49,0x79,0x30,0x66,0x62,0x6a,0x32,0x33,0x56,0x69,0x61,
        0x35,0x2f,0x67,0x4f,0x37,0x66,0x4a,0x45,0x70,0x44,0x32,0x68,0x64,
        0x32,0x66,0x2b,0x70,0x4d,0x6e,0x0a,0x4f,0x57,0x76,0x48,0x32,0x72,
        0x4f,0x4f,0x49,0x62,0x65,0x59,0x66,0x75,0x68,0x7a,0x41,0x63,0x36,
        0x42,0x51,0x6a,0x41,0x4b,0x74,0x6d,0x67,0x52,0x30,0x45,0x52,0x55,
        0x54,0x61,0x66,0x54,0x4d,0x39,0x57,0x62,0x36,0x46,0x31,0x33,0x43,
        0x4e,0x5a,0x5a,0x4e,0x5a,0x66,0x44,0x71,0x6e,0x46,0x44,0x50,0x36,
        0x4c,0x31,0x32,0x77,0x33,0x7a,0x0a,0x33,0x46,0x37,0x46,0x46,0x58,
        0x6b,0x7a,0x30,0x37,0x52,0x73,0x33,0x41,0x49,0x74,0x6f,0x31,0x5a,
        0x66,0x59,0x5a,0x64,0x34,0x73,0x43,0x53,0x70,0x4d,0x72,0x2f,0x30,
        0x53,0x35,0x6e,0x4c,0x72,0x48,0x62,0x49,0x76,0x47,0x4c,0x70,0x32,
        0x37,0x31,0x68,0x68,0x51,0x42,0x65,0x52,0x6d,0x6d,0x6f,0x47,0x45,
        0x4b,0x4f,0x32,0x4a,0x52,0x65,0x0a,0x6c,0x47,0x67,0x55,0x4a,0x32,
        0x43,0x55,0x7a,0x4f,0x64,0x74,0x77,0x44,0x49,0x4b,0x54,0x30,0x4c,
        0x62,0x43,0x70,0x76,0x61,0x50,0x38,0x50,0x56,0x6e,0x59,0x46,0x35,
        0x49,0x46,0x6f,0x59,0x4a,0x49,0x57,0x52,0x48,0x71,0x6c,0x45,0x74,
        0x35,0x75,0x63,0x54,0x58,0x73,0x74,0x5a,0x79,0x37,0x76,0x59,0x6a,
        0x4c,0x36,0x76,0x54,0x50,0x34,0x0a,0x6c,0x35,0x78,0x73,0x2b,0x4c,
        0x49,0x4f,0x6b,0x4e,0x6d,0x50,0x68,0x71,0x6d,0x66,0x73,0x67,0x4c,
        0x7a,0x56,0x6f,0x30,0x55,0x61,0x4c,0x74,0x38,0x30,0x68,0x4f,0x77,
        0x63,0x34,0x4e,0x76,0x44,0x43,0x4f,0x4c,0x41,0x41,0x4d,0x47,0x42,
        0x2f,0x39,0x67,0x2b,0x39,0x56,0x33,0x4f,0x52,0x7a,0x77,0x34,0x4c,
        0x76,0x4f,0x31,0x70,0x77,0x52,0x0a,0x59,0x4a,0x71,0x66,0x44,0x4b,
        0x55,0x71,0x2f,0x45,0x4a,0x30,0x72,0x4e,0x4d,0x4d,0x44,0x34,0x4e,
        0x38,0x52,0x4c,0x70,0x5a,0x52,0x68,0x4b,0x48,0x4b,0x4a,0x55,0x6d,
        0x39,0x6e,0x4e,0x48,0x4c,0x62,0x6b,0x73,0x6e,0x6c,0x5a,0x77,0x72,
        0x62,0x53,0x54,0x4d,0x35,0x4c,0x70,0x43,0x2f,0x55,0x36,0x73,0x68,
        0x65,0x4c,0x50,0x2b,0x6c,0x30,0x0a,0x62,0x4c,0x56,0x6f,0x71,0x30,
        0x6c,0x6d,0x73,0x43,0x63,0x55,0x53,0x79,0x68,0x2b,0x6d,0x59,0x36,
        0x50,0x78,0x57,0x69,0x72,0x4c,0x49,0x57,0x43,0x6e,0x2f,0x49,0x41,
        0x5a,0x41,0x47,0x6e,0x58,0x62,0x36,0x5a,0x64,0x36,0x54,0x74,0x49,
        0x4a,0x6c,0x47,0x47,0x36,0x70,0x71,0x55,0x4e,0x38,0x51,0x78,0x47,
        0x4a,0x59,0x51,0x6e,0x6f,0x6e,0x0a,0x6c,0x30,0x75,0x54,0x4a,0x4b,
        0x48,0x4a,0x45,0x4e,0x62,0x49,0x39,0x73,0x57,0x48,0x51,0x64,0x63,
        0x54,0x74,0x42,0x4d,0x63,0x33,0x34,0x67,0x6f,0x72,0x48,0x46,0x43,
        0x6f,0x31,0x42,0x63,0x76,0x70,0x6e,0x63,0x31,0x4c,0x46,0x4c,0x72,
        0x57,0x6e,0x37,0x6d,0x66,0x6f,0x47,0x78,0x36,0x49,0x4e,0x51,0x6a,
        0x66,0x33,0x48,0x47,0x51,0x70,0x0a,0x4d,0x58,0x41,0x57,0x75,0x53,
        0x42,0x51,0x68,0x7a,0x6b,0x61,0x7a,0x59,0x36,0x76,0x61,0x57,0x46,
        0x70,0x61,0x38,0x62,0x42,0x4a,0x2b,0x67,0x4b,0x62,0x42,0x75,0x79,
        0x53,0x57,0x7a,0x4e,0x6d,0x33,0x72,0x46,0x74,0x54,0x35,0x48,0x52,
        0x4b,0x4d,0x57,0x70,0x4f,0x2b,0x4d,0x39,0x62,0x48,0x70,0x34,0x64,
        0x2b,0x70,0x75,0x59,0x30,0x4c,0x0a,0x31,0x59,0x77,0x4e,0x31,0x4f,
        0x4d,0x61,0x74,0x63,0x4d,0x4d,0x70,0x63,0x57,0x6e,0x5a,0x70,0x69,
        0x57,0x69,0x52,0x38,0x33,0x6f,0x69,0x33,0x32,0x2b,0x78,0x74,0x57,
        0x55,0x59,0x32,0x55,0x37,0x41,0x65,0x33,0x38,0x6d,0x4d,0x61,0x67,
        0x38,0x7a,0x46,0x62,0x70,0x65,0x71,0x50,0x51,0x55,0x73,0x44,0x76,
        0x39,0x56,0x37,0x43,0x41,0x4a,0x0a,0x31,0x64,0x62,0x72,0x69,0x45,
        0x77,0x45,0x47,0x42,0x45,0x43,0x41,0x41,0x77,0x46,0x41,0x6b,0x44,
        0x59,0x42,0x6e,0x6f,0x46,0x43,0x51,0x35,0x74,0x33,0x2b,0x67,0x41,
        0x43,0x67,0x6b,0x51,0x71,0x45,0x37,0x61,0x36,0x4a,0x79,0x41,0x43,
        0x73,0x70,0x6e,0x70,0x67,0x43,0x66,0x52,0x62,0x59,0x77,0x78,0x54,
        0x33,0x69,0x71,0x2b,0x39,0x6c,0x0a,0x2f,0x50,0x67,0x4e,0x54,0x55,
        0x4e,0x54,0x5a,0x4f,0x6c,0x6f,0x66,0x32,0x6f,0x41,0x6e,0x32,0x35,
        0x79,0x30,0x65,0x47,0x69,0x30,0x33,0x37,0x31,0x6a,0x61,0x70,0x39,
        0x6b,0x4f,0x56,0x36,0x75,0x71,0x37,0x31,0x73,0x55,0x75,0x4f,0x0a,
        0x3d,0x70,0x4a,0x6c,0x69,0x0a,0x2d,0x2d,0x2d,0x2d,0x2d,0x45,0x4e,
        0x44,0x20,0x50,0x47,0x50,0x20,0x50,0x55,0x42,0x4c,0x49,0x43,0x20,
        0x4b,0x45,0x59,0x20,0x42,0x4c,0x4f,0x43,0x4b,0x2d,0x2d,0x2d,0x2d,
        0x2d,0x0a,0x00,
};

size_t _susekey_size=2173;
size_t *susekey_size=&_susekey_size;

BOOST_AUTO_TEST_CASE(publickey_test)
{
  BOOST_CHECK_THROW( zypp::PublicKey("nonexistant"), Exception );
  
  filesystem::TmpFile file;
  ofstream str(file.path().asString().c_str(),ofstream::out);

  if (!str.good())
    ZYPP_THROW(Exception("cant open file"));

  str << susekey;
  str.flush();
  str.close();
 
  zypp::PublicKey k2(file.path());
  
  BOOST_CHECK_EQUAL( k2.id(), "A84EDAE89C800ACA" );
  BOOST_CHECK_EQUAL( k2.name(), "SuSE Package Signing Key <build@suse.de>" );
  BOOST_CHECK_EQUAL( k2.fingerprint(), "79C179B2E1C820C1890F9994A84EDAE89C800ACA" );
  BOOST_CHECK_EQUAL( k2.created(), zypp::Date(1087899198) );
  BOOST_REQUIRE( k2.path() != Pathname() );
  BOOST_REQUIRE( k2 == k2 );
  // test for a empty key
  zypp::PublicKey empty_key;
  BOOST_REQUIRE( ! empty_key.isValid() );
}

