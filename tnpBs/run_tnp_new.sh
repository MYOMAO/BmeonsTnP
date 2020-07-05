#!/bin/bash

idxi=(0)
input=(
	/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/BPlusAna/InputFiles/crab_Bfinder_20190624_Hydjet_Pythia8_Official_BuToJpsiK_1033p1_pt3tkpt0p7dls2_allpthat_pthatweight_MuonJSON_BDT.root
)

g++ numberdetailed.cc $(root-config --libs --cflags) -g -o numberdetailed.exe || exit 1



[[ ${3:-0} -eq 1 ]] && {
	./numberdetailed.exe
}

rm numberdetailed.exe
