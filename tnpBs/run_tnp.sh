#!/bin/bash

idxi=(0)
input=(
	/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/BPlusAna/InputFiles/crab_Bfinder_20190624_Hydjet_Pythia8_Official_BuToJpsiK_1033p1_pt3tkpt0p7dls2_allpthat_pthatweight_MuonJSON_BDT.root
)

g++ tnp_converter.cc $(root-config --libs --cflags) -g -o tnp_converter.exe || exit 1
g++ draw_tnp.cc $(root-config --libs --cflags) -g -o draw_tnp.exe || exit 1
g++ number.cc $(root-config --libs --cflags) -g -o number.exe || exit 1
g++ numberdetailed.cc $(root-config --libs --cflags) -g -o numberdetailed.exe || exit 1



[[ ${1:-0} -eq 1 ]] && {
    for ii in ${idxi[@]}
    do
        echo ${input[ii]}
        ./tnp_converter.exe ${input[ii]}
    done
}

[[ ${2:-0} -eq 1 ]] && {
    for ii in `echo rootfiles/*.root`
    do
        echo $ii
        ./draw_tnp.exe "$ii"
    done
}

[[ ${3:-0} -eq 1 ]] && {
	./number.exe
}

[[ ${3:-0} -eq 1 ]] && {
	./numberdetailed.exe
}

rm tnp_converter.exe
rm draw_tnp.exe
rm number.exe
rm numberdetailed.exe
