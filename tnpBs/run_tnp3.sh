#!/bin/bash

idxi=(0)
input=(
/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/Samples/FinalAnaSamples/PrivateMC-Data-Official-SemiFinal/MC_Bs_PbPb_TMVA_BDT_PbPb.root
)

g++ tnp_converter.cc $(root-config --libs --cflags) -g -o tnp_converter.exe || exit 1



[[ ${1:-0} -eq 1 ]] && {
    for ii in ${idxi[@]}
    do
        echo ${input[ii]}
        ./tnp_converter.exe ${input[ii]}
    done
}


rm tnp_converter.exe

