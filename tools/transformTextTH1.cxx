
//---- transform a text file into a TH1


void transformTextTH1(std::string in, std::string out1, std::string out2) {

 std::cout << " in = " << in << std::endl;
 std::ifstream file (in.c_str());

 std::string buffer;
 if(!file.is_open()) {
  std::cerr << "** ERROR: Can't open '" << in << "' for input" << std::endl;
  return false;
 }

 std::vector<double> X;
 std::vector<double> YB;
 std::vector<double> YSBI;

// #          80 : dS/dmH (fb)     #          80 : dS/dmH (fb)
//          10.0000            0.156743E-10        0.237792E-11             10.0000            0.155207E-10        0.107798E-11

 double num;
 while(!file.eof()) {
  getline(file,buffer);
  std::cout << "buffer = " << buffer << std::endl;
  if (buffer != "" && buffer.at(0) != '#'){ ///---> save from empty line at the end!
//    std::cout << " buffer.at(0) = " << buffer.at(0) << std::endl;
   std::stringstream line( buffer );
   line >> num;
   X.push_back(num);
   line >> num;
   YSBI.push_back(num);
   line >> num; //---- skip
   line >> num; //---- skip
   line >> num;
   YB.push_back(num);
  }
 }

 TFile* fout1  = new TFile(out1.c_str(), "RECREATE");
 TH1F* h_mWW_B_dat    = new TH1F("h_mWW_B_dat",  "h_mWW_B_dat",  100,0,2000);
 TFile* fout2  = new TFile(out2.c_str(), "RECREATE");
 TH1F* h_mWW_SBI_dat  = new TH1F("h_mWW_SBI_dat","h_mWW_SBI_dat",100,0,2000);

 for (int iBin = 0; iBin<100; iBin++) {
  h_mWW_B_dat   -> SetBinContent(iBin+1, YB.at(iBin));
  h_mWW_SBI_dat -> SetBinContent(iBin+1, YSBI.at(iBin));
 }

 fout1->cd();
 h_mWW_B_dat   -> Write();
 fout2->cd();
 h_mWW_SBI_dat -> Write();

}

