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


