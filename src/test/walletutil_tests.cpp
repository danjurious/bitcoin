#include "main.h"
#include "test/test_bitcoin.h"
#include <boost/test/unit_test.hpp>

#ifdef ENABLE_WALLET
#include "wallet/db.h"
#include "wallet/wallet.h"
extern CWallet* pwalletMain;
#endif

using namespace std;

BOOST_FIXTURE_TEST_SUITE(walletutil_tests, WalletSetup)

BOOST_AUTO_TEST_CASE(walletutil_test)
{
#ifdef WIN32
	string strCmd = "wallet-utility -datadir="+mapArgs["-datadir"];
#else
	string strCmd = "./wallet-utility -datadir="+mapArgs["-datadir"];
#endif
	int ret = system(strCmd.c_str());
	BOOST_CHECK(ret == 0);

	strCmd += " -dumppass";
	ret = system(strCmd.c_str());
	BOOST_CHECK(ret == 0);
}

BOOST_AUTO_TEST_SUITE_END()
