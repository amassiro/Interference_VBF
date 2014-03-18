Tools
================

To transform TF into TGraph

    transform.cxx

How to use:

    root -l- tools/transform.cxx\(\"corr_wLeftRise/results_interference.1000.1.root\",\"test.root\"\)


all:

    root -l -q  tools/transform.cxx\(\"corr_wLeftRise/results_interference.350.1.root\",\"data/350/WWlvjj_turn_on.root\"\)
    root -l -q  tools/transform.cxx\(\"corr_wLeftRise/results_interference.500.1.root\",\"data/500/WWlvjj_turn_on.root\"\)
    root -l -q  tools/transform.cxx\(\"corr_wLeftRise/results_interference.650.1.root\",\"data/650/WWlvjj_turn_on.root\"\)
    root -l -q  tools/transform.cxx\(\"corr_wLeftRise/results_interference.800.1.root\",\"data/800/WWlvjj_turn_on.root\"\)
    root -l -q  tools/transform.cxx\(\"corr_wLeftRise/results_interference.1000.1.root\",\"data/1000/WWlvjj_turn_on.root\"\)

    root -l -q  tools/transform.cxx\(\"corr_woLeftRise/results_interference.350.1.root\",\"data/350/WWlvjj_turn_off.root\",0\)
    root -l -q  tools/transform.cxx\(\"corr_woLeftRise/results_interference.500.1.root\",\"data/500/WWlvjj_turn_off.root\",0\)
    root -l -q  tools/transform.cxx\(\"corr_woLeftRise/results_interference.650.1.root\",\"data/650/WWlvjj_turn_off.root\",0\)
    root -l -q  tools/transform.cxx\(\"corr_woLeftRise/results_interference.800.1.root\",\"data/800/WWlvjj_turn_off.root\",0\)
    root -l -q  tools/transform.cxx\(\"corr_woLeftRise/results_interference.1000.1.root\",\"data/1000/WWlvjj_turn_off.root\",0\)




To tranform root TGraph into txt

    root -l -q tools/dumptxt.cxx\(\"data/350/WWlvjj_turn_off\"\)
    ls data/*/*.root | tr "." " " | awk '{print "root -l -q tools/dumptxt.cxx\\(\\@" $1 "\\@\\)"}' | tr "@" "\""





Transform TH1 into TGraph

    transformTH1TGraph.cxx

How to use:

    root -l -q tools/transformTH1TGraph.cxx\(\"data/800/lhe_800.root\",\"data/800/MCatNLO_Rickard.root\"\)


Transform TH1 into TGraph

    transformTH1TGraphFromDifferentFiles.cxx

How to use:

    root -l -q tools/transformTH1TGraphDifferentFiles.cxx\(\"data/800/mWW_B_dat.root\",\"data/800/mWW_SBI_dat.root\",\"data/800/MCatNLO_Franziska.root\"\)




Transform Text file in TH1

    transformTextTH1.cxx
    transformTextTH1Simple.cxx

How to use:


    root -l -q tools/transformTextTH1.cxx\(\"data/800/mWW_SBI_B_LO.dat\",\"data/800/mWW_B_dat.root\",\"data/800/mWW_SBI_dat.root\"\)

    root -l -q tools/transformTextTH1Simple.cxx\(\"data/800/800_hist.80.dat\",\"data/800/mWW_SBI_dat.root\",\"h_mWW_SBI_dat\"\)
    root -l -q tools/transformTextTH1Simple.cxx\(\"data/800/126_hist.80.dat\",\"data/800/mWW_B_dat.root\",\"h_mWW_B_dat\"\)







