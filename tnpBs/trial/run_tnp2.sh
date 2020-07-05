#!/bin/bash

idxi=(0)
input=(
    /raid5/data/gwangjun/selected_mc_ntKp_PbPb_2018_MuonJSON_BDT.root
)

g++ tnp_converter2.cc $(root-config --libs --cflags) -g -o tnp_converter2.exe || exit 1
g++ draw_tnp.cc $(root-config --libs --cflags) -g -o draw_tnp.exe || exit 1
g++ number.cc $(root-config --libs --cflags) -g -o number.exe || exit 1

[[ ${1:-0} -eq 1 ]] && {
    for ii in ${idxi[@]}
    do
        echo ${input[ii]}
        ./tnp_converter2.exe ${input[ii]}
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
    for ii in `echo rootfiles/*.root`
    do
        echo $ii
        ./number.exe "$ii"
    done
}

rm tnp_converter2.exe
rm draw_tnp.exe
rm number.exe
