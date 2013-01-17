#ifndef SECRETUTIL_H
#define SECRETUTIL_H

#include <string>
#include <iostream>
using namespace std;

extern "C" {
#include "util.h"
#include "policy.h"
}
#include "CharmListZR.h"
#include "CharmListStr.h"
#include "Charm.h"

class Policy
{
public:
	charm_attribute_policy *p;
	bool isInit;
//	Policy();
	Policy(string);
	~Policy();
	Policy(const Policy&);
	Policy& operator=(const Policy&);
    friend ostream& operator<<(ostream&, const Policy&);
};


/* implements secret sharing */
class SecretUtil
{
public: 
	SecretUtil();
	~SecretUtil();
	Policy createPolicy(string s);
	CharmListStr prune(Policy&, CharmListStr attrs);
	CharmListStr getAttributeList(Policy&);
	CharmListZR genShares(PairingGroup & group, ZR secret, int k, int n);
	CharmDictZR calculateSharesDict(PairingGroup & group, ZR, Policy&);
// CharmList? calculateSharesList(ZR, Policy&); // TODO: implement
	CharmDictZR getCoefficients(PairingGroup & group, Policy&);
private:
//	PairingGroup group;
};







#endif
