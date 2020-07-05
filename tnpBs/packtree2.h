#ifndef _XJJC_PACKTREE_H_
#define _XJJC_PACKTREE_H_

#include "ntuple.h"

#include <TFile.h>
#include <TTree.h>
#include <string>

namespace xjjroot
{
  typedef std::vector<TTree*> trlist;
  class packtree
  {
  public:
    packtree(TFile* inf, std::string treename, std::string type, std::string gentreename = "");
    mytmva::ntuple* ntp;
    int getentries() { return fentries; }
    std::string getname() { return name; }
    void getentry(int i);
    // TTree* gethi() { return hi; }
  private:
    std::string name;
    TTree* nt;
    TTree* ntgen;
    int fentries;
  };
}

void xjjroot::packtree::getentry(int i)
{
  nt->GetEntry(i);
}

xjjroot::packtree::packtree(TFile* inf, std::string treename, std::string type, std::string gentreename)
{
  name = type;
  nt = (TTree*)inf->Get(treename.c_str());
  fentries = nt->GetEntries();

  ntp = new mytmva::ntuple(nt, ntgen);
}

#endif
