
void transformTH1TGraphDifferentFiles(std::string in1, std::string in2 , std::string out) {
 TFile* fin1  = new TFile(in1.c_str(), "READ");
 TFile* fin2  = new TFile(in2.c_str(), "READ");
 TFile* fout = new TFile(out.c_str(),"RECREATE");

 TH1F* h_B    = (TH1F*) fin1 -> Get ("h_mWW_B_dat");
 TH1F* h_SBI  = (TH1F*) fin2 -> Get ("h_mWW_SBI_dat");

 fout->cd();

 TGraph* g_SBI  = new TGraph (h_SBI);
 TGraph* g_B    = new TGraph (h_B);

 g_SBI -> SetName("SBI");
 g_B   -> SetName("B");

 g_SBI -> Write();
 g_B-> Write();

}

